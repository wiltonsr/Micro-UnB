#include "utils.h"

void atraso(volatile unsigned int i){
  while((i--)>0);
}
