/*
 * TIM.c
 *
 * Created: 2024-12-03 오후 3:31:56
 *  Author: iot
 */ 

#include "TIM.h"

void TIMER0_OVF_init()
{   
	
	//1ms interrupt Enable
	TCCR0 |= (1<<CS02) | (0<<CS01) | (1<<CS00);
	// TIMSK    Timer Overflow Interrpt Enable  0번째 비트를 켜줌
	TIMSK  |= (1<< TOIE0);  //인터럽트 발생전  설정만해줌
	TCNT0 = 131;
	
}

void TIM_CTC_init(){
	
	TCCR2 |= (0<<CS22) | (1<<CS21)| (1<<CS20) ;        //    1/64  PreScaler set
	TCCR2 |= (1<<WGM21)  | (0<<WGM20);    //ctc 모드설정
	TIMSK |= (1<<OCIE2);     
	OCR2  = 250 -1 ;    // 0부터 시작
 	     
	
}