.PHONY: run clean

CC              = msp430-gcc
CC2             = mspdebug
CPU             = -mmcu=msp430g2553
DRIVER          = rf2500
OPTIMIZATION		= -O2
CFLAGS          = $(CPU) $(OPTIMIZATION) -Wall -g -lm
COMPILER_ARG		= $(MAIN_FILE)
FLASH_ARG 			= $(MAIN_FILE:.c=.elf)


ifeq (run,$(firstword $(MAKECMDGOALS)))
  MAIN_FILE := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
endif

run: compiler flash clean
	@echo "All done!"

compiler:
	@echo "Compiling " $(COMPILER_ARG) " file ..."
	$(CC) $(CFLAGS) $(COMPILER_ARG) -o $(FLASH_ARG)
	@echo ""

flash:
	@echo "Erasing and reprogramming the device using the " $(FLASH_ARG) " binary file ..."
	$(CC2) $(DRIVER) "prog $(FLASH_ARG)"
	@echo ""

flasherase:
	@echo "Erasing Flash memory..."
	$(CC2) $(DRIVER) erase
	@echo ""

clean:
	@echo "Excluding .elf files ..."
	rm -f *.elf
	@echo ""
