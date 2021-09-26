
#ifndef __myTimers
#define __myTimers

#include "app.h"
#include "em_letimer.h"
#include "main.h"
#include "oscillators.h"




#define ACTUAL_CLK_FREQ     CLK_FREQ/PRESCALE

#define ACTUAL_CLK_PERIOD   1/ACTUAL_CLK_FREQ

#if (ENERGY_MODE < 3)
   //#define VALUE_TO_LOAD       (LETIMER_PERIOD_MS*ACTUAL_CLK_FREQ)/1000         //comp0 value, top value for counter
   // This is for LFXO @ 32768 Hz
   // so you set your prescaler to 4, 32678/4 = 8192 Hz, which is ~122us per count (per tick)
   //  3 seconds / 122 us = 24,576
   #define VALUE_TO_LOAD   (24576)
#else

   // This is for ULFRCO @ 1000 Hz, 1 ms per tick, 3000 ms = 3 secs
   #define VALUE_TO_LOAD   (3000)
#endif

#define INTERRUPT_VALUE     (LETIMER_ON_MS*ACTUAL_CLK_FREQ)/1000          //COMP1 value


void initLETIMER(void);

void TimerWaitUs_polled(uint32_t DELAY);

void TimerWaitUs_irq(uint32_t DELAY);


#endif

