#ifndef FND_H_
#define FND_H_

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



void FND_init();


void FND_dispNum(uint16_t fndNum); // fndNum 값을 fnd에 출력


void FND_setfndData(uint16_t data);


void FND_ISR_Process();


#endif /* FND_H_ */