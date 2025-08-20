#include "stm32l4xx_hal.h"
#include "adc.h"

ADC_HandleTypeDef hadc1 ;

uint32_t sensor_value ;

int main(void)
{
    HAL_Init();
    adc_pc0_interrupt_init();



    while (1)
    {

    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}


void HAL_ADC_ConvCpltCallback( ADC_HandleTypeDef  *hadc){

	sensor_value = pc0_adc_read();

}


