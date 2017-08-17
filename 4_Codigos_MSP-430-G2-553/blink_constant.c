#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void main()
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = LEDS;
  P1OUT = LEDS;
  while(1){
    P1OUT ^= LEDS;
    __delay_cycles(220000);
  }
}
