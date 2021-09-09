#ifndef __myOscillator
#define __myOscillator

#include "app.h"
#include "em_letimer.h"
#include "main.h"
#include <stdint.h>

#define PRESCALE            (4)
#define ACTUAL_CLK_FREQ     8192
#define ACTUAL_CLK_PERIOD   (1/ACTUAL_CLK_FREQ)
#define VALUE_TO_LOAD       18432

//function declarations
void clkInitLETIMER();
void energyMode(uint32_t mode);

#endif
