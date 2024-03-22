.eqv mandel_shift, 10
.eqv mandel_mul, 1024#(1<<mandel_shift)
.eqv xmin, -2048
.eqv xmax, 2048
.eqv ymin, -2048
.eqv ymax, 2048
.eqv dx, 51
.eqv dy, 51
.eqv norm_max, 4096


# X,Y         : s0,s1
# Cr,Ci       : s2,s3
# Zr,Zi       : s4,s5
# Zrr,2Zri,Zii: s6,s7,s8
# cnt         : s10
# 128         : s11
.include "RVLEONLib.inc"

.text
.globl main
.type main,@function
.align 14
main:
  add sp,sp,-4
  sw ra,0(sp)

  la a0,colormap_
  li t0,' '
  sb t0,0(a0)
  li t0,'.'
  sb t0,1(a0)
  li t0,','
  sb t0,2(a0)
  li t0,':'
  sb t0,3(a0)
  li t0,';'
  sb t0,4(a0)
  li t0,'o'
  sb t0,5(a0)
  li t0,'x'
  sb t0,6(a0)
  li t0,'%'
  sb t0,7(a0)
  li t0,'#'
  sb t0,8(a0)
  li t0,'@'
  sb t0,9(a0)
  sb zero,10(a0)
  sb zero,11(a0)

mandelstart_:
  li s1,0
  li s3,xmin
  li s11,80

loop_y_:
  li s0,0
  li s2,ymin

loop_x_:
  mv s4,s2 # Z <- C
  mv s5,s3 
  
  li s10,9 # iter <- 9
  
loop_z_:
    mv a0,s4 # Zrr <- (Zr*Zr) >> mandel shift
    mv a1,s4
    jal x1,__mulsi3
    srli s6,a0,mandel_shift
  
    mv a0,s4 # Zri <- (Zr*Zi) >> (mandel shift-1)
    mv a1,s5
    jal x1,__mulsi3
    srai s7,a0,mandel_shift

    mv a0,s5 # Zii <- (Zi*Zi) >> (mandel_shift)
    mv a1,s5
    jal x1,__mulsi3
    srli s8,a0,mandel_shift

    sub s4,s6,s8 # Zr <- Zrr -Zii + Cr
    add s4,s4,s2 

    add s7,s7,s7 # Zi <- 2* Zri + Ci
    add s5,s7,s3 
      
    add s6,s6,s8
    li s7,norm_max # if norm > norm_max, exit loop
    bgt s6,s7,exit_z_
  
    addi s10,s10,-1 # iter--, loop if non-zero
    bnez s10,loop_z_
  
  exit_z_:
  la a0,colormap_
  add a0,a0,s10
  lbu a0,0(a0)
  call putc_
  
  addi s0,s0,1
  addi s2,s2,dx
  bne s0,s11,loop_x_
  
  li a0,' '
  call putc_
  li a0,10
  call putc_

  addi s1,s1,1
  addi s3,s3,dy
  bne s1,s11,loop_y_
  
#  j mandelstart_
  lw ra,0(sp)
  addi sp,sp,4
  li a0,0
  call exit
  
mulsi3_:
  mv a2,a0
  li a0,0
  mulsi3_l0_:
    andi a3,a1,1
    beqz a3,mulsi3_l1_
    add a0,a0,a2
  mulsi3_l1_:
    srli a1,a1,1
    slli a2,a2,1
    bnez a1,mulsi3_l0_
  
  ret

.data
colormap_:
.align 2
.byte ' ','.',',',':',';','o','x','%','#','@',0,0
#.section DAT IO_UART_DAT
