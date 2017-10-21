# Steps to Run your code in MSP430

### First off all, you need these packages installed in your system. So check your distribution for more details about how to install them.
* gcc-msp430: Gcc port (GNU C compiler) for the MSP430.
* binutils-msp430: Binary manipulation tools (linker, assembler, etc.) for the MSP430.
* msp430mcu: Linker header files, specification files, and scripts.
* msp430-libc: Standard C library.
* gdb-msp430: GNU Debugger for the MSP430
* mspdebug: Write and debug tool for MSP430.

### After install all packages, you can download a Hello World code with the below command. This Hello World will power on a double LED when you press P1.3 button.
```
$ wget -O helloWorld.c https://git.io/v7ABV
```

### You can use the Makefile that is present in this repository and just run:
```
$ make run helloWorld.c
```

### Or to compile manually, pass the CPU model to the mps430-gcc. It changes according to the chip you are using, in our case the chip model is 553:
```
$ msp430-gcc -Os -mmcu=msp430g2553 helloWorld.c -o helloWorld.elf
```

### To write to the Launchpad just call the mspdebug tool:
```
$ sudo mspdebug rf2500
```

### Inside the mspdebug program the generated elf file:
```
(mspdebug) prog helloWorld.elf
```

### And then run the application finally:
```
(mspdebug) run
```

## That's all folks!
