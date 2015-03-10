//Makin 10Maret2015
#include <Arduino.h>
#include <SPI.h>
#include "MFRC522.h"
#define uint8_t unsigned char
class ArduinoSlave: public MFRC522{
public:
	
	ArduinoSlave(byte* InitKey,uint8_t selectpin,uint8_t resetpin)
	:MFRC522(selectpin,resetpin)
	{
		Key = InitKey;
	}
	
	byte* Key;
	
	byte* thisID();
	
	byte* bacaRFID();
	void requestKey();///Membaca RFID, loop hingga mendapatkan Key yang cocok
	
	void blink(uint8_t LedPin);
private:
	byte Pembacaan[10];
	bool checkTwo ( byte a[], byte b[] )
	{
		bool match = true;
		if ( a[0] != NULL ) 
			match = true; 
		for ( int k = 0; k < 4; k++ )
		{ 
			if ( a[k] != b[k] )
				match = false;
		}
		return match;
	}
};

