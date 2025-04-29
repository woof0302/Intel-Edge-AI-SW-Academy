// 인텔 ai sw 과정 AVR 수업 (2024.12.04)  

// 지금까지 배운 내용들을 바탕으로 다운 카운터, 인원체킹 등의 프로그램을 만들 수 있다.

 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ap/stopwatch/stopwatch.h"
#include "driver/FND/FND.h"
#include "common/TimeTick/TimeTick.h"

	


ISR(TIMER0_OVF_vect)  // ISR은 함수 같으면서도 함수 같지 않음 (?)  // 매개변수 : TIMER0에 오버플로가 났을 때의 ISR
{
	FND_ISR_Process(); //ISR에서 동작하는 함수
	TCNT0 = 131; // 130인지 131인지? : 130에서 125카운트해도 255 -> 오버플로 X / 131로 해야지 오버플로가 발생
	incTick();
}

ISR(TIMER2_COMP_vect) //OCR 설정 값과 같아졌을 때 interrupt 발생
{
	StopWatch_incMilisec();

}



int main(void)
{
	StopWatch_init();
	
	sei();
	
	
	while (1)
	{
		StopWatch_run();
	}
}




