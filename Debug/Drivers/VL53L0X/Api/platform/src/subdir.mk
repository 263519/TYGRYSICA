################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.c \
../Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.c 

OBJS += \
./Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.o \
./Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.o 

C_DEPS += \
./Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.d \
./Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.o: ../Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Drivers/VL53L0X/Api/platform/inc -I../Drivers/VL53L0X/Api/core/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/VL53L0X/Api/platform/src/vl53l0x_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.o: ../Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Drivers/VL53L0X/Api/platform/inc -I../Drivers/VL53L0X/Api/core/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/VL53L0X/Api/platform/src/vl53l0x_platform_log.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

