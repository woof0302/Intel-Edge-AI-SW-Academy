#ifndef CLOCK_H_
#define CLOCK_H_


#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "../../driver/button/Button.h"
#include "../../driver/fnd/FND.h"
#include "../../driver/lcd/LCD.h"
#include "../../periph/tim/TIM.h"

enum{HOUR_MIN, SEC_MIL};	// 시계 모드   (시:분, 초:밀리초)
enum{NORMAL, MODIFY};		// 시계 모드 , 시간 변경 모드

void clock_init();

void clock_incMilisec();

void clock_execute();

void clock_eventCheck();

void time_run();

void clock_run();

void clockDispCheck();

void clockModifyCheck();

void clock_dispHourMin();

void clock_dispMilsec();

void incHour();

void incMin();


#endif 