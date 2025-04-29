#ifndef TIM_H_
#define TIM_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void TIM0_OVF_init();

void TIM2_CTC_init();




#endif /* TIM_H_ */