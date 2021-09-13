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

     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF);   //Initialize Underflow Interrupt
     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP1);  //Initialize Comp1 Interrupt

     LETIMER_CompareSet(LETIMER0, 1, INTERRUPT_VALUE);  //175ms

    //enable LETIMER
    LETIMER_Enable(LETIMER0,true);

}
