#ifndef MAX7219_H
#define MAX7219_H

#define MAX7219_DIN BIT3
#define MAX7219_CS  BIT4
#define MAX7219_CLK BIT5

#include <stdint.h>

void shift_out(uint8_t dataPin, uint8_t clockPin, uint8_t val);

void initialise();

void setTestMode(int on);

void setShutdown(int off);

void setBrightness(char brightness);

void showDigits(char numDigits);

void put_byte(char data);

void output(char address, char data);

void max_single(char reg, char col);

void write8x8(char a, char b, char c, char d, char e, char f, char g, char h);

#endif
