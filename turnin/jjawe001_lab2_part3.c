/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #3
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

    // input for PINA
    unsigned char tmpA = 0x00;

    while (1) {
    	tmpA = PINA;

	// all spots are available
	if (tmpA == 0x00) {
		PORTC = 0x04;
	}
	// one spot is taken
	else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08) {
		PORTC = 0x03;
	}
	// two spots are taken
	else if (tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 || tmpA == 0x0A || tmpA == 0x0C) {
		PORTC = 0x02;
	}
	// three spots are taken
	else if (tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E) {
		PORTC = 0x01;
	}
	// all spots are taken
	else if (tmpA == 0x0F) {
		// set port C7 to 1 and everything else to 0 if no spots 
		PORTC = 0x80;
	}
    }
 
    return 1;
}

