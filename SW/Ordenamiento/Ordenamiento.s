.equ MAX,11
.data
	.align 2
	
arreglo:
	.word 3,10,1,8,15,5,12,6,5,4,9


.text
	.globl main
#--------------------------------------------------------------------------
	main:
	# Primero inicializamos 10 numeros en el arreglo
	la t0,arreglo
	li t1,3
	sw t1,0(t0)
	li t1,10
	sw t1,4(t0)
	li t1,1
	sw t1,8(t0)
	li t1,8
	sw t1,12(t0)
	li t1,15
	sw t1,16(t0)
	li t1,5
	sw t1,20(t0)
	li t1,12
	sw t1,24(t0)
	li t1,6
	sw t1,28(t0)
	li t1,5
	sw t1,32(t0)
	li t1,4
	sw t1,36(t0)
	li t1,-9
	sw t1,0(t0)

	# first -> s1
	# last  -> s2
		# jal    imprimearreglo # last = imprimirarreglo()

		add  s1,zero,zero # first = 0
		li   s2,(MAX-1) # last = 11

		la 	 a0,arreglo
		mv   a1,s1
		mv   a2,s2
		jal  SortArray
	
		# printf("\n\nArreglo ordenado \n\n")
		# addi 	$v0,$zero,4
		# la 	$a0,MensajeMain
		# syscall

	
		# fin del programa
		li	a0,0
		ret
#-----------------------------------------------------------------------
	# # Funcion que muestra en pantalla el contenido de un arreglo
	# imprimearreglo:
	# 	addi sp,sp,-4
	# 	sw   s0,0(sp)	
	# 	# s0 <= i
	# 	li s0,0 # i = 0
	# 	mv t0,a0	 # t2 = arreglo
	# for_imp:
	# 	slti t1,s0,MAX		 # t0 = 1 si i < 11, sino 0
	# 	beq	 t1,zero,for_imp_salida # sale del ciclo si t0 == 0 (i>=11)

	# 	# addi $v0,$zero,1	# Escribe
	# 	sll	t1,s0,2 	# t1 = 4*s0 = 4*i
	# 	add	t1,t0,t1	# t1 = &arreglo[i]
	# 	lw	a0,0(t1)	# a0 = arreglo[i]
	# 	# fin printf() --------------------
		
	# 	addi s0,s0,1	# i++
	# 	j    for_imp
	# for_imp_salida:
	
	# 	lw   s0,0(sp)
	# 	addi sp,sp,4
	# 	ret
#-----------------------------------------------------------------------
	# Funcion que ordenara el arreglo con ordenamiento tipo burbuja
	SortArray:
	# i -> s0
	# j -> s1
	# p -> s2
	# t -> s3
	# arreglo -> a0 -> s4
	# first   -> a1 -> s5
	# last    -> a2 -> s6
	# los 3 registros a se guardaran en los registros s porque esta funcion es recursiva
	# por lo cual es necesario que se recuperen al final de la funcion
	# por ello, se operarán a través de los registros
		addi	sp,sp,-32
		sw 	s0,0(sp)
		sw 	s1,4(sp)
		sw 	s2,8(sp)
		sw 	s3,12(sp)
		sw 	s4,16(sp)
		sw 	s5,20(sp)
		sw 	s6,24(sp)
		sw 	ra,28(sp)
		
		add	s4,a0,zero # los argumentos se guardaran en los registros s
		add	s5,a1,zero
		add	s6,a2,zero
		
		add 	s0,zero,s5	# i = first
		add 	s1,zero,s6	# j = last
	
		# 4 *(first+last)/2
		add	t0, s5, s6	# first+last
		srli t0, t0, 1 # entero de (first+last)/2
		
		slli t0,t0,2 	# se multiplican por 4 (tamaño del tipo de dato)
		add	t0,t0,s4	# $t0 =  & arreglo[(first+last)/2]
		lw	s2,0(t0)	# p = arreglo[(first+last)/2]
						
	DO_WHILE:
		WHILE1: #while(arreglo[i] < p) i++;
		sll	t0,s0,2	# Se obtendra 4*i
		add	t0,s4,t0	# t0 = arreglo + (4)*i  
		lw	t1,0(t0)	# t1 = arreglo[i]
		slt	t1,t1,s2	# $t1 = arreglo[i] < p
		beq	t1,zero,WHILE2 # si arreglo[i]>=p se sale del ciclo
		addi s0,s0,1	# i++
		j	WHILE1
		WHILE2: #while(p<arreglo[j]) j--;
	# final de while1 comienzo de while2, no hay instrucciones de por medio
		sll	t0,s1,2	# 4*j
		add	t0,s4,t0	# t0 = & arreglo[j]
		lw	t1,0(t0)	# t1 = arreglo[j]
		slt	t1,s2,t1	# t1 = p < arreglo[j]
		beq	t1,zero,END_WHILE # branch a END_WHILE si t1 = 0
		addi s1,s1,-1	# j--
		j	WHILE2
		
		END_WHILE: #Comienzo IF_1
		slt	t0,s1,s0	# t0 = i > j (1 se sale del IF)
		bne	t0,zero,END_IF_1
	# Se intercambian los elementos i-esimo y j-esimo del arreglo
		# La direccion de arreglo[i] se guarda en $t1
		# obtener arreglo[i]
		sll	t1,s0,2
		add	t1,t1,s4
		lw	s3,0(t1) # arreglo[i] se guarda en t (registro $s3)
		# La direccion de arreglo[i] se guarda en $t2
		#obtener arreglo[j]
		sll	t2,s1,2
		add	t2,t2,s4
		lw	t3,0(t2) # arreglo[j]se guarda en el registro $t3

		sw	t3,0(t1) # arreglo[i] = $t3 = arreglo[j]
		sw	s3,0(t2) # arreglo[j] = t
		
		addi s0,s0,1
		addi s1,s1,-1
		
		END_IF_1:
		slt	t0,s1,s0	# t0 = j<i (Si es cero, continua en el do_while)
		beq	t0,zero,DO_WHILE #

	END_DO_WHILE: #Y tambien comienzo IF_2
		slt  t0,s5,s1 	# Si first < j t0 = 1
		beq  t0,zero,END_IF_2 # si t0 = 0, no hay if
		or	 a0,s4,zero	# a0 no se altera
		add	 a1,s5,zero	# a1 no se altera
		add	 a2,s1,zero	# a2 es j
		jal	 SortArray #SortArray(arreglo,first,j)
	
	END_IF_2: #Comienzo del IF_3
		slt	t0,s0,s6 	# Si i < last, t0 = 1
		beq	t0,zero,END_IF_3 # si t0 = 1
		or	s4,s4,zero	# a0 no se altera
		add	a1,s0,zero 	# a1 es i
		add	a2,s6,zero 	# a2 no se altera (last)
		jal	SortArray #SortArray(arreglo,i,last)
	
	END_IF_3: #fin del IF_3	
		lw 	s0,0(sp)
		lw 	s1,4(sp)
		lw 	s2,8(sp)
		lw 	s3,12(sp)
		lw 	s4,16(sp)
		lw 	s5,20(sp)
		lw 	s6,24(sp)
		lw 	ra,28(sp)
		addi sp,sp,32
		# fin de la funcion
		addi a0,a0,12
		ret


#Fin del programa
