#include "max7219.h"
#include "utils.h"
#include <msp430g2553.h>

#define MAX7219_DIN BIT3
#define MAX7219_CS  BIT4
#define MAX7219_CLK BIT5


static void MAX7219_SendByte (unsigned char dataout)
{
  char i;
  for (i=8; i>0; i--) {
    unsigned char mask = 1 << (i - 1);              
    P1OUT &= ~(MAX7219_CLK);                                        
    if (dataout & mask)                               
      P1OUT |= MAX7219_DIN;                                     
    else                                             
      P1OUT &= ~(MAX7219_DIN);                                    
    P1OUT |= MAX7219_CLK;                                        
  }
}

void initialise(){
  P1OUT |= MAX7219_CS;

  P1DIR |= MAX7219_DIN;

  P1DIR |= MAX7219_CS;

  P1DIR |= MAX7219_CLK;

  output(0x0b, 7);                   
  output(0x09, 0x00); 
}

void output(char address, char data){
  P1OUT |= MAX7219_CS;
  MAX7219_SendByte(address);
  MAX7219_SendByte(data);
  P1OUT &= ~(MAX7219_CS);
  P1OUT |= MAX7219_CS;
}

void setTestMode(int on){
  output(0x0f, on ? 0x01 : 0x00);
}

void setShutdown(int off){
  output(0x0c, off ? 0x00 : 0x01);
}

void showDigits(char numDigits){
  output(0x0b, numDigits-1);
}

void setBrightness(char brightness){
  output(0x0a, brightness);
}

void put_byte(char data) {
  char i = 8;
  char mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);           
    P1OUT &= ~(MAX7219_CLK);
    if (data & mask){                
      P1OUT |= MAX7219_DIN;
    }else{
      P1OUT &= ~(MAX7219_DIN);
    }
    P1OUT |= MAX7219_CLK;
    --i;                             
  }
}

void max_single(char reg, char col) {
  P1OUT &= ~(MAX7219_CS);
  put_byte(reg);                        
  //asm("mov.w reg, R15");
  //asm("call #putByte");
  //asm("pop R15");
  put_byte(col);                        
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
  delay(5000);
}
