// �� �ܰ迡�� ���� ledMachine, trafficLight, standLight ��� button�� led������ driver������ ��� �־���.
// ������ ������ ���ϸ� �� �������� ����� �� ����̹���� �� �� ����.
// ��Ʈ�� �����Ǿ� �־ �ٸ� ��Ʈ�� ���� ����� �� ���� �� ���뼺�� �������� ����̹�����.
// �� ���������� ���뼺�� ���߱� ���� GPIO ������ �Լ��� ���� �ɰ� ��Ʈ�� ������ ���⼺�� ���Ѵٰų� ������� �� �� �ְ� �ߴ�.
// �׿� ���� button �� led ����̹��� �� �Լ����� ȣ���ϴ� ������ ���������.

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

