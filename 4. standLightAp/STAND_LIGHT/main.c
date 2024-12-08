// 과제로 만든 standLight 프로그램 (각 하드웨어의 동작은 드라이버에서 담당, ap에서 전체 프로그램을 제어)

#define F_CPU 1600000UL //CPU의 클록 주파수 1.6MHz로 정의
#include <avr/io.h>
#include <util/delay.h> //_delay_ms

#include "ap/StandLight.h"


int main(void)
{
	StandLight_init();
 
    while (1) 
    {
		StandLight_execute();
    }
}

