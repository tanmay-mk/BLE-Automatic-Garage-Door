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
	GPIO_PinModeSet(gpioPortD, 15, gpioModePushPull, false);

  GPIO_DriveStrengthSet(TRIG_PORT, gpioDriveStrengthWeakAlternateWeak);
  GPIO_PinModeSet(TRIG_PORT, TRIG_PIN, gpioModePushPull, false);

  //GPIO_DriveStrengthSet(ECHO_PORT, gpioDriveStrengthWeakAlternateWeak);
  GPIO_PinModeSet(ECHO_PORT, ECHO_PIN, gpioModeInput, false);  //previously configured as o/p

  GPIO_ExtIntConfig(ECHO_PORT, ECHO_PIN, ECHO_PIN, true, true, true);

//  GPIO_PinModeSet(PB0_port,PB0_pin,gpioModePushPull, true);
//  GPIO_ExtIntConfig (PB0_port, PB0_pin, PB0_pin, true, true, true);

//  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
//  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
    NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
    NVIC_EnableIRQ(GPIO_ODD_IRQn);


  GPIO_DriveStrengthSet(STEPPER_MOTOR_PORT_A, gpioDriveStrengthStrongAlternateStrong);
  GPIO_PinModeSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1, gpioModePushPull, false);
  GPIO_PinModeSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2, gpioModePushPull, false);
//
  GPIO_DriveStrengthSet(STEPPER_MOTOR_PORT_D, gpioDriveStrengthStrongAlternateStrong);
  GPIO_PinModeSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3, gpioModePushPull, false);
  GPIO_PinModeSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4, gpioModePushPull, false);

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
  GPIO_PinOutSet(gpioPortD, 15);
}

// turn off sensor enable
void gpioSensorEnSetOff()
{
  GPIO_PinOutClear(gpioPortD, 15);
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

void gpioSetDisplayExtcomin(bool value)
{
  if(value)
  {
    GPIO_PinOutSet(gpioPortD, 13);
  }
  else if(!value)
  {
    GPIO_PinOutClear(gpioPortD, 13);
  }
}

void TRIG_PIN_HIGH()
{
  GPIO_PinOutSet(TRIG_PORT, TRIG_PIN);
}
void TRIG_PIN_LOW()
{
  GPIO_PinOutClear(TRIG_PORT, TRIG_PIN);
}

void clockwise_step1()
{
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void clockwise_step2()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void clockwise_step3()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void clockwise_step4()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void counter_clockwise_step1()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void counter_clockwise_step2()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}

void counter_clockwise_step3()
{
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}
void counter_clockwise_step4()
{
  GPIO_PinOutSet(STEPPER_MOTOR_PORT_A, STEPPER_PIN_1);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_A, STEPPER_PIN_2);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_3);
  GPIO_PinOutClear(STEPPER_MOTOR_PORT_D, STEPPER_PIN_4);
}
