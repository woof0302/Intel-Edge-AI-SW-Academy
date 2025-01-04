#include "timer.h"

#include "device_driver.h"

void TIMER2::Stopwatch_Start(void) {
  TIM2->CR1 = (1 << 4) | (1 << 3);
  TIM2->ARR = TIM2_MAX;
  Macro_Set_Bit(TIM2->EGR, 0);
  Macro_Set_Bit(TIM2->CR1, 0);
}

unsigned int TIMER2::Stopwatch_Stop(void) {
  unsigned int time;
  Macro_Clear_Bit(TIM2->CR1, 0);
  time = (TIM2_MAX - TIM2->CNT) * TIM2_TICK;
  return time;
}

void TIMER2::Delay(int time) {
  unsigned int i;
  unsigned int t = TIME2_PLS_OF_1ms * time;
  TIM2->CR1 = (1 << 4) | (1 << 3);
  TIM2->ARR = 0xffff;
  Macro_Set_Bit(TIM2->EGR, 0);
  Macro_Set_Bit(TIM2->DIER, 0);

  for (i = 0; i < (t / 0xffffu); i++) {
    Macro_Set_Bit(TIM2->EGR, 0);
    Macro_Clear_Bit(TIM2->SR, 0);
    Macro_Set_Bit(TIM2->CR1, 0);
    while (Macro_Check_Bit_Clear(TIM2->SR, 0));
  }

  TIM2->ARR = t % 0xffffu;
  Macro_Set_Bit(TIM2->EGR, 0);
  Macro_Clear_Bit(TIM2->SR, 0);
  Macro_Set_Bit(TIM2->CR1, 0);
  while (Macro_Check_Bit_Clear(TIM2->SR, 0));

  Macro_Clear_Bit(TIM2->CR1, 0);
  Macro_Clear_Bit(TIM2->DIER, 0);
}
