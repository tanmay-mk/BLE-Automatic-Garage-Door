


#include "oscillators.h"


// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"




void clkInitLETIMER()
{
  //uint32_t frequency;

#if (ENERGY_MODE < 3)
//DOS #if (LOWEST_ENERGY_MODE < 3)

    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);    // Enable oscillator.
    CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);  // Select reference clock/oscillator used for a clock branch.
    CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE); // DOS

#else

  CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);  // Enable oscillator.
  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);  // Select reference clock/oscillator used for a clock branch.
  CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE); // DOS

#endif         //Configuring LETIMER clock as ULFRCO oscillator

  //CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE); // DOS did you really want the same prescaler value when using ULFRCO ???
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  /*frequency = CMU_ClockFreqGet (cmuClock_LFA);
  LOG_INFO("cmuClock_LFA=%d", (int)frequency);
  frequency = CMU_ClockFreqGet (cmuClock_LETIMER0);
  LOG_INFO("cmuClock_LETIMER0=%d", (int)frequency);*/

}


