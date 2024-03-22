
NOW:=$(shell date -d "today" +'%d%b%g_%H_%M')

INCDIR=./Perifericos ./Debugger ./Procesador ./Perifericos/UKPtoRVLeon .
VERILOG_FILES=$(foreach D,$(INCDIR),$(wildcard $(D)/*.v))

LOGFILE=-q -l log/${NOW}_RVleon_

YOSYS_OPT=-p 'synth_ice40 -json hardware.json'
NEXTPNR_OPT=--hx8k --json hardware.json --package cb132 --asc hardware.asc --pcf icefun.pcf \
 --freq 12 
#--timing-allow-fail -r --opt-timing

all: hardware.bin

%.json: ${VERILOG_FILES}
	apio raw "yosys ${YOSYS_OPT} ${VERILOG_FILES} ${LOGFILE}IYOS.txt"

%.asc: %.json
	apio raw "nextpnr-ice40 ${PNR_EXTRA} ${NEXTPNR_OPT} ${LOGFILE}NPnR.txt"


%.bin: %.asc
	apio raw "icetime -p icefun.pcf -P cb132 -r log/${NOW}_RVleon.timings -d hx8k -t hardware.asc"
	cp ./hardware.asc log/hardware.asc
	apio raw "icepack -s hardware.asc hardware.bin"

clean:
	rm -rf hardware.bin hardware.asc hardware.json

upload: hardware.bin
	iceFUNprog hardware.bin 

.PHONY: all upload clean