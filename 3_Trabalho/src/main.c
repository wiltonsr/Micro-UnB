#include <msp430g2553.h>
#include <stdint.h>
#define MAX7219_DIN BIT4

#define MAX7219_CS  BIT5

//Não alterar
#define MAX7219_CLK BIT1

const int wait = 100;

void _shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t val)
{
     uint8_t i;

     for (i = 0; i < 8; i++)  {
      if(!!(val & (1 << (7 - i))) == 0){
           //digitalWrite(dataPin, !!(val & (1 << (7 - i))));
           P1OUT |= dataPin;
      }else{
          P1OUT &= ~(dataPin);  
      }
           //digitalWrite(clockPin, HIGH);
           P2OUT |= clockPin;
           //digitalWrite(clockPin, LOW);            
           P2OUT &= clockPin;
     }
}

void seta(){
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
  //digitalWrite(MAX7219_CS, HIGH);
  P1OUT |= MAX7219_CS;
  
  //pinMode(MAX7219_DIN, OUTPUT);
  P1DIR |= MAX7219_DIN;
  
  //pinMode(MAX7219_CS, OUTPUT);
  P1DIR |= MAX7219_CS;
  
  //pinMode(MAX7219_CLK, OUTPUT);
  P2DIR |= MAX7219_CLK;
}

void output(char address, char data)
{
  //digitalWrite(MAX7219_CS, LOW);
  P1OUT &= ~(MAX7219_CS);
  _shiftOut(MAX7219_DIN, MAX7219_CLK, address);
  _shiftOut(MAX7219_DIN, MAX7219_CLK, data);
  //digitalWrite(MAX7219_CS, HIGH);
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

void putByte(char data) {
  char i = 8;
  char mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);           // get bitmask
    //digitalWrite(MAX7219_CLK, LOW);   // tick
    P2OUT &= ~(MAX7219_CLK);
    if (data & mask){                 // choose bit
      //digitalWrite(MAX7219_DIN, HIGH);// send 1
      P1OUT |= MAX7219_DIN;
    }else{
      //digitalWrite(MAX7219_DIN, LOW); // send 0
      P1OUT &= ~(MAX7219_DIN);
    }
    //digitalWrite(MAX7219_CLK, HIGH);  // tock
    P2OUT |= MAX7219_CLK;
    --i;                              // move to lesser bit
  }
}

void maxSingle(char reg, char col) {
  //digitalWrite(MAX7219_CS, LOW);       // CS has to transition from LOW to HIGH    
  P1OUT &= ~(MAX7219_CS);
  putByte(reg);                        // specify register
  putByte(col);                        // put data  
  //digitalWrite(MAX7219_CS, LOW);       // Load by switching CS HIGH
  P1OUT &= ~(MAX7219_CS);
  //digitalWrite(MAX7219_CS, HIGH);
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
   __delay_cycles(10000);
}

void setup() {
  initialise();
  //setTestMode(0);
  //setShutdown(0);
  setBrightness(1); // Brightness range 1..0x0f
  showDigits(8);    // Make sure all digits are visible
  output(0x09, 0);  // using an led matrix (not digits)
}

int main(){
	setup();
	seta();
	
  	//write8x8(0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0);
 // 	write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff);
	//write8x8(0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff);
	//while(1){
	//	seta();
	//}
}

