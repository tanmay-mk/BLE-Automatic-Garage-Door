#include <sl_i2cspm.h>
#include <em_i2c.h>

#include "src/timers.h" // DOS
#include "src/gpio.h"   // DOS


/// DO NOT INLCUDE THIS .h file in another .h file!!!! #include "src/log.h"
/// #include from .c

#define BASE_ADDRESS_TEMPERATURE (0x80U)


void InitI2C();       //initializes I2C transfer


//void turn_ON(GPIO_Port_TypeDef PORT, uint8_t PIN); //turns on the SI7021


//void turn_OFF(GPIO_Port_TypeDef PORT, uint8_t PIN); //turns off the SI7021


//I2C_TransferReturn_TypeDef I2CRead (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* readValue);  //reads the value during I2C transfer


//I2C_TransferReturn_TypeDef I2CWrite (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* writeValue);   //writes the value during I2C transfer


void  read_temp_from_si7021();      //measures the temperature of surroundings using the on chip temperature sensor
