SRC := uart.c
HEX := $(SRC:%.c=%.hex)
BIN := $(SRC:%.c=%.bin)

.PHONY: all
all:
	avr-gcc -o $(BIN) -Os -mmcu=atmega328 $(SRC)
	avr-objcopy -O ihex -R .eeprom -j .data -j .text $(BIN) $(HEX)

.PHONY: upload
upload: all
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -U flash:w:$(HEX)

.PHONY: clean
clean:
	$(RM) $(HEX) $(BIN)
