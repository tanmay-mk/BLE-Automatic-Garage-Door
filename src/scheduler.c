#include "scheduler.h"
#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include <em_core.h>
#include <stdint.h>
#include <stdio.h>
#include "i2c.h"


// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"


uint32_t eventFlag=0; // my private scheduler data structure to maintain up to 32 events as single bits


void schedulerSetEventUF()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;

  // DOS for debug
  //gpioToggleLed0();

  CORE_ENTER_CRITICAL();
  eventFlag |= UFevent; // this is a RMW
  CORE_EXIT_CRITICAL();
}

void schedulerSetEventCOMP1()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;

  // DOS for debug
  //gpioToggleLed0();

  CORE_ENTER_CRITICAL();
  eventFlag |= COMP1Event; // this is a RMW
  CORE_EXIT_CRITICAL();
}

void schedulerSetEventI2CDone()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;

  // DOS for debug
  //gpioToggleLed0();

  CORE_ENTER_CRITICAL();
  eventFlag |= I2CDoneEvent; // this is a RMW
  CORE_EXIT_CRITICAL();
}


uint32_t getNextEvent()         //returns the next event to the main loop
{
  uint32_t event=noEvent;
  CORE_DECLARE_IRQ_STATE;


  if (eventFlag & UFevent) {

      // DOS for debug
      //gpioToggleLed1();
      //LOG_INFO("B");

      event      = UFevent; // event to return to caller
      CORE_ENTER_CRITICAL();
      //eventFlag ^= readTemperature; // RMW, clear event in my private scheduler data structure
      eventFlag = eventFlag & (UFevent ^ 0xFFFFFFFF); // RMW, clear event in my private scheduler data structure
      CORE_EXIT_CRITICAL();
  }

  // DOS: add other events here for A4
  else if (eventFlag & COMP1Event) {

      // DOS for debug
      //gpioToggleLed1();
      //LOG_INFO("B");

      event      = COMP1Event; // event to return to caller
      CORE_ENTER_CRITICAL();
      //eventFlag ^= readTemperature; // RMW, clear event in my private scheduler data structure
      eventFlag = eventFlag & (COMP1Event ^ 0xFFFFFFFF); // RMW, clear event in my private scheduler data structure
      CORE_EXIT_CRITICAL();
  }

  else if (eventFlag & I2CDoneEvent) {

      // DOS for debug
      //gpioToggleLed1();
      //LOG_INFO("B");

      event      = I2CDoneEvent; // event to return to caller
      CORE_ENTER_CRITICAL();
      //eventFlag ^= readTemperature; // RMW, clear event in my private scheduler data structure
      eventFlag = eventFlag & (I2CDoneEvent ^ 0xFFFFFFFF); // RMW, clear event in my private scheduler data structure
      CORE_EXIT_CRITICAL();
  }

  return event;

} // getNextEvent()



void state_machine (uint32_t event)
{
     state_t       currentState;
     static state_t nextState = STATE0_IDLE;

     currentState = nextState;

     switch(currentState)
     {
       case STATE0_IDLE:
         nextState = STATE0_IDLE;
         if (event == UFevent)
           {
             // turn power on to 7021
           //  gpioSensorEnSetOn();
             // wait 80ms for power to stabilize and 7021 to complete its power up sequence
             TimerWaitUs_irq(80000);
             nextState = STATE1_POWERUP;
           }
         break;

       case STATE1_POWERUP:
         nextState = STATE1_POWERUP;
         if (event == COMP1Event)
           {
             //add power requirement to em1
             sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

             //i2c write
             I2C_Write();

             nextState = STATE2_I2C_WRITE;

           }
         break;

       case STATE2_I2C_WRITE:
         nextState = STATE2_I2C_WRITE;
         if (event == I2CDoneEvent)
           {

             //remove power management requirement to wake up from EM3
             sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);

             //wait for 10.8 ms for si7021 to take reading
             TimerWaitUs_irq(10800);

             nextState = STATE3_TIMERWAIT;

           }
         break;

       case STATE3_TIMERWAIT:
         nextState = STATE3_TIMERWAIT;
         if (event == COMP1Event)
           {
             //add power requirement to em1
             sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

             //i2c read
             I2C_Read();

             nextState = STATE4_I2C_READ;
             //LOG_INFO("To4");
           }
         break;

       case STATE4_I2C_READ:
         nextState = STATE4_I2C_READ;

         if(event == I2CDoneEvent)
           {



             //remove power management requirement to wake up from EM3
             sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);

             // turn power off to 7021
             gpioSensorEnSetOff();

             //convert to deg C and log them
             read_temp_from_si7021();
             //go back to idle

             // done with I2C for this measurement cycle
             nextState = STATE0_IDLE;
             //LOG_INFO("To0");

           }
         break;

       default:
         break;
     } //switch

} //state_machine
