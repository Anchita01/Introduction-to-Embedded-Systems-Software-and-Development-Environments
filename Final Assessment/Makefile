#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Dependency Directory
DEPDIR := .
# Dependency Flag
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.dep


# Output File
TARGET = c1m2

# Platform Dependent Variables

ifeq ($(PLATFORM),MSP432)
	
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
	CPPFLAGs = -DMSP432
	CPU = -mcpu=cortex-m4
	ARCH = -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS = --specs=nosys.specs
	#Compiler Flags
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-T$(LINKER_FILE) -Wl,-M=$(TARGET).map
	DumpFLAGs = -d
else
	
	CC = gcc
	SIZE = size
	OBJDUMP = objdump
	CPPFLAGs = -DHOST
	#Compiler Flags
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-M=$(TARGET).map
	DumpFLAGs = -d
endif


# Compiling the C files, by defining the implicit rule "using the pattern match operator (%)":
%.o : %.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) $(DEPFLAGS) -c -o $@ $^


# Preprocessing the C files, by defining the implicit rule "using the pattern match operator (%)":
%.i : %.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) -E -o $@ $^


# Assembling the C files, by defining the implicit rule "using the pattern match operator (%)":
%.asm : %.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) -S -o $@ $^



# Deassemble the project executable file "$(TARGET).out", and save the output in the file named "$(TARGET).asm"
$(TARGET).asm : Check-Exe-Existence
	@$(OBJDUMP) $(DumpFLAGs) $(TARGET).out $> $(TARGET).asm

Check-Exe-Existence :
	@test -s c1m2.out && echo "" || echo "Please call the Build Rule (make build PLATFORM=platform-name) to generate the target executable file (c1m2.out)"

# Define PHONY
.PHONY: compile-all clean build

# Compile all C files without linking
compile-all : $(OBJS)

# Remove all generated files
clean :
	@rm -f *.i
	@rm -f *.asm
	@rm -f *.o
	@rm -f *.out
	@rm -f *.map
	@rm -f *.dep

build : $(OBJS)
	@$(CC) $(ARCH) $(SPECS) $(LDFLAGS) -o  $(TARGET).out $^
	@$(SIZE) -Atd $(TARGET).out


# Architectures Specific Flags
#LINKER_FILE = 
#CPU = 
#ARCH = 
#SPECS = 

# Compiler Flags and Defines
#CC = 
#LD = 
#LDFLAGS = 
#CFLAGS = 
#CPPFLAGs =

