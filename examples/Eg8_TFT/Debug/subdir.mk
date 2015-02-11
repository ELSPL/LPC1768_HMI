################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup_LPC17xx.c 

OBJS += \
./startup_LPC17xx.o 

C_DEPS += \
./startup_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\arm-none-eabi\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include-fixed" -I"C:\E_Workspace\LPC1768\Eg8_TFT\Header Files" -I"C:\E_Workspace\LPC1768\Eg8_TFT\CM3 Core" -Os -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


