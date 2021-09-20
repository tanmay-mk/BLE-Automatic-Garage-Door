#include "scheduler.h"
#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include <em_core.h>
#include <stdint.h>
#include <stdio.h>

  uint32_t eventFlag=0;

void schedulerSetEventReadTemperature()     //sets the event in the scheduler
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  eventFlag = readTemperature;
  CORE_EXIT_CRITICAL();
}

uint32_t getNextEvent()         //returns the next event to the main loop
{
  uint32_t event=0;
  if (eventFlag)
    {
      CORE_DECLARE_IRQ_STATE;
      CORE_ENTER_CRITICAL();
      {
        event = eventFlag;
        eventFlag = 0;
      }
      CORE_EXIT_CRITICAL();
    }
  return event;
}


