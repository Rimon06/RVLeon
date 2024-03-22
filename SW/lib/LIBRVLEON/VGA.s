# Libreria de la pantalla VGA para 80x60 datos
# Seleccion de modo entre texto y colores
# Modo Texto: Configuración de colores de fondo y letra. Los datos enviados se trataran como caracteres ASCII (No todos disponibles en hardware)
# Modo Color: Los datos enviados se trataran como colores... 
#
.include "RVLEONLib.inc"
.global VGAWriteChar
.macro VGAWriteChar char, x, y
  li   a0,\char
  li   a1,\x
  li   a2,\y
  jal  PrintInVGA
.endm

.global VGAtextmode
.type VGAtextmode, @function
VGAtextmode:
  lw   t0,IO_VGA_CMD(gp)
  andi t0,t0,0b11111101 # Solo bit 1 se hace cero, los demas no cambian
  sb   t0,IO_VGA_CMD(gp)
  ret

.global VGAcolormode
.type VGAcolormode, @function
VGAcolormode:
  lw   t0,IO_VGA_CMD(gp)
  ori  t0,t0,2     # Solo bit 1 se hace uno, los demas no cambian
  sb   t0,IO_VGA_CMD(gp)
  ret

.global VGAActivate
.type VGAActivate, @function
VGAActivate:
  lw   t0,IO_VGA_CMD(gp)
  ori  t0,t0,1 # Hace uno solo el bit 10
  sw   t0,IO_VGA_CMD(gp)
  ret
.global VGADeactivate
.type VGADeactivate, @function
VGADeactivate:
  lw   t0,IO_VGA_CMD(gp)
  andi t0,t0,0b11111110 # Hace cero solo el bit 0
  sb   t0,IO_VGA_CMD(gp)
  ret

.global PrintInVGA
.type PrintInVGA, @function
# Recibe a0: Dato a guardar (solo byte menos significativo)
#        a1: posicion x de la pantalla del (0-79)
#        a2: posicion y de la pantalla del (0-59)
# Entrega a0=-1 si esta ocurre un error.
PrintInVGA:
  addi sp,sp,-4
  sw   s0,0(sp)

  # Se asume que este ambos valores estan dentro del rango
  sll  t0,a2,4 # a2<<4 === 16*a2
  sll  t1,a2,6 # a2<<6 === 64*a2
  add  s0,t0,t1 # 80*a2 === 80*posy
  add  s0,s0,a1 # a1+80*a2 === posx + 80*posy
  lui  t2,2 #t2 <- 0x0000_2000
  add  s0,s0,t2 # 
  add  s0,s0,gp # 0x8000_2000 + posx + 80*posy
  sb   a0,0(s0)

  lw   s0,0(sp)
  addi sp,sp,4
  ret

.global VGAClean
.type VGAClean, @function
VGAClean:
  li a0,0
  # j VGAPaintAll

.global VGAPaintAll
.type VGAPaintAll, @function
# a0: Recibe el color al cual se imprimira
VGAPaintAll:
  addi sp,sp,-4
  sw   s0,0(sp)

  lui  s0,0x2
  add  s0,s0,gp
  li   t1,0x1400
  add  t1,t1,s0 #0x8000_3400
.VGAPaintAllloop: # Itera en cada dato de 32 bits del framebuffer
  sb   a0,0(s0)
  sb   a0,1(s0)
  sb   a0,2(s0)
  sb   a0,3(s0)
  addi s0,s0,4
  blt  s0,t1,.VGAPaintAllloop # s0 < t1

  lw   s0,0(sp)
  addi sp,sp,4
  ret

# Recibe a0: Color del marco
# Recibe a1: Color del resto
DibujaMarco:
  addi sp,sp,-16
  sw   ra,0(sp)
  sw   s0,4(sp)
  sw   s1,8(sp)
  sw   s2,12(sp)

  lui  s2,2 #s2 <- 0x0000_2000
  add  s2,gp,s2 # direccion del framebuffer
  li   s1,0  # posy
  li   s0,0  # posx

  li   t0,79
  li   t1,59
  li   t2,4800
DibujarMarco_Loop:
  # si posx==0 o posx==79 o posy==0 o posy==59 pintar de marco
  beq  s0, zero, DibujarMarco_marco
  beq  s1, zero, DibujarMarco_marco
  beq  s0, t0, DibujarMarco_marco
  beq  s1, t1, DibujarMarco_marco
  
  #pintar fondo
  sb   a1,0(s2)
  j    DibujarMarco_incX
DibujarMarco_marco:
  #slt  t0,s0, # Si s1 == 0 o s1 == 59 o s0 == 0 o s0 == 79
  sb   a0,0(s2) # pintamos
DibujarMarco_incX:
  addi s2,s2,1 # incrementamos puntero del framebuffer
  beq  s2,t2,DibujarMarco_Fin
  bge  s0,t0,DibujarMarco_incY # si posx >= 79 => posx=0 y posy++
  # si es menor
  addi s0,s0,1 # posx++
  j DibujarMarco_Loop
DibujarMarco_incY:
  beq  s1,t1,DibujarMarco_Fin # Si

  li s0,0 # reiniciar cero
  addi s1,s1,1 # posy++
  j DibujarMarco_Loop
DibujarMarco_Fin:
  lw   s2,12(sp)
  lw   s1,8(sp)
  lw   s0,4(sp)
  lw   ra,0(sp)
  addi sp,sp,16
  ret

