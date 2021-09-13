#include "irq.h"
#include <stdint.h>
#include "em_letimer.h"


void LETIMER0_IRQHandler (void)
{
// determine source of IRQ
uint32_t flags;
flags = LETIMER_IntGetEnabled(LETIMER0);

 if (LETIMER0->IF & LETIMER_IF_UF)        //Setting LED OFF on underflow
  {
      CORE_DECLARE_IRQ_STATE;
      CORE_ENTER_CRITICAL();
      gpioLed0SetOff();
      CORE_EXIT_CRITICAL();
  }

  if (LETIMER0->IF & LETIMER_IF_COMP1)    //Setting LED ON on COMP1 interrupt
  {
      CORE_DECLARE_IRQ_STATE;
      CORE_ENTER_CRITICAL();
      gpioLed0SetOn();
      CORE_EXIT_CRITICAL();
  }
  // clear source of IRQ
  LETIMER_IntClear(LETIMER0, flags);
} // LETIMER0_IRQHandler()
