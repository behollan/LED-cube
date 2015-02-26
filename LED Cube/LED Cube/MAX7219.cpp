/*
 * MAX7219.cpp
 *
 * Created: 2/24/2015 2:32:04 PM
 * Author: Ben
 */ 

#include "MAX7219.h"

void MAX7219::setup()
{
	pinMode(SERIAL, OUTPUT);
	pinMode(CLOCK,  OUTPUT);
	pinMode(LOAD,   OUTPUT);
	digitalWrite(13, HIGH);  //Begin Serial
	maxAll(max7219_reg_scanLimit, 0x07);
	maxAll(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
	maxAll(max7219_reg_shutdown, 0x01);    // not in shutdown mode
	maxAll(max7219_reg_displayTest, 0x00); // no display test
	for (e=1; e<=8; e++) {    // empty registers, turn all LEDs off
		maxAll(e,0);
	}
	maxAll(max7219_reg_intensity, 0x0f & 0x0f);    // the first 0x0f is the value you can set
	// range: 0x00 to 0x0f
}

void MAX7219::loop()
{

}

void MAX7219::putByte(byte data) {
	byte i = 8;
	byte mask;
	while(i > 0) {
		mask = 0x01 << (i - 1);      // get bitmask
		digitalWrite( CLOCK, LOW);   // tick
		if (data & mask){            // choose bit
			digitalWrite(SERIAL, HIGH);// send 1
			}else{
			digitalWrite(SERIAL, LOW); // send 0
		}
		digitalWrite(CLOCK, HIGH);   // tock
		--i;                         // move to lesser bit
	}
}
void maxAll (byte reg, byte col) {    // initialize  all  MAX7219's in the system
	int c = 0;
	digitalWrite(LOAD, LOW);  // begin
	for ( c =1; c<= numberChips; c++) {
		putByte(reg);  // specify register
		putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
	}
	digitalWrite(LOAD, LOW);
	digitalWrite(LOAD,HIGH);
}
void maxSingle( byte reg, byte col) {
	//maxSingle is the "easy"  function to use for a     //single max7219
	
	digitalWrite(LOAD, LOW);       // begin
	putByte(reg);                  // specify register
	putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
	digitalWrite(LOAD, LOW);       // and load da shit
	digitalWrite(LOAD,HIGH);
}
void maxOne(byte maxNr, byte reg, byte col) {
	//maxOne is for adressing different MAX7219's,
	//whilele having a couple of them cascaded
	
	int c = 0;
	digitalWrite(LOAD, LOW);  // begin
	
	for ( c = numberChips; c > maxNr; c--) {
		putByte(0);    // means no operation
		putByte(0);    // means no operation
	}
	
	putByte(reg);  // specify register
	putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
	
	for ( c =maxNr-1; c >= 1; c--) {
		putByte(0);    // means no operation
		putByte(0);    // means no operation
	}
	
	digitalWrite(LOAD, LOW); // and load da shit
	digitalWrite(LOAD,HIGH);
}
MAX7219 MAX;

