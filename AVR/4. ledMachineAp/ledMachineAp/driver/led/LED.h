#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 

#define  LED_DDR	DDRD
#define	LED_PORT	PORTD


void Led_init();
void Led_blink(uint8_t data);





#endif /* LED_H_ */