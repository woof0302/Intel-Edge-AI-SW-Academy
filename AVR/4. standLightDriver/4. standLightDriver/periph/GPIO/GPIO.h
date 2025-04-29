#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum{INPUT,OUTPUT};
enum{GPIO_RESET, GPIO_SET};

void Gpio_initPort(volatile uint8_t *DDR, uint8_t dir);						// 포트 단위로 방향설정
void Gpio_initPin(volatile uint8_t *DDR,uint8_t pinNum,uint8_t dir);		// 핀 단위로 방향설정

void Gpio_writePort(volatile uint8_t *PORT, uint8_t data);					// 포트 단위로 출력
void Gpio_writePin(volatile uint8_t *PORT,uint8_t pinNum,uint8_t state);	// 핀 단위로 출력

uint8_t Gpio_readPort(volatile uint8_t *PIN);								// 포트 단위로 입력
uint8_t Gpio_readPin(volatile uint8_t *PIN,uint8_t pinNum);					// 핀 단위로 입력

#endif /* GPIO_H_ */