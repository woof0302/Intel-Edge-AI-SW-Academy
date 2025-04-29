// B0 UART Echo-Back 12

void Main(void) {
  Sys_Init();
  Uart_Printf("UART Echo-Back Test\n");

  for (;;) {
    for (;;) {
      if (Macro_Check_Bit_Set(USART1->SR, 5)) {
        break;
      }
    }

    char x = USART1->DR;

    for (;;) {
      if (Macro_Check_Bit_Set(USART1->SR, 7)) {
        break;
      }
    }

    USART1->DR = x;

    //

    while (!Macro_Check_Bit_Set(USART1->SR, 5));

    char x = UART1->DR;

    while (!Macro_Check_Bit_Set(USART1->SR, 7));

    UART1->DR = x;
  }
}

// B1 Uart 드라이버 - Uart1_Get_Pressed, Uart1_Get_Char p.204

char Uart1_Get_Pressed(void) {
  if (Macro_Check_Bit_Set(USART1->SR, 5)) {
    return USAT1->DR;
  } else {
    return 0;
  }
}

char Uart1_Get_Char(void) {
  while (!Macro_Check_Bit_Set(USART1->SR, 5));
  return USART1->DR;
}

// B3 stop watch test 15 timer.c  p.218

#define TIM2_TICK 20                       // usec
#define TIM2_FREQ (1000000.0 / TIM2_TICK)  // Hz
#define TIM2_MAX 0xFFFF
#define TIM2_1ms_PLS (1000 / TIM2_TICK)

void TIM2_Stopwatch_Start(void) {
  Macro_Set_Bit(RCC->APB1ENR, 0);

  TIM2->PSC = (int)(TIMXCLK / TIM2_FREQ + 0.5) - 1;
  TIM2->ARR = TIM2_MAX;
  Macro_Set_Bit(TIM2->EGR, 0);
  TIM2->CR1 = (1 << 4) | (1 << 3) | (1 << 0);
}

unsigned int TIM2_Stopwatch_Stop(void) {
  Macro_Clear_Bit(TIM2->CR1, 0);
  return (TIM2_MAX - TIM2_ > CNT) * TIM2_TICK;
}

// B4 delay test    15 timer.c p.220

void TIM2_Delay(int time) {
  Macro_Set_Bit(RCC->APB1ENR, 0);

  TIM2->ARR = TIM2_1ms_PLS * time;
  TIM2->PSC = (int)(TIMXCLK / TIM2_FREQ + 0.5) - 1;
  Macro_Set_Bit(TIM2->EGR, 0);

  Macro_Clear_Bit(TIM2->SR, 0);
  Macro_Set_Bit(TIM2->DIER, 0);
  TIM2->CR1 = (1 << 4) | (1 << 3) | (1 << 0);

  while (!Macro_Check_Bit_Set(TIM2->SR, 0));

  Macro_Clear_Bit(TIM2->CR1, 0);
  Macro_Clear_Bit(TIM2->DIER, 0);
}

// B5 repeat timeout test     15 timer.c / p.221

void TIM4_Repeat(int time) {
  Macro_Set_Bit(RCC->APB1ENR, 2);

  // TIM4 CR1: ARPE=0, down counter, repeat mode
  TIM2->CR1 = (1 << 4);

  // PSC(50KHz),  ARR(reload시 값) 설정
  TIM4->PSC = (int)(TIMXCLK / TIM2_FREQ + 0.5) - 1;
  TIM4->ARR = time * TIM4_1ms_PLS - 1;

  // UG 이벤트 발생
  Macro_Set_Bit(TIM4->EGR, 0);
  // Update Interrupt Pending Clear
  Macro_Clear_Bit(TIM4->SR, 0);
  // Update Interrupt Enable
  Macro_Set_Bit(TIM4->DIER, 0);
  // TIM4 start
  Macro_Set_Bit(TIM4->CR1, 0);
}

// B6 주파수 생성    16 timer.c / p.229

