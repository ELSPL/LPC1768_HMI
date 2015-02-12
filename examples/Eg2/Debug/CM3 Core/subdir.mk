################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CM3\ Core/core_cm3.c \
../CM3\ Core/system_LPC17xx.c 

OBJS += \
./CM3\ Core/core_cm3.o \
./CM3\ Core/system_LPC17xx.o 

C_DEPS += \
./CM3\ Core/core_cm3.d \
./CM3\ Core/system_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
CM3\ Core/core_cm3.o: ../CM3\ Core/core_cm3.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\arm-none-eabi\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include-fixed" -I"E:\EDUTECH\New folder\TGLCD\Eg2\Header Files" -I"E:\EDUTECH\New folder\TGLCD\Eg2\CM3 Core" -Os -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"CM3 Core/core_cm3.d" -MT"CM3\ Core/core_cm3.d" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CM3\ Core/system_LPC17xx.o: ../CM3\ Core/system_LPC17xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\arm-none-eabi\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include" -I"C:\Program Files\GNU Tools ARM Embedded\4.7 2013q2\lib\gcc\arm-none-eabi\4.7.4\include-fixed" -I"E:\EDUTECH\New folder\TGLCD\Eg2\Header Files" -I"E:\EDUTECH\New folder\TGLCD\Eg2\CM3 Core" -Os -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"CM3 Core/system_LPC17xx.d" -MT"CM3\ Core/system_LPC17xx.d" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


