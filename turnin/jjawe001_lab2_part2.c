/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

   // create individual pin variables 
    unsigned char pinA0 = 0x00;
    unsigned char pinA1 = 0x00;
    unsigned char pinA2 = 0x00;
    unsigned char pinA3 = 0x00;

    // tmp variable for PORTC
    unsigned char cntavail = 0x00;

    while (1) {
	   pinA0 = PINA & 0x01;
	   pinA1 = PINA & 0x02;
	   pinA2 = PINA & 0x04;
	   pinA3 = PINA & 0x08;

	   cntavail = 0x00;

	   if (pinA0 == 0x01) {
		cntavail += 1;
	   }
	   if (pinA1 == 0x01) {
		cntavail += 1;
	   }
	   if (pinA2 == 0x01) {
		cntavail += 1;
	   }
	   if (pinA3 == 0x01) {
		cntavail += 1;
	   }

	   PORTC = cntavail;
    }
 
    return 1;
}

