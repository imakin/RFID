//10Maret2015
#include <Arduino.h>
#include <SPI.h>
#include "Kontrol.h"
#include "MFRC522.h"

byte* ArduinoSlave::thisID()
{
	return ArduinoSlave::Key;
}

byte* ArduinoSlave::bacaRFID()
{
	bool sukses=false;
	
	while (not sukses)
	{
		sukses = true;
		if ( ! ArduinoSlave::PICC_IsNewCardPresent()) 
		{ 
			sukses = false;
		}
		if ( ! ArduinoSlave::PICC_ReadCardSerial())
		{
			sukses = false;
		}
	}
	
	for (byte i = 0; i < ArduinoSlave::uid.size; i++) {	
		Pembacaan[i] = ArduinoSlave::uid.uidByte[i];
	}

	ArduinoSlave::PICC_HaltA(); //halt state?
	return Pembacaan;
}

void ArduinoSlave::requestKey()
{
	/** loop hingga dapat key yang cocok **/
	byte* pembacaan = ArduinoSlave::bacaRFID();
	while (not ArduinoSlave::checkTwo(pembacaan,ArduinoSlave::Key))
	{
		pembacaan = ArduinoSlave::bacaRFID();
	}
	return;
}

void ArduinoSlave::blink(uint8_t LedPin)
{
	pinMode(LedPin,OUTPUT);
	digitalWrite(LedPin, LOW);
	delay(500);
	digitalWrite(LedPin, HIGH);
	delay(500);
	digitalWrite(LedPin, LOW);
	delay(500);
	digitalWrite(LedPin, HIGH);
	delay(500);
	digitalWrite(LedPin, LOW);
	delay(500);
	digitalWrite(LedPin, HIGH);
	delay(500);
	digitalWrite(LedPin, LOW);
	delay(1000);
	digitalWrite(LedPin, HIGH);
	delay(500);
	digitalWrite(LedPin, LOW);
}

