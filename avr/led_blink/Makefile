HEX := $(wildcard *.hex)
BIN := $(wildcard *.bin)

.PHONY: all
all:
	avr-gcc -Os -mmcu=atmega328p -o blink.bin blink.c
	avr-objcopy -O ihex -j .text -j .data -R .eeprom blink.bin blink.hex

.PHONY: upload
upload:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -U flash:w:blink.hex

.PHONY: clean
clean:
	$(RM) $(HEX) $(BIN)
