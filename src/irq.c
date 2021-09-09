#include "irq.h"
#include <stdint.h>


void LETIMER0_IRQHandler (void) {
// determine source of IRQ
uint32_t flags;
flags = LETIMER_IntGetEnabled(LETIMER0);
// clear source of IRQ
LETIMER_IntClear(LETIMER0, flags);
// perform whatever processing is required
if (LETIMER_IEN_UF){
gpioLed0SetOff();
}
if (LETIMER_IEN_COMP1){
gpioLed0SetOn();
}
} // LETIMER0_IRQHandler()

/*void LETIMER0_IRQ_ON(void)
{
  CORE_DECLARE_IRQ_STATE;
  uint32_t flags;
  flags=LETIMER_IntGetEnabled(LETIMER0);  //should be called
  CORE_ENTER_CRITICAL();
  {
    gpioLed0SetOn();
    LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP1);
  }
  CORE_EXIT_CRITICAL();
}

void LETIMER0_IRQ_RESET(void)
{
  CORE_DECLARE_IRQ_STATE;
  LETIMER_IntGetEnabled(LETIMER0);  //should be called
  CORE_ENTER_CRITICAL();
  {
    gpioLed0SetOff();
    LETIMER_IntDisable(LETIMER0, LETIMER_IEN_UF);
  }
  CORE_EXIT_CRITICAL();
}*/
