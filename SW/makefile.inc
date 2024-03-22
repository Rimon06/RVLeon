# LIB=lib/mouseusb.o lib/oled_SSD1306.o lib/VGA.o lib/CSR_counters.o lib/wait.o lib/tecladousb.o lib/serial.o

RVASM=riscv32-unknown-linux-gnu-as
RVGCC=riscv32-unknown-linux-gnu-gcc
RVLD=riscv32-unknown-linux-gnu-ld
RVDUMP=riscv32-unknown-linux-gnu-objdump
RVCOPY=riscv32-unknown-linux-gnu-objcopy
RVRANLIB=riscv32-unknown-linux-gnu-ranlib
RVAR=riscv32-unknown-linux-gnu-ar

FIRMWARE_DIR=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))
LIB_DIR=$(FIRMWARE_DIR)lib

CODEDIRS=$(LIB_DIR)/LIBRVLEON $(LIB_DIR)/MATHRVLEON

INCDIRS=$(foreach D,$(CODEDIRS), -I$(D))

BINARY=bin
ASMFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.[sS]))
#CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
######################################
#CCOBJ=$(patsubst %.c,%.o,$(CFILES))
#DEPFILES=$(patsubst %.c,%.d,$(CFILES))
ASOBJ=$(patsubst %.s,%.o,$(ASMFILES))
#####################################################
ASMFlags= -fno-pic -march=rv32i -mabi=ilp32 --mno-relax $(INCDIRS)
CFLAGS= -march=rv32i -mabi=ilp32
LDFLAGS=--no-check-sections -m elf32lriscv -b elf32-littleriscv -nostdlib --print-memory-usage --no-relax

all: $(LIB_DIR)/START/start.o $(PROJ).flash.elf $(PROJ).flash.bin $(PROJ).dbg.hex
########## hexdump -v -e '/4 "%08x" "\n"' $<
.s.o: $<
	@echo "- Compilando: $<"
	$(RVASM) $(ASMFlags) $< -o $@

# Aqui obtengo el .bin para cargarlo a la memoria flash
$(PROJ).flash.bin: $(PROJ).flash.elf
	$(RVCOPY) -O binary --only-section=.text $< $@

# Obtengo el archivo .elf
$(PROJ).flash.elf: $(ASOBJ) $(PROJ).o
	$(RVLD) $(LDFLAGS) -T "$(LIB_DIR)/linker/rvleonflash.ld" $^ -o $@

# Desemsamblamos para utilizarlo después
$(PROJ).dbg.hex: $(PROJ).flash.elf
	$(RVDUMP) -Mnumeric -D $< > $@

upload:  $(LIB_DIR)/START/start.o $(PROJ).flash.elf $(PROJ).flash.bin $(PROJ).dbg.hex
	iceFUNprog -o 0x80000 $(PROJ).flash.bin

.PHONY: clean all upload

clean:
	rm -f $(PROJ).flash.elf

cleanall:
	rm -f $(prog).flash.elf $(prog).flash.bin $(prog).dbg.hex $(prog).o
