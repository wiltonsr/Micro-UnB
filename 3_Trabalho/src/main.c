#include "max7219.h"
#include "utils.h"
#include "drawing.h"
#include <msp430g2553.h>
#include <legacymsp430.h> // Para rodar interrupcoes
#define BTN BIT6

int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Disable WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise();
  P1DIR &= ~BTN;
  P1REN &= ~BTN;
  P1OUT |= BTN;
  P1IES |= BTN;
  P1IE |= BTN;
  _BIS_SR(GIE);

  clear_screen();

  while(1){
    //setaDir();
    //parada();
    //parada();
    //parada();
    //setaEsq();
    //parada();
	    setaFrente();
	    P1OUT |= 0xFF;
}
	
  return 0;
}

interrupt(PORT1_VECTOR) Interrupcao_P1(void)
{
	while(!(P1IN&BTN)==0){
	  parada();
  }
	P1IFG &= ~BTN;
}
