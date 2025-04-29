#include "LCD.h"

uint8_t lcdControlData;


void LCD_init()
{
	GPIO_init();
	
	_delay_ms(15);
	LCD_writeCmdData(LCD_FUNCTION_SET);   
	_delay_ms(5);
	LCD_writeCmdData(LCD_FUNCTION_SET);   
	_delay_ms(1);
	LCD_writeCmdData(LCD_FUNCTION_SET);   
	LCD_writeCmdData(LCD_FUNCTION_SET);   
	LCD_writeCmdData(LCD_DISPLAY_OFF);    
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);  
	LCD_writeCmdData(LCD_ENTRY_MODE_SET); 
	LCD_writeCmdData(LCD_DISPLAY_ON);     
}




void GPIO_init()
{
	LCD_CONTROL_DDR |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_E);
	LCD_DATA_DDR |= 0xff;
}


void GPIO_writeControlData(uint8_t data)
{
	LCD_CONTROL_PORT = data;
}

void GPIO_writeData(uint8_t data)
{
	LCD_DATA_PORT = data;
}

void LCD_cmdMode()
{
	// RS -> Low
	lcdControlData &= ~(1<<LCD_RS);
	GPIO_writeControlData(lcdControlData);
	
}
void LCD_charMode()
{
	// RS -> High
	lcdControlData |= (1<<LCD_RS);
	GPIO_writeControlData(lcdControlData);
}

void LCD_writeMode()
{
	// RW -> Low
	lcdControlData &= ~(1<<LCD_RW);
	GPIO_writeControlData(lcdControlData);
}

void LCD_enableHigh()
{
	lcdControlData |= (1<<LCD_E);
	GPIO_writeControlData(lcdControlData);
	_delay_ms(1);
}

void LCD_enableLow()
{
	lcdControlData &= ~(1<<LCD_E);
	GPIO_writeControlData(lcdControlData);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	GPIO_writeData(data);
}

void LCD_writeCmdData(uint8_t data)
{
	// LCD 내부 명령어 동작
	LCD_cmdMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
	
}

void LCD_writeCharData(uint8_t data)
{
	// LCD Char 쓰는 동작
	LCD_charMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}


void LCD_writeString(char *str)
{
	for(int i=0; str[i]; i++)   
	{
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col %= 16, row %= 2;
	uint8_t lcdregisterAddress = (0x40 * row) + col;
	uint8_t command   = 0x80 + lcdregisterAddress;
	LCD_writeCmdData(command);
}


void LCD_writeStringXY(uint8_t row, uint8_t col, char *str)
{
	LCD_gotoXY(row, col);
	LCD_writeString(str);
}


