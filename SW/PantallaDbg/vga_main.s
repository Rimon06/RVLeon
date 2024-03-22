# Hola Mundo en 

.include "RVLEONLib.inc"
.data

.text
.global main
.type main,@function
.macro VGAWriteChar char, x, y
  li   a0,\char
  li	 a1,\x
  li   a2,\y
  jal  PrintInVGA
.endm

main:
	li a0,5
	call microwait

	call VGAcolormode
	call VGAActivate

	li s0,0xf2
	addi s1,s0,20
loop2:

	sw s0,IO_LEDS(gp)
	mv a0,s0#0xb2
	call VGAPaintAll
	addi s0,s0,1
	blt s0,s1,loop2
# - - - - - - - - 
 	li s0,50 #Loop
 	li s1,60
 loop1:
 	beq s1,s0,loop1_out
 	li a0,0xff
 	mv a1,s0
 	li a2,40
 	jal PrintInVGA
 	addi s0,s0,1
 	j loop1
loop1_out:
#  call VGAClean

	call VGAtextmode
	VGAWriteChar 16,17,30
	VGAWriteChar 16,18,30
	VGAWriteChar 16,19,30
	VGAWriteChar 'H',5,30
	VGAWriteChar 'o',6,30
	VGAWriteChar 'l',7,30
	VGAWriteChar 'a',8,30
	VGAWriteChar ' ',9,30
	VGAWriteChar 'M',10,30
	VGAWriteChar 'u',11,30
	VGAWriteChar 'n',12,30
	VGAWriteChar 'd',13,30
	VGAWriteChar 'o',14,30
	VGAWriteChar '!',15,30
	VGAWriteChar ' ',16,30
	VGAWriteChar 16,17,30
	VGAWriteChar 16,18,30
	VGAWriteChar 16,19,30

	# call VGADeactivate

	li a0,0
  call exit
  nop
  nop


