#include "i2c.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

// make these global in prep for A4 which will use IRQs, so these variables should
// not be on the stack !!! they need to be global variables in the heap
I2C_TransferSeq_TypeDef       sequenceValue;
I2C_TransferReturn_TypeDef    returnValue;
uint8_t                       command;
uint8_t                       read_data[2];
uint32_t                      timestamp;


void InitI2C()
{
  I2CSPM_Init_TypeDef init;

  init.port            = I2C0;           // I2C Instance 0
  init.sclPort         = gpioPortC;         // SCL Port
  init.sclPin          = 10;             // SCL Pin
  init.sdaPort         = gpioPortC;         // SDA Port
  init.sdaPin          = 11;             // SDA Pin
  init.portLocationScl = 14;        // Location of SCL
  init.portLocationSda = 16;        // Location of SDA

  init.i2cRefFreq      = 0;            // Using reference clock currently configured
  init.i2cMaxFreq      = I2C_FREQ_STANDARD_MAX;  // Standard rate setting
  init.i2cClhr         = i2cClockHLRStandard;

  I2CSPM_Init(&init);
//DOS: do this in your state machine   NVIC_EnableIRQ(I2C0_IRQn);

}




void I2C_Write ()
{

  InitI2C(); // init I2C hardware

  // set up the transfer
  command                       = 0xF3;
  sequenceValue.addr            = 0x40 << 1;
  sequenceValue.flags           = I2C_FLAG_WRITE;
  sequenceValue.buf[0].data     = &command;   // this is where we're taking the write data from
  sequenceValue.buf[0].len      = sizeof(command);

  // execute the transfer using a polling routine
  returnValue = I2C_TransferInit(I2C0, &sequenceValue);

  if (returnValue < i2cTransferDone)
    {
      timestamp = loggerGetTimestamp();
      LOG_ERROR ("Timestamp: %d\nI2C write return error code=%d\n", timestamp, (int) returnValue);
    }

} // I2C_Write()



void I2C_Read ()
{

  InitI2C(); // init I2C hardware

  // set up the transfer
  sequenceValue.addr            = 0x40 << 1;
  sequenceValue.flags           = I2C_FLAG_READ;
  sequenceValue.buf[0].data     = &read_data[0];    // this is where the read data will be put
  sequenceValue.buf[0].len      = sizeof(read_data);

  // execute the transfer using a polling routine
  returnValue = I2C_TransferInit(I2C0, &sequenceValue);

  if (returnValue < i2cTransferDone)
    {
      timestamp = loggerGetTimestamp();
      LOG_ERROR ("Timestamp: %d\nI2C read return error code=%d\n", timestamp, (int) returnValue);
    }

} // I2C_Read()


void  read_temp_from_si7021()
{

  int32_t      temp_in_degC;

  //LOG_INFO("C");

  // read_data now contains the 2 bytes of the temp measurement
  // convert it to C.
  // note: MSB of measurement is in array elemt [0], so we have to swap them before conversion to C
  temp_in_degC = (int32_t) (((175.72 * (read_data[0]<<8 | read_data[1]))/65536)-46.85);


  // Log it
  timestamp = loggerGetTimestamp();
  LOG_INFO("Timestamp: %d MilliSeconds: Temp=%d C", timestamp, (int) temp_in_degC);

} // read_temp_from_si7021()


