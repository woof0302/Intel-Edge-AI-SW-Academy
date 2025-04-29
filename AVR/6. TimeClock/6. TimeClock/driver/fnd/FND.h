
#define  FND_DIGIT_DDR   DDRE    
#define  FND_DIGIT_PORT  PORTE
#define  FND_NUM_DDR     DDRF
#define  FND_NUM_PORT    PORTF
#define  FND_DIGIT0 4
#define  FND_DIGIT1 5
#define  FND_DIGIT2 6
#define  FND_DIGIT3 7
#define F_CPU 16000000UL




#define LED_PORT PORTD
#define LED_DDR DDRD
#define BUTTON_DDR DDRA
#define BUTTON_PIN PINA


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



void FND_init();
void FND_dispNum(uint16_t fndNum);
void FND_setfndData(uint16_t data);
void FND_ISR_Process();

