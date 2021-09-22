#include "timers.h"
#include "app.h"

#include <stdio.h>

#include "oscillators.h"
#include "em_letimer.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"




void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;
  uint16_t      counter_value;

     letimerInit.comp0Top = true;         //Loading comp1 value in CNT register
     letimerInit.ufoa0 = letimerUFOANone;   //No output action on underflow
     letimerInit.repMode = letimerRepeatFree;   //Repeats until stopped
     letimerInit.enable = false;
     letimerInit.topValue = VALUE_TO_LOAD;      //Loading top value in COMP1
     letimerInit.debugRun = true; // allow counter to run when in debugger mode

     LOG_INFO("topValue=%d", (int) VALUE_TO_LOAD); // DEBUG DOS

     LETIMER_Init(LETIMER0, &letimerInit); // Initialize and enable LETIMER

     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF);   //Initialize Underflow Interrupt
     //LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP1);  //Initialize Comp1 Interrupt

    //enable LETIMER
    LETIMER_Enable(LETIMER0, true);

    // read the counter  a few times in the debugger to sanity check that the values
    // we're seeing stay with the expected range
    counter_value = LETIMER_CounterGet (LETIMER0);
    counter_value = LETIMER_CounterGet (LETIMER0);
    counter_value = LETIMER_CounterGet (LETIMER0);



    NVIC_ClearPendingIRQ(LETIMER0_IRQn);
    NVIC_EnableIRQ(LETIMER0_IRQn);             //Enabling NVIC to handle LETIMER0 interrupts


} // initLETIMER()



void TimerWaitUs(uint32_t DELAY)
{
  uint32_t CURRENT_COUNT, MAX_COUNT, TICKS;

  if(DELAY > (LETIMER_PERIOD_MS*1000))         // Condition to check if the delay time can be handled
  {
    LOG_ERROR("The delay is greater than the value which can be handled by LETIMER", "Error", 0);
    DELAY=3000000;                 // Maximum possible delay
  }

  // DOS - FIXME
  // This will only work for EM3 @ 1000 Hz
  TICKS = (uint32_t) DELAY/1000; // number of ticks we need to see go by in order for the requested time to pass
  CURRENT_COUNT = LETIMER_CounterGet(LETIMER0);
  while (TICKS) {
      if (CURRENT_COUNT != LETIMER_CounterGet(LETIMER0) ) {
          // CNT just changed
          TICKS--; // decrement ticks
          CURRENT_COUNT = LETIMER_CounterGet(LETIMER0); // get new CNT value
      }

  } // while


  /*
  TICKS=ACTUAL_CLK_FREQ * DELAY;
  TICKS=TICKS/1000000;              //Calculate the ticks required in us

  CURRENT_COUNT=LETIMER_CounterGet(LETIMER0);       //Get the present value of timer count

  MAX_COUNT=CURRENT_COUNT-TICKS;
  if(MAX_COUNT>VALUE_TO_LOAD)                  // Case when timer overflows
  {
      TICKS=65535-MAX_COUNT; // cannot use
      MAX_COUNT=VALUE_TO_LOAD-TICKS;
  }
  */

  // DOS: Why are you setting up COMP1 register? This routine is supposed to poll on the
  //      counter value? This si what we will do in A4
//  LETIMER_CompareSet(LETIMER0,1,MAX_COUNT);
//  LETIMER_IntEnable(LETIMER0,LETIMER_IF_COMP1);     // Enable interrupt for COMP1


} // TimerWaitUs()
