/*
  gpio.c
 
   Created on: Dec 12, 2018
       Author: Dan Walkes
   Updated by Dave Sluiter Dec 31, 2020. Minor edits with #defines.

   March 17
   Dave Sluiter: Use this file to define functions that set up or control GPIOs.

 */




#include "gpio.h"
#include "em_cmu.h"





// Set GPIO drive strengths and modes of operation
void gpioInit()
{

  // DOS leave these in

	//GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, false);

	//GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthStrongAlternateStrong);
	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, false);

	// DOS: SENSOR_ENABLE GPIO
	GPIO_PinModeSet(Si7021SENSOR_EN_port, Si7021SENSOR_EN_pin, gpioModePushPull, false);

} // gpioInit()


void gpioLed0SetOn()
{
	GPIO_PinOutSet(LED0_port,LED0_pin);
}


void gpioLed0SetOff()
{
	GPIO_PinOutClear(LED0_port,LED0_pin);
}


void gpioLed1SetOn()
{
	GPIO_PinOutSet(LED1_port,LED1_pin);
}


void gpioLed1SetOff()
{
	GPIO_PinOutClear(LED1_port,LED1_pin);
}



// Added for A3+
// turn on sensor, this SENSOR_ENABLE which is the same wire as
// DISP_ENABLE on the main PCB
void gpioSensorEnSetOn()
{
  GPIO_PinOutSet(Si7021SENSOR_EN_port, Si7021SENSOR_EN_pin);
}

// turn off sensor enable
void gpioSensorEnSetOff()
{
  GPIO_PinOutClear(Si7021SENSOR_EN_port, Si7021SENSOR_EN_pin);
  //LOG_ERROR("SENSOR_ENABLE is tied to DISP_ENABLE on the main PCB, not setting to off");
}


void gpioToggleLed0() {
  static bool   state=false;

  if (state == false) {
     GPIO_PinOutSet(LED0_port, LED0_pin);
     state = true;
  } else {
      GPIO_PinOutClear(LED0_port, LED0_pin);
      state = false;
  }

} // gpioToggleLed0()


void gpioToggleLed1() {
  static bool   state=false;

  if (state == false) {
     GPIO_PinOutSet(LED1_port, LED1_pin);
     state = true;
  } else {
      GPIO_PinOutClear(LED1_port, LED1_pin);
      state = false;
  }

} // gpioToggleLed1()


