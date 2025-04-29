// 인텔 ai sw 과정 AVR 수업 (2024.11.25 ~ 2024.11.26)


// 각 상태에 해당하는 LED가 깜빡이다가
// 버튼0이 눌리면 다음 번호의 LED가 깜빡이는 상태로 전환 
// 버튼1이 눌리면 이전 번호의 LED가 깜빡이는 상태로 전환 
// 상태 1과 4가 이어지게 구현한 코드



#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms


uint8_t ledData; // LED의 출력 PORT값을 지정할 변수

enum{LED1, LED2, LED3, LED4}; // 상태들을 상수 값으로 지정 (숫자 번째의 LED가 깜빡이는 상태)



void Led1_blink()	// 각 LED들을 깜빡이게할 함수 정의
{
	ledData ^= 0x01;
	PORTD = ledData;
}

void Led2_blink()
{
	ledData ^= 0x02;
	PORTD = ledData;
}

void Led3_blink()
{
	ledData ^= 0x04;
	PORTD = ledData;
}
void Led4_blink()
{
	ledData ^= 0x08;
	PORTD = ledData;
}

int main(void)
{
	DDRD = 0xff;
	DDRA &= ~((1<<0) | (1<<1)); // 0, 1번 핀을 입력으로 쓰겠다

	ledData = 0x01;
	uint8_t ledState = LED1;	// 초기화
	
	while (1)					// 버튼0이 눌리면 다음 번호의 LED가 깜빡이는 상태로 전환 
	{							// 버튼1이 눌리면 이전 번호의 LED가 깜빡이는 상태로 전환 
		switch(ledState)		// 상태 1과 4가 이어지게 구현
		{
			case LED1 :
			Led1_blink();
			if(!(PINA & (1<<0)))
			{
				ledState = LED2;
				ledData=0x00;
			}
			else if(!(PINA&(1<<1)))
			{
				ledState = LED4;
				ledData=0x00;
			}
			break;
			
			
			case LED2 :
			Led2_blink();
			if(!(PINA & (1<<0)))
			{
				ledState = LED3;
				ledData=0x00;
			}
			else if(!(PINA&(1<<1)))
			{
				ledState = LED1;
				ledData=0x00;
			}
			break;
			
			
			case LED3 :
			Led3_blink();
			if(!(PINA & (1<<0)))
			{
				ledState = LED4;
				ledData=0x00;
			}
			else if(!(PINA&(1<<1)))
			{
				ledState = LED2;
				ledData=0x00;
			}
			break;
			
			
			case LED4 :
			Led4_blink();
			if(!(PINA & (1<<0)))
			{
				ledState = LED1;
				ledData=0x00;
			}
			else if(!(PINA&(1<<1)))
			{
				ledState = LED3;
				ledData=0x00;
			}
			break;
		}
		_delay_ms(200);
	}

}

