MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

# Source files
SRC = src/main.c src/constants.c \
      lib/delay/delay.c \
      lib/io/io.c \
      lib/serial/serial.c \
      lib/timer/timer.c \
      lib/tone/tone.c

# Object files (derived from the source files)
OBJ = $(SRC:.c=.o)

# AVRDUDE Configuration
AVRDUDE_PORT = /dev/cu.usbserial-2110   # Update this for your system

# Default target to build the hex file
all: main.hex

# Compile each .c file into a .o object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files to create the main ELF executable
main.elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main.elf

# Convert the ELF executable to a HEX file
main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

# Upload the hex file to the microcontroller
upload: main.hex
	avrdude -V -F -c arduino -p $(MCU) -P $(AVRDUDE_PORT) -b 115200 -U flash:w:main.hex

# Clean all generated files
clean:
	rm -f $(OBJ) main.elf main.hex

