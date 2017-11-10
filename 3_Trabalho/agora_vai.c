#include <msp430g2553.h>
#include "utils.h"
#include "max7219.h"
#include "drawing.h"
#include <stdint.h>

#define MAX7219_DIN BIT3

#define MAX7219_CS  BIT4

//Não alterar
#define MAX7219_CLK BIT5


void atraso(volatile unsigned int i)
{
  while((i--)>0);
}

void _shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t val)
{
  uint8_t i;

  for (i = 0; i < 8; i++)  {
    if(!!(val & (1 << (7 - i))) == 0){
      P1OUT |= dataPin;
    }else{
      P1OUT &= ~(dataPin);
    }
    P1OUT |= clockPin;
    P1OUT &= clockPin;
  }
}

void parada(){
  write8x8(0x0,0x42,0x24,0x18,0x18,0x24,0x42,0x0);
  atraso(2000000);
  write8x8(0xff,0xbd,0xdb,0xe7,0xe7,0xdb,0xbd,0xff);
  atraso(2000000);
}

void setaEsq(){
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x18);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x18,0x3c);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x18,0x3c,0x7e);
  write8x8(0x0,0x0,0x0,0x0,0x18,0x3c,0x7e,0xff);
  write8x8(0x0,0x0,0x0,0x18,0x3c,0x7e,0xff,0x18);
  write8x8(0x0,0x0,0x18,0x3c,0x7e,0xff,0x18,0x18);
  write8x8(0x0,0x18,0x3c,0x7e,0xff,0x18,0x18,0x18);
  write8x8(0x18,0x3c,0x7e,0xff,0x18,0x18,0x18,0x18);
  write8x8(0x18,0x3c,0x7e,0xff,0x18,0x18,0x18,0x18);
  write8x8(0x3c,0x7e,0xff,0x18,0x18,0x18,0x18,0x0);
  write8x8(0x7e,0xff,0x18,0x18,0x18,0x18,0x0,0x0);
  write8x8(0xff,0x18,0x18,0x18,0x18,0x0,0x0,0x0);
  write8x8(0x18,0x18,0x18,0x18,0x0,0x0,0x0,0x0);
  write8x8(0x18,0x18,0x18,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x18,0x18,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x18,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
}

void setaDir(){
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x18,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x3c,0x18,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x7e,0x3c,0x18,0x0,0x0,0x0,0x0,0x0);
  write8x8(0xff,0x7e,0x3c,0x18,0x0,0x0,0x0,0x0);
  write8x8(0x18,0xff,0x7e,0x3c,0x18,0x0,0x0,0x0);
  write8x8(0x18,0x18,0xff,0x7e,0x3c,0x18,0x0,0x0);
  write8x8(0x18,0x18,0x18,0xff,0x7e,0x3c,0x18,0x0);
  write8x8(0x18,0x18,0x18,0x18,0xff,0x7e,0x3c,0x18);
  write8x8(0x18,0x18,0x18,0x18,0xff,0x7e,0x3c,0x18);
  write8x8(0x0,0x18,0x18,0x18,0x18,0xff,0x7e,0x3c);
  write8x8(0x0,0x0,0x18,0x18,0x18,0x18,0xff,0x7e);
  write8x8(0x0,0x0,0x0,0x18,0x18,0x18,0x18,0xff);
  write8x8(0x0,0x0,0x0,0x0,0x18,0x18,0x18,0x18);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x18,0x18,0x18);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x18,0x18);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x18);
}
void initialise(){
  P1OUT &= ~(MAX7219_CS);
  P1OUT |= MAX7219_CS;

  P1DIR &= ~(MAX7219_DIN);
  P1DIR |= MAX7219_DIN;

  P1DIR &= ~(MAX7219_CS);
  P1DIR |= MAX7219_CS;

  P1DIR &= ~(MAX7219_CLK);
  P1DIR |= MAX7219_CLK;
}


void putByte(char data) {
  char i = 8;
  char mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);           // get bitmask
    P1OUT &= ~(MAX7219_CLK);
    if (data & mask){                 // choose bit
      P1OUT |= MAX7219_DIN;
    }else{
      P1OUT &= ~(MAX7219_DIN);
    }
    P1OUT |= MAX7219_CLK;
    --i;                              // move to lesser bit
  }
}

void maxSingle(char reg, char col) {
  P1OUT &= ~(MAX7219_CS);
  putByte(reg);                        // specify register
  //asm("mov.w reg, R15");
  //asm("call #putByte");
  //asm("pop R15");
  putByte(col);                        // put data
  P1OUT &= ~(MAX7219_CS);
  P1OUT |= (MAX7219_CS);
}

void write8x8(char a, char b, char c, char d, char e, char f, char g, char h){
  maxSingle(1,a);
  maxSingle(2,b);
  maxSingle(3,c);
  maxSingle(4,d);
  maxSingle(5,e);
  maxSingle(6,f);
  maxSingle(7,g);
  maxSingle(8,h);
  atraso(10000);
}


int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Disable WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;

  initialise();
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0); // Cleaning screen

  while(1){
    setaDir();
    parada();
    setaEsq();
    parada();
  }
  return 0;
}