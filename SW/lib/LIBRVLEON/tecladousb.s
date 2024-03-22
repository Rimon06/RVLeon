# Teclado
.include "RVLEONLib.inc"
.include "RVLEONKEYS.inc"
.data
.align 2
teclas: .byte 0,0,0,0,0
.align 2
special: .word 0
.text

.globl conectado_teclado_usb
.type conectado_teclado_usb,@function
conectado_teclado_usb:
	lw t0,IO_KBRD_status(gp)
	li a0,1
	andi t0,t0,0b1
	bne t0,zero,conectado_teclado_usb_fin
	li a0,0
conectado_teclado_usb_fin:
	ret

.globl init_teclado
.type init_teclado,@function
init_teclado:
	addi sp,sp,-4
	sw   ra,0(sp)
init_teclado_wait:
	jal conectado_teclado_usb
	beq a0,zero,init_teclado_fin

	la t0, teclas # inicializamos tec / special
	sw zero,0(t0)
	la t0,special
	sb zero,0(t0) # special

	li a0,1
init_teclado_fin:
	lw   ra,0(sp)
	addi sp,sp,4
	ret

.globl leer_teclado_usb
.type leer_teclado_usb,@function
leer_teclado_usb:
	addi sp,sp,-12
	sw   ra,0(sp)
	sw   s0,4(sp)
	sw   s1,8(sp)

	lw   s0, IO_KBRD_status(gp)
	lbu  t0, IO_KBRD_key0(gp) # Obtenemos todos los caraceres
	lbu  t1, IO_KBRD_key1(gp)
	lbu  t2, IO_KBRD_key2(gp)
	lbu  t3, IO_KBRD_key3(gp)
	srl  s0,s0,8 # Obtenemos los caracteres especiales
	la   s1,teclas # Obtengo los valores anteriores de las teclas...
	lbu  t4,0(s1)
	lbu  a1,1(s1)
	lbu  a2,2(s1)
	lbu  a3,3(s1)
	li   a0,0
leerkey0:
	# Si key0 != 0 && key0 != key0Anterior && key0 != key1Anterior && ...
	beq t0,zero, leerkey1 
	beq t0,t4,   leerkey1
	beq t0,a1,   leerkey1
	beq t0,a2,   leerkey1
	beq t0,a3,   leerkey1

	mv  a0,t0 # se utiliza t0=key0

	j finleertecla
leerkey1:
	# Si key1 != 0 && key1 != key0Anterior && key1 != key1Anterior ...
	beq t1,zero, leerkey2
	beq t1,t4,   leerkey2
	beq t1,a1,   leerkey2
	beq t1,a2,   leerkey2
	beq t1,a3,   leerkey2

	mv a0,t1 # se utiliza a key1
	j finleertecla
leerkey2:
	# Si key2 != 0 && key2 != key0Anterior && key1 != key1Anterior ...
	beq t2,zero, leerkey3
	beq t2,t4,   leerkey3
	beq t2,a1,   leerkey3
	beq t2,a2,   leerkey3
	beq t2,a3,   leerkey3

	mv a0,t2	
	j finleertecla # Se utiliza key2
leerkey3:
	# Si key3 != 0 && key3 != key0Anterior && key3 != key1Anterior ...
	beq t3,zero, finleertecla
	beq t3,t4,   finleertecla
	beq t3,a1,   finleertecla
	beq t3,a2,   finleertecla
	beq t3,a3,   finleertecla

	mv a0,t3	
	j finleertecla # Se utiliza key3

finleertecla:
	# Actualiza valores anteriores...
	sb   t0,0(s1)
	sb   t1,1(s1)
	sb   t2,2(s1)
	sb   t3,3(s1)
	la   s1,special
	sw   s0,0(s1)

	# Ahora, llamamos a la funcion de tabla
	# El valor de a0 se obtuvo anteriormente... 
	mv   a1,s0 # Obtenemos los bits especiales
	jal  ScancodeToAscii
	# 
	lw   s1,8(sp)
	lw   s0,4(sp)
	lw	 ra,0(sp)
	addi sp,sp,12

	ret

.globl TeclaUSBPresionada
.type TeclaUSBPresionada,@function
# a0: constante Scancode basado en RVLEONKEYS.inc
# retorna el byte index-0 en el que se ubica, o -1 si es cero...
TeclaUSBPresionada:
	la t0,teclas
	li t5,0
TeclaUSBPresionada_loop:
	lbu t1,0(t0)
	addi t0,t0,1 # t1 = *(teclas++)
	beq t1,zero,TeclaUSBPresionada_no # t1 != 0
	beq t1,a0,TeclaUSBPresionada_si   # t1 != a0

	addi t5,t5,1 # incrementamos t5
	j TeclaUSBPresionada_loop
TeclaUSBPresionada_si:
	mv a0,t5
	j TeclaUSB_fin

TeclaUSBPresionada_no:
	li a0,-1
TeclaUSB_fin:
	ret

.globl ModifierUSBPresionado
.type ModifierUSBPresionado,@function
# a0: bit del modificador que se desea saber. Constante ubicada en RVLEONKEYS
# Entrega 0 si no está presionado el modifcador y 1 en caso de que si
ModifierUSBPresionado:
	la   t0,special
	lbu  t1,0(t0)
	and  t1,a0,t1 
	sltu a0,zero,t1
	ret

