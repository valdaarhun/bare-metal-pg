HEX := $(wildcard *.hex)
BIN := $(wildcard *.bin)

.PHONY: all
all:
	avr-gcc -Os -mmcu=atmega328p -o driver.bin driver.c
	avr-objcopy -O ihex -R .eeprom -j .text -j .data driver.bin driver.hex

upload:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -U flash:w:driver.hex

.PHONY: clean
clean:
	$(RM) $(HEX) $(BIN)
