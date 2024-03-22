// interfaz_mem.v

/* StoretoMEM (.addr_LSB(),.data(),.memWrite(),.data_width(),.wr_datatoMem(),.mask_data());
*/
module StoretoMEM (//********************************************************************
  // Entradas de Store
  input [1:0] addr_LSB, // 2 bits menos significativo de la direccion
  input [31:0] data, // Data to save!
  // entrada de control
  input memWrite, // señal de control que permite escribir en memoria!
  input [1:0] data_width, // 00: byte; 01:half-word; 10:word
  // salidas a la memoria!
  output [31:0] wr_datatoMem,
  output [3:0] mask_data
);//*************************************************************************************

  wire [3:0] mask;
  assign mask_data = {4{memWrite}} & mask; 
  wire [1:0] LSB = data_width[1]? 2'b0 : addr_LSB; // Asegura que lw guarde 
  
  //--- Bloque de alineacion: se revisa si se guarda byte, half-w o word, y el dato de entrada se alinea
  //    al byte/half-word correspondiente a los dos bits menos significativos de address. mask indica cual
  //    de los 4 bytes se realiza la operacion de escritura.
  assign  wr_datatoMem[ 7: 0] = data[7:0];
  assign  wr_datatoMem[15: 8] = LSB[0] ? data[7:0]  : data[15: 8];
  assign  wr_datatoMem[23:16] = LSB[1] ? data[7:0]  : data[23:16];

  assign  wr_datatoMem[31:24] = LSB[0] ? data[7:0]  :
                                LSB[1] ? data[15:8] : data[31:24];
  //--- Mascara
  assign mask = (data_width[1])? 4'b1111   
              : (data_width[0])?
                  (addr_LSB[1]? 4'b1100 : 4'b0011)
              :   (addr_LSB[1]? (addr_LSB[0] ? 4'b1000 : 4'b0100) 
                              : (addr_LSB[0] ? 4'b0010 : 4'b0001));

endmodule

/* StoretoMEM (.addr_LSB(),.data_mem(),.data_width(),.sin_signo(),.data_readed());
*/
module LoadfromMEM(//***************************************************************
  // entradas
  input [1:0] addr_LSB, // 2 bits menos significativo de la direccion
  input [31:0] data_mem, // dato proveniente de la memoria
  // control
  input [1:0] data_width, // 00: byte; 01:half-word; 10:word
  input sin_signo, // indica si el dato cargado debe extenderse con cero o con signo
  // salida al procesador
  output [31:0] data_readed // dato alineado, hacia el procesador
);//********************************************************************************

  //--- Decodificando data_byte y data_half addr para lb/lbu y lh/lhu!
  wire  [7:0] data_byte;
  wire [15:0] data_half;
  assign data_half = addr_LSB[1] ? data_mem[31:16] : data_mem[15:0];
  assign data_byte = addr_LSB[0] ? data_half[15:8] : data_half[7:0]; 

  //--- señal que extiende el signo para byte o half-word
  wire signo_byte,signo_half;
  assign signo_byte = (sin_signo) ? 0 :  data_byte[7];
  assign signo_half = (sin_signo) ? 0 : data_half[15];

  //--- Bloque multiplexor final, dependiendo del tamaño del dato, y si debe extenderse con signo o no,
  //    el dato de la memoria se ajusta para ser recibido por el procesador
  assign data_readed = (data_width[1])? data_mem
                     : (data_width[0])? {{16{signo_half}},data_half}
                     : {{24{signo_byte}},data_byte};

endmodule