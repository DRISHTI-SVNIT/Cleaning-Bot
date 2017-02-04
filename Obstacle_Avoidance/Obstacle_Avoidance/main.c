/*
 * only_obs_avoid.c
 *
 * Created: 01-02-2017 22:36:43
 * Author : chirag
 */ 

 #define F_CPU 8000000UL
 #include <avr/io.h>
 #include "Ultrasonic.h"
 #include <avr/interrupt.h>
 #include "USART_128.h"

 volatile int a = 0;

 int main()
 {
	USART_Init(12,0);
	ultrasonic_init();
	sei();
		while(1)
		{	
			trigger(0);
			_delay_ms(100);
	     	USART_TransmitNumber(getDistance(0),0);
	        USART_Transmitchar(0x0d,0);	
		}
}
