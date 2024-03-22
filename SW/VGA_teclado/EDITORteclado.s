# Programa de prueba del raton

.include "RVLEONLib.inc"

.data

.text

.globl main
.type main,@function

.macro VGAWriteChar char, x, y
  li   a0,\char
  li   a1,\x
  li   a2,\y
  jal  PrintInVGA
.endm

main:
  # la s0,pos_act
  # sb zero,0(s0) # posx = 0
  # sb zero,1(s0) # posy = 0

  call VGAtextmode # Activamos VGA
  call VGAActivate
  call VGAClean
InfiniteLoop:
  li t0,-1
  sw t0,IO_LEDS(gp) # Aviso de Teclado desconectado
  li s0,0 # caracter
  li s1,0 # posicion x
  li s2,0 # posixion y
EsperarConexion:
  call init_teclado # Conecta mouse
  beq a0,zero,EsperarConexion

  sw zero,IO_LEDS(gp) # Apagamos Matriz Led

loop1:
  call leer_teclado_usb 
  mv s0,a0
  sw s0,IO_LEDS(gp)
  beq a0,zero,seguirloop1
  li t1,'\n'
  beq a0,t1,SaltoDeLinea
  li t1,8
  beq a0,t1,Retroceder
  # Caso de caracter legible...
  #Imprimir en posicion inicial x,y (s1,s2)
  mv a0,s0
  mv a1,s1
  mv a2,s2
  call PrintInVGA
  li t0,80
  addi s1,s1,1
  beq s1,t0,SaltoDeLinea
  j seguirloop1

SaltoDeLinea: # En un salto de linea, incrementa s2
  li s1,0
  li t0,60
  addi s2,s2,1
  bne s2,t0,seguirloop1
  li s2,0
  #
  j seguirloop1 
  #nop
Retroceder:
  addi s1,s1,-1 # Si se presiona retroceder, retrocede un espacio en x
  bge  s1,zero,SeguirRetroceder # Si x es menor que cero, entonces 
  li   s1,79 # se establece s1 a x, 
  addi s2,s2,-1 # y retrocede un espacio
  bge  s2,zero,SeguirRetroceder # Si y es menor que cero
  li   s2,59 # Se establece y=59...
 
SeguirRetroceder: # Ademas, si se presiona retroceder,
  li a0,0 # La casilla anterior queda en blanco para su escritura
  mv a1,s1
  mv a2,s2
  call PrintInVGA

seguirloop1:
  li a0,90000 # Se esperan ~250ms...
  call microwait
  call conectado_teclado_usb # Si se revisa el estado del raton
  bne a0,zero,loop1 # Si sigue conectado, seguimos escribiendo
  
  # sino, retornamos al InfiniteLoop
   
  li a0,90000 # Esperamos 0.9 segundos
  call microwait
  li a0,0xff # La 'borramos' a su estado inicial
  call VGAPaintAll

  j InfiniteLoop

  li a0,0
  call exit

.type RatonEnPantalla,@function
RatonEnPantalla:
  addi sp,sp,-16
  sw   ra,0(sp)
  sw   s0,4(sp)
  sw   s1,8(sp)
  sw   a0,12(sp)
  call refresh_mouse # No usa a0
  # sw a0,IO_LEDS(gp)

  call LeerMouseX  # a0 entre -1024 a 1023
  addi s0,a0,1024 # Se Suma el offset... 0 a 2047 ....
  srli s0,s0,4 # Se desplazan 6 bits a la derecha 
 # andi s0,s0,0x7f
  li   t0,80
  bltu s0,t0,continuarMouseX
  li   s0,79
continuarMouseX:
  
  call LeerMouseY # a0 entre -1024 a 1023
  addi s1,a0,1024 # Ahora entre 0 a 2047 
  srli s1,s1,5 # Se desplazan 7 bits (y va de 0 a 59)
  sw   s1,IO_LEDS(gp)
 # andi s1,s1,0x3f
  li   t0,60
  bltu s1,t0,continuarMouseY
  li   s1,59

continuarMouseY:
  # Luego de obtener los nuevos valores, ahora se imprime un pixel en VGA
  lw   a0,12(sp)
  mv   a1,s0
  mv   a2,s1
  call PrintInVGA

  # No se recupera a0...
  lw   s1,8(sp)
  lw   s0,4(sp)
  lw   ra,0(sp)
  addi sp,sp,16
  ret
  nop
  nop