# Atividade 03 - Data: 16/08/2017

### 1. **Dada uma variável `a` do tipo `char` (um byte), escreva os trechos de código em C para:**
- ### **(a) Somente setar o bit menos significativo de `a`.**
```c
char a = 0x01;
```

- ### **(b) Somente setar dois bits de `a`: o menos significativo e o segundo menos significativo.**
```c
char a = 0x03;
```

- ### **(c) Somente zerar o terceiro bit menos significativo de `a`.**
```c
char a = 0xFB;
```

- ### **(d) Somente zerar o terceiro e o quarto bits menos significativo de `a`.**
```c
char a = 0xF3;
```

- ### **(e) Somente inverter o bit mais significativo de `a`.**
```c
char a = a|0b10000000;
```

- ### **(f) Inverter o nibble mais significativo de `a`, e setar o nibble menos significativo de `a`.**
```c
char a = a|0b00000000;
a = a^0b11110000;
```

### 2. **Considerando a placa Launchpad do MSP430, escreva o código em C para piscar os dois LEDs ininterruptamente.**
```c
#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void main()
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = LEDS;
  P1OUT = BIT6;
  while(1){
    P1OUT ^= LEDS;
    __delay_cycles(220000);
  }
}
```

### 3. **Considerando a placa Launchpad do MSP430, escreva o código em C para piscar duas vezes os dois LEDs sempre que o usuário pressionar o botão.**
```c
#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void main(void)
{
  int i;
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = LEDS;

  P1REN = BIT3;
  P1OUT = BIT3;

  while(1){
    if((P1IN & BIT3)!=BIT3){
      for (i = 0; i < 2; ++i) {
        P1OUT ^= LEDS;
        __delay_cycles(500000);
        P1OUT = BIT3;
        __delay_cycles(500000);
      }
    }
  }
}
```

### 4. **Considerando a placa Launchpad do MSP430, faça uma função em C que pisca os dois LEDs uma vez.**
```c
void blink_led(){
  P1OUT ^= LEDS;
}
```

### 5. **Reescreva o código da questão 2 usando a função da questão 4.**
```c
#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void blink_led(){
  P1OUT ^= LEDS;
}

void main()
{
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR = LEDS;
  P1OUT = BIT6;
  while(1){
    blink_led();
    __delay_cycles(220000);
  }
}
```

### 6. **Reescreva o código da questão 3 usando a função da questão 4.**
```
#include <msp430g2553.h>
#define LEDS (BIT0 + BIT6)

void blink_led(){
  P1OUT ^= LEDS;
}

void main(void)
{
  int i;
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = LEDS;

  P1REN = BIT3;
  P1OUT = BIT3;

  while(1){
    if((P1IN & BIT3)!=BIT3){
      for (i = 0; i < 2; ++i) {
        blink_led();
        __delay_cycles(500000);
        P1OUT = BIT3;
        __delay_cycles(500000);
      }
    }
  }
}
```
