#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 

#include "../../periph/GPIO/GPIO.h"
void Led_init(volatile uint8_t *DDR);
void Led_writeData(volatile uint8_t *PORT,uint8_t data);
void Led_allOn(volatile uint8_t *PORT,uint8_t data);
void Led_allOff(volatile uint8_t *PORT,uint8_t data);

#endif /* LED_H_ */