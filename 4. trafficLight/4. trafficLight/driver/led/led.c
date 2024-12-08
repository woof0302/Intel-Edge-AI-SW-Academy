#include "LED.h"

void Led_init()
{
	LED_DDR=0xff;
}

void traffic_Signal(uint8_t data)
{
	LED_PORT=data;	
}