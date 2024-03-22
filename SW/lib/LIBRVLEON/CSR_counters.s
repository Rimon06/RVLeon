
.text

.global LeerCiclos
.type LeerCiclos, @function
# Recibe: nada
# Entrega: a1,a0 - cycle 64 bits. Numero de ciclos de reloj en ejecucion
LeerCiclos:
    rdcycleh t0
    rdcycle  a0
    rdcycleh a1
    bne      a1,t0,LeerCiclos # Si ocurre over
    ret
.global LeerTiempo
.type LeerTiempo, @function
# Recibe: nada
# Entrega: a1,a0 - time 64 bits. Tiempo de ejecucion en Ciclos de 12MHz
LeerTiempo:
    rdtimeh t0
    rdtime  a0
    rdtimeh a1
    bne     a1,t0,LeerCiclos # Si ocurre over
    ret

.global LeerInstrRet
.type LeerInstrRet, @function
# Recibe: nada
# Entrega: a1,a0 - instret 64 bits. Numero de instrucciones ejecutadas.
LeerInstrRet:
    rdinstreth t0
    rdinstret  a0
    rdinstreth a1
    bne        a1,t0,LeerCiclos # Si ocurre over
    ret
