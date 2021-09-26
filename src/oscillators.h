#ifndef __myOscillator
#define __myOscillator

#include "app.h"
#include "em_letimer.h"
#include "main.h"
#include <stdint.h>

#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"

#if (ENERGY_MODE < 3)
   // This is for LFXO @ 32768 Hz
   #define PRESCALE        (4)
#else

   // This is for ULFRCO @ 1000 Hz, 1 ms per tick, 3000 ms = 3 secs
   #define PRESCALE        (1)
#endif


void clkInitLETIMER();          //Function to initialize clock

#endif
