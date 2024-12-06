// 인텔 ai sw 과정 AVR 수업 (2024.11.21 ~ 2024.11.22)  

#define _CRT_SECURE_NO_WARNINGS
#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms
#include <stdlib.h> // 랜덤
#include <time.h> //시간



// ----------------------------------------------------------------------------//

// 1. LED가 깜빡이는 코드

#if 0

int main(void)
{

	while (1)
	{
		PORTD = 0xff;

		while (1)
		{
			PORTD = 0x00;
			_delay_ms(300);
			PORTD = 0xff;
			_delay_ms(300);
		}
	}
}

#endif

// ----------------------------------------------------------------------------//

// 2. LED의 1,3,5,7/ 2,4,6,8 번 핀이 번갈아 가면서 불이 들어오게하는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	
	while(1)
	{
		PORTD=0x55;		// 1 + 4 = 5
		_delay_ms(1500);
		PORTD=0xaa;		// 2 + 8 = 10(16진수 a)
		_delay_ms(1500);
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 3. LED가 순서대로 하나씩 불들어오는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	
	while(1)
	{
		PORTD=0x01;
		_delay_ms(500);
		PORTD=0x02;
		_delay_ms(500);
		PORTD=0x04;
		_delay_ms(500);
		PORTD=0x08;
		_delay_ms(500);
		PORTD=0x10;
		_delay_ms(500);
		PORTD=0x20;
		_delay_ms(500);
		PORTD=0x40;
		_delay_ms(500);
		PORTD=0x80;
		_delay_ms(500);
		
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 4. LED가 순서대로 하나씩 불들어오는 코드(for문 사용)

#if 0

int main(void)
{
	DDRD=0xff;
	
	while(1)
	{
		int i=0;
		for(i;i<8;i++)
		{
			PORTD=0x01<<i;
			_delay_ms(500);
		}
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 5. LED가 순서대로 하나씩 불들어오는 코드(배열 사용)

#if 0

int main(void)
{
	DDRD=0xff;
	char LED_patterns[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	int i=0;
	
	while(1)
	{
		PORTD=LED_patterns[i];
		i=(i+1)%8;
		_delay_ms(500);
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 6. LED가 순서대로 하나씩 불들어오는 코드(변수 사용)

#if 0

int main(void)
{
	DDRD=0xff;
	uint8_t ledData=0x01;
	
	while(1)
	{
		PORTD=ledData;
		ledData=ledData*2;
		_delay_ms(500);
		if(ledData==0x80)
		{
			ledData=0x01;
		}
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 7. LED가 순서대로 하나씩 불들어오는 코드(shift연산 사용)

#if 0

int main(void)
{
	DDRD=0xff;
	uint8_t ledData=0x01;
	
	while(1)
	{
		PORTD=ledData;
		_delay_ms(500);
		ledData=ledData>>7|ledData<<1;
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 8. LED가 하나씩 불이 들어오면서 내려갔다가 올라오는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	uint8_t i;
	uint8_t ledData=0x01;
	
	while(1)
	{
		for(i=0;i<7;i++) //i<8로 하면 오버플로
		{
			PORTD=ledData;
			ledData<<=1;
			_delay_ms(500);
		}
		for(i=0;i<7;i++)
		{
			PORTD=ledData;
			ledData>>=1;
			_delay_ms(500);
		}
		
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 9. LED가 2,4,6,8개 누적으로 불이들어오는 코드

#if 0

int main(void)
{
	DDRD=0xff;
	uint8_t i;
	uint8_t ledState[]={0x03,0x0f,0x3f,0xff};
	
	while(1)
	{
		for(i=0;i<4;i++)
		{
			PORTD=ledState[i];
			_delay_ms(3000);
			i=i%4;
		}
	}
	
}

#endif

// ----------------------------------------------------------------------------//

// 10. LED가 랜덤으로 깜빡이는 코드

#if 0

void delay_sec(uint16_t sec)
{
	volatile uint16_t i,j,k;
	for(i=0;i<sec;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			;
		}
	}
}


int main(void)
{
	DDRD=0xff;
	uint8_t ledData=0x00;
	srand(time(NULL));
	
	while(1)
	{
		PORTD=ledData;
		ledData=rand()%256;
		_delay_ms(1000);
		delay_sec(rand()%3);
	}
	
}

#endif

