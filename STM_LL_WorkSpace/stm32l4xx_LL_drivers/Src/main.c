

#include <stdint.h>
#include "stm32l4xx.h"
#include"stm32l4xx_gpio_driver.h"
/// define pins

#define  TRIG   GPIO_PIN_NO_3
#define  ECHO   GPIO_PIN_NO_2
#define  SOUND_SPEED   0.034f   // in cm/us

long duration;
float distanceCm;

// crude delay
void delay(void){
	for (uint32_t i = 0 ; i< 500000 ; i++ );
}

// microsecond delay (approximate)
void delayMicroseconds(uint32_t us) {
    for(uint32_t i=0; i<us*16; i++);  // tune for your clock (16MHz example)
}

int main(void)
{
	// TRIG pin (output)
	GPIO_Handle_t GpioTrig;
	GpioTrig.pGPIOx = GPIOC;
	GpioTrig.GPIO_PinConfig.GPIO_PinNumber = TRIG;
	GpioTrig.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioTrig.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioTrig.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioTrig.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioTrig);

	// ECHO pin (input)
	GPIO_Handle_t GpioEcho;
	GpioEcho.pGPIOx = GPIOC;
	GpioEcho.GPIO_PinConfig.GPIO_PinNumber = ECHO;
	GpioEcho.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioEcho.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioEcho.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioEcho);

	// User LED for indication (PA5)
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		// Clear TRIG
		GPIO_WriteToOutputPin(GPIOC, TRIG, RESET);
		delayMicroseconds(2);

		// Set TRIG high for 10 us
		GPIO_WriteToOutputPin(GPIOC, TRIG, SET);
		delayMicroseconds(10);
		GPIO_WriteToOutputPin(GPIOC, TRIG, RESET);

		// wait for ECHO to go HIGH
		while(!GPIO_ReadFromInputPin(GPIOC, ECHO));
		uint32_t start = 0;
		while(GPIO_ReadFromInputPin(GPIOC, ECHO)) {
			start++;
		}

		// duration in microseconds (approx)
		duration = start;

		// calculate distance
		distanceCm = (duration * SOUND_SPEED) / 2.0f;

		// Blink LED if object < 10 cm
		if(distanceCm < 10) {
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, SET);
		} else {
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, RESET);
		}

		delay();
	}
}
