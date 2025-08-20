################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/cs42l51/cs42l51.c 

OBJS += \
./Drivers/BSP/Components/cs42l51/cs42l51.o 

C_DEPS += \
./Drivers/BSP/Components/cs42l51/cs42l51.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/cs42l51/%.o Drivers/BSP/Components/cs42l51/%.su Drivers/BSP/Components/cs42l51/%.cyclo: ../Drivers/BSP/Components/cs42l51/%.c Drivers/BSP/Components/cs42l51/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DUSE_HAL_DRIVER -c -I../Inc -I"C:/Users/subha/OneDrive/Documents/STM32_Reference/STM_WorkSpace/01_GPIO/Drivers/CMSIS/Include" -I"C:/Users/subha/OneDrive/Documents/STM32_Reference/STM_WorkSpace/01_GPIO/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/subha/OneDrive/Documents/STM32_Reference/STM_WorkSpace/01_GPIO/Drivers/STM32L4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-cs42l51

clean-Drivers-2f-BSP-2f-Components-2f-cs42l51:
	-$(RM) ./Drivers/BSP/Components/cs42l51/cs42l51.cyclo ./Drivers/BSP/Components/cs42l51/cs42l51.d ./Drivers/BSP/Components/cs42l51/cs42l51.o ./Drivers/BSP/Components/cs42l51/cs42l51.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-cs42l51

