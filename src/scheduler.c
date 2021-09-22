#include "scheduler.h"
#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include <em_core.h>
#include <stdint.h>
#include <stdio.h>


// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"


uint32_t eventFlag=0; // my private scheduler data structure to maintain up to 32 events as single bits

void schedulerSetEventReadTemperature()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;

  // DOS for debug
  gpioToggleLed0();

  CORE_ENTER_CRITICAL();
  //eventFlag = readTemperature; // DOS why is this not a read-modify-write (RMW) !!!!!!!
  eventFlag |= readTemperature; // this is a RMW
  CORE_EXIT_CRITICAL();
}


uint32_t getNextEvent()         //returns the next event to the main loop
{
  uint32_t event=noEvent;
  CORE_DECLARE_IRQ_STATE;

   // Again why is this not a read-modfiy-write? !!!!!
//      {
//        event = eventFlag;
//        eventFlag = 0;
//      }

  if (eventFlag & readTemperature) {

      // DOS for debug
      //gpioToggleLed1();
      LOG_INFO("B");

      event      = readTemperature; // event to return to caller
      CORE_ENTER_CRITICAL();
      //eventFlag ^= readTemperature; // RMW, clear event in my private scheduler data structure
      eventFlag = eventFlag & (readTemperature ^ 0xFFFFFFFF); // RMW, clear event in my private scheduler data structure
      CORE_EXIT_CRITICAL();

  }

  // DOS: add other events here for A4



  return event;

} // getNextEvent()


