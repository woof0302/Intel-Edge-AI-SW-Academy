#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
// ���� ai sw ���� AVR ���� (2024.12.05) 

// LCD ��� �ǽ�
// ������ ��Ʈ�� �а� �ʱ�ȭ ������ ���ְ� ������ ������ִ� ��� ����

#include <stdio.h>

#include "driver/LCD/LCD.h"

int main(void)
{
	LCD_init();
	
	char buff[30];
	uint16_t counter = 0;
	
	
	
	//LCD_writeCharData('H');
	//LCD_writeCharData('e');
	//LCD_writeCharData('l');
	//LCD_writeCharData('l');
	//LCD_writeCharData('o');
	//
	//_delay_ms(3000);
	//LCD_writeCmdData(LCD_DISPLAY_CLEAR);   
	//
	//LCD_writeCmdData(LCD_DISPLAY_ON);
	//
	//LCD_writeCharData('W');
	//LCD_writeCharData('o');
	//LCD_writeCharData('r');
	//LCD_writeCharData('l');
	//LCD_writeCharData('d');
	//
	//_delay_ms(3000);
	//LCD_writeCmdData(LCD_DISPLAY_CLEAR);
	//

	while (1)
	{
		sprintf(buff, "counter :%d", counter++);
		LCD_writeStringXY(0, 3, buff);
		_delay_ms(1000);
	}
}

