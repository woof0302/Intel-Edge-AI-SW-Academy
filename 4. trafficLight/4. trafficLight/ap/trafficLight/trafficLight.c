#include "trafficLight.h"

uint8_t ledData; 
uint8_t trafficModeState = AUTO;
uint8_t trafficState = RED_GREEN;
button_t btnAUTO,btnMANUAL,btnSWITCHING;


void trafficSignal_init()
{
	Led_init();
	
	Button_init(&btnAUTO,&DDRA,&PINA,0);
	Button_init(&btnMANUAL,&DDRA,&PINA,1);
	Button_init(&btnSWITCHING,&DDRA,&PINA,2);
}


void trafficSignal_execute()
{
	while (1)
	{
		
		if((BUTTON_PIN & (1<<B_AUTO)) == 0)
		{
			trafficModeState = AUTO;
		}
		else if((BUTTON_PIN & (1<<B_MANUAL)) == 0)
		{
			trafficModeState = MANUAL;
		}
		
		
		switch(trafficModeState)
		{
			case AUTO :
			trafficSignal_Auto();
			break;
			case MANUAL :
			trafficSignal_Manual();
			break;
		}
		
	}
}

void trafficSignal_Auto()
{
	switch (trafficState)
	{
		case RED_GREEN :
		trafficSignal_RedGreen();
		_delay_ms(3000);
		trafficState = RED_YELLOW;
		break;
		
		case RED_YELLOW :
		trafficSignal_RedYellow();
		_delay_ms(1000);
		trafficState = GREEN_RED;
		break;
		
		case GREEN_RED :
		trafficSignal_GreenRed();
		_delay_ms(3000);
		trafficState = YELLOW_RED;
		break;
		
		case YELLOW_RED :
		trafficSignal_YellowRed();
		_delay_ms(1000);
		trafficState = RED_GREEN;
		break;
	}
	
}


void trafficSignal_Manual()

{
	switch (trafficState)
	{
		case RED_GREEN :
		trafficSignal_RedGreen();
		if((BUTTON_PIN & (1<<B_SWITCHING))==0)
		{
			trafficState = RED_YELLOW;
		}
		break;
		
		case RED_YELLOW :
		trafficSignal_RedYellow();
		if((BUTTON_PIN & (1<<B_SWITCHING))==0)
		{
			trafficState = GREEN_RED;
		}
		break;
		
		case GREEN_RED :
		trafficSignal_GreenRed();
		if((BUTTON_PIN & (1<<B_SWITCHING))==0)
		{
			trafficState = YELLOW_RED;
		}
		break;
		
		case YELLOW_RED :
		trafficSignal_YellowRed();
		if((BUTTON_PIN & (1<<B_SWITCHING))==0)
		{
			trafficState = RED_GREEN;
		}
		break;
	}
}

void trafficSignal_RedGreen()
{
	ledData=0x09;
	LED_PORT=ledData;
}

void trafficSignal_RedYellow()
{
	ledData=0x11;
	LED_PORT=ledData;
}


void trafficSignal_GreenRed()
{
	ledData=0x24;
	LED_PORT=ledData;
}

void trafficSignal_YellowRed()
{
	ledData=0x22;
	LED_PORT=ledData;
}
