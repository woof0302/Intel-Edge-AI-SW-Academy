/*
 * TIM.h
 *
 * Created: 2024-12-03 오후 3:32:04
 *  Author: iot
 */ 




#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void TIMER0_OVF_init();
void TIM_CTC_init();