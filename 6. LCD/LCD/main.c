#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
// 인텔 ai sw 과정 AVR 수업 (2024.12.05) 

// LCD 사용 실습
// 데이터 시트를 읽고 초기화 설정을 해주고 데이터 출력해주는 방법 연습

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

