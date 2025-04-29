#ifndef BUTTON_H_
#define BUTTON_H_


#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#define BUTTON_DDR	DDRA
#define BUTTON_PIN	PINA

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




#endif /* BUTTON_H_ */