# Atividade 05 - Data: 25/08/2017

### **Para as questões 2 a 5, considere que as variáveis `f`, `g`, `h`, `i` e `j` são do tipo inteiro (16 bits na arquitetura do MSP430), e que o vetor `A[]` é do tipo inteiro. Estas variáveis estão armazenadas nos seguintes registradores:**
- **f: R4**
- **g: R5**
- **h: R6**
- **i: R7**
- **j: R8**
- **A: R9**

### **Utilize os registradores R11, R12, R13, R14 e R15 para armazenar valores temporários.**

### 1. **Escreva os trechos de código assembly do MSP430 para:**
- **(a) Somente setar o bit menos significativo de R5.**
```assembly
mov.w #1,R4
bis.w R4,R5
```
- **(b) Somente setar dois bits de R6: o menos significativo e o segundo menos significativo.**
```assembly
mov.w #3,R4
bis.w R4,R6
```
- **(c) Somente zerar o terceiro bit menos significativo de R7.**
```assembly
mov.w #4,R4
bic.w R4,R7
```
- **(d) Somente zerar o terceiro e o quarto bits menos significativo de R8.**
```assembly
mov.w #12,R4
bic.w R4,R8
```
- **(e) Somente inverter o bit mais significativo de R9.**
```assembly
mov.w #128,R4
xor.w R4,R9
```
- **(f) Inverter o nibble mais significativo de R10, e setar o nibble menos significativo de R10.**
```assembly
mov.w #240,R4
xor.w R4,R10
mov.w #15,R4
bis.w R4,R10
```

### 2. **"Traduza" o seguinte trecho de código em C para o assembly do MSP430:**

```C
if(i>j) f = g+h+10;
else f = g-h-10;
```
```assembly
cmp R8,R7
jge MAIOR
mov.w R5,R11
mov.w R6,R12
sub.w R12,R11
sub.w #10,R11
mov.w R11,R4
MAIOR:
mov.w R5,R11
mov.w R6,R12
add.w R11,R12
add.w #10,R12
mov.w R12,R4
```

### 3. **"Traduza" o seguinte trecho de código em C para o assembly do MSP430:**

```C
while(save[i]!=k) i++;
```
```assembly
LOOP:
mov.w R7,R11
rla R11
add.w R9,R11   ; R9 = save
cmp 0(R11),R10 ; R10 = k
jeq EXIT
inc.w R7
jmp LOOP
EXIT:
```

### 4. **"Traduza" o seguinte trecho de código em C para o assembly do MSP430:**

```C
for(i=0; i<100; i++) A[i] = i*2;
```
```assembly
mov.w #0,R7
LOOP:
mov.w R7,R11
cmp #100,R7
jl MENOR
jmp EXIT
MENOR:
rla R11
add.w R9,R11
mov.w R7,R12
rla R12
mov.w R12,0(R11)
inc.w R7
jmp LOOP
EXIT:
```

### 5. **"Traduza" o seguinte trecho de código em C para o assembly do MSP430:**

```C
for(i=99; i>=0; i--) A[i] = i*2;
```
```assembly
mov.w #99,R7
LOOP:
mov.w R7,R11
cmp #0,R7
jge MAIOR
jmp EXIT
MAIOR:
rla R11
add.w R9,R11
mov.w R7,R12
rla R12
mov.w R12,0(R11)
dec.w R7
jmp LOOP
EXIT:
```
