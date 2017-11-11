#include "utils.h"
#include "max7219.h"
#include <msp430g2553.h>

void delay(volatile unsigned int i){
  while((i--)>0);
}

void clear_screen(){
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0); // Cleaning screen
}

void configure_buttons(){
  P1DIR &= ~(RIGHT_BTN + LEFT_BTN + STOP_BTN); //Seta como entrada 0 = entrada
  P1OUT &= ~(RIGHT_BTN + LEFT_BTN + STOP_BTN); //Desliga ambos os leds
  P1IE |= (RIGHT_BTN + LEFT_BTN + STOP_BTN);
  P1IFG &= ~(RIGHT_BTN + LEFT_BTN + STOP_BTN);
  P1REN = (RIGHT_BTN + LEFT_BTN + STOP_BTN);
  P1IES |= (RIGHT_BTN + LEFT_BTN + STOP_BTN);
}
