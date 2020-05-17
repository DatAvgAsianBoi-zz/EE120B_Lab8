/*	Author: huryan18
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
const unsigned short light_max = 0b0111000000;

void ADC_init(){
      ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;  PORTA = 0xff;
    DDRB = 0xff;  PORTB = 0x00;
    DDRD = 0xff;  PORTD = 0x00;
    /* Insert your solution below */
    ADC_init();
    unsigned short adc_read = ADC;
    unsigned short temp = light_max/8;
    while (1) {
		adc_read = ADC;
            if(adc_read < temp)
                  PORTB = 0x00;
            else if(adc_read < temp * 2)
                  PORTB = 0x01;
            else if(adc_read < temp * 3)
                  PORTB = 0x02;
            else if(adc_read < temp * 4)
                  PORTB = 0x04;
            else if(adc_read < temp * 5)
                  PORTB = 0x08;
            else if(adc_read < temp * 6)
                  PORTB = 0x10;
            else if(adc_read < temp * 7)
                  PORTB = 0x20;
            else if(adc_read < temp * 8)
                  PORTB = 0x40;
            else
                  PORTB = 0x80;
    }
    return 1;
}
