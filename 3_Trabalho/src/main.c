#include "max7219.h"
#include "utils.h"
#include "drawing.h"
#include <msp430g2553.h>
#include <legacymsp430.h> // Para rodar interrupcoes

/*
                MSP430G2553
            -------------------
            |VCC           GND|
RIGHT_BTN-->|P1.0          XIN|
            |P1.1         XOUT|
            |P1.2          TST|
      DIN<--|P1.3          RST|
       CS<--|P1.4         P1.7|<--STOP_BTN
      CLK<--|P1.5         P1.6|<--LEFT_BTN
            |P2.0         P2.5|
            |P2.1         P2.4|
            |P2.2         P2.3|
            -------------------
*/

int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Desabilita WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise(); 
  setTestMode(0);
  setShutdown(0);
  setBrightness(0xff);
  showDigits(8);   
  
  configure_buttons();

  __enable_interrupt();

  clear_screen();

  while(1){
    ahead_arrow();
  }

  return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){
  if(P1IFG & RIGHT_BTN){
    while(!(P1IN & RIGHT_BTN)==0){
      right_arrow();
    }
    P1IFG &= ~RIGHT_BTN;
  }
  if(P1IFG & LEFT_BTN){
    while(!(P1IN & LEFT_BTN)==0){
      left_arrow();
    }
    P1IFG &= ~LEFT_BTN;
  }
  if(P1IFG & STOP_BTN){
    while((P1IN & STOP_BTN)==0){
      delay(20);
      stop();
    }
    P1IFG &= ~STOP_BTN;
  }
  return 0;
}
