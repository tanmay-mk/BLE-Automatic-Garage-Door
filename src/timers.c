#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"


void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;
     uint32_t counter;
     letimerInit.comp0Top = true;
     letimerInit.ufoa0 = letimerUFOANone;
     letimerInit.repMode = letimerRepeatFree;
     letimerInit.enable = false;
     letimerInit.topValue = VALUE_TO_LOAD;
     letimerInit.debugRun = true;


     LETIMER_Init(LETIMER0, &letimerInit ); // Initialize and enable LETIMER

     LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF | LETIMER_IEN_COMP1);


     LETIMER_CompareSet(LETIMER0, 1, 1434); //175ms




    //enable LETIMER
    LETIMER_Enable(LETIMER0,true);
    counter = LETIMER_CounterGet (LETIMER0);
    counter = LETIMER_CounterGet (LETIMER0);
    counter = LETIMER_CounterGet (LETIMER0);
    counter = LETIMER_CounterGet (LETIMER0);

}
