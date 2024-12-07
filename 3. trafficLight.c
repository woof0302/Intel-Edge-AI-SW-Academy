// 인텔 ai sw 과정 AVR 수업 (2024.11.25 ~ 2024.11.26)

// 신호등 구현
// 자동으로 신호가 바뀌는 상태에서 시작
// B_MANUAL버튼을 누르면 MANUAL모드(B_SWITCHING버튼을 눌러야 다음 신호로 바뀐는 모드)로 전환 
// B_AUTO을 누르면 다시 AUTO모드로 돌아온다

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define	trafficButtonDDR   DDRA
#define	trafficButtonPIN   PINA
#define trafficLedDDR      DDRF
#define trafficLedPORT     PORTF

#define B_AUTO			0
#define B_MANUAL		1
#define B_SWITCHING     2

enum {AUTO, MANUAL};
enum {RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED};

void TrafficSignal_Auto();
void TrafficSignal_Manual();
void TrafficSignal_RedGreen();
void TrafficSignal_RedYellow();
void TrafficSignal_GreenRed();
void TrafficSignal_YellowRed();

uint8_t trafficState;  // 신호등 모드 enum {AUTO, MANUAL};

int main(void)
{
	trafficButtonDDR &= ~((1<<B_AUTO) | (1<<B_MANUAL) | (1<<B_SWITCHING)); // 버튼 DDR의 3개의 핀만 리셋
	trafficLedDDR |= ((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) |(1<<5)); // LED DDR의 6개 핀 셋
	
	uint8_t trafficModeState = AUTO;
	trafficState = RED_GREEN;		// 초기화
	
	while (1)
	{
		// Mode Event Check  신호등의 모드를 체크 B_AUTO, B_MANUAL버튼이 눌릴 때마다 상태 전환
		if((trafficButtonPIN & (1<<B_AUTO)) == 0)
		{
			trafficModeState = AUTO;
		}
		else if((trafficButtonPIN & (1<<B_MANUAL)) == 0)
		{
			trafficModeState = MANUAL;
		}
		
		// Mode Running
		switch(trafficModeState)  // 각 신호등 상태의 함수 호출
		{
			case AUTO :
			TrafficSignal_Auto();
			break;
			case MANUAL :
			TrafficSignal_Manual();
			break;
		}
		
	}
}

void TrafficSignal_Auto()  // 신호등 자동 모드(자동으로 신호가 바뀐다)
{
	switch (trafficState)
	{
		case RED_GREEN :
		TrafficSignal_RedGreen();
		_delay_ms(3000);
		trafficState = RED_YELLOW;
		break;
		case RED_YELLOW :
		TrafficSignal_RedYellow();
		_delay_ms(1000);
		trafficState = GREEN_RED;
		break;
		case GREEN_RED :
		TrafficSignal_GreenRed();
		_delay_ms(3000);
		trafficState = YELLOW_RED;
		break;
		case YELLOW_RED :
		TrafficSignal_YellowRed();
		_delay_ms(1000);
		trafficState = RED_GREEN;
		break;
	}
}
void TrafficSignal_Manual()  // 신호등 메뉴얼 모드(B_SWITCHING이 눌릴 때마다 신호가 바뀐다)
{
	switch (trafficState)
	{
		case RED_GREEN :
		TrafficSignal_RedGreen();
		if((trafficButtonPIN & (1<<B_SWITCHING))==0)
		{
			trafficState = RED_YELLOW;
		}
		break;
		case RED_YELLOW :
		TrafficSignal_RedYellow();
		if((trafficButtonPIN & (1<<B_SWITCHING))==0)
		{
			trafficState = GREEN_RED;
		}
		break;
		case GREEN_RED :
		TrafficSignal_GreenRed();
		if((trafficButtonPIN & (1<<B_SWITCHING))==0)
		{
			trafficState = YELLOW_RED;
		}
		break;
		case YELLOW_RED :
		TrafficSignal_YellowRed();
		if((trafficButtonPIN & (1<<B_SWITCHING))==0)
		{
			trafficState = RED_GREEN;
		}
		break;
	}
}

// 신호등을 켜주는 함수들

void TrafficSignal_RedGreen()
{
	trafficLedPORT = ((1<<0) | (1<<4));
}

void TrafficSignal_RedYellow()
{
	trafficLedPORT = ((1<<0) | (1<<5));
}

void TrafficSignal_GreenRed()
{
	trafficLedPORT = ((1<<2) | (1<<6));
}

void TrafficSignal_YellowRed()
{
	trafficLedPORT = ((1<<1) | (1<<6));
}