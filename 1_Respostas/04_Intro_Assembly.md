# Atividade 04 - Data: 18/08/2017

### **Para todas as questões, considere que as variáveis `f`, `g`, `h`, `i` e `j` são do tipo inteiro (16 bits na arquitetura do MSP430), e que o vetor `A[]` é do tipo inteiro. Estas variáveis estão armazenadas nos seguintes registradores:**
- **f: R4**
- **g: R5**
- **h: R6**
- **i: R7**
- **j: R8**
- **A: R9**
### **Utilize os registradores R11, R12, R13, R14 e R15 para armazenar valores temporários.**

### 1. **Traduza as seguintes linhas em C para a linguagem assembly do MSP430. Utilize somente as seguintes instruções: mov.w, add.w e sub.w.**
- ### **(a) `f = 0;`**
```assembly
mov.w #0,R4
```

- ### **(b) `g++;`**
```assembly
mov.w #1,R11
add.w R11,R5
```

- ### **(c) `h--;`**
```assembly
mov.w #1,R11
sub.w R11,R6
```

- ### **(d) `i += 2;`**
```assembly
mov.w #2,R11
add.w R11,R7
```

- ### **(e) `j -= 2;`**
```assembly
mov.w #2,R11
sub.w R11,R8
```

### 2. **Traduza as seguintes linhas em C para a linguagem assembly do MSP430. Utilize somente as seguintes instruções: mov.w, add.w, sub.w, clr.w, dec.w, decd.w, inc.w e incd.w.**
- ### **(a) `f = 0;`**
```assembly
clr.w R4
```

- ### **(b) `g++;`**
```assembly
inc.w R5
```

- ### **(c) `h--;`**
```assembly
dec.w R6
```

- ### **(d) `i += 2;`**
```assembly
incd.w R7
```

- ### **(e) `j -= 2;`**
```assembly
decd.w R8
```

3. Traduza as seguintes linhas em C para a linguagem assembly do MSP430. Utilize somente as seguintes instruções: mov.w, add.w, sub.w, clr.w, dec.w, decd.w, inc.w e incd.w.
- ### **(a) `f *= 2;`**
```assembly
add.w R4,R4
```

- ### **(b) `g *= 3;`**
```assembly
mov.w R5,R11
add.w R5,R5
add.w R11,R5
```

- ### **(c) `h *= 4;`**
```assembly
mov.w R6,R11
mov.w R6,R12
add.w R11,R11
add.w R12,R12
add.w R11,R12
mov.w R12,R6
```

- ### **(d) `A[2] = A[1] + A[0];`**
```assembly
mov.w 2(R9),R11
add.w 0(R9),R11
mov.w R11,4(R9)
```

- ### **(e) `A[3] = 2*f - 4*h;`**
```assembly
mov.w R4,R11
mov.w R6,R12
add.w R11,R11
add.w R6,R12
add.w R6,R12
add.w R6,R12
sub.w R12,R11
mov.w R11,6(R9)
```

- ### **(f) `A[3] = 2*(f - 2*h);`**
```assembly
mov.w R4,R11
mov.w R6,R12
add.w R12,R12
sub.w R12,R11
add.w R11,R11
mov.w R11,6(R9)
```
