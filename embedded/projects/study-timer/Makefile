# MCU and clock frequency
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and flags
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
LDFLAGS = -mmcu=$(MCU)

# Source and target files
TARGET = timeroni
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEX = $(TARGET).hex

# Programmer settings for ATmega328P
PROGRAMMER = arduino
PORT = /dev/ttyACM0
BAUD = 115200

# Default target
all: $(TARGET).hex

# Compile all C files into object files
$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the final ELF file
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET).elf $(OBJ)

# Create the hex file from the ELF file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex

# Flash the hex file to the microcontroller
flash: $(TARGET).hex
	avrdude -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -U flash:w:$(TARGET).hex:i

# Clean up build files
clean:
	rm -f $(TARGET).elf $(TARGET).hex $(OBJ)

.PHONY: all flash clean
