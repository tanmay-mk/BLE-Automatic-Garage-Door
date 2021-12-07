/*
 * File Name: timers.c
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

/*  LIBRARY FILES */
#include <stdio.h>
#include "em_letimer.h"

/*  OTHER FILES TO BE INCLUDED  */
#include "timers.h"
#include "app.h"
#include "oscillators.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

     letimerInit.comp0Top = true;                 //Loading comp1 value in CNT register
     letimerInit.ufoa0 = letimerUFOANone;         //No output action on underflow
     letimerInit.repMode = letimerRepeatFree;     //Repeats until stopped
     letimerInit.enable = false;
     letimerInit.topValue = VALUE_TO_LOAD;        //Loading top value in COMP1
     letimerInit.debugRun = true;                 // allow counter to run when in debugger mode

     NVIC_EnableIRQ(LETIMER0_IRQn);               //Enabling NVIC to handle LETIMER0 interrupts

     LETIMER_Init(LETIMER0, &letimerInit);        // Initialize and enable LETIMER

     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF); //Initialize Underflow Interrupt

    //enable LETIMER
    LETIMER_Enable(LETIMER0, true);

} // initLETIMER()


void TimerWaitUs_irq(uint32_t DELAY)
{
    uint32_t CURRENT_COUNT, TICKS, COMP1VALUE;
    if(DELAY > (LETIMER_PERIOD_MS*1000))            // Condition to check if the delay time can be handled
    {
        LOG_ERROR("The delay is greater than the value which can be handled by LETIMER", "Error", 0);
        DELAY=LETIMER_PERIOD_MS*1000;               // Maximum possible delay
    }

    TICKS= ACTUAL_CLK_FREQ * DELAY;

    TICKS=(uint32_t) TICKS/1000000;                 //Calculate the ticks required in us

    CURRENT_COUNT = LETIMER_CounterGet(LETIMER0);

    COMP1VALUE = CURRENT_COUNT-TICKS;

    LETIMER_IntEnable(LETIMER0, LETIMER_IF_COMP1);  //Initialize Comp1 Interrupt

    LETIMER_CompareSet(LETIMER0, 1, COMP1VALUE);

    LETIMER0->IEN |= LETIMER_IF_COMP1;
}

void TimerWaitUs_polled(uint32_t DELAY)
{
    uint32_t CURRENT_COUNT, TICKS, t1;
    if(DELAY > (LETIMER_PERIOD_MS*1000))            // Condition to check if the delay time can be handled
    {
       LOG_ERROR("The delay is greater than the value which can be handled by LETIMER", "Error", 0);
       DELAY=LETIMER_PERIOD_MS*1000;               // Maximum possible delay
    }

    TICKS= ACTUAL_CLK_FREQ * DELAY;
    TICKS=(uint32_t) TICKS/1000000;                 //Calculate the ticks required in us

    CURRENT_COUNT = t1 = LETIMER_CounterGet(LETIMER0);

    while (TICKS)
    {
        if (CURRENT_COUNT != LETIMER_CounterGet(LETIMER0) )
        {
            // CNT just changed
            TICKS--; // decrement ticks
            CURRENT_COUNT = LETIMER_CounterGet(LETIMER0); // get new CNT value
        }
    }
}
