# Agregar ambos eqv en un include en conjunto
.include "RVLEONLib.inc"
.eqv STACKTOP, 0x1000

.text
.globl _start
.type _start,@function

_start:
  .option push
  .option norelax
    li   gp,IO_BASE 
  .option pop

    li   sp,STACKTOP # Cambiar poste
    call main


#################################################################################

# FemtoRV32 support library

# exit function: display exit code
# on LEDS, or spinning wheel if exit
# code is zero. 
.globl exit
.type  exit, @function
exit:   
  sw   a0, IO_LEDS(gp) # display exit code
exitl1:     
  bnez a0, exitl1    # if exit code is non-0, loop.
  li   t1, 1
exitl:
  sw   t1, IO_LEDS(gp)
  li   a0, 100000
  call  microwait
  slli t1,t1,1
  bne  t1,zero,exitl
  li   t1,1
  j    exitl

.globl abort
.type   abort, @function
abort:
  li a0,0xa0a0
  ebreak
  j exit
  ret
