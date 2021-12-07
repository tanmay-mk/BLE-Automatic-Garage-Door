/*
 * File Name: scheduler.h
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

/*  LIBRARY FILES */
#include "em_letimer.h"

/*  OTHER FILES TO BE INCLUDED  */
#include "timers.h"
#include "app.h"
#include "oscillators.h"
#include "irq.h"

/* ENUMERATION FOR VALUES OF VARIOUS EVENTS THAT ARE TO BE SET IN SCHEDULER */
enum {
noEvent                     = 0,
UFevent                     = 1,
COMP1Event                  = 2,
GPIOEvent                   = 4
};

/* ENUMERATION FOR STATES TO DRIVE THE STATE MACHINE */
typedef enum {
  STATE_IDLE,
  STATE_TRIG_START,
  STATE_ECHO_START,
  STATE_ECHO_END,
  STATE_CALCULATE_DISTANCE
}distance_t;

/* ENUMERATION FOR DIRECTION OF STEPPER MOTOR */
enum {
  CLOCKWISE         = 0,
  COUNTER_CLOCKWISE = 1
};

/*  FUNCTION PROTOTYPES */
/*-------------------------------------------------------------------------------
 * @brief:  after every underflow interrupt, this function sets the event in the
 *          scheduler
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void schedulerSetEventUF();

/*-------------------------------------------------------------------------------
 * @brief:  after every comp 1 interrupt, this function sets the event in the
 *          scheduler
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void schedulerSetEventCOMP1();  //sets the event in the state machine to sleep in EM1 while delay is running

/*-------------------------------------------------------------------------------
 * @brief:  after every GPIO interrupt, this function sets the event in the
 *          scheduler
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void schedulerSetEventGPIOEvent();

/*-------------------------------------------------------------------------------
 * @brief:  Takes measurements from the state machine using various interrupts
 *          and measures the distance using ultrasonic sensor
 *
 * @parameters: evt : event that is set in the scheduler after corresponding
 *                    interrupt
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void distance_state_machine(sl_bt_msg_t *evt);

/*-------------------------------------------------------------------------------
 * @brief:  Code to turn stepper motor in a particular direction
 *
 * @parameters: direction : the direction in which the motor is to be turned
 *
 * @returns: none
 ------------------------------------------------------------------------------*/

void operate_door();

#endif
