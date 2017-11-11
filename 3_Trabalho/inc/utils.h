#ifndef UTILS_H
#define UTILS_H

#define RIGHT_BTN BIT0
#define LEFT_BTN BIT6
#define STOP_BTN BIT7

void delay(volatile unsigned int i);

void clear_screen();

void configure_buttons();

#endif
