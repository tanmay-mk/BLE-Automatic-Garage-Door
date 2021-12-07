/*
 * File Name: oscillators.h
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

/*  OTHER FILES TO BE INCLUDED  */
#include "oscillators.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

void clkInitLETIMER()
{
    #if (ENERGY_MODE < 3)

    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);    // Enable oscillator.
    CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);  // Select reference clock/oscillator used for a clock branch.
    CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE);     // DOS

    #else

      CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);    // Enable oscillator.
      CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);  // Select reference clock/oscillator used for a clock branch.
      CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE);       // DOS

    #endif         //Configuring LETIMER clock as ULFRCO oscillator

    CMU_ClockEnable(cmuClock_LETIMER0, true);
}


