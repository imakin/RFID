#include <SPI.h>
#include "MFRC522.h"
#include "Kontrol.h"

byte Key[4] = {0xe9,0x45,0x98,0x1a};

#define INPUTBOX 3
#define LED 4

#define RST_PIN 9
#define SS_PIN 10

ArduinoSlave Perangkat(Key,SS_PIN,RST_PIN);

void setup() {
	SPI.begin();
	Perangkat.PCD_Init();
	pinMode(LED,OUTPUT);
	digitalWrite(4, LOW);
	delay(3000);
	digitalWrite(4, HIGH);
	delay(3000);
	digitalWrite(4, LOW);
}

void loop () 
{
	Perangkat.requestKey();
	Perangkat.blink(LED);
}


