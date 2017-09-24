#include <msp430g2553.h>
#define LED1 BIT0
#define LED2 BIT6
#define LEDS (LED1|LED2)
#define BTN  BIT3

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	P1OUT |= LEDS;
	P1DIR |= LEDS;
	while(1);
	return 0;
}