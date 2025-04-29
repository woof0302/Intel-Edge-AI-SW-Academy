#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "../../driver/button/button.h"
#include "../../driver/led/led.h"

#define      B_AUTO            0
#define      B_MANUAL         1
#define      B_SWITCHING         2

enum{AUTO,MANUAL};  // trafficModeState
enum {RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED}; // trafficState

void trafficSignal_init();

void trafficSignal_execute();

void trafficSignal_Auto();

void trafficSignal_Manual();

void trafficSignal_RedGreen();
void trafficSignal_RedYellow();
void trafficSignal_GreenRed();
void trafficSignal_YellowRed();


#endif /* TRAFFICLIGHT_H_ */