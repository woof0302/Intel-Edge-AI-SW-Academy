// 인텔 ai sw 과정 AVR 수업 (2024.11.21 ~ 2024.11.22)  

#define _CRT_SECURE_NO_WARNINGS
#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms



// ----------------------------------------------------------------------------//

// 1. LED가 켜져 있는 상태에서 A포트의 0번 핀과 연결된 버튼을 누르면 LED가 모두 꺼지는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	DDRA=0x00;
	PORTA=0xff; // 플로팅 없애기 위해 풀업 저항 활성화
	
	while(1)
	{
		if((PINA&(1<<0))==0)  //PINA 레지스터의 0번 비트가 0이라면(버튼이 눌렸다면)
		//1은 이진수로 0b00000001 <<0연산하면 그대로
		//1을 3으로 바꾼다면 0번 핀, 1번 핀과 연결된 버튼을 동시에 눌러야 LED가 꺼진다.
		{
			PORTD=0x00;
		}
		else
		{
			PORTD=0xff;
		}
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 2. 0번 버튼으로 LED를 끄고, 1번 버튼으로 LED를 키는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	DDRA=0x00;
	PORTA=0xff; // 플로팅 없애기 위해 풀업 저항 활성화
	PORTD=0x00;
	
	uint8_t buttonStatus;
	
	while(1)
	{
		buttonStatus=PINA;
		
		
		if((buttonStatus&(1<<0))==0) //0번 버튼이 눌리면
		{
			PORTD=0x00;
		}
		if((buttonStatus&(1<<1))==0) //1번 버튼이 눌리면
		{
			PORTD=0xff;
		}
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 3. LED가 0번 버튼을 누르면 LED가 좌 쉬프트, 1번 버튼을 누르면 우 쉬프트 2번 버튼을 누르면 정지하는 코드

#if 0

#define LED_DDR        DDRD
#define LED_PORT       PORTD
#define BUTTON_DDR     DDRA
#define BUTTON_PIN     PINA
#define BUTTPN_PORT    PORTA

#define BUTTON_LEFT    0
#define BUTTON_RIGHT   1
#define BUTTON_STOP    2

enum{LEFT, RIGHT, STOP};

int main(void)
{
	DDRD = 0xff;
	DDRA = 0x00;
	PORTA = 0xff;
	
	uint8_t ledData = 0x01;
	uint8_t buttonStatus;
	uint8_t ledStatus = LEFT;
	
	while(1)
	{
		buttonStatus = BUTTON_PIN;
		
		if((buttonStatus & (1<<0)) == 0)
		{
			ledStatus = LEFT;
		}
		if((buttonStatus & (1<<1)) == 0)
		{
			ledStatus = RIGHT;
		}
		if((buttonStatus & (1<<2)) == 0)
		{
			ledStatus = STOP;
		}
		
		switch(ledStatus)
		{
			case LEFT:
			LED_PORT = ledData;
			ledData = ledData<<1 | ledData>>7;
			break;
			
			case RIGHT:
			LED_PORT = ledData;
			ledData = ledData>>1 | ledData<<7;
			break;
			
			case STOP:
			PORTD = ledData;
			break;
		}
		
		_delay_ms(500);
		
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 4. 누르는 버튼에 따라 LED가 다른 동작을 하는 코드

#if 0

#define LED_DDR		DDRD
#define LED_PORT	PORTD
#define BUTTON_DDR	DDRA
#define BUTTON_PORT PORTA
#define BUTTON_PIN	PINA

#define BUTTON_LEFT  0	// 좌 쉬프트
#define BUTTON_RIGHT 1	// 우 쉬프트
#define BUTTON_BLINK 2	// 깜빡임
#define BUTTON_OFF   3	// 꺼진다

enum{LEFT, RIGHT, BLINK, OFF};


int main(void)
{
	LED_DDR=0xff;
	BUTTON_DDR=0x00;
	BUTTON_PORT=0xff;
	
	uint8_t ledData=0x01;
	uint8_t ledStatus=LEFT;
	uint8_t buttonStatus=BUTTON_PIN;
	
	while(1)
	{
		buttonStatus=BUTTON_PIN;
		if((buttonStatus&(1<<0))==0)
		{
			ledStatus=0;
		}
		
		if((buttonStatus&(1<<1))==0)
		{
			ledStatus=1;
		}
		
		if((buttonStatus&(1<<2))==0)
		{
			ledStatus=2;
		}
		
		if((buttonStatus&(1<<3))==0)
		{
			ledStatus=3;
		}
		
		
		switch(ledStatus)
		{
			case BUTTON_LEFT:
			ledData=ledData<<1|ledData>>7;
			LED_PORT=ledData;
			_delay_ms(1500);
			break;
			
			case BUTTON_RIGHT:
			ledData=ledData>>1|ledData<<7;
			LED_PORT=ledData;
			_delay_ms(1500);
			break;
			
			case BUTTON_BLINK:
			LED_PORT=0xff;
			_delay_ms(1000);
			LED_PORT=0x00;
			_delay_ms(1000);
			break;
			
			case BUTTON_OFF:
			LED_PORT=0x00;
			break;
		}
		
	}
	
}

#endif




