#include "irq.h"
#include <stdint.h>
#include "em_letimer.h"

void LETIMER0_IRQHandler() {
// determine source of IRQ (interrupt) in peripheral
  uint32_t flags;
  flags = LETIMER_IntGetEnabled(LETIMER0);

// call scheduler routine to set a scheduler event.
  if (LETIMER0->IF & LETIMER_IF_UF)
   {
       CORE_DECLARE_IRQ_STATE;
       CORE_ENTER_CRITICAL();
       schedulerSetEventUF();
       CORE_EXIT_CRITICAL();
   }
   // clear interrupt source (bit / flip-flop) in peripheral
     LETIMER_IntClear(LETIMER0, flags);
}

void some_IRQHandler(void) {
struct sameData_t *myData;
struct irq_event_t {
uint32_t timestamp;
uint32_t someValue;
};
static event_index=0;
static struct irq_event_t event_array[32];
// determine IRQ source
// clear IRQ source
myData = getPtrToMyData();
// record event
event_array[event_index].timestamp = getTimestamp();
event_array[event_index].someValue = myData->someValue;
event_index++;
callSomeFunction(myData);
// record event
event_array[event_index].timestamp = getTimestamp();
event_array[event_index].someValue = myData->someValue;
event_index++;
if (event_index >= 32)
{ __BKPT(0); // break
}
if (myData->someValue)
  {
// do something
  }
} // some_IRQHandler()



