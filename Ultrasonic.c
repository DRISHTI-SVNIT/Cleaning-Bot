#define F_CPU 8000000UL
#include "Ultrasonic.h"
#include <avr/interrupt.h>
#include <util/delay.h>


volatile uint8_t INT_PINS[3] = {4,2,3};
volatile uint8_t trigger_PINS[3] = {0,1,3};
volatile int timerCapture[3] = {0,0,0};
volatile uint8_t echoFlag[3] = {0,0,0};
void ultrasonic_init() {
	//setting trigger PINS as outputs
	triggerDDR = (1 << trigger_PINS[0]) | (1 << trigger_PINS[1]) | (1 << trigger_PINS[2]);
	//timer init
	TCCR1B = preScalar0;
	TCCR3B = preScalar1;
//	TCCR4B = preScalar2; 
	//interrupt init
	EICRB = falling_edge;
	EIMSK = (1 << INT_PINS[0]);	// | (1 << INT_PINS[1]) | (1 << INT_PINS[2]);
	sei();
}

void trigger(uint8_t n) {
		
		if(echoFlag[n])		return;
		triggerPort &=~(1<<trigger_PINS[n]);	//setting trig pin to low
		_delay_us(2);			//delay to let signal settle
		triggerPort |= (1<<trigger_PINS[n]); 	//setting trig pin to high to activate sensor
		_delay_us(15);			//pause in high state greater than 10us
		triggerPort &= ~(1<<trigger_PINS[n]);	//bring trig pin back to low
		echoFlag[n] = 1;
		//assigning timer counter value zero
		if (n == 0)			timerCounter0 = 0;
		else if(n == 1)		timerCounter1 = 0;
	//	else if(n == 2)		timerCounter2 = 0;
}

float getDistance(uint8_t n) {
			return timerCapture[n] * 2.1;
}

ISR(INT4_vect) {
		timerCapture[0] = timerCounter0;
		echoFlag[0] = 0;
}

/*
ISR(INT5_vect) {
	timerCapture[1] = timerCounter1;
	echoFlag[1] = 0;
}
/*
ISR(INT3_vect) {
	timerCapture[2] = timerCounter2;
}
*/