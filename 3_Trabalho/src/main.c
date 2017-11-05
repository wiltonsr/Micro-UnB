#include "max7219.h"
#include "utils.h"
#include "drawing.h"
#include <msp430g2553.h>

int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Disable WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise();
  clear_screen();

  while(1){
    setaDir();
    parada();
    parada();
    parada();
    setaEsq();
    parada();
  }
  return 0;
}
