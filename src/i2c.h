#ifndef __MY_I2C_ROUTINE__
#define __MY_I2C_ROUTINE__

#include <sl_i2cspm.h>
#include <em_i2c.h>

#include "src/timers.h" // DOS
#include "src/gpio.h"   // DOS


/// DO NOT INLCUDE THIS .h file in another .h file!!!! #include "src/log.h"
/// #include from .c

#define BASE_ADDRESS_TEMPERATURE (0x80U)


void InitI2C();       //initializes I2C transfer


void I2C_Read ();  //reads the value during I2C transfer


void I2C_Write ();   //writes the value during I2C transfer


void  read_temp_from_si7021();      //measures the temperature of surroundings using the on chip temperature sensor

#endif
