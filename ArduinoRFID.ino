#include <SPI.h>
#include "MFRC522.h"
#include "Kontrol.h"

#define SLAVENUM 5 //Nomor arduino RFID

#if SLAVENUM==1
	#define KEY {0xe9,0x45,0x98,0x1a}
#elif SLAVENUM==2
	#define KEY {0x89,0x9B,0x97,0x1a}
#elif SLAVENUM==3
	#define KEY {0xd9,0xcc,0x97,0x1a}
#elif SLAVENUM==4
	#define KEY {0x99,0xcf,0x97,0x1a}
#else
	#define KEY {0xf9,0xcf,0x97,0x1a}
#endif

byte Key[4] = KEY;

#define INPUTBOX 3
#define LED 4

#define RST_PIN 9
#define SS_PIN 10

static ArduinoSlave Perangkat(Key,SS_PIN,RST_PIN);

void setup() {
	SPI.begin();
	Perangkat.PCD_Init();
	pinMode(LED,OUTPUT);
	pinMode(INPUTBOX,OUTPUT);
	digitalWrite(LED, HIGH);
	delay(1000);
	digitalWrite(LED, LOW);
	digitalWrite(INPUTBOX,LOW);
}

void loop () 
{
	Perangkat.requestKey();
	digitalWrite(INPUTBOX,HIGH);
	Perangkat.blink(LED);
	//~ uint8_t* r;
	//~ r = Perangkat.bacaRFID();
	//~ if (Perangkat.checkTwo(r,Perangkat.Key))
		//~ digitalWrite(LED,HIGH);
	//~ else
		//~ digitalWrite(LED,LOW);
		
	
	//~ byte* pembacaan = Perangkat.bacaRFID();
	//~ if (Perangkat.checkTwo(pembacaan,Perangkat.Key))
	//~ {
		//~ digitalWrite(LED,HIGH);
	//~ }
	//~ else
	//~ {
		//~ digitalWrite(LED,LOW);
	//~ }
	//~ return;
	//~ while (Perangkat.checkTwo(Perangkat.lihatRFID(),Perangkat.Key))
	//~ {
		//~ digitalWrite(LED,HIGH);
	//~ }
	//~ digitalWrite(LED,LOW);
}


