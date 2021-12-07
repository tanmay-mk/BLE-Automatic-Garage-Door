#include "scheduler.h"
#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include <em_core.h>
#include <stdint.h>
#include <stdio.h>
#include "ble.h"
#include "lcd.h"
#include "irq.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

uint32_t eventFlag=0; // my private scheduler data structure to maintain up to 32 events as single bits

int t1 = 0, t2 = 0, difference=0;
int  duration = 0, distance = 0;

static void turn_on_stepper_motor (int direction);
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
        //printf("1\n\r");
        nextState = STATE_IDLE;

        if (running_event & UFevent)
          {
            //printf("2\n\r");
            TRIG_PIN_HIGH();
            TimerWaitUs_irq(10);
            nextState = STATE_TRIG_START;
          }
        break;

      case STATE_TRIG_START:
        //printf("3\n\r");
        nextState = STATE_TRIG_START;

        if (running_event & COMP1Event)
          {
            //printf("4\n\r");
            TRIG_PIN_LOW();
            nextState = STATE_ECHO_START;
          }
        break;

      case STATE_ECHO_START:
        //printf("5\n\r");
        nextState = STATE_ECHO_START;

        if(running_event & GPIOEvent)
          {
            //printf("6\n\r");
            t1 = LETIMER_CounterGet(LETIMER0);
            nextState = STATE_ECHO_END;
          }
        break;


      case STATE_ECHO_END:
        //printf("7\n\r");
        nextState = STATE_ECHO_END;

        if(running_event & GPIOEvent)
          {
            //printf("8\n\r");
            t2 = LETIMER_CounterGet(LETIMER0);
            nextState = STATE_CALCULATE_DISTANCE;
          }
        break;

      case STATE_CALCULATE_DISTANCE:
        //printf("9\n\r");
        difference = t1-t2;
        duration = (difference*1000000)>>13; //divide by 8192, 2^13 = 8192
        distance = (float) duration/58;

        displayPrintf(DISPLAY_ROW_TEMPVALUE, "Distance = %d", distance);

        status = sl_bt_gatt_server_send_indication(ble_common_data->connectionHandle,
                                                   gattdb_distance_value,
                                                   sizeof(distance),
                                                   &distance);

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
  }
}   //distance state machine



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
  }

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
    }
}

static void turn_off_stepper_motor ()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void operate_door()
{
  printf("CAUTION: DOOR OPENING\n\r");
  for (int i = 0; i<1000; i++)
    {
      turn_on_stepper_motor(CLOCKWISE);
    }
  turn_off_stepper_motor();
  for(int i = 0; i<1000; i++)
  {
     TimerWaitUs_polled(3000);
  }
  printf("CAUTION: DOOR CLOSING\n\r");
  for (int i = 0; i<1000; i++)
    {
      turn_on_stepper_motor(COUNTER_CLOCKWISE);
    }
  turn_off_stepper_motor();
}
