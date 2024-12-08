#include "LedMachine.h"


uint8_t ledData;
uint8_t ledState = LED1;
button_t btnNext, btnPrev;			



void LedMachine_init()
{
	Led_init();
	ledData = 0x01;

	Button_init(&btnNext, &DDRA, &PINA, 0);
	Button_init(&btnPrev, &DDRA, &PINA, 1);
}

void LedMachine_execute(){
	switch(ledState)
	{
		case LED1 :
		Led_blink(LED1);
		if(Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = LED2;
		}
		else if(Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = LED4;
		}
		break;
		
		
		
		case LED2 :
		Led_blink(LED2);
		if(Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = LED3;
		}
		else if(Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = LED1;
		}
		break;
		
		
		
		case LED3 :
		Led_blink(LED3);
		if(Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = LED4;
		}
		else if(Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = LED2;
		}
		break;
		
		
		
		case LED4 :
		Led_blink(LED4);
		if(Button_GetState(&btnNext) == ACT_RELEASED)
		{
			ledState = LED1;
		}
		else if(Button_GetState(&btnPrev) == ACT_RELEASED)
		{
			ledState = LED3;
		}
		break;
	}
	_delay_ms(200);
}