#include "stm32l4xx_hal.h"

#define LED_PIN		GPIO_PIN_5
#define LED_PORT	GPIOA

void led_init(void);

int main(void)
{
    HAL_Init();


    while (1)
    {

    }
}



void SysTick_Handler(void)
{
    HAL_IncTick();
}

