
BOARD_TAG = uno
ARDUINO_LIBS =

flashlangsung :
	sudo avrdude -C/usr/share/arduino/hardware/tools/avrdude.conf -v -v -v -v -patmega328p -cusbasp -Pusb -Uflash:w:build-uno/ArduinoRFID.hex:i
include Arduino.mk
