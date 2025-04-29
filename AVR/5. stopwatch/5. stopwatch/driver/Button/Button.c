#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
	btn ->DDR = ddr;
	btn ->PIN = pin;
	btn ->pinNum = pinNum;
	btn ->prevstate = RELEASED;
	Gpio_initPin(btn->DDR,btn->pinNum,0);
}

uint8_t Button_GetState(button_t *btn)
{
	uint8_t curState = Gpio_readPin(btn->PIN,btn->pinNum); //pinNum 버튼 눌리면 0(PUSHED)
	
	if((curState == PUSHED) && (btn->prevstate == RELEASED)) // 안 눌 -> 눌
	{
		_delay_ms(10);
		btn->prevstate = PUSHED;
		return ACT_PUSHED;  //눌린 상태
	}
	else if((curState != PUSHED) && (btn->prevstate == PUSHED)) // 눌 -> 안 눌
	{
		_delay_ms(10);
		btn->prevstate = RELEASED;
		return ACT_RELEASED; // 눌렀다 뗀 상태
		
	}
	return ACT_NONE; // 아무 동작도 없는 상태
}