void TIM3_Out_Freq_Generation(unsigned short freq) {
  // Timer 주파수가 TIM3_FREQ가 되도록 PSC 설정
  TIM3->PSC = (unsigned int)(TIMXCLK / (double)TIM3_FREQ + 0.5) - 1;
  // 요청한 주파수가 되도록 ARR 설정
  TIM3->ARR = (double)TIM3_FREQ / freq - 1;
  // Duty Rate 50%가 되도록 CCR3 설정
  TIM3->CCR3 = TIM3->ARR / 2;
  // Manual Update(UG 발생)
  Macro_Set_Bit(TIM3->EGR, 0);
  // Down Counter, Repeat Mode, Timer Start
  TIM3->CR1 = (1 << 4) | (0 << 3) | (0 << 1) | (1 << 0);
}

// B7 EXTI_IRQ      17 main, stm32f10x_it.c / p.252

void Main(void) {
  Sys_Init();
  Uart1_Printf("EXTI Test\n");

  Macro_Set_Bit(RCC->APB2ENR, 3);
  Macro_Set_Bit(RCC->APB2ENR, 0);

  Macro_Write_Block(GPIOB->CRL, 0xFF, 0x44, 24);
  Macro_Write_Block(AFIO->EXTICR[1], 0xFF, 0x11, 8);

  EXTI->PR = 0x3 << 6;
  Macro_Set_Area(EXTI->FTSR, 0x3, 6);
  Macro_Set_Area(EXTI->IMR, 0x3, 6);

  NVIC_ClearPendingIRQ(23);
  NVIC_EnableIRQ(23);
  __enable_irq();

  for (;;) {
    LED_Display(1);
    TIM2_Delay(500);
    LED_Display(2);
    TIM2_Delay(500);
  }
}

void EXTI9_5_IRQHandler(void) {
  Uart1_Printf("KEY = %x\n", Macro_Extract_Area(EXTI->PR, 0x3, 6));
  EXTI->PR = 0x3 << 6;
  NVIC_ClearPendingIRQ(23);
}

// B9 UART 수신 있으면 에코백   19 main.c / p.258

void Main(void) {
  Sys_Init();
  Uart1_Printf("USART1 IRQ Test\n");
  Key_ISR_Enable(1);

  Macro_Set_Bit(USART1->CR1, 5);
  NVIC_ClearPendingIRQ(37);
  NVIC_EnableIRQ(37);

  for (;;) {
    if (Key_Value) {
      Uart1_Printf("KEY=%d\n", Key_Value);
      Key_Value = 0;
    }

    LED_Display(1);
    TIM2_Delay(100);
    LED_Display(2);
    TIM2_Delay(100);
  }
}

// C0 수신 인터럽트 사용 디바이스 드라이버 20 uart.c, main.c, stm21f10xit.c
// p.259-260

void Uart1_RX_Interrupt_Enable(int en) {
  if (en) {
    Macro_Set_Bit(USART1->CR1, 5);
    NVIC_ClearPendingIRQ(37);
    NVIC_EnableIRQ(37);
  }

  else {
    Macro_Clear_Bit(USART1->CR1, 5);
    NVIC_DisableIRQ(37);
  }
}

volatile int Uart1_Rx_In = 0;
volatile int Uart1_Rx_Data = 0;

void USART1_IRQHandler(void) {
  Uart1_Rx_Data = (unsigned char)USART1->DR;
  Uart1_Rx_In = 1;
  NVIC_ClearPendingIRQ(37);
}

// C1 타이머 인터럽트 repteat함수 재설계  21 timer.c  p.265

void TIM4_Repeat_Interrupt_Enable(int en, int time) {
  if (en) {
    Macro_Set_Bit(RCC->APB1ENR, 2);

    TIM4->CR1 = (1 << 4) | (0 << 3);
    TIM4->PSC = (unsigned int)(TIMXCLK / (double)TIM4_FREQ + 0.5) - 1;
    TIM4->ARR = TIME4_PLS_OF_1ms * time;

    Macro_Set_Bit(TIM4->EGR, 0);
    Macro_Clear_Bit(TIM4->SR, 0);
    NVIC_ClearPendingIRQ(30);
    Macro_Set_Bit(TIM4->DIER, 0);
    NVIC_EnableIRQ(30);
    Macro_Set_Bit(TIM4->CR1, 0);
  }

  else {
    NVIC_DisableIRQ(30);
    Macro_Clear_Bit(TIM4->CR1, 0);
    Macro_Clear_Bit(TIM4->DIER, 0);
  }
}
