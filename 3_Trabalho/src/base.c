#define MAX7219_DIN P1_5
#define MAX7219_CS  P2_0
#define MAX7219_CLK P2_1
const int wait = 100;

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
  digitalWrite(MAX7219_CS, HIGH);
  pinMode(MAX7219_DIN, OUTPUT);
  pinMode(MAX7219_CS, OUTPUT);
  pinMode(MAX7219_CLK, OUTPUT);
}

void output(byte address, byte data)
{
  digitalWrite(MAX7219_CS, LOW);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, address);
  shiftOut(MAX7219_DIN, MAX7219_CLK, MSBFIRST, data);
  digitalWrite(MAX7219_CS, HIGH);
}

void setTestMode(boolean on)
{
  output(0x0f, on ? 0x01 : 0x00);
}

void setShutdown(boolean off)
{
  output(0x0c, off ? 0x00 : 0x01); //shutdown register - normal operation
}

void showDigits(byte numDigits)
{
  output(0x0b, numDigits-1); //scan limit register
}

void setBrightness(byte brightness)
{
  output(0x0a, brightness); //intensity register - max brightness
}

void putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);           // get bitmask
    digitalWrite(MAX7219_CLK, LOW);   // tick
    if (data & mask){                 // choose bit
      digitalWrite(MAX7219_DIN, HIGH);// send 1
    }else{
      digitalWrite(MAX7219_DIN, LOW); // send 0
    }
    digitalWrite(MAX7219_CLK, HIGH);  // tock
    --i;                              // move to lesser bit
  }
}

void maxSingle(byte reg, byte col) {
  digitalWrite(MAX7219_CS, LOW);       // CS has to transition from LOW to HIGH    
  putByte(reg);                        // specify register
  putByte(col);                        // put data  
  digitalWrite(MAX7219_CS, LOW);       // Load by switching CS HIGH
  digitalWrite(MAX7219_CS, HIGH);
}

void write8x8(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h){
   maxSingle(1,a);
   maxSingle(2,b);
   maxSingle(3,c);
   maxSingle(4,d);
   maxSingle(5,e);
   maxSingle(6,f);
   maxSingle(7,g);
   maxSingle(8,h);
  delay(wait);
}

void setup() {
  initialise();
  setTestMode(false);
  setShutdown(false);
  setBrightness(1); // Brightness range 1..0x0f
  showDigits(8);    // Make sure all digits are visible
  output(0x09, 0);  // using an led matrix (not digits)
}

void loop() {
  // Generate bytes with something like the LED Byte Generator Chrome App: https://goo.gl/w4xhzm
  seta();
}
