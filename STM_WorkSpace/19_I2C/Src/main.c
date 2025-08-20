#include "stm32l4xx_hal.h"
#include <string.h>

I2C_HandleTypeDef hi2c1;

uint8_t tx_buffer[10] = {0,1,2,3,4,5,6,7,8,9};

// --- I2C Master Init ---
void i2c_master_init(void) {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_I2C1_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;  // PB6=SCL, PB7=SDA
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    hi2c1.Instance = I2C1;
    hi2c1.Init.Timing = 0x00B1112E;   // ~100kHz (standard mode)
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}

int main(void) {
    HAL_Init();
    i2c_master_init();

    while(1) {
        // Send tx_buffer to ESP32 slave (0x55)
        HAL_I2C_Master_Transmit(&hi2c1, (0x55 << 1), tx_buffer, sizeof(tx_buffer), HAL_MAX_DELAY);

        // Small delay so ESP32 has time to process
        HAL_Delay(1000);
    }
}

void SysTick_Handler(void) {
    HAL_IncTick();
}
