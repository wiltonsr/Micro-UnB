#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = LEDS;
  P1REN = BIT3;
  P1OUT = BIT3;
  while(1)
  {
    if((P1IN & BIT3)!=BIT3)
    {
      __delay_cycles(220000);
      P1OUT ^= LEDS;
    }
  }
}
