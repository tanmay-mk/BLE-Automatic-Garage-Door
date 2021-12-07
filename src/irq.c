/*
 * File Name: irq.c
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

/*  LIBRARY FILES   */
#include <stdint.h>
#include "em_letimer.h"

/*  OTHER FILES TO BE INCLUDED  */
#include "irq.h"
#include "scheduler.h"
#include "timers.h"
#include "src/log.h"

/*  MACROS  */
#define INCLUDE_LOG_DEBUG 1

/*  GLOBAL VARIABLES  */
uint32_t rollOver=0;

void LETIMER0_IRQHandler()
{
  uint32_t flags=0;

  flags = LETIMER_IntGetEnabled(LETIMER0);

  LETIMER_IntClear(LETIMER0, flags);

  if (flags & LETIMER_IF_UF)
   {
        rollOver++;
        schedulerSetEventUF();
   }

  if (flags & LETIMER_IF_COMP1)
    {
      LETIMER_IntDisable(LETIMER0, LETIMER_IF_COMP1);  //Initialize Comp1 Interrupt
      schedulerSetEventCOMP1();
    }

} // LETIMER0_IRQHandler()


void GPIO_ODD_IRQHandler(void)
{
  uint32_t int_flag= GPIO_IntGet();

  if (int_flag & (1 << ECHO_PIN))
  {
     schedulerSetEventGPIOEvent();
  }
  GPIO_IntClear(int_flag);

} //GPIO_ODD_IRQHandler()

uint32_t letimerMilliseconds()
{
  uint32_t timePassed, totalUnderflowTime, nextUnderflowRemainingTime;
  uint32_t current_count;

  totalUnderflowTime = rollOver * LETIMER_PERIOD_MS;

  current_count = LETIMER_CounterGet(LETIMER0);

  nextUnderflowRemainingTime = ((VALUE_TO_LOAD-current_count)*1000)>>13;

  timePassed = totalUnderflowTime + nextUnderflowRemainingTime;

  return timePassed/1000;

} //letimerMilliseconds()

