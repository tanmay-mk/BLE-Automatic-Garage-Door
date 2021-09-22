#ifndef __MY_SCHEDULER__
#define __MY_SCHEDULER__

#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include "irq.h"


typedef enum {
noEvent           = 0,
readTemperature   = 1,
readHumidity      = 2
} myFlags;

void schedulerSetEventReadTemperature();

uint32_t getNextEvent();


#endif
