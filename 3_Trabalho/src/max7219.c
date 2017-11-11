#include "max7219.h"
#include "utils.h"
#include <msp430g2553.h>

#define MAX7219_DIN BIT3
#define MAX7219_CS  BIT4
#define MAX7219_CLK BIT5

void shift_out(uint8_t dataPin, uint8_t clockPin, uint8_t val){
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


void put_byte(char data) {
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

void max_single(char reg, char col) {
  P1OUT &= ~(MAX7219_CS);
  put_byte(reg);                        // specify register
  //asm("mov.w reg, R15");
  //asm("call #putByte");
  //asm("pop R15");
  put_byte(col);                        // put data
  P1OUT &= ~(MAX7219_CS);
  P1OUT |= (MAX7219_CS);
}

void write8x8(char a, char b, char c, char d, char e, char f, char g, char h){
  max_single(1,a);
  max_single(2,b);
  max_single(3,c);
  max_single(4,d);
  max_single(5,e);
  max_single(6,f);
  max_single(7,g);
  max_single(8,h);
  delay(10000);
}