.globl ScancodeToAscii
.type ScancodeToAscii,@function
# a0: scancode
# a1: modificadores. shift, alt,supr,
ScancodeToAscii:
	addi sp,sp,-4
	sw   ra,0(sp)
	andi t0,a1,0b00100010 # Comprobar que solo estan shift activados
	# Si  a0 >= 4 y a0<=29
	li   t1,4
	blt  a0,t1,endNoAscii # a0 < 4 salir
	li   t2,30 
	bge  a0,t2,else_otros_caracteres # a0 >= 30 ir al else
	# entonces, si hay modificadores
	beq  t0,zero,letras_no_MAYUS
	addi a0,a0,61 # a0 <- a0-4+65
	j    endScancodeToAscii
letras_no_MAYUS:
	# sino, en caso que no hay modificadores:
	addi a0,a0,93 # a0<- a0-4+97
	j endScancodeToAscii
else_otros_caracteres:
	# sino, 
	# si a0 es menor de 57 entonces:
	li t1,57
	bge a0,t1,endNoAscii # Terminar operacion, scancode a secas
	#  sino. Obtenemos offset codigo entre 30 y 57 (multiplicamos por 4 bytes y por 2 instrucciones)
	addi t2,a0,-30 # Restamos 30. # Esto para la tabla
	sll t2,t2,3 # multiplicamos por 8
	bne t0,zero,otros_caracteres_shift

	la t1,ScancodeTabla1 # Buscamos la direccion de ScancodeTabla1
	add t1,t1,t2
	jalr t1 # y saltamos a ScancodeTabla1 + OFFSET

otros_caracteres_shift:
	la t1,ScancodeTabla2 # Buscamos la direccion de ScancodeTabla2
	add t1,t1,t2
	jalr t1 # y saltamos a ScancodeTabla2 + OFFSET
endNoAscii:
	li a0,0
endScancodeToAscii:
	lw   ra,0(sp)
	addi sp,sp,4
	ret
############# TABLA ############################
ScancodeTabla1: # Teclado Ingles. (TODO) Colocar un IFDEF aca para separar teclado ingles del español
	li a0,'1' # 30
	j endScancodeToAscii
	li a0,'2' # 31
	j endScancodeToAscii
	li a0,'3' # 32
	j endScancodeToAscii
	li a0,'4' # 33
	j endScancodeToAscii
	li a0,'5' # 34
	j endScancodeToAscii
	li a0,'6' # 35
	j endScancodeToAscii
	li a0,'7' # 36
	j endScancodeToAscii
	li a0,'8' # 37
	j endScancodeToAscii
	li a0,'9' # 38
	j endScancodeToAscii
	li a0,'0' # 39
	j endScancodeToAscii
	li a0,'\n'# 40  # enter codigo 10
	j endScancodeToAscii
	li a0,27  # 41  # esc
	j endScancodeToAscii
	li a0,8   # 42  # backspace
	j endScancodeToAscii
	li a0,9   # 43  # tab
	j endScancodeToAscii
	li a0,' ' # 44  # space
	j endScancodeToAscii
	li a0,'-' # 45
	j endScancodeToAscii
	li a0,'=' # 46
	j endScancodeToAscii
	li a0,'[' # 47
	j endScancodeToAscii
	li a0,']' # 48
	j endScancodeToAscii
	li a0,'\\'# 49
	j endScancodeToAscii
	li a0,'#' # 50
	j endScancodeToAscii
	li a0,';' # 51
	j endScancodeToAscii
	li a0,'\''# 52
	j endScancodeToAscii
	li a0,'`' # 53
	j endScancodeToAscii
	li a0,',' # 54
	j endScancodeToAscii
	li a0,'.' # 55
	j endScancodeToAscii
	li a0,'/' # 56
	j endScancodeToAscii
ScancodeTabla2:
	li a0,'!' # 30
	j endScancodeToAscii
	li a0,'@' # 31
	j endScancodeToAscii
	li a0,'#' # 32
	j endScancodeToAscii
	li a0,'$' # 33
	j endScancodeToAscii
	li a0,'%' # 34
	j endScancodeToAscii
	li a0,'^' # 35
	j endScancodeToAscii
	li a0,'&' # 36
	j endScancodeToAscii
	li a0,'*' # 37
	j endScancodeToAscii
	li a0,'(' # 38
	j endScancodeToAscii
	li a0,')' # 39
	j endScancodeToAscii
	li a0,'\n'# 40  # enter
	j endScancodeToAscii
	li a0,27  # 41  # esc
	j endScancodeToAscii
	li a0,8   # 42  # backspace
	j endScancodeToAscii
	li a0,9   # 43  # tab
	j endScancodeToAscii
	li a0,' ' # 44  # space
	j endScancodeToAscii
	li a0,'_' # 45
	j endScancodeToAscii
	li a0,'+' # 46
	j endScancodeToAscii
	li a0,'{' # 47
	j endScancodeToAscii
	li a0,'}' # 48
	j endScancodeToAscii
	li a0,'|'# 49
	j endScancodeToAscii
	li a0,'~' # 50
	j endScancodeToAscii
	li a0,':' # 51
	j endScancodeToAscii
	li a0,'\"'# 52
	j endScancodeToAscii
	li a0,'~' # 53
	j endScancodeToAscii
	li a0,'<' # 54
	j endScancodeToAscii
	li a0,'>' # 55
	j endScancodeToAscii
	li a0,'?' # 56
	j endScancodeToAscii


