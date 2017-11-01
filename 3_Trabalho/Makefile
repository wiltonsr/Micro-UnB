SRC_DIR = src
ELF_DIR = elf
INC_DIR = inc

MAIN_FILE 			= agora_vai.c
CC              = msp430-gcc
CC2             = mspdebug
CPU             = -mmcu=msp430g2553
DRIVER          = rf2500
CFLAGS 					= $(CPU) -Wall -g -lm -O2

SRC = ${wildcard $(SRC_DIR)/*.c}

COMPILER_ARG		= $(MAIN_FILE)
FLASH_ARG 			= $(MAIN_FILE:.c=.elf)

.PHONY: clean folders compiler flash flasherase

all: folders
	$(MAKE) $(MAIN_FILE)

$(MAIN_FILE): flasherase compiler flash clean
	@echo All Done Sucessfully.

compiler:
	@echo "Compiling " $(SRC_DIR)/$(COMPILER_ARG) " file ..."
	$(CC) $(CFLAGS) $(SRC_DIR)/$(COMPILER_ARG) -o $(ELF_DIR)/$(FLASH_ARG)
	@echo ""

flash:
	@echo "Erasing and reprogramming the device using the " $(ELF_DIR)/$(FLASH_ARG) " binary file ..."
	$(CC2) $(DRIVER) "prog $(ELF_DIR)/$(FLASH_ARG)"
	@echo ""

flasherase:
	@echo "Erasing Flash memory..."
	$(CC2) $(DRIVER) erase
	@echo ""

clean:
	@echo Cleaning recursively...
	@rm -rf $(ELF_DIR) *~
	@echo Cleaning Done Sucessfully.

folders:
	@echo Creating project structure...
	@mkdir -p $(ELF_DIR) $(SRC_DIR) $(INC_DIR)
	@echo Structure Done Sucessfully.

