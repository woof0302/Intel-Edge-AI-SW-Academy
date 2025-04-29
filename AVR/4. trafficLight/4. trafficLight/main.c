// trafficLight 프로그램의 기능 나눈 버전

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	trafficSignal_init();
	
	while (1)
	{
		trafficSignal_execute();
	}

}