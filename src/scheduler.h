#ifndef __MY_SCHEDULER__
#define __MY_SCHEDULER__

#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "em_letimer.h"
#include "irq.h"


enum {
noEvent           = 0,
UFevent           = 1,
COMP1Event        = 2,
I2CDoneEvent      = 4,
};


typedef enum uint32_t {
  STATE0_IDLE,
  STATE1_POWERUP,   //underflow
  STATE2_I2C_WRITE, //comp1
  STATE3_TIMERWAIT, //i2c done
  STATE4_I2C_READ,  //comp1
  MY_STATES
} state_t;



void schedulerSetEventUF();  //sets the event in the state machine to power up the si7021

void schedulerSetEventCOMP1();  //sets the event in the state machine to sleep in EM1 while delay is running

void schedulerSetEventI2CDone();   //sets the event in the state machine to take temperature measurement

uint32_t getNextEvent();

void state_machine(uint32_t event);

#endif
