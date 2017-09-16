.PHONY: run

ifeq (run,$(firstword $(MAKECMDGOALS)))
  MAIN_FILE := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(MAIN_FILE):;@:)
endif

MSPDEBUG_ARG = $(addsuffix .elf, $(basename $(MAIN_FILE)))
MSP430_ARG = $(addsuffix .c, $(basename $(MAIN_FILE)))

run: msp430
	mspdebug rf2500 "prog $(MSPDEBUG_ARG)"

msp430:
	msp430-gcc -Os -mmcu=msp430g2553 $(MSP430_ARG) -o $(MSPDEBUG_ARG)
