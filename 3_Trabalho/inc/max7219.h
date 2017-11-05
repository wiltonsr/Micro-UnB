#ifndef MAX7219_H
#define MAX7219_H

#define MAX7219_DIN BIT3
#define MAX7219_CS  BIT4
#define MAX7219_CLK BIT5

#include <stdint.h>

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t val);

void initialise();

void putByte(char data);

void maxSingle(char reg, char col);

void write8x8(char a, char b, char c, char d, char e, char f, char g, char h);

#endif
