################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CM3_Core/core_cm3.c \
../CM3_Core/system_LPC17xx.c 

OBJS += \
./CM3_Core/core_cm3.o \
./CM3_Core/system_LPC17xx.o 

C_DEPS += \
./CM3_Core/core_cm3.d \
./CM3_Core/system_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
CM3_Core/%.o: ../CM3_Core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler'
	arm-none-eabi-gcc -I../Header_Files -I../CM3_Core -Os -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


