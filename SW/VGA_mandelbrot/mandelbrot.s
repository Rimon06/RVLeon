.eqv mandel_shift, 5
.eqv WIDTH, 80
.eqv HEIGHT, 60
.equ mandel_mul, (1<<mandel_shift)
.equ xmin, -2*mandel_mul
.equ xmax,  2*mandel_mul
.equ ymin, -2*mandel_mul
.equ ymax,  2*mandel_mul
.equ dx, (xmax-xmin)/WIDTH
.equ dy, (ymax-ymin)/HEIGHT
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
main:
  add sp,sp,-4
  sw ra,0(sp)


  la a0,colormap_
  li t0,0x03020100
  
  sw t0,0(a0)
  li t1,0x1C140C04
  sw t1,4(a0)
  or t2,t0,t1 # 0x1F160D04
  sw t2,8(a0)
  li t3,0xE0A06020
  sw t3,12(a0)
  or t4,t3,t0 # 0xE3A26120
  sw t4,16(a0)
  or t5,t3,t1 # 0xFCB46C24
  sw t5,20(a0)
  or t6,t3,t2 # 0xFFB66D24
  sw t6,24(a0)
  
  call VGAcolormode # Activamos VGA
  # sw zero,28(a0)

  la a1,frame
  sw zero,0(a1)

  call VGAActivate
  call VGAClean 

mandelstart_:
  li s1,0
  li s3,xmin

loop_y_:
  li s0,0
  li s2,ymin

loop_x_:
  mv s4,s2 # Z <- C
  mv s5,s3 
  
  li s10,27 # iter <- 27
  
loop_z_:
    mv a0,s4 # Zrr <- (Zr*Zr) >> mandel shift
    mv a1,s4
    jal x1,__mulsi3
    srli s6,a0,mandel_shift
  
    mv a0,s4 # Zri <- (Zr*Zi) >> (mandel shift-1)
    mv a1,s5
    jal x1,__mulsi3
    srai s7,a0,(mandel_shift-1)

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
  
  exit_z_: # fin loop_z_
  la t0,frame
  lw a0,0(t0)
  add a0,a0,s10 # frame+item
  li a1,28
  call __umodsi3 # color(a0) <- (iter+frame) % 28
  la t2,colormap_
  add a0,a0,t2 # colormap + color

  sw a0,IO_LEDS(gp)
  lbu a0,0(a0)
  mv a1,s0
  mv a2,s1
  call PrintInVGA
  
  addi s0,s0,1
  addi s2,s2,dx
  li t0,WIDTH
  bne s0,t0,loop_x_
  # fin loop_x_

  addi s1,s1,1
  addi s3,s3,dy
  li t6,HEIGHT
  bne s1,t6,loop_y_
  # fin loop_y_

  la   t0,frame
  lw   t1,0(t0)
  addi t1,t1,1
  sw   t1,0(t0)
  #li a0,999999 
  #call microwait

  j mandelstart_

  lw ra,0(sp)
  addi sp,sp,4
  li a0,0
  call exit
  

.data
colormap_:
.align 2
.word 0,0,0,0,0,0,0,0
.align 2
frame:
.word 0
