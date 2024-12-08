#include "StandLight.h"

uint8_t ledData=0x00;
uint8_t ledState=ALL_OFF;
button_t btn_ModeChange, btn_AllOff;

void StandLight_init()
{
	LED_init();
	
	Button_init(&btn_ModeChange,&DDRA,&PINA,0);
	Button_init(&btn_AllOff,&DDRA,&PINA,1);
}

void StandLight_execute()
{
	switch(ledState)
	{
		case LED2:
		ledData= 0x03;
		LED_writeData(ledData);
		if(Button_GetState(&btn_ModeChange) == ACT_RELEASED)
		{
			ledState = LED4;
		}
		else if(Button_GetState(&btn_AllOff) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		break;
		
		
		
		case LED4:
		ledData= 0x0f;
		LED_writeData(ledData);
		if(Button_GetState(&btn_ModeChange) == ACT_RELEASED)
		{
			ledState = LED6;
		}
		else if(Button_GetState(&btn_AllOff) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		break;
		
		
		
		case LED6:
		ledData= 0x3f;
		LED_writeData(ledData);
		if(Button_GetState(&btn_ModeChange) == ACT_RELEASED)
		{
			ledState = LED8;
		}
		else if(Button_GetState(&btn_AllOff) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		break;
		
		
		
		case LED8:
		ledData= 0xff;
		LED_writeData(ledData);
		if(Button_GetState(&btn_ModeChange) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		else if(Button_GetState(&btn_AllOff) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		break;
		
		
		
		case ALL_OFF:
		ledData= 0x00;
		LED_writeData(ledData);
		if(Button_GetState(&btn_ModeChange) == ACT_RELEASED)
		{
			ledState = LED2;
		}
		else if(Button_GetState(&btn_AllOff) == ACT_RELEASED)
		{
			ledState = ALL_OFF;
		}
		break;	
	}
	
	
	
}