#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
	btn ->DDR = ddr;		// 포변일때는 -> 사용
	btn ->PIN = pin;
	btn ->pinNum = pinNum;
	btn ->prevstate = RELEASED;
	*btn ->DDR &= ~(1 << btn -> pinNum);
}

uint8_t Button_GetState(button_t *btn) //*btn 주소 유효범위 button_t
{
	uint8_t curState = *btn -> PIN & (1<<btn -> pinNum);// *btn->PIN // 현재 레지스터 값을 읽어오기
														//1 << btn->pinNum // 버튼이 연결된 핀 번호(pinNum)에 해당하는 비트만 1로 만든 값을 생성
														// & // 현재 PIN 레지스터 값을 AND 연산하여, 해당 핀(pinNum)의 상태만 읽습니다.
	if((curState == PUSHED) && (btn->prevstate == RELEASED))
	{
		_delay_ms(10);
		btn->prevstate = PUSHED;
		return ACT_PUSHED;
	}
	else if((curState != PUSHED) && (btn->prevstate == PUSHED))
	{
		_delay_ms(10);
		btn->prevstate = RELEASED;
		return ACT_RELEASED;
		
	}
	return ACT_NONE;
}
