/*
 * File Name: irq.h
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */
#ifndef _IRQ_H_
#define _IRQ_H_

/*  LIBRARY FILES */
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include "em_core.h"

/*  OTHER FILES TO BE INCLUDED   */
#include "oscillators.h"
#include "timers.h"
#include "app.h"
#include "gpio.h"


/*  FUNCTION PROTOTYPES */
/*-------------------------------------------------------------------------------
 * @brief:  calculates the time passed since last reset
 *
 * @parameters: none
 *
 * @returns: total time passed (timestamp)
 ------------------------------------------------------------------------------*/
uint32_t letimerMilliseconds();

#endif /*_IRQ_H_*/

