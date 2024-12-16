
#ifndef INCFILE1_H_
#define INCFILE1_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../../periph/GPIO/GPIO.h"    

enum {PUSHED, RELEASED};
enum {ACT_NONE, ACT_PUSHED, ACT_RELEASED};

typedef struct _button
{
	volatile uint8_t *DDR;		
	volatile uint8_t *PIN;				
	uint8_t pinNum;				
	uint8_t prevState;         
}button_t;


void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t Button_GetState(button_t *btn);

#endif