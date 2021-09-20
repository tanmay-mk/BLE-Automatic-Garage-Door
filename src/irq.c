#include "irq.h"
#include <stdint.h>
#include "em_letimer.h"
#include "scheduler.h"

void LETIMER0_IRQHandler() {
// determine source of IRQ (interrupt) in peripheral
  uint32_t flags;
  flags = LETIMER_IntGetEnabled(LETIMER0);

// call scheduler routine to set a scheduler event.
  if (LETIMER0->IF & LETIMER_IF_UF)
   {
      CORE_DECLARE_IRQ_STATE;
      CORE_ENTER_CRITICAL();
      {
        LETIMER_IntClear(LETIMER0, flags);
        schedulerSetEventReadTemperature();
      }
      CORE_EXIT_CRITICAL();
   }
   // clear interrupt source (bit / flip-flop) in peripheral
}



