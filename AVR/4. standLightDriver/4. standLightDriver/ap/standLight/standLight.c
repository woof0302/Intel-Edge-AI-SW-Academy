#include "StandLight.h"

uint8_t standLightState; // enum{LED_OFF,MODE1,MODE2,MODE3,MODE4};

button_t btnMode,btnOff; //0,1



void StandLight_init()
{
	Led_init(&LED_DDR);
	
	Button_init(&btnMode, &BUTTON_DDR, &BUTTON_PIN, 0);
	Button_init(&btnOff, &BUTTON_DDR, &BUTTON_PIN, 1);
	
	standLightState=LED_OFF;
}

void StandLight_run()
{
	StandLight_eventCheck();
	
	StandLight_execute();
	
}

void StandLight_eventCheck() // 버튼이 눌리는 이벤트에 맞춰 상태를 바꿔주는 함수
{
	switch(standLightState)
	{
		case LED_OFF:
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			standLightState = MODE1;
		}
		else if(Button_GetState(&btnOff) == ACT_RELEASED)
		{
			standLightState = LED_OFF;
		}
		break;
		
		
		case MODE1:
		if(Button_GetState(&btnMode) == ACT_RELEASED)
		{
			standLightState = MODE2;
		}
		else if(Button_GetState(&btnOff) == ACT_RELEASED)
		{
			standLightState = LED_OFF;
		}
		break;
		
		
		case MODE2:
		if(Button_GetState(&btnMode)==ACT_RELEASED)
		{
			standLightState=MODE3;
		}
		else if(Button_GetState(&btnOff)==ACT_RELEASED)
		{
			standLightState=LED_OFF;
		}
		break;
		
		
		case MODE3:
		if(Button_GetState(&btnMode)==ACT_RELEASED)
		{
			standLightState=MODE4;
		}
		else if(Button_GetState(&btnOff)==ACT_RELEASED)
		{
			standLightState=LED_OFF;
		}
		break;
		
		
		case MODE4:
		if(Button_GetState(&btnMode)==ACT_RELEASED)
		{
			standLightState=LED_OFF;
		}
		else if(Button_GetState(&btnOff)==ACT_RELEASED)
		{
			standLightState=LED_OFF;
		}
		break;
		
		
	}
}
void StandLight_execute() // 상태에 맞는 함수 호출
{
	switch(standLightState)
	{
		case LED_OFF:
		StandLight_allOff();
		break;
		
		
		case MODE1:
		StandLight_MODE1();
		break;
		
		
		case MODE2:
		StandLight_MODE2();
		break;
		
		
		case MODE3:
		StandLight_MODE3();
		break;
		
		
		case MODE4:
		StandLight_MODE4();
		break;
		
		
	}
}


void StandLight_allOff()
{
	Led_allOff(&LED_PORT,0x00);
}


void StandLight_MODE1()
{
	Led_writeData(&LED_PORT,0b00000011);
}

void StandLight_MODE2()
{
	Led_writeData(&LED_PORT,0b00001111);
}

void StandLight_MODE3()
{
	Led_writeData(&LED_PORT,0b00111111);
	
}

void StandLight_MODE4()
{
	Led_writeData(&LED_PORT,0b11111111);
	
}
