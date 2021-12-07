/*
 * File Name: oscillators.h
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */
#ifndef _OSCILLATORS_H_
#define _OSCILLATORS_H_

/*  LIBRARY FILES   */
#include "app.h"
#include "em_letimer.h"
#include "main.h"
#include <stdint.h>
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"


#if (ENERGY_MODE < 3)
   // This is for LFXO @ 32768 Hz
   #define PRESCALE        (4)
#else

   // This is for ULFRCO @ 1000 Hz, 1 ms per tick, 3000 ms = 3 secs
   #define PRESCALE        (1)
#endif

/*  FUNCTION PROTOTYPES   */
/*-------------------------------------------------------------------------------
 * @brief: initializes clock for peripherals (LETIMER) based on Energy mode
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void clkInitLETIMER();

#endif /*_OSCILLATORS_H_*/
