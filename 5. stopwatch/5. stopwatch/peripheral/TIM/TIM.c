#include "TIM.h"


void TIM0_OVF_init() // 1ms 마다 interrupt 
{
	
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00));

	TIMSK |= ((1<<TOIE0));
	TCNT0=131;
}

void TIM2_CTC_init()
{
	// 1/64 PreScaler set
	TCCR2 |= (0<<CS22)|(1<<CS21)|(1<<CS20); // p.157 table68
	
	// CTC모드 설정
	TCCR2 |= (1<<WGM21)|(0<<WGM20); // p.156 table64
	
	//마스크 설정
	TIMSK |= (1<<OCIE2);
	
	//
	OCR2 = 250-1 ;
	
}