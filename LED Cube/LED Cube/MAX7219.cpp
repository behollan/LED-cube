/*
 * MAX7219.cpp
 *
 * Created: 2/24/2015 2:32:04 PM
 * Author: Ben
 */ 

#include "MAX7219.h"

void MAX7219::setup(int numberChips)
{

}

void MAX7219::loop()
{

}

void MAX7219::putByte(byte data) {
	byte i = 8;
	byte mask;
	while(i > 0) {
		mask = 0x01 << (i - 1);      // get bitmask
		digitalWrite( clock, LOW);   // tick
		if (data & mask){            // choose bit
			digitalWrite(dataIn, HIGH);// send 1
			}else{
			digitalWrite(dataIn, LOW); // send 0
		}
		digitalWrite(clock, HIGH);   // tock
		--i;                         // move to lesser bit
	}
}
MAX7219 cube;

