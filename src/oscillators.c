
#include "app.h"
#include "oscillators.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include <stdint.h>

  uint8_t mode=0;
  //sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
  //sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM2);
  //sl_power_manager_remove_em_requirement();

void clkInitLETIMER()
{
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockEnable(cmuClock_GPIO, true);

  energyMode(mode);

  CMU_ClockEnable(cmuClock_LETIMER0, true);
  CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_4);
}

void energyMode (uint32_t mode)
{

  if (mode < 3)
    {
      CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
      CMU_ClockSelectSet(cmuClock_LETIMER0, cmuSelect_LFXO);
    }
  if (mode == 3)
    {
      CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
      CMU_ClockSelectSet(cmuClock_LETIMER0, cmuSelect_ULFRCO);
    }
}
