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

    unsigned char tmpD = 0x00;
    unsigned char tmpD2 = 0x00;
    unsigned char tmpD3 = 0x00;

    unsigned char total = 0x00;
 
    while (1) {
	tmpD = 0x00;

	// add up all weights
	total = PINA + PINB + PINC;

	// total weight is less than 140kg
	if (total <= 0x8C) {
		tmpD = 0x00;
	}
	else if (total > 0x8C) {
		tmpD = 0x01;
	}	

	if ((PINA - PINC) > 0x50 || (PINC - PINA) > 0x50) {
		tmpD2 = 0x02;
	}	
	
	tmpD3 = (total & 0xFC) | tmpD | tmpD2;
	PORTD = tmpD3;	
    }
 
    return 1;
}

