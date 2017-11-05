#include "max7219.h"
#include "utils.h"
#include <msp430g2553.h>

#define MAX7219_DIN BIT3
#define MAX7219_CS  BIT4
#define MAX7219_CLK BIT5

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t val){
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
