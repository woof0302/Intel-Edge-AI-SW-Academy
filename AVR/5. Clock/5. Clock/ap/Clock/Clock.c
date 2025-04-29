#include "Clock.h"

uint16_t milisec; // 0 ~ 999
uint8_t sec, min ;
uint16_t hour, ClockData; // hour 100 ~ 2300

void Clock_init()
{
	milisec = 0;
	sec = 0;
	min = 3;
	hour = 7;
	
	FND_init();
	TIM0_OVF_init();
	TIM2_CTC_init();
}


void Clock_incMilisec()
{
	milisec = (milisec + 1) % 1000;
	if(milisec) return; // milisec 이 1000일때 제외하고 모두 return 1000일 때 sec 증가
	
	sec = (sec + 1) % 60;
	if(sec) return;

	min = (min + 1) % 60;
	if(min) return;
	
	hour = (hour + 1) % 24;
}



void Clock_execute()
{
	uint16_t ClockData;
	ClockData = (hour * 1000) + min * 10 + sec / 10;  // 시 : 분 : 분 : 초
	FND_dispNum(ClockData);
}

