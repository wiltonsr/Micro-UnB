#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void blink_led(){
  P1OUT ^= LEDS;
}

void main(void)
{
  int i;
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = LEDS;

  P1REN = BIT3;
  P1OUT = BIT3;

  while(1){
    if((P1IN & BIT3)!=BIT3){
      for (i = 0; i < 2; ++i) {
        blink_led();
        __delay_cycles(500000);
        P1OUT = BIT3;
        __delay_cycles(500000);
      }
    }
  }
}
