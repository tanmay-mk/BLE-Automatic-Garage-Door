#include <sl_i2cspm.h>
#include <em_i2c.h>

#include "src/log.h"

#define BASE_ADDRESS_TEMPERATURE (0x80U)


void InitI2C();
void turn_ON(GPIO_Port_TypeDef PORT, uint8_t PIN);
void turn_OFF(GPIO_Port_TypeDef PORT, uint8_t PIN);
I2C_TransferReturn_TypeDef I2CRead (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* readValue);
I2C_TransferReturn_TypeDef I2CWrite (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* writeValue);
uint16_t  read_temp_from_si7021();
