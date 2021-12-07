/*
   gpio.h
  
    Created on: Dec 12, 2018
        Author: Dan Walkes

    Updated by Dave Sluiter Sept 7, 2020. moved #defines from .c to .h file.
    Updated by Dave Sluiter Dec 31, 2020. Minor edits with #defines.
    Updated by Tanmay Kothale Dec 04, 2021. Few edits for course project

 */

#ifndef _GPIO_H_
#define _GPIO_H_

/*  LIBRARY FILES   */
#include <stdbool.h>
#include <stdio.h>
#include "em_gpio.h"
#include <string.h>

/*  OTHER FILES TO BE INCLUDED   */
#include "src/log.h"
#include "timers.h"

/*  MACROS  */
#define	LED0_port  gpioPortF // change to correct ports and pins
#define LED0_pin   4
#define LED1_port  gpioPortF
#define LED1_pin   5
#define PB0_port   gpioPortF
#define PB0_pin    6

// SENSOR_ENABLE (Si7021) = DISP_ENABLE (LCD) on the main PCB
#define Si7021SENSOR_EN_port        gpioPortD // Sensor Enable for I2C Si7021
#define Si7021SENSOR_EN_pin         15       // Sensor Enable for I2C Si7021 at PD15

#define TRIG_PORT                   gpioPortD
#define TRIG_PIN                    12
#define ECHO_PORT                   gpioPortF
#define ECHO_PIN                    3

#define STEPPER_MOTOR_PORT_A        gpioPortA
#define STEPPER_PIN_1               2
#define STEPPER_PIN_2               3

#define STEPPER_MOTOR_PORT_D        gpioPortD
#define STEPPER_PIN_3               10
#define STEPPER_PIN_4               11

/*  FUNCTION PROTOTYPES */
/*-------------------------------------------------------------------------------
 * @brief:  initializes all the required gpio pins for their corresponding use
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioInit();

/*-------------------------------------------------------------------------------
 * @brief:  turns LED0 On
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioLed0SetOn();

/*-------------------------------------------------------------------------------
 * @brief:  turns LED0 Off
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioLed0SetOff();

/*-------------------------------------------------------------------------------
 * @brief:  turns LED1 On
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioLed1SetOn();

/*-------------------------------------------------------------------------------
 * @brief:  turns LED1 Off
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioLed1SetOff();

/*-------------------------------------------------------------------------------
 * @brief:  enables on board display
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioSetDisplayExtcomin(bool value);

// DOS
/*-------------------------------------------------------------------------------
 * @brief:  turns on the SI7021
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioSensorEnSetOn();

/*-------------------------------------------------------------------------------
 * @brief:  turns off the SI7021
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioSensorEnSetOff();

/*-------------------------------------------------------------------------------
 * @brief:  toggles LED0
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioToggleLed0();

/*-------------------------------------------------------------------------------
 * @brief:  toggles LED1
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void gpioToggleLed1();

//FOR ULTRASONIC SENSOR
/*-------------------------------------------------------------------------------
 * @brief:  drives trigger pin high
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void TRIG_PIN_HIGH();

/*-------------------------------------------------------------------------------
 * @brief:  drives trigger pin low
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void TRIG_PIN_LOW();

//FOR STEPPER MOTOR
/*-------------------------------------------------------------------------------
 * @brief:  completes one quarter step for stepper motor in clockwise direction
 *          after 4 steps, the stepper motor completes one full step. the stepper
 *          motor requires 2048 steps to complete one full rotation
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void clockwise_step1();
void clockwise_step2();
void clockwise_step3();
void clockwise_step4();

/*-------------------------------------------------------------------------------
 * @brief:  completes one quarter step for stepper motor in counter - clockwise
 *          direction after 4 steps, the stepper motor completes one full step.
 *          the stepper motor requires 2048 steps to complete one full rotation
 *
 * @parameters: none
 *
 * @returns: none
 ------------------------------------------------------------------------------*/
void counter_clockwise_step1();
void counter_clockwise_step2();
void counter_clockwise_step3();
void counter_clockwise_step4();

#endif /* SRC_GPIO_H_ */
