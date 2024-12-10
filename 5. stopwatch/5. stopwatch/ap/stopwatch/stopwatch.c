#include "stopwatch.h"

uint16_t milisec; // 0 ~ 999
uint8_t sec, min, hour;
button_t btnRunStop, btnReset;

uint8_t stopWatch_mode =STOP; // 스탑워치 모드

uint16_t stopWatchData; //출력할 데이터 가공해서 함수로 전달


void StopWatch_init()
{
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	
	FND_init();
	Button_init(&btnRunStop, &DDRA, &PINA, RunStop);
	Button_init(&btnReset, &DDRA, &PINA, Reset);
	TIM0_OVF_init();
	TIM2_CTC_init();
}


void StopWatch_incMilisec() // 시간 증가시키는 함수
{
	milisec = (milisec + 1) % 1000;
	if(milisec) return; // milisec 이 1000일때 제외하고 모두 return 1000일 때 sec 증가
	
	sec = (sec + 1) % 60;
	if(sec) return;
	
	min = (min + 1) % 60;
	if(min) return;
	
	hour = (hour + 1) % 24;
	
	//// if 문의 중첩을 되도록 안쓰는게 좋다.
	//
	//if(milisec >= 1000)
	//{
	//milisec = 0;
	//sec++;
	//if(sec >= 60)
	//{
	//sec = 0;
	//min++;
	//if(min >= 60)
	//{
	//min = 0;
	//hour++;
	//if(hour >= 24)
	//hour = 0;
	//}
	//}
	//}
	//
}


void StopWatch_run()  // 스탑워치 실행
{
	
	StopWatch_checkMode(stopWatch_mode);

	StopWatch_execute();
	
}


void StopWatch_checkMode()  // 모드 체크해서 모드 반환
{
	switch(stopWatch_mode)
	{
		case RUN :
		if(Button_GetState(&btnRunStop)==ACT_RELEASED)
		{
			stopWatch_mode = STOP;
		}
		break;
		
		
		case STOP :
		if(Button_GetState(&btnRunStop)==ACT_RELEASED)
		{
			stopWatch_mode = RUN;
		}
		if(Button_GetState(&btnReset)==ACT_RELEASED)
		{
			stopWatch_mode = RESET;
		}
		break;
		
		case RESET :
		if(Button_GetState(&btnRunStop)==ACT_RELEASED)
		{
			stopWatch_mode = STOP;
		}
		
	}
	
}


void StopWatch_execute()
{
	switch(stopWatch_mode)
	{
		case RUN :
		
		{
			// FND 첫째    둘째, 셋째			넷째 자리
			stopWatchData = (min%10*1000) + (sec*10) + (milisec/100); 
			
			FND_setfndData(stopWatchData); // 함수로 값 전달(동기화)
			
			StopWatch_incMilisec();
		}
		break;
		
		
		case STOP :
		
		{						
			stopWatchData = (min%10*1000) + (sec*10) + (milisec/100); 
			
			FND_setfndData(stopWatchData); 
		}
		break;
		
		case RESET :
		
		{
			stopWatchData = 0;
		}
		break;
		
	}
}