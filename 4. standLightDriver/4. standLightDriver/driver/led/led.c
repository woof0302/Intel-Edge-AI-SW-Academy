#include "LED.h"

void Led_init(volatile uint8_t *DDR)
{
	Gpio_initPort(DDR,OUTPUT);
}

void Led_writeData(volatile uint8_t *PORT,uint8_t data)
{
	Gpio_writePort(PORT,data);
}

void Led_allOff(volatile uint8_t *PORT,uint8_t data)
{
	Gpio_writePort(PORT,0x00);
}

void Led_allOn(volatile uint8_t *PORT,uint8_t data)
{
	Gpio_writePort(PORT,0xff);
}