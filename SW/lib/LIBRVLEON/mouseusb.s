
.include "RVLEONLib.inc"

.section .data
.align 2
mouse_x:   .word 0 #.skip 4 # va de -1024 a 1023
mouse_y:   .word 0 #.skip 4 # va de -1024 a 1023
mouse_btn: .word 0 #.skip 4 # Solo los 3 bits menos significativos importan

.text

.globl conectado_mouse_USB
.type conectado_mouse_USB, @function
# Retorna a0 <- 0 Si raton no ha sido conectado, 1 si se conecto
conectado_mouse_USB:
	lw t0,IO_mouse_status(gp)
	li a0,1
	andi t0,t0,0b1
	bne t0,zero,conectado_mouse_USB_fin
	li a0,0
conectado_mouse_USB_fin:
	ret

.globl init_mouse
.type init_mouse, @function
init_mouse:
	addi sp,sp,-4
	sw	 ra,0(sp)

	la   t0,mouse_x # todas las variables se establecen a cero.
	la   t1,mouse_y
	la   t2,mouse_btn
	sw   zero,0(t0)
	sw   zero,0(t1)
	sw   zero,0(t2)

init_mouse_wait: # Esperamos en un bucle hasta que un raton se conecta
	jal  conectado_mouse_USB 
	beq  a0,zero,init_mouse_wait # Continua luego de que a0 == 0

	lw	 ra,0(sp)
	addi sp,sp,4
	ret

################################################################################
# Funcion para actualizar las variables del mouse (tanto x,y y los tres botones)
################################################################################
.globl refresh_mouse
.type refresh_mouse, @function
# retorna bool: si cero, entonces no cambio el mouse. Uno, el mouse cambio.
refresh_mouse:
	addi sp,sp,-20
	sw   ra,0(sp)
	sw   s0,4(sp)
	sw   s1,8(sp)
	sw   s2,12(sp)
	sw   s3,16(sp)

	li 	 a0,0
	lw   t0,IO_mouse_status(gp) # Si report_no_readed = 0
	andi t0,t0,0b010
	beq  t0,zero, refresh_mouse_out # No se hace nada y termina la funcion
 #### Se lee el valor de dx, dy y los botones
	lw   t0,IO_mouse_data(gp) # Se leen todos los datos

	la   s0,mouse_x # Direccion de la posicion x del ratón
	la   s1,mouse_y # Direccion de la posicion y del raton
 #### Desglosamos cada valor por separado...	
	slli s2,t0,8 
	srai s2,s2,24 # Obtenemos dx extendido en signo
	
	srai s3,t0,24 # y tambien a dy extendido en signo
	
 #### Actualizamos los botones
	andi t1,t0,0b111 # Botones	
	la   t0,mouse_btn
	sw	 t1,0(t0) # guardamos estado

 #### Sumamos: x+dx. Si esta suma es < -1024 se establece -1024. Si es mayor a 1023, se establece a 1023
	# Mismo caso para y+dy. Pero primero x:
	lw   t2,0(s0) # Ahora, obtenemos la posicion x actual
	add  a0,t2,s2 # Sumamos (dx+x)
	
	jal  CorregirPosicionRaton
	sw   a0,0(s0)
	
 #### Repetimos para y: 
	lw   t3,0(s1) # Obtenemos la posicion y actual
	add  a0,t3,s3 # Sumamos (dy+y)
	jal  CorregirPosicionRaton
	sw	 a0,0(s1) # Guardamos el valor calculado en y 

 #### Retornamos 1, operacion de refrescado, realizada
	li 	 a0,1
refresh_mouse_out: 
	#sw a0,IO_LEDS(gp)
	lw   s3,16(sp)
	lw   s2,12(sp)
	lw   s1,8(sp)
	lw   s0,4(sp)
	lw   ra,0(sp)
	addi sp,sp,20

	ret 

.type CorregirPosicionRaton,@function
# Recibe a0 valor que debe corregirse
# Entrega a0 valor ajustado al rango [-1024,1023]
CorregirPosicionRaton:
	# si a0 < -1024 entonces a0 = -1024
	li   t4,-1024
	blt  t4,a0,CorregirPosicion_else
	mv   a0,t4 # a0 = - 1024
	j    Fin_CorregirPosicion
CorregirPosicion_else:
	# sino, si a0 > 1023 entonces a0 = 1023
	li   t4,1023
	blt  a0,t4,Fin_CorregirPosicion
	mv   a0,t4 # a0 = 1023
Fin_CorregirPosicion:
	# sino a0 se mantiene con el mismo valor
	ret

################################################################################
# Funciones de lectura de los botones del mouse
################################################################################
.macro SEL_BUTTON mask
	la   t0,mouse_btn
	lb   t1,0(t0)
	andi t1,t1,\mask
	slt a0,zero,t1 # devuelve a0=1 si 0<t1 (o sea, si t1 == 0 entonces cero)
.endm

.globl MouseMiddleButton
.type MouseMiddleButton, @function
MouseMiddleButton:
	SEL_BUTTON 0b100 
	ret

.globl MouseRightButton
.type MouseRightButton, @function
MouseRightButton:
	SEL_BUTTON 0b010
	ret

.globl MouseLeftButton
.type MouseLeftButton, @function
MouseLeftButton:
	SEL_BUTTON 0b001
	ret

################################################################################
# Lectura y escritura del valor actual de x y y
.globl LeerMouseX
.type LeerMouseX, @function
# Entrega en a0 el valor actual de mouse_x
LeerMouseX:
	la t0,mouse_x
	lw a0,0(t0)
	ret

.globl LeerMouseY
.type LeerMouseY, @function
# Entrega en a0 el valor actual de mouse_y
LeerMouseY:
	la t0,mouse_y
	lw a0,0(t0)
	ret

.globl EscribirMouseX
.type EscribirMouseX, @function
EscribirMouseX:
	addi sp,sp,-4
	lw   ra,0(sp)

	jal  CorregirPosicionRaton
	
	la 	 t0,mouse_x # Se corrije 
	sw   a0,0(t0)
	
	lw   ra,0(sp)
	addi sp,sp,4
	ret

.globl EscribirMouseY
.type EscribirMouseY, @function
EscribirMouseY:
	addi sp,sp,-4
	lw   ra,0(sp)

	jal  CorregirPosicionRaton
	
	la 	 t0,mouse_y
	sw   a0,0(t0)

	lw   ra,0(sp)
	addi sp,sp,4
	ret
################################################################################
