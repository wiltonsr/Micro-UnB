#include <msp430g2553.h>
#include <stdint.h>

#define MAX7219_DIN BIT4

#define MAX7219_CS  BIT5

//Não alterar
#define MAX7219_CLK BIT1


void atraso(volatile unsigned int i)
{
  while((i--)>0);
}

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
void initialise()
{
  
  //digitalWrite(MAX7219_CS, HIGH);
  P1OUT &= ~(MAX7219_CS);
  P1OUT |= MAX7219_CS;

  //pinMode(MAX7219_DIN, OUTPUT);
  P1DIR &= ~(MAX7219_DIN);
  P1DIR |= MAX7219_DIN;
  
  //pinMode(MAX7219_CS, OUTPUT);
  P1DIR &= ~(MAX7219_CS);
  P1DIR |= MAX7219_CS;
  
  //pinMode(MAX7219_CLK, OUTPUT);
  P2DIR &= ~(MAX7219_CLK);
  P2DIR |= MAX7219_CLK;
}

// void output(char address, char data)
// {
//   //digitalWrite(MAX7219_CS, LOW);
//   P1OUT &= ~(MAX7219_CS);
//   _shiftOut(MAX7219_DIN, MAX7219_CLK, address);
//   _shiftOut(MAX7219_DIN, MAX7219_CLK, data);
//   //digitalWrite(MAX7219_CS, HIGH);
//   P1OUT |= (MAX7219_CS);
// }

// void setTestMode(int on)
// {
//   output(0x0f, on ? 0x01 : 0x00);
// }

// void setShutdown(int off)
// {
//   output(0x0c, off ? 0x00 : 0x01); //shutdown register - normal operation
// }

// void showDigits(char numDigits)
// {
//   output(0x0b, numDigits-1); //scan limit register
// }

// void setBrightness(char brightness)
// {
//   output(0x0a, brightness); //intensity register - max brightness
// }

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
  //asm("mov.w reg, R15");
  //asm("call #putByte");
  //asm("pop R15");
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
   atraso(10000);
}


int main(){
  WDTCTL = WDTPW + WDTHOLD;   // Disable WDT
  DCOCTL = CALDCO_1MHZ;     // 1 Mhz DCO
  BCSCTL1 = CALBC1_1MHZ;  
  
  initialise();
  //setTestMode(0);
  //setShutdown(0);
  //setBrightness(1); // Brightness range 1..0x0f
  //showDigits(8);    // Make sure all digits are visible
  //output(0x09, 0);  // using an led matrix (not digits)
  
  atraso(100);
  write8x8(0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0); // Cleaning screen
  atraso(100);
  while(1){
    setaDir();
    setaEsq();
    parada();
  }
  return 0;
}
