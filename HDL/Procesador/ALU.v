// ALU.v

module ALU (
  //control
  input [3:0] ALUCtrl, // Control de operaciones de la ALU: {esp_fun, funcion} 
  // Entradas
  input [31:0] in1, // entrada 1,
  input [31:0] in2, // entrada 2
  //salida
  output reg [31:0] ALUout, // salida de la ALU
  output [31:0] ADDERout,
  // salida de control
  output reg branch // indica si ocurre o no un salto!
);
  function [31:0] flip32;
    input [31:0] x;
    flip32 = {x[ 0], x[ 1], x[ 2], x[ 3], x[ 4], x[ 5], x[ 6], x[ 7], 
              x[ 8], x[ 9], x[10], x[11], x[12], x[13], x[14], x[15], 
              x[16], x[17], x[18], x[19], x[20], x[21], x[22], x[23],
              x[24], x[25], x[26], x[27], x[28], x[29], x[30], x[31]};
   endfunction

  //--- Decodificacion del control dentro del ALU
  (* onehot *) wire [7:0] funcionIs;
  assign funcionIs = 8'b00000001 << ALUCtrl[2:0]; // Indica uno de los 8 casos de funct3 del opcode
  wire esp_fun = ALUCtrl[3]; // operacion especial de ADD (SUB) y de SLL (SRL/SRA)
 
  //--- Bloque de desplazamiento: realiza solo desplazamiento hacia la derecha (flip32 corrije este valor)
  wire [4:0] shamt = in2[4:0]; // shamt
  wire [31:0] shift_in = funcionIs[5] ? in1 : flip32(in1); // Valor de entrada del shift
  wire [31:0] shift_out = $signed( {esp_fun & (in1[31]), shift_in}) >>> shamt; // Valor de salida del shift

  //--- Bloque de resta y comparacion:
  wire [32:0] minus = {1'b0,in1} + ({1'b1, ~in2} + 33'b1); //in1 - in2
  wire  LT  = (in1[31] ^ in2[31]) ? in1[31] : minus[32];
  wire  LTU = minus[32];
  wire  EQ  = (minus[31:0] == 0);
  
  //--- Bloque de suma:
  assign ADDERout = in1+in2;

  //--- bloque de operaciones de la ALU: el resultado dependen de las señales de control de entrada.    
  always @(*) 
    ALUout = 
      (funcionIs[0]? (esp_fun ? minus[32:0]: ADDERout) : 32'b0)| // ADD/ADDI/SUB o instrucciones store/load o (tipo U)
      (funcionIs[1]? flip32(shift_out) : 32'b0)                | // SLL/SLI
      (funcionIs[2]? {31'b0,LT }       : 32'b0)                | // SLT/SLTI
      (funcionIs[3]? {31'b0,LTU}       : 32'b0)                | // SLTU/SLTUI
      (funcionIs[4]? in1 ^ in2         : 32'b0)                | // XOR/XORI
      (funcionIs[5]? shift_out         : 32'b0)                | // SRL/SRLI/SRA/SRAI
      (funcionIs[6]? in1 | in2         : 32'b0)                | // OR/ORI
      (funcionIs[7]? in1 & in2         : 32'b0)                ; // AND/ANDI

  //--- bloque branch: basado en lo que indique funcion y las tres señales logicas LT,LTU y EQ
  always @(*)
    branch = (funcionIs[0] &   EQ) | // BEQ
             (funcionIs[1] &  ~EQ) | // BNE
             (funcionIs[4] &   LT) | // BLT
             (funcionIs[5] &  ~LT) | // BGE
             (funcionIs[6] &  LTU) | // BLTU
             (funcionIs[7] & ~LTU) ; // BGEU
 
endmodule

