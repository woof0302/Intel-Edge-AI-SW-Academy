#ifndef CLOCK_H_
#define CLOCK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../../driver/FND/FND.h"
#include "../../common/TimeTick/TimeTick.h"
#include "../../peripheral/TIM/TIM.h"

void Clock_init();

void Clock_incMilisec();

void Clock_execute();




#endif /* CLOCK_H_ */