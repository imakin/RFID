//Makin 10Maret2015
#include <Arduino.h>
#include <SPI.h>
#include "MFRC522.h"
#ifndef KONTROLH
#define KONTROLH
#define _set(_REG,_BIT) _REG |= (1<<_BIT) //set bit
#define _clear(_REG,_BIT) _REG &= ~(1<<_BIT) //clear bit
#define _togle(_REG,_BIT) _REG ^= (1<<_BIT) //togle bit

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
	byte* lihatRFID();
	void requestKey();///Membaca RFID, loop hingga mendapatkan Key yang cocok
	
	void blink(uint8_t LedPin);
//~ private:
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

#endif
