#include "timers.h"
#include "app.h"

#include "oscillators.h"
#include "em_letimer.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"


void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

     letimerInit.comp0Top = true;         //Loading comp1 value in CNT register
     letimerInit.ufoa0 = letimerUFOANone;   //No output action on underflow
     letimerInit.repMode = letimerRepeatFree;   //Repeats until stopped
     letimerInit.enable = false;
     letimerInit.topValue = VALUE_TO_LOAD;      //Loading top value in COMP1
     letimerInit.debugRun = true;

     NVIC_EnableIRQ(LETIMER0_IRQn);             //Enabling NVIC to handle LETIMER0 interrupts

     LETIMER_Init(LETIMER0, &letimerInit); // Initialize and enable LETIMER
     NVIC_ClearPendingIRQ(LETIMER0_IRQn);

     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF);   //Initialize Underflow Interrupt
     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP1);  //Initialize Comp1 Interrupt

     LETIMER_CompareSet(LETIMER0, 1, INTERRUPT_VALUE);  //175ms

    //enable LETIMER
    LETIMER_Enable(LETIMER0,true);

}

void TimerWaitUs(uint32_t DELAY)
{
  uint32_t CURRENT_COUNT, MAX_COUNT, TICKS;

  if(DELAY > (LETIMER_PERIOD_MS*1000))         // Condition to check if the delay time can be handled
  {
    LOG_ERROR("The delay is greater than the value which can be handled by LETIMER", "Error", 0);
    DELAY=3000000;                 // Maximum possible delay
  }

  TICKS=ACTUAL_CLK_FREQ * DELAY;
  TICKS=TICKS/1000000;              //Calculate the ticks required in us

  CURRENT_COUNT=LETIMER_CounterGet(LETIMER0);       //Get the present value of timer count

  MAX_COUNT=CURRENT_COUNT-TICKS;
  if(MAX_COUNT>VALUE_TO_LOAD)                  // Case when timer overflows
  {
      TICKS=65535-MAX_COUNT;
      MAX_COUNT=VALUE_TO_LOAD-TICKS;
  }

  LETIMER_CompareSet(LETIMER0,1,MAX_COUNT);
  LETIMER_IntEnable(LETIMER0,LETIMER_IF_COMP1);     // Enable interrupt for COMP1
}
