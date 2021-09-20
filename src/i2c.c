#include "i2c.h"

void InitI2C()
{
  I2CSPM_Init_TypeDef init;
  init.port = I2C0;           // Use I2C Instance 0
  init.sclPort=gpioPortC;         // SCL Port
  init.sclPin=10;             // SCL Pin
  init.sdaPort=gpioPortC;         // SDA Port
  init.sdaPin=11;             // SDA Pin
  init.portLocationScl=14;        // Location of SCL
  init.portLocationSda=16;        // Location of SDA
  init.i2cRefFreq=0;            // Using reference clock currently configured
  init.i2cMaxFreq=I2C_FREQ_STANDARD_MAX;  // Standard rate setting
  init.i2cClhr=i2cClockHLRStandard;   // Set to use 4:4 low/high duty cycle


  I2CSPM_Init(&init);
  //NVIC_EnableIRQ(I2C0_IRQn);

  uint8_t i;
  for (i=0; i<9; i++)
    {
      GPIO_PinOutSet(gpioPortC, 10);
      GPIO_PinOutClear(gpioPortC, 10);
    }
}

void turn_ON(GPIO_Port_TypeDef PORT, uint8_t PIN)
{
  GPIO_PinOutSet (PORT, PIN);
}

void turn_OFF(GPIO_Port_TypeDef PORT, uint8_t PIN)
{
  GPIO_PinOutClear (PORT, PIN);
}



I2C_TransferReturn_TypeDef I2C_Read (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* readValue)
{
  I2C_TransferSeq_TypeDef sequenceValue;
  I2C_TransferReturn_TypeDef returnValue;

  sequenceValue.addr            = SLAVE_ADDRESS;
  sequenceValue.flags           = I2C_FLAG_READ;
  sequenceValue.buf[0].data     = readValue;
  sequenceValue.buf[0].len      = length;

  returnValue = I2C_TransferInit(I2C0, &sequenceValue);

  if (returnValue < i2cTransferNack)
    {
      return returnValue;
    }

  while (returnValue == i2cTransferInProgress)
    {
      returnValue = I2C_Transfer(I2C0);
    }
  return returnValue;

}

I2C_TransferReturn_TypeDef I2C_Write (uint8_t length, uint8_t SLAVE_ADDRESS, uint8_t* writeValue)
{
  I2C_TransferSeq_TypeDef sequenceValue;
  I2C_TransferReturn_TypeDef returnValue;

  sequenceValue.addr            = SLAVE_ADDRESS;
  sequenceValue.flags           = I2C_FLAG_WRITE;
  sequenceValue.buf[0].data     = writeValue;
  sequenceValue.buf[0].len      = length;

  returnValue = I2C_TransferInit(I2C0, &sequenceValue);

  if (returnValue < i2cTransferNack)
    {
      return returnValue;
    }

  while (returnValue == i2cTransferInProgress)
    {
      returnValue = I2C_Transfer(I2C0);
    }
  return returnValue;

}

uint16_t  read_temp_from_si7021()
{
  I2C_TransferReturn_TypeDef rawValue = 0;
  uint8_t writeAddress[1]={0xE3};
  uint8_t readAddress[2]={0};

  rawValue = I2C_Write (1, 0x80, &writeAddress[0]);

  #if ENABLE_LOGGING
  LOG_ERROR("I2C Write Value: %d\n\r", (int) rawValue);
  #endif

  I2C_Read (2, 0x80, &readAddress[0]);

  #if ENABLE_LOGGING
  LOG_ERROR("I2C Read Value: %d\n\r", (int) rawValue);
  #endif

  uint16_t value=5;
  value =  readAddress[1];
  return value;
  }
