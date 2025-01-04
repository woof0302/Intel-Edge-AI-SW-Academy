#include "device_driver.h"
#include "timer.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);
	Key_Poll_Init();
}

extern "C" void abort(void)
{
  while (1);
}

extern "C" void Main(void)
{
	Sys_Init();
	Uart1_Printf("TIM2 delay test\n");

	TIMER2 t2;

	TIMER * p = &t2;

	for(;;)
	{
		LED_Display(0x1);
		t2.Delay(300);
		LED_Display(0x2);
		t2.Delay(300);
		Uart1_Printf(".");

		LED_Display(0x1);
		p->Delay(500);
		LED_Display(0x2);
		p->Delay(500);
		Uart1_Printf("#");
	}
}

