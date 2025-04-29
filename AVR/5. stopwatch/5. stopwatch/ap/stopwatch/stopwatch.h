#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../../driver/Button/Button.h"
#include "../../driver/FND/FND.h"
#include "../../common/TimeTick/TimeTick.h"
#include "../../peripheral/TIM/TIM.h"

enum{RunStop, Reset};  // 버튼
enum{RUN, STOP, RESET}; // 모드

void StopWatch_incMilisec();

void StopWatch_init();

void StopWatch_run();

void StopWatch_checkMode();

void StopWatch_execute();




#endif /* STOPWATCH_H_ */