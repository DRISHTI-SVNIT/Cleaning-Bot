#ifndef Ultrasonic
#define Ultrasonic

#include <avr/io.h>

#define triggerPort		PORTF
#define triggerDDR		DDRF
#define timerCounter0	TCNT1
#define timerCounter1	TCNT3
//#define	timerCounter2	TCNT4
#define preScalar0      0x05			// prescalar of 1024
#define preScalar1		0x05			// prescalar of 1024 
#define preScalar2      0x05			// prescalar of 1024
#define falling_edge	0b00001010

void ultrasonic_init();
float getDistance(uint8_t n);
void trigger(uint8_t n);
#endif
