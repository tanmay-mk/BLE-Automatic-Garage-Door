#include "irq.h"
#include <stdint.h>
#include "em_letimer.h"
#include "scheduler.h"

void LETIMER0_IRQHandler() {

  uint32_t flags;

  // DOS for debug
  //gpioToggleLed0();

  // step 1: determine source of IRQ (interrupt) in peripheral
  flags = LETIMER_IntGetEnabled(LETIMER0);

  // step 2: punch down all IF bits in peripheral IF register
  LETIMER_IntClear(LETIMER0, flags);


  // step 3: process the IF bits

  // call scheduler routine to set a scheduler event.
  //DOS if (LETIMER0->IF & LETIMER_IF_UF)
  if (flags & LETIMER_IF_UF)
   {
      //DOS critical section is implemented in schedulerSetEventReadTemperature, so not needed here
      //CORE_DECLARE_IRQ_STATE;
      //CORE_ENTER_CRITICAL();
      {
        schedulerSetEventReadTemperature();       //sets the event in the scheduler
      }
      //CORE_EXIT_CRITICAL();
   }

} // LETIMER0_IRQHandler()





