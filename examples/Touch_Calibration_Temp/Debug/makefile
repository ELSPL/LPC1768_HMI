################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source\ Files/subdir.mk
-include CM3\ Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Touch_Calibration_Temp.hex \

SECONDARY_LIST += \
Touch_Calibration_Temp.lst \

SECONDARY_SIZE += \
Touch_Calibration_Temp.siz \


# All Target
all: Touch_Calibration_Temp.elf secondary-outputs

# Tool invocations
Touch_Calibration_Temp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Windows GCC C Linker'
	arm-none-eabi-gcc -T"../ldscript_LPC1769.ld" -nostartfiles -Wl,-Map,Touch_Calibration_Temp.map -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "Touch_Calibration_Temp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Touch_Calibration_Temp.hex: Touch_Calibration_Temp.elf
	@echo 'Invoking: ARM Windows GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex Touch_Calibration_Temp.elf  "Touch_Calibration_Temp.hex"
	@echo 'Finished building: $@'
	@echo ' '

Touch_Calibration_Temp.lst: Touch_Calibration_Temp.elf
	@echo 'Invoking: ARM Windows GNU Create Listing'
	arm-none-eabi-objdump -h -S Touch_Calibration_Temp.elf > "Touch_Calibration_Temp.lst"
	@echo 'Finished building: $@'
	@echo ' '

Touch_Calibration_Temp.siz: Touch_Calibration_Temp.elf
	@echo 'Invoking: ARM Windows GNU Print Size'
	arm-none-eabi-size  --format=berkeley Touch_Calibration_Temp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) Touch_Calibration_Temp.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
