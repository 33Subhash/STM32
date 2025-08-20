#include "stm32l4xx_hal.h"
#include "adc.h"

uint32_t sensor_value ;
ADC_HandleTypeDef hadc1 ;

int main(void)
{
    HAL_Init();
    adc_init_start();

    while (1)
    {
    	//1.Start ADC
    	HAL_ADC_Start(&hadc1);

    	//2.Poll for Conversion
    	HAL_ADC_PollForConversion(&hadc1, 1);

    	//3.Get conversion
    	sensor_value =pc0_adc_read();

    	HAL_Delay(10);

    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

