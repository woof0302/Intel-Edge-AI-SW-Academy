#include "FND.h"

uint16_t fndData = 0;

void FND_init()
{
	FND_DIGIT_DDR = 0xff;
	FND_NUM_DDR = 0xff;
	
}

void FND_dispNum(uint16_t fndNum) // fndNum 값을 fnd에 출력
{
	uint8_t fndFont[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
	
	static uint8_t findDigitState = 0;
	
	findDigitState = (findDigitState + 1) % 4;
	
	PORTE |= (1<<FND_DIGIT_4) | (1<<FND_DIGIT_3) | (1<<FND_DIGIT_2) | (1<<FND_DIGIT_1); 
	
	switch(findDigitState)
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



void FND_setfndData(uint16_t data)
{
	fndData = data;	
}


void FND_ISR_Process()
{
	FND_dispNum(fndData);
}