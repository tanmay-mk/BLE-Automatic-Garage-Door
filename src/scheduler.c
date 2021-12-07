/*
 * File Name: scheduler.c
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

/*  LIBRARY FILES   */
#include "em_letimer.h"
#include <em_core.h>
#include <stdint.h>
#include <stdio.h>

/*  OTHER FILES TO BE INCLUDED  */
#include "ble.h"
#include "lcd.h"
#include "irq.h"
#include "scheduler.h"
#include "timers.h"
#include "app.h"
#include "oscillators.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

/*  GLOBAL VARIABLES  */
/*
 * t1             = LETIMER0 value when rising edge echo pulse GPIO Interrupt is received
 * t2             = LETIMER0 value when rising edge echo pulse GPIO Interrupt is received
 * difference     = time difference between two GPIO interrupts
 * duration       = convert LETIMER difference to microseconds
 * distance       = distance in cm
 */
int t1 = 0, t2 = 0, difference=0;
int  duration = 0, distance = 0;

/*
 * @brief: turns on stepper motor in the intended direction
 *
 * @parameters: direction : clockwise = 0
 *                          counter clockwise = 1
 *
 * @returns: none
 */
static void turn_on_stepper_motor (int direction);

/*
 * @brief: turns off stepper motor
 *
 * @parameters: none
 *
 * @returns: none
 */
static void turn_off_stepper_motor ();


void schedulerSetEventGPIOEvent()
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  sl_bt_external_signal(GPIOEvent);
  CORE_EXIT_CRITICAL();
}

void schedulerSetEventUF()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  sl_bt_external_signal(UFevent);
  CORE_EXIT_CRITICAL();
}

void schedulerSetEventCOMP1()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  sl_bt_external_signal(COMP1Event);
  CORE_EXIT_CRITICAL();
}

void distance_state_machine(sl_bt_msg_t *evt)
{
  if (indications)
  {
    uint32_t running_event;

    running_event = evt->data.evt_system_external_signal.extsignals; //event
    sl_status_t status = 0;
    distance_t          currentState;
    static distance_t   nextState = STATE_IDLE;

    ble_data_structure_t* ble_common_data = getBLEdata(); //get reference to common ble data structure

    currentState = nextState;

    switch(currentState)
    {

      case STATE_IDLE:
        nextState = STATE_IDLE;

        if (running_event & UFevent)
          {
            TRIG_PIN_HIGH();
            TimerWaitUs_irq(10);
            nextState = STATE_TRIG_START;
          }
        break;

      case STATE_TRIG_START:
        nextState = STATE_TRIG_START;

        if (running_event & COMP1Event)
          {
            TRIG_PIN_LOW();
            nextState = STATE_ECHO_START;
          }
        break;

      case STATE_ECHO_START:
        nextState = STATE_ECHO_START;

        if(running_event & GPIOEvent)
          {
            t1 = LETIMER_CounterGet(LETIMER0);
            nextState = STATE_ECHO_END;
          }
        break;


      case STATE_ECHO_END:
        nextState = STATE_ECHO_END;

        if(running_event & GPIOEvent)
          {
            t2 = LETIMER_CounterGet(LETIMER0);
            nextState = STATE_CALCULATE_DISTANCE;
          }
        break;

      case STATE_CALCULATE_DISTANCE:
        difference = t1-t2;
        duration = (difference*1000000)>>13; //divide by 8192, 2^13 = 8192
        distance = (float) duration/58;

        displayPrintf(DISPLAY_ROW_TEMPVALUE, "Distance = %d", distance);

        status = sl_bt_gatt_server_send_indication(ble_common_data->connectionHandle,
                                                   gattdb_distance_value,
                                                   sizeof(distance),
                                                   &distance);

        if (status) {} //to avoid compiler warning

        printf("%ld sec: DISTANCE: %.02f cm\n\r", letimerMilliseconds(), (float) distance);
        if (distance < 100)
          {
            operate_door();
            indications = 0;
          }
        printf("------------------------------------------------------------------\n\r");
        nextState = STATE_IDLE;
        break;

      default:
        break;

    } //switch
  }  //if (indications)
}   //distance state machine()



static void turn_on_stepper_motor(int direction)
{
  if (direction==CLOCKWISE)
  {
      clockwise_step1();
      TimerWaitUs_polled(2500);
      clockwise_step2();
      TimerWaitUs_polled(2500);
      clockwise_step3();
      TimerWaitUs_polled(2500);
      clockwise_step4();
      TimerWaitUs_polled(2500);
  } //if

  if (direction==COUNTER_CLOCKWISE)
    {
      counter_clockwise_step1();
      TimerWaitUs_polled(2500);
      counter_clockwise_step2();
      TimerWaitUs_polled(2500);
      counter_clockwise_step3();
      TimerWaitUs_polled(2500);
      counter_clockwise_step4();
      TimerWaitUs_polled(2500);
    } //if()
} //turn_on_stepper_motor()

static void turn_off_stepper_motor()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
} //turn_off_stepper_motor()

void operate_door()
{
  displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s" , "Opening the door");
  printf("%ld sec: CAUTION: DOOR OPENING\n\r", letimerMilliseconds());
  for (int i = 0; i<1000; i++)
    {
      turn_on_stepper_motor(CLOCKWISE);
    }
  displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s" , "Car is being parked");
  turn_off_stepper_motor();
  for(int i = 0; i<1000; i++)
  {
     TimerWaitUs_polled(3000);
  }
  displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s" , "Closing the door");
  printf("%ld sec: CAUTION: DOOR CLOSING\n\r", letimerMilliseconds());
  for (int i = 0; i<1000; i++)
    {
      turn_on_stepper_motor(COUNTER_CLOCKWISE);
    }
  turn_off_stepper_motor();
  displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s" , "Car is parked.");
} //operate_door()
