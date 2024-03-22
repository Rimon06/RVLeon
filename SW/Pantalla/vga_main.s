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

	call VGAcolormode
	call VGAActivate
	li a0,500000
	call microwait
 	li s0,0 #Loop
 	li s1,80
 loop1:
 	beq s1,a1,loop1_out
 	li a0,0xff
 	mv a1,s0
 	li a2,10
 	jal PrintInVGA
 	addi s0,s0,1
 	j loop1
loop1_out:
	li a0,5000000
	call microwait
	li s0,0xf2
	addi s1,s0,20
loop2:
	li a0,800000
	call microwait
	sw s0,IO_LEDS(gp)
	mv a0,s0#0xb2
	call VGAPaintAll
	addi s0,s0,1
	blt s0,s1,loop2
  call VGAClean

	 VGAWriteChar 0xf2, 0, 1
	 VGAWriteChar 0xf2, 0, 2
	 VGAWriteChar 0xf2, 0, 3
	 VGAWriteChar 0xf2, 0, 4
	 VGAWriteChar 0xf2, 0, 5
	 VGAWriteChar 0x52, 4, 1
	 VGAWriteChar 0x72, 4, 2
	 VGAWriteChar 0x52, 4, 3
	 VGAWriteChar 0x92, 4, 4
	 VGAWriteChar 0xb2, 4, 5
	 VGAWriteChar 0xf1, 1,2
	 VGAWriteChar 0xa2, 2,3
	 VGAWriteChar 0x78, 3,4
	 VGAWriteChar 0x1d, 4,5
	 VGAWriteChar 0x12, 6,7
	 VGAWriteChar 0x77, 11, 12
	li a0,5000000
	call microwait
	call VGAtextmode
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
	li a0,10000000
	call microwait
	# call VGADeactivate

	li a0,0
  call exit


