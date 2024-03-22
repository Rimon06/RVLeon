# Modulo del Puerto Serial
.include "RVLEONLib.inc"
.globl putc_
.type  putc_, @function
putc_:
.globl UART_putc
.type  UART_putc, @function
UART_putc:
  lbu  t1,IO_UART_TX_READY(gp)
  beqz t1,UART_putc
  sb   a0,IO_UART(gp)
  ret

.globl UART_getc
.type  UART_getc, @function
UART_getc:
	lbu t0,IO_UART_RX_leido(gp)
	beqz t0, UART_getc
	lbu a0,IO_UART(gp)
	ret
