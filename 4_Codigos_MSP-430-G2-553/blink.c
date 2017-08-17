#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void main(void)
{
  /* Stop watchdog timer */
  WDTCTL = WDTPW + WDTHOLD;

  /* Set LEDS (BIT0 and BIT6) as output
   * and others bits as input */
  P1DIR = LEDS;

  /* P1.3 is connected to the button. In order to make the button work,
   * we have to add pull-up resistor to make it normally high. */
  P1REN = BIT3;
  P1OUT = BIT3;

  /* Loop */
  while(1)
  {
    if((P1IN & BIT3)!=BIT3)
    {
      __delay_cycles(220000);
      P1OUT ^= LEDS;
    }
  }
}
