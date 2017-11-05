#include "utils.h"

void atraso(volatile unsigned int i){
  while((i--)>0);
}

void clear_screen(){
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0); // Cleaning screen
}
