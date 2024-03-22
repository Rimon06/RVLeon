# exit function: display exit code
# on LEDS, or spinning wheel if exit
# code is zero. 
.global milliwait
.type  milliwait, @function
milliwait:
  ret

.global microwait
.type microwait,@function
# Retardo para un reloj de 12MHz
# Recibe a0: numero de microsegundos, numero sin signo
# El retardo no es eficaz para menos de 10us
microwait:
  #sll t0,a0,2 # Multiplicando por 5
  add t0,a0,a0 # multiplicamos por 2
.loop_microwait:
  beq t0,zero,.out_microwait # while (t0-- != 0)
  addi t0,t0,-1
  j .loop_microwait 
.out_microwait:
  ret
