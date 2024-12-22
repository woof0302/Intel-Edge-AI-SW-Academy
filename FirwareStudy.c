RCC_APB2ENR |= (1 << 3);

// A0 대입 연산 LED1만 ON 3
GPIOB_CRH = 0x66;
GPIOB_ODR = 0x100;

// A1 비트 연산1 5
GPIOB->ODR = 0x0 << 8;  // LED 모두 ON
GPIOB->ODR = 0x3 << 8;  // LED 모두 OFF

// A2 비트 연산2 6
GPIOB->CRH |= (0x3 << 5) | (0x3 << 1);
GPIOB->CRH &= ~((0x9 << 4) | (0x9 << 0));

GPIOB->ODR |= (0x1 << 8);
GPIOB->ODR &= ~(0x1 << 9);

// A3 매크로 6
Macro_Write_Block(GPIO->CHR, 0xff, 0x66, 0);
Macro_Write_Block(GPIO->ODR, 0x3, 0x2, 8);

// A4 토클링 6
Macro_Invert_Area(GPIOB->ODR, 0x3, 8);

// A5 드라이버 7
void LED_Display(unsigned int num) {
  int disp = Macro_Extract_Area(num, 0x3, 0);

  if (disp == 0b00) {
    Macro_Clear_Area(GPIOB->ODR, 0x3, 8);
  }
  if (disp == 0b11) {
    Macro_Set_Area(GPIOB->ODR, 0x3, 8);
  }
  if (disp == 0b10) {
    Macro_Write_Block(GPIOB->ODR, 0x03, 0x1, 9);
  }
  if (disp == 0b01) {
    Macro_Write_Block(GPIOB->ODR, 0x03, 0x1, 8);
  }
}

// A6 키 인식 9
void Main(void) {
  Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);

  for (;;) {
    Macro_Write_Block(GPIOB->ODR, 0x3, Macro_Extract_Area(GPIOB->IDR, 0x3, 6),
                      8);
  }
}

// A7 키에 의한 토글링(inter lock) 9

for (;;) {
  if ((interlock != 0) && Macro_Check_Bit_Clear(GPIOB->IDR, 6)) {
    Macro_Invert_Bit(GPIOB->ODR, 8);
    interlock = 0;
  }

  else if ((interlock == 0) && Macro_Check_Bit_Set(GPIOB->IDR, 6)) {
    interlock = 1;
  }
}

// A8 키 드라이버 10

void Key_Poll_Init(void) {
  Macro_Set_Bit(RCC->APB2ENR, 3);
  Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);
}

int Key_Get_Pressed(void) { return Macro_Extract_Area(~GPIOB->IDR, 0x3, 6); }

void Key_Wait_Key_Released(void) {
  while (!(Key_Get_Pressed() == 0));

  // while( Key_Get_Pressed() != 0 );

  // for(;;)
  // {
  // 	if( Key_Get_Pressed() == 0 ) return;
  // }
}

int Key_Wait_Key_Pressed(void) {
  int r;
  while (!((r = Key_Get_Pressed()) != 0));
  return r;

  // for(;;)
  // {
  // 	int r = Key_Get_Pressed();
  // 	if(r != 0) return r;
  // }
}

// A9 채터링 제거 11

void Key_Poll_Init(void) {
  Macro_Set_Bit(RCC->APB2ENR, 3);
  Macro_Write_Block(GPIOB->CRL, 0xff, 0x44, 24);
}

static int Key_Check_Input(void) {
  return Macro_Extract_Area(~GPIOB->IDR, 0x3, 6);
}

int Key_Get_Pressed(void) {
  unsigned int i, k;

  for (;;) {
    k = Key_Check_Input();

    for (i = 0; i < N; i++) {
      if (k != Key_Check_Input()) {
        break;
      }
    }

    if (i == N) break;
  }

  return k;
}

void Key_Wait_Key_Released(void) { while (Key_Get_Pressed()); }

int Key_Wait_Key_Pressed(void) {
  int k;

  while ((k = Key_Get_Pressed()) == 0);
  return k;
}
