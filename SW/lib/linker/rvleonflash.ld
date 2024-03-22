ENTRY(_start)

MEMORY 
{
  ROM   (rx)  : ORIGIN = 0x01000000, LENGTH = 512K
  RAM   (rwx) : ORIGIN = 0x00000000, LENGTH = 0x1000 
}

  SECTIONS {
  	. = 0;
    .text : 
    {
      . = ALIGN(4);
      ../lib/START/start.o(.text)
      *(.text*)
      _etext = .;
    } > ROM

    . = 0;
    .data :{
    	*(.*data*);
      _ebss = .;
    } > RAM

   /* .bss : {
      *(.*bss *);
    }
  */
 }