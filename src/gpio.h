/*
   gpio.h
  
    Created on: Dec 12, 2018
        Author: Dan Walkes

    Updated by Dave Sluiter Sept 7, 2020. moved #defines from .c to .h file.
    Updated by Dave Sluiter Dec 31, 2020. Minor edits with #defines.

 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_
#include <stdbool.h>
#include "em_gpio.h"
#include <string.h>


// Student Edit: Define these, 0's are placeholder values.
// See the radio board user guide at https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf
// and GPIO documentation at https://siliconlabs.github.io/Gecko_SDK_Doc/efm32g/html/group__GPIO.html
// to determine the correct values for these.

#define	LED0_port  gpioPortF // change to correct ports and pins
#define LED0_pin   4
#define LED1_port  gpioPortF
#define LED1_pin   5


// DOS
// SENSOR_ENABLE (Si7021) = DISP_ENABLE (LCD) on the main PCB
#define Si7021SENSOR_EN_port    (gpioPortD) // Sensor Enable for I2C Si7021
#define Si7021SENSOR_EN_pin     (15)        // Sensor Enable for I2C Si7021 at PD15




// Function prototypes
void gpioInit();
void gpioLed0SetOn();
void gpioLed0SetOff();
void gpioLed1SetOn();
void gpioLed1SetOff();


// DOS
void gpioSensorEnSetOn();
void gpioSensorEnSetOff();
void gpioToggleLed0();
void gpioToggleLed1();

#endif /* SRC_GPIO_H_ */
