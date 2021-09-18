
#include "app.h"
#include "oscillators.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include <stdint.h>

void clkInitLETIMER()
{
  uint32_t frequency;

#if (LOWEST_ENERGY_MODE < 3)
    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);    // Enable oscillator.
    CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);  // Select reference clock/oscillator used for a clock branch.

#else

  CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);  // Enable oscillator.
  CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);  // Select reference clock/oscillator used for a clock branch.

#endif         //Configuring LETIMER clock as ULFRCO oscillator

  CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  frequency = CMU_ClockFreqGet (cmuClock_LFA);
  frequency = CMU_ClockFreqGet (cmuClock_LETIMER0);
}


