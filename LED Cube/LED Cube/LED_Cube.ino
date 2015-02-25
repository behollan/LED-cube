/*
 * LED_Cube.ino
 *
 * Created: 2/24/2015 2:32:04 PM
 * Author: Ben Holland
 */ 
/*
 * Hookup guide for an 8x8 LED Cube
 * For EACH Max7219 chip, wire DIN (Pin 1) to the data line.
 *   --First chip to Arduino serial output line (See definition below)
 *   --Each successive chip (up to chip 8) wire DIN (Pin 1 on MAX chip) to DOUT (Pin 24) on the Previous Chip
 *  Additionally, For EACH Max 7219 chip: 
		--Wire CLOCK (Pin 13) to the clock line.
 *		--Place a 2.2k resistor between ISET and V+ (Pins 18 and 19)
 *		--Wire LOAD (Pin 13) to the Arduino LOAD pin (See definition below)
 * Pin 4 and 9 go to ground
 * 
 */
#include "MyClass.h"

#define SERIAL=2	//Define the SERIAL data output line on the Arduino
#define CLOCK=3		//Define the CLOCK line on the Arduino
#define LOAD=4      //Define the LOAD line on the Arduino

int numberChips = 8 //Set Number of MAX7219 Drivers

void setup()
{
	cube.putByte();
}

void loop()
{
	cube.loop();
}
