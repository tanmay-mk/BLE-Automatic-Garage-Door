
#include "oscillators.h"
#include "timers.h"
#include "app.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include "em_core.h"

void LETIMER0_IRQ_ON(void);
void LETIMER0_IRQ_RESET(void);
