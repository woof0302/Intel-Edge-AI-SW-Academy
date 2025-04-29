// 전 단계에서 만든 ledMachine, trafficLight, standLight 모두 button과 led파일이 driver폴더에 들어 있었다.
// 하지만 엄밀히 말하면 그 버전들은 제대로 된 드라이버라고 할 수 없다.
// 포트가 고정되어 있어서 다른 포트나 핀을 사용할 수 없는 즉 범용성이 떨어지는 드라이버였다.
// 이 버전에서는 범용성을 갖추기 위해 GPIO 파일의 함수를 통해 핀과 포트를 선택해 방향성을 정한다거나 입출력을 할 수 있게 했다.
// 그에 맞춰 button 과 led 드라이버도 그 함수들을 호출하는 것으로 변경해줬다.

#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>

#include "ap/StandLight/StandLight.h"


int main(void)
{
	StandLight_init();
	
	
	
	while (1)
	{
		StandLight_run();
	}
}

