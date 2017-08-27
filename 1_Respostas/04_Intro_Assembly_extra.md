# Atividade 04_Extra - Data: 23/08/2017

### **Para todas as questões, considere que as variáveis `f`, `g`, `h`, `i` e `j` são do tipo inteiro (16 bits na arquitetura do MSP430), e que o vetor `A[]` é do tipo inteiro. Estas variáveis estão armazenadas nos seguintes registradores:**
- **f: R4**
- **g: R5**
- **h: R6**
- **i: R7**
- **j: R8**
- **A: R9**

### **Utilize os registradores R11, R12, R13, R14 e R15 para armazenar valores temporários.**

### 1. **Traduza as seguintes linhas em C para a linguagem assembly do MSP430. Utilize somente as seguintes instruções: mov.w, add.w, sub.w, clr.w, dec.w, decd.w, inc.w e incd.w.**

- ### **(a) `f *= 5;`**
```assembly
mov.w R4,R11
mov.w R4,R12
add.w R11,R11
add.w R12,R12
add.w R11,R4
add.w R12,R4
```

- ### **(b) `g *= 6;`**
```assembly
mov.w R5,R11
mov.w R5,R12
mov.w R5,R13
add.w R11,R11
add.w R12,R12
add.w R13,R13
add.w R11,R13
add.w R12,R13
mov.w R13,R5
```

- ### **(d) `A[2] = 6*A[1] + 5*A[0];`**
```assembly
mov.w 2(R9),R11
mov.w 2(R9),R12
mov.w 2(R9),R13
add.w R11,R11
add.w R12,R12
add.w R13,R13
add.w R11,R13
add.w R12,R13
mov.w R13,2(R9)
mov.w 0(R9),R11
mov.w 0(R9),R12
add.w R11,R11
add.w R12,R12
add.w R11,0(R9)
add.w R12,0(R9)
mov.w 0(R9),4(R9)
add.w 2(R9),4(R9)
```

- ### **(e) `A[3] = 3*f - 5*h;`**
```assembly
mov.w R4,R11
add.w R11,R11
add.w R4,R11
mov.w R6,R12
mov.w R6,R13
add.w R12,R12
add.w R13,R13
add.w R6,R12
add.w R12,R13
sub.w R13,R11
mov.w R11,6(R9)
```

- ### **(f) `A[5] = 6*(f - 2*h);`**
```assembly
mov.w R4,R11
mov.w R6,R12
add.w R12,R12
sub.w R12,R11
mov.w R11,R12
mov.w R11,R13
mov.w R11,R14
add.w R12,R12
add.w R13,R13
add.w R14,R14
add.w R12,R14
add.w R13,R14
mov.w R14,10(R9)
```
