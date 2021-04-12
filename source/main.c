/*	Author: lab
 *  Partner(s) Name: Jaired Jawed
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #1
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0X00;

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
 
    unsigned char tmpD = 0x00;
    unsigned char tmpD2 = 0x00;
    unsigned char tmpD3 = 0x00;

    unsigned short total = 0x0000;
 
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;

	tmpD = 0x00;
	tmpD2 = 0x00;

	total = tmpA + tmpB + tmpC;

	if (total <= 0x008C) {
		tmpD = 0x00;
	}
	else {
		tmpD = 0x01;
	}


	if ((tmpA - tmpC > 0x50) || (tmpC - tmpA > 0x50)) {
		tmpD2 = 0x02;
	}

	tmpD3 = (total << 2) | tmpD2 | tmpD;
	PORTD = tmpD3;

    }
 
    return 1;
}

