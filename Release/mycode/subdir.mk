################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mycode/Bar.c 

C_DEPS += \
./mycode/Bar.d 

OBJS += \
./mycode/Bar.o 


# Each subdirectory must supply rules for building sources it contributes
mycode/Bar.o: ../mycode/Bar.c mycode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"G:/STM32/BAR/mycode" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"mycode/Bar.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

