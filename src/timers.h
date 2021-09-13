
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

//#define VALUE_TO_LOAD       18432         //Top value for EM0, EM1 & EM2
#define VALUE_TO_LOAD       563         //Top Value for EM 3

//#define INTERRUPT_VALUE     1434          //COMP1 value for EM0, EM1 & EM2
#define INTERRUPT_VALUE     44          //COMP1 value for EM3

void initLETIMER(void);

#endif

