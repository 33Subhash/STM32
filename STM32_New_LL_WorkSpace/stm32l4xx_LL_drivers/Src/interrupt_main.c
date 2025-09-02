#include <stdint.h>
#include "stm32l4xx.h"
#include"stm32l4xx_gpio_driver.h"


int main(){

	RCC->APB2ENR |= (1 << 0);  // Enable SYSCFG clock

	GPIO_Handle_t GPIOled;
	GPIO_Handle_t GPIOpushBtn ;

	///Pin configuration for led
	GPIOled.pGPIOx = GPIOA ;
	GPIOled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5 ;
	GPIOled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT ;
	GPIOled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP	 ;
	GPIOled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST ;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GPIOled);

	//Configuration of push button
	GPIOpushBtn.pGPIOx = GPIOC ;
	GPIOpushBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13 ;
	GPIOpushBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT ;
	GPIOpushBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST ;
	GPIOpushBtn.GPIO_PinConfig.GPIO_PinPuPdControl =GPIO_NO_PUPD ;

	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&GPIOpushBtn);

	GPIO_IRQConfig(IRQ_NO_EXTI15_10, 10 , ENABLE);

	while(1);
}

void EXTI15_10_IRQHandler(void){
	GPIO_IRQHandling(GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}
