#ifndef STANDLIGHT_H_
#define STANDLIGHT_H_

#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms

#include "../Driver/Button/Button.h"
#include "../Driver/LED/LED.h"

enum{LED2, LED4, LED6, LED8, ALL_OFF};

void StandLight_init();
void StandLight_execute();

#endif