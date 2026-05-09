HEX := $(wildcard *.hex)
BIN := $(wildcard *.bin)

.PHONY: all
all:
	avr-gcc -o pwm.bin -Os -mmcu=atmega328 pwm.c
	avr-objcopy -O ihex -R .eeprom -j .data -j .text pwm.bin pwm.hex

.PHONY: upload
upload:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -U flash:w:pwm.hex

.PHONY: clean
clean:
	$(RM) $(HEX) $(BIN)
