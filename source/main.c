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
    DDRB = 0xFF; PORTB = 0x00;

    unsigned char pinA0 = 0x00;
    unsigned char pinA1 = 0x00;

    while (1) {
	// read the individual pins of A
	pinA0 = PINA & 0x01;
	pinA1 = PINA & 0x02;

    	// if PA0 is 1 and PA1 is 0
	// set PB0 to 1
	// make A the input and B the output
	if (pinA0 == 0x01 && pinA1 == 0x00) {
		PORTB = 0x01;
	}		
	else {
		PORTB = 0x00;
	}
    }
 
    return 1;
}

