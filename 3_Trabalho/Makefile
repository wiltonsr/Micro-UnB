SRC_DIR = src
OBJ_DIR = obj
ELF_DIR = elf
INC_DIR = inc

MAIN_FILE 			= main.c
CC              = msp430-gcc
CC2             = mspdebug
CPU             = -mmcu=msp430g2553
DRIVER          = rf2500
CFLAGS 					= $(CPU) -Wall -g -lm -O2 -Iinc/

SRC = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.c=.o}}}

COMPILER_ARG		= $(MAIN_FILE)
FLASH_ARG 			= $(MAIN_FILE:.c=.elf)

.PHONY: clean folders compiler flash flasherase relatorio

all: folders
	$(MAKE) $(MAIN_FILE)

$(MAIN_FILE): $(OBJ) flasherase compiler flash clean
	@echo All Done Sucessfully.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Creating object $@
	@echo Command:
	$(CC) -c $(CFLAGS) $< -o $@
	@echo ""

compiler:
	@echo "Compiling " $(SRC_DIR)/$(COMPILER_ARG) " file ..."
	$(CC) $(CFLAGS) -o $(ELF_DIR)/$(FLASH_ARG) $(OBJ)
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
	@rm -rf $(ELF_DIR) $(OBJ_DIR) *~
	@echo Cleaning Done Sucessfully.

folders:
	@echo Creating project structure...
	@mkdir -p $(ELF_DIR) $(SRC_DIR) $(OBJ_DIR) $(INC_DIR)
	@echo Structure Done Sucessfully.

relatorio:
	cd relatorio && pdflatex relatorio.tex
	-cd relatorio && bibtex relatorio.aux
	cd relatorio && pdflatex relatorio.tex
	cd relatorio && pdflatex relatorio.tex
	cd relatorio && rm -rf *.aux *.bbl *.blg *.dvi *.log
	mv relatorio/relatorio.pdf ./relatorio_final.pdf

