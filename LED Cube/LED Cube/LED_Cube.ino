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
#include "MAX7219.h"
//***Arduino Pin Configurations***

int SERIAL=2	//Define the SERIAL data output line on the Arduino
int CLOCK=3		//Define the CLOCK line on the Arduino
int LOAD=4      //Define the LOAD line on the Arduino

int numberChips = 8 //Set Number of MAX7219 Drivers

void setup()
{
	MAX.setup()
}

void loop()
{
	//if you use more than one MAX7219, it should look like this
 
  /*
  maxAll(1,1);                       //  + - - - - - - -
  maxAll(2,3);                       //  + + - - - - - -
  maxAll(3,7);                       //  + + + - - - - -
  maxAll(4,15);                      //  + + + + - - - -
  maxAll(5,31);                      //  + + + + + - - -
  maxAll(6,63);                      //  + + + + + + - -
  maxAll(7,127);                     //  + + + + + + + -
  maxAll(8,255);                     //  + + + + + + + +
  */
 
  //
 
  //if you use more then one max7219 the second one should look like this
 
 
  MAX.maxOne(2,1,1);                       //  + - - - - - - -
  MAX.maxOne(2,2,2);                       //  - + - - - - - -
  MAX.maxOne(2,3,4);                       //  - - + - - - - -
  MAX.maxOne(2,4,8);                       //  - - - + - - - -
  MAX.maxOne(2,5,16);                      //  - - - - + - - -
  MAX.maxOne(2,6,32);                      //  - - - - - + - -
  MAX.maxOne(2,7,64);                      //  - - - - - - + -
  MAX.maxOne(2,8,128);                     //  - - - - - - - +
 
 
  //
  delay(2000);
}
