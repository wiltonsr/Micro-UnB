#include "max7219.h"
#include "utils.h"
#include "drawing.h"
#include <msp430g2553.h>
#include <legacymsp430.h> // Para rodar interrupcoes
#define STOP_BTN BIT6
#define RIGHT_BTN BIT0
#define LEFT_BTN BIT6

int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Desabilita WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise();

  P1DIR &= ~(RIGHT_BTN + LEFT_BTN); //Seta como entrada 0 = entrada
  P1OUT &= ~(RIGHT_BTN + LEFT_BTN); //Desliga ambos os leds
  P1IE |= (RIGHT_BTN + LEFT_BTN);
  P1IFG &= ~(RIGHT_BTN + LEFT_BTN);
  P1REN = (RIGHT_BTN + LEFT_BTN);
  P1IES |= (RIGHT_BTN + LEFT_BTN);


  __enable_interrupt(); // enable all interrupts

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
}
