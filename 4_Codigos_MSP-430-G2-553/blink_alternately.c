#include <msp430g2553.h>

void main()
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = BIT0 + BIT6;
  P1OUT = BIT6;
  while(1){
    P1OUT ^= BIT0 + BIT6;
    __delay_cycles(220000);
  }
}
