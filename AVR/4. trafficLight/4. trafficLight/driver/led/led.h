﻿#ifndef LED_H_
#define LED_H_


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 

#define  LED_DDR	DDRF
#define	LED_PORT	PORTF


void Led_init();

void traffic_Signal(uint8_t data);


#endif /* LED_H_ */