#include "GPIO.h"

void Gpio_initPort(volatile uint8_t *DDR, uint8_t dir)
{
	if(dir==OUTPUT)
	{
		*DDR=0xff;
	}
	else
	{
		*DDR=0x00;
	}
}

// init- pin(1EA)
void Gpio_initPin(volatile uint8_t *DDR,uint8_t pinNum,uint8_t dir)
{
	if(dir==OUTPUT)
	{
		*DDR|=(1<<pinNum);
	}
	else
	{
		*DDR&=!(1<<pinNum);
	}
}

//Output-port
void Gpio_writePort(volatile uint8_t *PORT, uint8_t data)
{
	*PORT=data;
}

// Output -pin
void Gpio_writePin(volatile uint8_t *PORT,uint8_t pinNum,uint8_t state) //state : 0을 출력할건지 1을 출력할건지
{
	if(state==GPIO_SET)
	{
		*PORT|=(1<<pinNum);
	}
	else
	{
		*PORT&=~(1<<pinNum);
	}
}

//Input-port
uint8_t Gpio_readPort(volatile uint8_t *PIN)
{
	return *PIN;
}

//Input-pin
uint8_t Gpio_readPin(volatile uint8_t *PIN,uint8_t pinNum)
{
	return((*PIN&(1<<pinNum)) != 0);  // *PIN&(1<<pinNum)값은 0아니면1  // 0 != 0 // 거짓
	// != 을 쓴이유 : pinNum 제외한 버튼을 눌렀을 때 반응 안함

	
}