#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms

#define BUTTON_DDR  DDRA
#define BUTTON_PIN PINA

enum {PUSHED, RELEASED};
enum {ACT_NONE, ACT_PUSHED, ACT_RELEASED};

typedef struct _button
{
	volatile uint8_t *DDR;
	volatile uint8_t *PIN;
	uint8_t pinNum;			
	uint8_t prevstate;		
	
}button_t;

uint8_t Button_GetState(button_t *btn);
void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);

#endif 