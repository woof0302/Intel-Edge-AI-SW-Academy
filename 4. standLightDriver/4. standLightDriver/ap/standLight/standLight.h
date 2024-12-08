#ifndef STANDLIGHT_H_
#define STANDLIGHT_H_

#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h> 

#include "../../driver/Button/BUTTON.h"
#include "../../driver/LED/LED.h"


#define  LED_DDR	DDRD
#define	LED_PORT	PORTD
#define  BUTTON_DDR DDRA
#define  BUTTON_PIN PINA


enum{LED_OFF,MODE1,MODE2,MODE3,MODE4};  //standLight의 상태

void StandLight_init();

void StandLight_run();

void StandLight_eventCheck();

void StandLight_execute();

void StandLight_allOff();
void StandLight_MODE1();
void StandLight_MODE2();
void StandLight_MODE3();
void StandLight_MODE4();




#endif /* STANDLIGHT_H_ */