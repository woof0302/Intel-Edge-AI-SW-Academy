// 인텔 ai sw 과정 AVR 수업 (2024.12.03)

// 전날 배운 FND + interrupt 추가한 프로그램
// while문에서 counter값을 계속 1씩 증가시키고 인터럽트가 발생할 때 호출되는 ISR이 FND_dispNum함수를 호출하여 그 값을 FND에 출력한다.

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> // 인터럽트를 위한 헤더 추가
#include "driver/fnd.h"


ISR(TIMER0_OVF_vect)  // 매개변수 : TIMER0에 오버플로가 났을 때의 ISR
{
	FND_ISR_Process(); //ISR에서 동작하는 함수
	TCNT0 = 130;
}


int main(void)
{
	FND_init();
	
	
	// Timer/Counter0 레지스터에 overflow가 발생할 때마다 Interrupt (주기적으로 하겠다)
	// prescaler 1/128
	
	//			 CS02		 CS01		 CS00      클럭 분주 설정
	//			  1		      1			  1
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00));
	
	//TIMSK Timer Overflow Interrupt Enable 오버플로 인터럽트 가능하게 설정
	TIMSK |= ((1<<TOIE0));
	
	// Global Interrupt Enable
	sei();
	
	uint16_t counter = 3215;
	
	while (1)
	{
		FND_setfndData(counter++);	// counter를 계속 1씩 올린다
		_delay_ms(1000);
		
	}
}

