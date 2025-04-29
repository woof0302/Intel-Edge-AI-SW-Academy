
// 이전의 ledMachine은 main함수 내에 모든 기능을 구현했다면 
// 현 버전은 프로그램의 전체 동작을 제어하는 ap와 각 하드웨어의 정보를 담당하는 파일들로 나눠졌다.

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "ap/ledMachine/ledMachine.h" // ap의 헤더를 include

int main(void)
{
	LedMachine_init();
	
	while (1)
	{
		LedMachine_execute();
	}

}
