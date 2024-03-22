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

  call VGAcolormode # Activamos VGA
  call VGAActivate

InfiniteLoop:
  li t0,-1
  sw t0,IO_LEDS(gp) # Aviso de raton desconectado
  
  call init_mouse # Esperamos hasta que un mouse se conecte

  sw zero,IO_LEDS(gp) # Apagamos Matriz Led
loop1:  
  li a0,0xff        # Pintamos la pantalla en 'blanco'
  call VGAPaintAll 
  # Encima de esto, pintamos la posicion del raton
  # Crear Funcion que Dada la posicion x,y del raton, imprima en pantalla un color dentro del rango de la pantalla
loop1_5:
  li a0,0x33 # Amarillo... creo.
  call RatonEnPantalla # Esta funcion llama internamente a la lectura de la posicion del raton x,y (actualizando el valor)
  # Se imprime la posicion actual del raton
loop2:

  call MouseLeftButton # Entrega estado del boton izquierdo
  beq a0,zero,loop2_end

  li a0,0xc0 # Mientras el boton izquierdo esté presionado. Se pinta la pantalla en la posicion del raton
  call RatonEnPantalla

  j loop2
loop2_end:
  call MouseRightButton
  beq a0,zero,seguirloop1
  # Si se presiona el boton derecho, se reinicia el puntero...
  # li a0,0xff        # Pintamos la pantalla en 'blanco'
  # call VGAPaintAll 
  j loop1
  li a0,0 
  call EscribirMouseX
  
  li a0,0
  call EscribirMouseY
  # sino, sigue
seguirloop1:
  li a0,25000
  call microwait
  call conectado_mouse_USB # Si se revisa el estado del raton
  bne a0,zero,loop1_5 # Si sigue conectado, seguimos escribiendo

  # sino, retornamos al InfiniteLoop
  li a0,0xc0        # Pintamos la pantalla
  call VGAPaintAll 
  li a0,900000 # Esperamos 0.9 segundos
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
  call refresh_mouse

  call LeerMouseX  # a0 entre -1024 a 1023
  addi s0,a0,1024 # Se Suma el offset... 0 a 2047 ....
  srli s0,s0,4 # Se desplazan 4 bits a la derecha 
 # andi s0,s0,0x7f
  li   t0,80
  bltu s0,t0,continuarMouseX
  li   s0,79
continuarMouseX:
  
  call LeerMouseY # a0 entre -1024 a 1023
  addi s1,a0,1024 # Ahora entre 0 a 2047 
  srli s1,s1,5 # Se desplazan 5 bits (y va de 0 a 59)
  sw   s1,IO_LEDS(gp)
 # andi s1,s1,0x3f
  li   t0,60
  bltu s1,t0,continuarMouseY
  li   s1,59

continuarMouseY:
  # Luego de obtener los nuevos valores, ahora se imprime un pixel en VGA
  lw   a0,12(sp) # Color
  mv   a1,s0     # X
  mv   a2,s1     # Y
  call PrintInVGA

  # No se recupera a0...
  lw   s1,8(sp)
  lw   s0,4(sp)
  lw   ra,0(sp)
  addi sp,sp,16
  ret