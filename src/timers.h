
#ifndef __myTimers
#define __myTimers

#include "app.h"
#include "em_letimer.h"
#include "main.h"
#include "oscillators.h"


#define PRESCALE            4

//#define ACTUAL_CLK_FREQ     8192          //Actual Clock for EM0, EM1 & EM2
#define ACTUAL_CLK_FREQ     250         //Actual Clock for EM3

#define ACTUAL_CLK_PERIOD   1/ACTUAL_CLK_FREQ

#define VALUE_TO_LOAD       (LETIMER_PERIOD_MS*ACTUAL_CLK_FREQ)/1000         //comp0 value, top value for counter

#define INTERRUPT_VALUE     (LETIMER_ON_MS*ACTUAL_CLK_FREQ)/1000          //COMP1 value


void initLETIMER(void);

#endif

