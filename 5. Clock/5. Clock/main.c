// 시계 FND에 시 두자리 분 두자리 출력

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "driver/FND/FND.h"
#include "common/TimeTick/TimeTick.h"
#include "ap/Clock/Clock.h"




ISR(TIMER0_OVF_vect)  // 매개변수 : TIMER0에 오버플로가 났을 때의 ISR
{
	FND_ISR_Process(); 
	TCNT0 = 131; // 130인지 131인지? : 130에서 125카운트해도 255 -> 오버플로 X / 131로 해야지 오버플로가 발생
	incTick();
}


ISR(TIMER2_COMP_vect) //OCR 설정 값과 같아졌을 때 interrupt 발생
{
	Clock_incMilisec();
}



int main(void)
{
	Clock_init();
	
	sei(); // ??
	
	
	while (1)
	{
		Clock_execute();
	}
}

