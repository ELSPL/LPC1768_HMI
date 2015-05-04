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
Eg19i.hex \

SECONDARY_LIST += \
Eg19i.lst \

SECONDARY_SIZE += \
Eg19i.siz \


# All Target
all: Eg19i.elf secondary-outputs

# Tool invocations
Eg19i.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Windows GCC C Linker'
	arm-none-eabi-gcc -T"../ldscript_LPC1769.ld" -nostartfiles -Wl,-Map,Eg19i.map -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "Eg19i.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Eg19i.hex: Eg19i.elf
	@echo 'Invoking: ARM Windows GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex Eg19i.elf  "Eg19i.hex"
	@echo 'Finished building: $@'
	@echo ' '

Eg19i.lst: Eg19i.elf
	@echo 'Invoking: ARM Windows GNU Create Listing'
	arm-none-eabi-objdump -h -S Eg19i.elf > "Eg19i.lst"
	@echo 'Finished building: $@'
	@echo ' '

Eg19i.siz: Eg19i.elf
	@echo 'Invoking: ARM Windows GNU Print Size'
	arm-none-eabi-size  --format=berkeley Eg19i.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) Eg19i.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
