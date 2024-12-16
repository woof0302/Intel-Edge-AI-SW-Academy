#include "FND.h"

uint16_t  FNDstate  =  0;
uint16_t fndData = 0;

void FND_init() 
{	
	FND_DIGIT_DDR = 0xff;
	FND_NUM_DDR = 0xff;		
}


void FND_dispNum(uint16_t fndNum)  
{
	uint8_t	fndFont[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	
	
	static uint8_t fndDigiState = 0;   
	fndDigiState = ( fndDigiState + 1 ) % 4 ; 
	
	FND_DIGIT_PORT |= (1<<7) | (1<<6) | (1<<5) | (1<<4);    
	
	switch(fndDigiState){
		
		
		case 0 :
		
		FND_NUM_PORT = fndFont [fndNum/1000%10];  
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT0);       
		break;
		
		case 1 :

		FND_NUM_PORT = fndFont [fndNum/100%10];   
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT1);

		break;
		
		case 2 :

		FND_NUM_PORT = fndFont [fndNum/10%10]; 
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT2);

		break;
		
		case 3 :
		

		FND_NUM_PORT = fndFont [fndNum%10];  
		FND_DIGIT_PORT &= ~(1<<FND_DIGIT3);    

		
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

