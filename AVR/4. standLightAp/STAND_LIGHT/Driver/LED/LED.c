#include "LED.h"

void LED_init()
{
	LED_DDR=0x00;	
}

void LED_writeData(uint8_t data)
{
	LED_PORT= data;	
}

void LED_allOff()
{
	LED_PORT=0x00;
}