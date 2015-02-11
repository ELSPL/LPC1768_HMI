################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source_Files/crc32.c \
../Source_Files/lpc17xx_can.c \
../Source_Files/lpc17xx_clkpwr.c \
../Source_Files/lpc17xx_emac.c \
../Source_Files/lpc17xx_gpio.c \
../Source_Files/lpc17xx_i2c.c \
../Source_Files/lpc17xx_mcpwm.c \
../Source_Files/lpc17xx_nvic.c \
../Source_Files/lpc17xx_pinsel.c \
../Source_Files/lpc17xx_ssp.c \
../Source_Files/lpc17xx_systick.c \
../Source_Files/lpc17xx_uart.c \
../Source_Files/lpc17xx_wdt.c \
../Source_Files/lpc_global.c \
../Source_Files/lpc_i2c_tsc2004.c \
../Source_Files/lpc_ssp_glcd.c \
../Source_Files/lpc_system_init.c \
../Source_Files/main.c 

OBJS += \
./Source_Files/crc32.o \
./Source_Files/lpc17xx_can.o \
./Source_Files/lpc17xx_clkpwr.o \
./Source_Files/lpc17xx_emac.o \
./Source_Files/lpc17xx_gpio.o \
./Source_Files/lpc17xx_i2c.o \
./Source_Files/lpc17xx_mcpwm.o \
./Source_Files/lpc17xx_nvic.o \
./Source_Files/lpc17xx_pinsel.o \
./Source_Files/lpc17xx_ssp.o \
./Source_Files/lpc17xx_systick.o \
./Source_Files/lpc17xx_uart.o \
./Source_Files/lpc17xx_wdt.o \
./Source_Files/lpc_global.o \
./Source_Files/lpc_i2c_tsc2004.o \
./Source_Files/lpc_ssp_glcd.o \
./Source_Files/lpc_system_init.o \
./Source_Files/main.o 

C_DEPS += \
./Source_Files/crc32.d \
./Source_Files/lpc17xx_can.d \
./Source_Files/lpc17xx_clkpwr.d \
./Source_Files/lpc17xx_emac.d \
./Source_Files/lpc17xx_gpio.d \
./Source_Files/lpc17xx_i2c.d \
./Source_Files/lpc17xx_mcpwm.d \
./Source_Files/lpc17xx_nvic.d \
./Source_Files/lpc17xx_pinsel.d \
./Source_Files/lpc17xx_ssp.d \
./Source_Files/lpc17xx_systick.d \
./Source_Files/lpc17xx_uart.d \
./Source_Files/lpc17xx_wdt.d \
./Source_Files/lpc_global.d \
./Source_Files/lpc_i2c_tsc2004.d \
./Source_Files/lpc_ssp_glcd.d \
./Source_Files/lpc_system_init.d \
./Source_Files/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source_Files/%.o: ../Source_Files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Windows GCC C Compiler'
	arm-none-eabi-gcc -I../Header_Files -I../CM3_Core -Os -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


