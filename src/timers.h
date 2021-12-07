/*
 * File Name: timers.h
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

#ifndef _TIMERS_H_
#define _TIMERS_H_

/*  LIBRARY FILES */
#include "em_letimer.h"

/*  OTHER FILES TO BE INCLUDED  */
#include "app.h"
#include "main.h"
#include "oscillators.h"

/*  MACROS  */
#define ACTUAL_CLK_FREQ     CLK_FREQ/PRESCALE
#define ACTUAL_CLK_PERIOD   1/ACTUAL_CLK_FREQ

// This is for LFXO @ 32768 Hz
// so you set your prescaler to 4, 32678/4 = 8192 Hz, which is ~122us per count (per tick)
// 1 second / 122 us = 4096
#define VALUE_TO_LOAD   (4096)
#define INTERRUPT_VALUE     (LETIMER_ON_MS*ACTUAL_CLK_FREQ)/1000          //COMP1 value

/*  FUNCTION PROTOTYPES */
/*------------------------------------------------------------------------------
 * @brief: initializes LETIMER0
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void initLETIMER(void);

/*------------------------------------------------------------------------------
 * @brief: Delay function without interrupts
 *
 * @parameters: DELAY: total delay required (in microseconds)
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void TimerWaitUs_polled(uint32_t DELAY);

/*------------------------------------------------------------------------------
 * @brief: Delay function with interrupts
 *
 * @parameters: DELAY: total delay required (in microseconds)
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void TimerWaitUs_irq(uint32_t DELAY);

#endif /*_TIMERS_H_*/

