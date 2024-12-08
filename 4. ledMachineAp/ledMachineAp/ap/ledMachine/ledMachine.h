#ifndef LEDMECHINE_H_
#define LEDMECHINE_H_

#include <avr/io.h>

#include "../../Driver/LED/LED.h"
#include "../../Driver/BUTTON/BUTTON.h"  // 버튼과 led의 헤더 include

enum{LED1, LED2, LED3, LED4};


void LedMachine_init();

void LedMachine_execute();


#endif /* LEDMECHINE_H_ */



