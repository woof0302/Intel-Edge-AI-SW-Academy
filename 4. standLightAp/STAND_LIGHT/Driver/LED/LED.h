#ifndef LED_H_
#define LED_H_

#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms

#define LED_DDR  DDRD
#define LED_PORT PORTD

void LED_init();

void LED_writeData(uint8_t data);

void LED_allOff();



#endif /* LED_H_ */