#ifndef BUTTON_H_
#define BUTTON_H_

#include <util/delay.h>
#include <avr/io.h>
#include "../../periph/GPIO/GPIO.h"

#define BUTTON_DDR	DDRA
#define BUTTON_PIN	PINA

enum {PUSHED, RELEASED};
enum {ACT_NONE, ACT_PUSHED, ACT_RELEASED};

typedef struct _button
{
	volatile uint8_t *DDR;	//DDR포인터  // volatile c컴파일러가 변수 컴파일 단계에서 최적화해주는데 그걸 하지 않겠다.
	volatile uint8_t *PIN;	//PIN포인터
	uint8_t pinNum;			//pin 번호
	uint8_t prevstate;		//이전 상태
	
}button_t;


void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);

uint8_t Button_GetState(button_t *btn);



#endif /* BUTTON_H_ */