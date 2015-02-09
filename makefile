# GNU ARM Embedded Toolchain
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

# Build Parameters: MCU Flags, Definitions, Includes, 
#                   Compile Flags, Linker Script, Linker Flags
MCFLAGS=-mcpu=cortex-m3 -mthumb -O0 
DEFS=
INCLUDES=-I"C:\E_Workspace\LPC1768\travis\Header_Files" \
-I"C:\E_Workspace\LPC1768\travis\CM3_Core"
CFLAGS=-c $(MCFLAGS) $(DEFS) $(INCLUDES)
LDSCRIPT = ldscript_LPC1769.ld
LDFLAGS=-T $(LDSCRIPT) -nostartfiles $(MCFLAGS)

# Inputs: C Sources, Assembler Sources
SOURCES=Source_Files/main.c \
Source_Files/lpc17xx_uart.c \
Source_Files/lpc17xx_systick.c \
Source_Files/lpc17xx_pinsel.c \
Source_Files/lpc17xx_nvic.c \
Source_Files/lpc17xx_gpio.c \
Source_Files/lpc17xx_clkpwr.c \
Source_Files/lpc_system_init.c \
CM3_Core/core_cm3.c \
CM3_Core/system_LPC17xx.c \
startup_LPC17xx.c
ASMSOURCES=

# Outputs: Object Files, ELF Executable & 
#          Converted ELF Executable to Intel HEX format
OBJECTS=$(SOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.s=%.o)
EXECUTABLE=travis.elf
TARGET=travis.hex

# Build Rules
.PHONY: release
release: $(TARGET)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: CFLAGS+=-g3 -gdwarf-2 # Add debug flag
debug: LDFLAGS+=-g3 -gdwarf-2
debug: $(TARGET) 

$(TARGET): $(EXECUTABLE)
	$(CP) -O ihex $< $@
	@echo "Objcopy from ELF to IHEX complete!\n"

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@echo "Linking complete!\n"

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled "$<"!\n"

%.o: %.s
	$(CC) $(CFLAGS) $< -o $@
	@echo "Assambled "$<"!\n"

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TARGET)