// 네개가 연달아 붙어있는 FND를 이용한 실습

// 1. FND 네자리에 동일한 숫자(0~9) 출력

#if 0

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define  FND_DIGIT_DDR	DDRE
#define  FND_NUM_DDR	DDRF

void FND_init()
{
	FND_DIGIT_DDR = 0xff;	// 출력 자리를 설정할 레지스터
	FND_NUM_DDR = 0xff;		// 출력할 값을 설정할 레지스터
	
}

int main(void)
{
	FND_init();
	
	uint8_t fndFont[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67}; // FND로 0~9를 출력하기 위한 값


	
	while (1)
	{
		for(int i=0; i<10; i++)
		{
			PORTF=fndFont[i];
			_delay_ms(200);
		}
		
	}
}

#endif



// 2. 각 자리에 다른 수 출력하기(1,2,3,4)

#if 0

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define  FND_DIGIT_DDR	DDRE
#define  FND_NUM_DDR	DDRF

void FND_init()
{
	FND_DIGIT_DDR = 0xff;
	FND_NUM_DDR = 0xff;

}

int main(void)
{
	FND_init();
	
	uint8_t fndFont[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
	
	while (1)
	{
		PORTE = ~(1<<4);  // 천의 자리
		PORTF=fndFont[1];
		_delay_ms(1);
		
		PORTE = ~(1<<5);  // 백의 자리
		PORTF=fndFont[2];
		_delay_ms(1);
		
		PORTE = ~(1<<6);  // 십의 자리
		PORTF=fndFont[3];
		_delay_ms(1);
		
		PORTE = ~(1<<7);  // 일의 자리
		PORTF=fndFont[4];
		_delay_ms(1);
		
		
	}
}

#endif



// 3. fndData(multiplexing 이용)를 FND_disNum함수로 출력 (1씩 증가하도록)

#if 0

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define  FND_DIGIT_DDR	DDRE
#define  FND_DIGIT_PORT PORTE
#define  FND_NUM_DDR	DDRF
#define  FND_NUM_PORT	PORTF
#define  FND_DIGIT_1	4  //0x10
#define  FND_DIGIT_2	5  //0x20
#define  FND_DIGIT_3	6  //0x40
#define  FND_DIGIT_4	7  //0x80


void FND_init()
{
	FND_DIGIT_DDR = 0xff;
	FND_NUM_DDR = 0xff;
}

void FND_dispNum(uint16_t fndNum) // fndNum 값을 fnd에 출력
{
	uint8_t fndFont[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
	
	static uint8_t fndDigitState = 0; // 출력 자릿수 의미
	
	fndDigitState = (fndDigitState + 1) % 4; 
	
	PORTE |= (1<<FND_DIGIT_4) | (1<<FND_DIGIT_3) | (1<<FND_DIGIT_2) | (1<<FND_DIGIT_1); // 1을 내보낸다 == 끈다(common cathode)
	
	switch(fndDigitState)
	{
		case 0 :
		FND_NUM_PORT = fndFont[fndNum/1000%10];	// fndNum의 천의 자리 추출
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT_1);  // 한 자리만 지정해서 출력
		break;
		
		case 1 :
		FND_NUM_PORT=fndFont[fndNum/100%10];  // fndNum의 천의 자리 추출
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT_2);
		break;
		
		case 2 :		
		FND_NUM_PORT=fndFont[fndNum/10%10];  // fndNum의 천의 자리 추출
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT_3);
		break;
		
		case 3 :		
		FND_NUM_PORT=fndFont[fndNum/1%10];  // fndNum의 천의 자리 추출
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT_4);
		break;
	}
}



int main(void)
{
	FND_init();
	
	uint32_t timeTick = 0;
	uint32_t prevTime = 0;
	
	uint16_t fndData = 0;
	
	while (1)
	{
		FND_dispNum(fndData); //fndData 0부터 1씩 증가하면서 출력
		
		if(timeTick - prevTime >= 100)
		{
			prevTime = timeTick;
			fndData++;
			
		}
		_delay_ms(1);  // _delay 지양해야함 하지만 아예 안 쓸 수는 없음
		timeTick++;
	}
}

#endif