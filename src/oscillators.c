
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

  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);          //Selecting oscillator for EM0, EM1 & EM2
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);       //Configuring LETIMER clock as LFXO oscillator

  //CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);            //Selecting oscillator for EM3
  //CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);         //Configuring LETIMER clock as ULFRCO oscillator

  CMU_ClockDivSet(cmuClock_LETIMER0, PRESCALE);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  frequency = CMU_ClockFreqGet (cmuClock_LFA);
  frequency = CMU_ClockFreqGet (cmuClock_LETIMER0);
}


