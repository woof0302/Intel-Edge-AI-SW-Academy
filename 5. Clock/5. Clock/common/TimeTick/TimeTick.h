


#ifndef TIMETICK_H_
#define TIMETICK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void incTick();

void clearTick();

uint32_t getTick();




#endif /* TIMETICK_H_ */