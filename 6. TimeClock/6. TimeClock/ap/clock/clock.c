#include "clock.h"

uint8_t sec, min;
uint16_t milisec, hour, clockMode, clockDisp;

button_t btnMode, btnModify, btnHour, btnMin;


void clock_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	

	FND_init();
	TIMER0_OVF_init();
	TIM_CTC_init();
	LCD_init();
	
	Button_init(&btnMode, &DDRA, &PINA, 0);
	Button_init(&btnModify, &DDRA, &PINA, 1);
	Button_init(&btnHour, &DDRA,&PINA, 2);
	Button_init(&btnMin, &DDRA, &PINA, 3);

	clockMode = NORMAL;
	clockDisp = HOUR_MIN;
	
}



void clock_incMilisec()  // 시간 증가
{
	milisec = (milisec+1) % 1000;
	if(milisec) return;
	
	sec = ( sec+1 ) % 60;
	if(sec) return;
	
	min = ( min +1) % 60;
	if(min) return;
	
	hour = (hour + 1) % 24;
	
	clockDisp = HOUR_MIN;
}

void clock_execute()  // 실행  (이벤트를 체크하고 시간을 디스플레이해라)
{
	clock_eventCheck();
	clock_run();
	
}


void clock_eventCheck()
{								// 버튼 푸시 이벤트에 맞춰
	switch(clockMode){			// 시계의 모드와  디스플레이 방식을 나타내는 변수들을 바꿔주는 함수
		
		case NORMAL :
		if(Button_GetState(& btnModify)== ACT_RELEASED)
		{
			clockMode = MODIFY;
			clockDisp = HOUR_MIN;
		}
		clockDispCheck();
		break;
		
		case MODIFY :
		if(Button_GetState(& btnModify)== ACT_RELEASED)
		{
			clockMode = NORMAL;
			clockDisp = HOUR_MIN;
			
			sec = 0;
			milisec = 0;
		}
		clockModifyCheck();
		
		break;
		
	}
	
	
	switch(clockDisp){
		
		case HOUR_MIN :
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			clockDisp = SEC_MIL;
		}
		break;
		
		
		case SEC_MIL :
		
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			clockDisp = HOUR_MIN;
		}
		break;
	}
	
}



void time_run()			// 디스플레이 함수
{
	clock_run();
	
	switch(clockDisp)
	{
		
		case HOUR_MIN :
		clock_dispHourMin();
		break;
		
		
		case SEC_MIL :
		clock_dispMilsec();
		break;
	}
	
}

void clock_run()		//LCD 출력 함수
{
	static uint8_t prevSec = 0xff;
	
	if(sec != prevSec)
	{
		prevSec = sec;
		char buff[20];
		
		sprintf(buff ,"Time Clock");
		LCD_writeStringXY(0,3,buff);
		
		sprintf(buff,"%02d:%02d:%02d" ,hour ,min,sec );
		LCD_writeStringXY(1,4,buff);			
	}
	
}



void clockDispCheck()   // 0번 버튼 이벤트 체크
{
	switch(clockDisp){
		
		case HOUR_MIN :
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			clockDisp = SEC_MIL;
		}
		break;
		
		
		case SEC_MIL :
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			clockDisp = HOUR_MIN;
		}
		break;
	}
	
}

void clockModifyCheck()		// 1번 버튼 이벤트 체크
{
	if(Button_GetState(&btnHour) == ACT_RELEASED){
		
		incHour();
	}
	else if(Button_GetState(&btnMin) == ACT_RELEASED)
	{
		incMin();
	}
	
}

void clock_dispHourMin()		// 시:분 디스플레이 함수
{
	uint16_t timeClockData;
	timeClockData = (hour*100) + min;
	FND_setfndData(timeClockData);
}


void clock_dispMilsec()			// 초:밀리초 디스플레이 함수
{
	uint16_t timeClockData;
	timeClockData = (sec*100) + milisec/10;
	FND_setfndData(timeClockData);
}


void incHour()
{
	hour = (hour + 1) % 24;
}


void incMin()
{
	if(min >= 60) min = 0;
	min++;
}