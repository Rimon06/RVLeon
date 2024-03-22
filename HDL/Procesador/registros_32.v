// registros_32.v

/* registros(.clk,.wr_ena,.rd_reg1,.rd_reg2,.reg1,.reg2,.wr_reg,.wr_data);
*
* El modulo de registros tiene dos puertos de lectura y uno de escritura.
* Cada puerto de lectura es direccionado con el valor de su respectivo rd_reg
* El puerto de escritura se habilita con wr_ena y guarda el valor de wr_data en el registro direccionado con wr_reg.
*
*/
module registros (
  input clk, // reloj
  input rst,
  // control
  input wr_ena, // habilitacion de escritura
  // lectura
  input [4:0] readReg1,  // Direccion de registro fuente 1
  input Reg1Zero,
  input [4:0] readReg2,  // Direccion de registro fuente 2
  input Reg2Zero,
  output [31:0] reg1,   // Registro 2
  output [31:0] reg2,   // Registro 2
  // escritura
  input [4:0] wr_reg,   // Direccion de registro destino
  input [31:0] wr_data // Dato a ser escrito en el destino
);

  (* ram_style = "logic" *)
  reg [31:0] WORKREG [31:0]; // Definicion de los registros de trabajo
  integer i;

  //--- lectura de registro fuente 1
  assign reg1 = WORKREG[readReg1];//
  //--- lectura de registro fuente 2
  assign reg2 = WORKREG[readReg2];//

  //--- Escritura
  always @(negedge clk) // Escribe siempre en flanco de subida
    if (rst)
      for(i=0;i<32;i=i+1) begin
        WORKREG[i] <= 32'b0;
    end else 
    if (wr_ena) // Si la habilitacion de escritura esta habilitada y la direccion de escritura no es 0
      WORKREG[wr_reg] <= wr_data;

endmodule