#include "irq.h"
#include <stdint.h>
#include "em_letimer.h"
#include "scheduler.h"
#include "timers.h"
#include "i2c.h"

#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

uint32_t rollOver=0;

void LETIMER0_IRQHandler() {


  uint32_t flags=0;

  static flag=false;

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
        rollOver++;      //sets the event in the scheduler
        schedulerSetEventUF();
        // DOS: debug to determine if UF is occurring every 3 sec, it is.
        if (flag == false) {
            flag = true;
            gpioLed0SetOn();
        } else {
            flag = false;
            gpioLed0SetOff();
        }
   }

  if (flags & LETIMER_IF_COMP1)
    {
      schedulerSetEventCOMP1();
      LETIMER_IntDisable(LETIMER0, LETIMER_IEN_COMP1);
    }

} // LETIMER0_IRQHandler()

void I2C0_IRQHandler(void)
{
  // this can be locally defined
  I2C_TransferReturn_TypeDef transferStatus;

  // This shepherds the IC2 transfer along,
  // it’s a state machine! see em_i2c.c
  // It accesses global variables :
  // transferSequence
  // cmd_data
  // read_data
  transferStatus = I2C_Transfer(I2C0);

if (transferStatus == i2cTransferDone)
  {
    schedulerSetEventI2CDone();
     // NVIC_DisableIRQ(I2C0_IRQn); // DOS: moved to state machine
  }

  if (transferStatus < 0) {
  LOG_ERROR("%d", transferStatus);
  }

} // I2C0_IRQHandler()





uint32_t letimerMilliseconds()
{
uint32_t timePassed, totalUnderflowTime, nextUnderflowRemainingTime;
uint32_t current_count;

totalUnderflowTime = rollOver * 3000;

current_count = LETIMER_CounterGet(LETIMER0);

nextUnderflowRemainingTime = ((3000-current_count)/1000);

timePassed = totalUnderflowTime + nextUnderflowRemainingTime;

return timePassed;

}


