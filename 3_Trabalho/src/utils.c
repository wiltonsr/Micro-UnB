#include "utils.h"
#include "max7219.h"

void delay(volatile unsigned int i){
  while((i--)>0);
}

void clear_screen(){
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0); // Cleaning screen
}
