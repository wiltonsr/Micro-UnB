#include<msp430.h>

/* #define MAX7219_DIN P1_5 */
#define MAX7219_DIN BIT3
/* #define MAX7219_CS  P2_0 */
#define MAX7219_CS  BIT4
/* #define MAX7219_CLK P2_1 */
#define MAX7219_CLK BIT5

void putByte(char data) {
  char i = 8;
  char mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);           // get bitmask
    /* digitalWrite(MAX7219_CLK, LOW);   // tick */
    P1OUT &= ~(MAX7219_CLK);
    if (data & mask){                 // choose bit
      /* digitalWrite(MAX7219_DIN, HIGH);// send 1 */
      P1OUT |= (MAX7219_DIN);
    }else{
      /* digitalWrite(MAX7219_DIN, LOW); // send 0 */
      P1OUT &= ~(MAX7219_DIN);
    }
    /* digitalWrite(MAX7219_CLK, HIGH);  // tock */
    P1OUT |= (MAX7219_CLK);
    --i;                              // move to lesser bit
  }
}

void maxSingle(char reg, char col) {
  /* digitalWrite(MAX7219_CS, LOW);       // CS has to transition from LOW to HIGH */
  P1OUT &= ~(MAX7219_CS);
  putByte(reg);                        // specify register
  putByte(col);                        // put data
  /* digitalWrite(MAX7219_CS, LOW);       // Load by switching CS HIGH */
  P1OUT &= ~(MAX7219_CS);
  /* digitalWrite(MAX7219_CS, HIGH); */
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
  /* delay(wait); */
  __delay_cycles(1000);
}

void seta1(){
  write8x8(0x8,0xc,0xe,0xff,0xff,0xe,0xc,0x8);
  /* delay(1000); */
  __delay_cycles(1000);
  write8x8(0xf7,0xf3,0xf1,0x0,0x0,0xf1,0xf3,0xf7);
  /* delay(1000); */
  __delay_cycles(1000);
}

void seta2(){
  write8x8(0x8,0xc,0xe,0xff,0xff,0xe,0xc,0x8);
  write8x8(0x4,0x6,0x7,0x7f,0x7f,0x7,0x6,0x4);
  write8x8(0x2,0x3,0x3,0x3f,0x3f,0x3,0x3,0x2);
  write8x8(0x1,0x1,0x1,0x1f,0x1f,0x1,0x1,0x1);
  write8x8(0x0,0x0,0x0,0xf,0xf,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x7,0x7,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x3,0x3,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x1,0x1,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x0,0x80,0x80,0x0,0x0,0x0);
  write8x8(0x0,0x0,0x80,0xc0,0xc0,0x80,0x0,0x0);
  write8x8(0x0,0x80,0xc0,0xe0,0xe0,0xc0,0x80,0x0);
  write8x8(0x80,0xc0,0xe0,0xf0,0xf0,0xe0,0xc0,0x80);
  write8x8(0x40,0x60,0x70,0xf8,0xf8,0x70,0x60,0x40);
  write8x8(0x20,0x30,0x38,0xfc,0xfc,0x38,0x30,0x20);
  write8x8(0x10,0x18,0x1c,0xfe,0xfe,0x1c,0x18,0x10);
  write8x8(0x8,0xc,0xe,0xff,0xff,0xe,0xc,0x8);
}

void initialise()
{
  /* pinMode(MAX7219_DIN, OUTPUT); */
  /* pinMode(MAX7219_CS, OUTPUT); */
  /* pinMode(MAX7219_CLK, OUTPUT); */
  P1DIR |= (MAX7219_DIN | MAX7219_CS | MAX7219_CLK);
  /* digitalWrite(MAX7219_CS, HIGH); */
  P1OUT |= (MAX7219_CS);
}

void output(char address, char data)
{
  /* digitalWrite(MAX7219_CS, LOW); */
  P1OUT &= ~(MAX7219_CS);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, address);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, data);
  /* digitalWrite(MAX7219_CS, HIGH); */
  P1OUT |= (MAX7219_CS);
}

void setTestMode(int on)
{
  output(0x0f, on ? 0x01 : 0x00);
}

void setShutdown(int off)
{
  output(0x0c, off ? 0x00 : 0x01); //shutdown register - normal operation
}

void showDigits(char numDigits)
{
  output(0x0b, numDigits-1); //scan limit register
}

void setBrightness(char brightness)
{
  output(0x0a, brightness); //intensity register - max brightness
}

void setup() {
  initialise();
  setTestMode(0);
  setShutdown(0);
  setBrightness(1); // Brightness range 1..0x0f
  showDigits(8);    // Make sure all digits are visible
  output(0x09, 0);  // using an led matrix (not digits)
}

/* void loop() { */
/*   seta2(); */
/* } */
int main(){
  setup();
  while(1){
    seta2();
  }
}
