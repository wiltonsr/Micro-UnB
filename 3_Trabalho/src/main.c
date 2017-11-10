#include "max7219.h"
#include "utils.h"
#include "drawing.h"
#include <msp430g2553.h>
#define BTN BIT6

int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Disable WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise();
  P1DIR &= ~BTN;
  P1REN &= ~BTN;
  P1OUT |= BTN;
  clear_screen();

  while(1){
    //setaDir();
    //parada();
    //parada();
    //parada();
    //setaEsq();
    //parada();
    if(!(P1IN&BTN)==0){ //botão pressionado
	    setaEsq();
	    P1OUT |= BTN;
	}
    else{
	    parada();
	    P1OUT |= 0xFF;
}
	
	    //P1OUT &= ~BIT0;
  }
  return 0;
}
