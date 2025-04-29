#include "LED.h"

void Led_init()
{
	LED_DDR=0xff;
}

void Led_blink(uint8_t data)
{
	LED_PORT^=(1<<data);
	_delay_ms(50);
}