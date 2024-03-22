//CoreLeon.v
// V3.3: Segmentado.
// * Segmentacion de 5 etapas
// * ebreak detiene el programa implementado
// * ecall no está implementado ...
// * implementado ZiCSR: Timers implementados
// * Modo depurador implementado
// RV32I_Zicsr
`default_nettype none
//------CoreLeon()----------------------------------------------------------------------
module CoreLeon (
  input rst,
  input clk,
  // Bus de control y estado del cpu
  output error, 
  output end_prog,

  // Bus de memoria de instrucciones
  //    bus de control
  input  InstrWait,  // Esperar instruccion de la memoria
  output InstrValid, // Valor de InstrAddr es válido para leer en memoria
  output InstrStall, // No cambiar instruccion 
  //    Direccion y dato
  output [31:0] InstrAddr, // bus de direccion de instruccion
  input  [31:0] InstrData, // bus de instruccion
  // bus de memoria de datos
  //    bus de datos:
  input  [31:0] mem_in,  // datos de entrada    
  output [31:0] mem_out, // datos de salida
  //    bus de direcciones
  output [31:0] mem_address,
  //    bus de control
  output [ 3:0] mem_mask, // mascara del byte a escribir
  output        mem_read,// señal de lectura de memoria
  output        mem_write, // señal de escritura de la memoria
  output        memStall,
  input         memWait,

  // Bus del Depurador [31:0] DBG
  input [15:0]  dbg_address,
  input [31:0]  dbg_indata,
  output [31:0] dbg_outdata,
  input dbg_rd,
  input dbg_wr,
  input dbg_isvalid,
  output dbg_ready,
  // Señales de Estado al depurador
  input  dbg_haltreq,
  input  dbg_resumereq,
  output dbg_halted

); //------------------------------------------------------------------------------------

  parameter [31:0] INIT_ADDRESS = 32'h0000_0000; // Direccion inicial. Así será fácilmente cambiada...
  localparam I_NOP = 32'h0000_0013; // addi x0,x0,0

  // #################*** operacion del softcore ***#####################

  // -- Definicion de los CSR 
  reg [63:0] cycle, instret; // registro time implementado como cycle...
  reg [31:0]  dbg_dpc, dscratch0;
  wire [31:0] dcsr, misa;
 
  // -- Definicion de las señales de control de la segmentación
  wire Stall_F, Stall_D, Stall_E, Stall_M, Stall_W; // Estancamiento del flujo de los segmentos siguientes
  wire Flush_D, Flush_E, Flush_M, Flush_W; // Generacion de "burbujas" en el segmento que viene
  
  // Niveles: Fetch-Decode-Execute-Memory-WriteBack (F/D/E/M/Wb)

  // -1- %%%%%%%%%%%%%%%%%%%%%%%%%%*       *%%%%%%%%%%%%%%%%%%%%%%%%%% -1-
  // --------------------------***** Fetch *****--------------------------
    
    reg [31:0] pc = INIT_ADDRESS[31:0];
    wire [31:0] F_pc = pc;

    // --- Instruccion a buscar
    assign InstrAddr = F_pc; 
    
    assign InstrValid = ~((D_opcode[2] & D_opcode[6]) | DE_Jump); // D_Jump
    assign InstrStall = Stall_D;
    
    // --- Sumador de pc con numero 4
    wire[31:0] F_pcMas4 = F_pc+4; // 

    // Registros de Segmentacion F->D ##############################################
    always @(posedge clk) begin
      if (rst) begin// -- Operacion en Reset
        pc  <= INIT_ADDRESS;
        FD_nop <= 1;
      end else begin
        // Registro pc
        if (!Stall_F) begin 
          pc <= F_pcMas4; 
          if (E_JumpOrBranch) // -- Ocurre salto
            pc <= E_JumpAddr[31:0];
        end
        //-- F->D
        if (!Stall_D) begin 
          FD_pc  <= F_pc;
          FD_nop <= Flush_D;
        end
      end      
    end  // ########################################################################
    
    reg [31:0] FD_pc;//=INIT_ADDRESS;
    reg FD_nop=1;
    // --- generacion de siguiente instruccion. Si FD_nop, entonces nop
    wire [31:0] FD_instr = FD_nop ? I_NOP : InstrData;
  // -1- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%% -1-

  // -2- %%%%%%%%%%%%%%%%%%%%%%%%%%*        *%%%%%%%%%%%%%%%%%%%%%%%%%% -2-
  // --------------------------***** Decode *****--------------------------
    
    // -------- Decodificacion del a instruccion -----------
    // --- Decodificacion directa de la instruccion
    wire [6:0] D_opcode = FD_instr[6:0];
    wire [4:0] D_rd     = FD_instr[11:7];
    wire [2:0] D_funct3 = FD_instr[14:12];
    wire [4:0] D_rs1    = FD_instr[19:15]; 
    wire [4:0] D_rs2    = FD_instr[24:20];
    wire [7:0] D_funct7 = FD_instr[31:25];
    
    // --- Decodificacion del tipo de instruccion (control)
   
    wire D_isLOAD   = (D_opcode[6:2] == 5'b00_000);//_11);
    wire D_isALUimm = (D_opcode[6:2] == 5'b00_100);//_11);
    wire D_isSTORE  = (D_opcode[6:2] == 5'b01_000);//_11);
    wire D_isALUreg = (D_opcode[6:2] == 5'b01_100);//_11);
    wire D_isAUIPC  = {D_opcode[5],D_opcode[2]} == 2'b0_1;
    wire D_isLUI    = {D_opcode[5:4],D_opcode[2]} == 3'b11_1;
    wire D_isBRANCH = {D_opcode[6],D_opcode[4],D_opcode[2]} == 3'b1_0_0;
    wire D_isJALR   = {D_opcode[6], D_opcode[3:2]} == 3'b1_01;
    wire D_isJAL    =  D_opcode[3];
    wire D_isEBREAK = D_opcode[6] & D_opcode[4] & D_funct3ZERO & FD_instr[20];
    wire D_isCSR    = D_opcode[6] & D_opcode[4] & ~D_funct3ZERO;

    wire D_ALUFun  = D_opcode[4] | D_opcode[6];
    wire D_Jump    = D_opcode[2] & D_opcode[6]; // D_isJAL || D_isJALR
    wire D_isUpper = D_opcode[2] & D_opcode[4]; // D_isAUIPC || D_isLUI


    // --- Decodificacion del inmediato segun formatos 
    wire [31:0] D_Iimm = {{21{FD_instr[31]}}, FD_instr[30:20]};
    wire [31:0] D_Simm = {{21{FD_instr[31]}}, FD_instr[30:25], FD_instr[11:7]};
    wire [31:0] D_Bimm = {{20{FD_instr[31]}}, FD_instr[7], FD_instr[30:25], FD_instr[11:8], 1'b0};
    wire [31:0] D_Jimm = {{12{FD_instr[31]}}, FD_instr[19:12], FD_instr[20], FD_instr[30:21], 1'b0};   
    wire [31:0] D_Uimm = {FD_instr[31], FD_instr[30:12], {12{1'b0}}};

    // --- Seleccion de inmediato
    reg [31:0] D_imm;
    (*parallel_case*) 
    always @(*) case (1'b1)
      D_isUpper:  D_imm = D_Uimm; // isAUIPC || D_isLUI
      D_isBRANCH: D_imm = D_Bimm;
      D_isSTORE:  D_imm = D_Simm;
      D_isJAL:    D_imm = D_Jimm;
      default:    D_imm = D_Iimm;
    endcase

    // ------------- Control Principal -----------------
    // --- Señales de ayuda para la decodificacion o deteccion de peligros
    wire D_rdNoZero =  |D_rd;
    wire D_rs1NoZero = |D_rs1;
    wire D_rs2NoZero = |D_rs2;
    
    wire D_funct3ZERO = (D_funct3 == 3'b0);
    
    // --- Generacion del Control Principal que se propagará al resto de la segmentacion
    reg D_RegWrite, D_ALUSrc1, D_ALUSrc2, D_PCPlus4toReg, D_funQual,
        D_CSRWrite, D_CSRRead, D_PC_src1, D_PC_src2, D_error,
        D_rs1Read,D_rs2Read;

    (*parallel_case*)
    always @(*) begin
      // caso por default 
      D_error = (D_opcode[1:0]!= 2'b11) | (
                 (D_opcode[6]  & ~D_opcode[5]) | 
                 (D_opcode[3]  & ~D_opcode[2]) |
                 ((D_opcode[4] ~^ D_opcode[6]) & D_opcode[2]) |
                 (D_opcode[4]  &  D_opcode[3]));
      D_rs1Read = 1; 
      D_rs2Read = 0;
      D_RegWrite = D_rdNoZero; // 0: no escribe en rd; 1: escribe (si D_rdNoZero)
      D_ALUSrc2=0; // 0: reg(rs2); 1: Imm
      D_funQual=0; // 0: op usual; 1: op alternativa (para sub y sra)
      case(1'b1) 
        D_isLOAD: begin // load
          D_ALUSrc2=1;  // ALUin1=reg / ALUin2=imm // lee en memoria y guarda en Reg(rd)
          end
        D_isALUimm: begin // ALUimm
          D_ALUSrc2=1; // ALUin1=reg / ALUin2=imm
          D_funQual = (D_funct3[1:0] == 2'b01)? D_funct7[5] : 1'b0; // En estas instrucciones, solo se presta atencion a este cualificador cuando funct3[1:0] indica desplazamientos.
          end
        D_isAUIPC: begin // AUIPC
          D_rs1Read = 0;
          end
        D_isSTORE: begin //store
          D_ALUSrc2=1;  // ALUin1=reg / ALUin2=imm
          D_RegWrite=0; // No guarda en los registros, pero si en memoria
          D_rs2Read=1;
          end
        D_isALUreg: begin //ALUreg
          D_funQual = D_funct7[5]; // modificador se activa con restador
          D_rs2Read = 1;
          end
        D_isLUI: begin //LUI
          D_rs1Read = 0;
          end
        D_isBRANCH: begin //branch
          D_RegWrite=0; // Branch no escribe en registros
          D_rs2Read = 1;
          end 
        D_isJALR: begin//jalr
          D_ALUSrc2=1; // ALUin1=reg / ALUin2=imm
          end
        D_isJAL: begin //jal
          D_rs1Read = 0;
          D_ALUSrc2 = 1'bx; // ALUin2=imm
          end
        D_isEBREAK: begin // ebreak
          D_RegWrite= 0; // ebreak no escribe en registros Por el opcode, esto no es necesario
          D_rs2Read = 1;
          end 
        D_isCSR: begin // csr (read/write)
          D_rs2Read = 1;
          end
      endcase
    end

    //-- Multiplexor por el depurador:
    wire [4:0] D_selrs1;
    assign D_selrs1 = dbg_sel_REG ? dbg_address[4:0] : D_rs1;

    // ----------- 32 Registros -----------
    wire [31:0] D_rs1Data, D_rs2Data, Wb_rdData; // Dato de los registros
    wire [4:0] Wb_rd; 
    wire Wb_RegWrite;
    registros reg32( // control: RegWrite
      .clk(clk),
      .rst(rst),
      .wr_ena(Wb_RegWrite),
      .readReg1(D_selrs1),
      .readReg2(D_rs2),
      .reg1(D_rs1Data),
      .reg2(D_rs2Data),
      .wr_reg(Wb_rd), 
      .wr_data(Wb_rdData) ); 

    // ------- Unidad de Forwarding (Anticipación) -------
    wire D_rs1_eq_DE_rd = (D_rs1 == DE_rd);
    wire D_rs2_eq_DE_rd = (D_rs2 == DE_rd);

    // de M -> E
    wire D_E_M_fwd_rs1 = DE_RegWrite && D_rs1_eq_DE_rd;
    wire D_E_M_fwd_rs2 = DE_RegWrite && D_rs2_eq_DE_rd;
    // de Wb -> E
    wire D_E_W_fwd_rs1 = EM_RegWrite && (D_rs1 == EM_rd); 
    wire D_E_W_fwd_rs2 = EM_RegWrite && (D_rs2 == EM_rd);

    // Registros de Segmentacion D->E ############################################## 
    always @(posedge clk) begin
      if (rst) begin
        DE_nop      <= 1'b1;
        DE_MemWrite <= 1'b0;
        DE_MemRead  <= 1'b0;
        DE_RegWrite <= 1'b0;
        DE_ALUSrc2  <= 1'b0;
        DE_ALUfun   <= 1'b0;
        DE_funQual  <= 1'b0;
        DE_isJALR   <= 1'b0;
        DE_Jump     <= 1'b0;
        DE_isBRANCH <= 1'b0;
        DE_isCSR    <= 1'b0;
        DE_isEBREAK <= 1'b0;
        DE_error    <= 1'b0;
        DE_AUIPC    <= 1'b0;
        DE_LUI      <= 1'b0;
      end else
      if(!Stall_E) begin // operacion usual
       // señales de datos
        DE_rs1Data <= D_rs1Data;
        DE_rs2Data <= D_rs2Data;
        DE_imm <= D_imm;
        DE_pc  <= FD_pc;
        DE_rs1 <= D_rs1;
        DE_rs2 <= D_rs2;
        DE_rd  <= D_rd;
        DE_funct3 <= D_funct3;

        // señales de control
        DE_nop      <= FD_nop;
        DE_MemWrite <= D_isSTORE;
        DE_MemRead  <= D_isLOAD;
        DE_RegWrite <= D_RegWrite; // D_isALUimm | D_isALUreg | D_isLUI | D_isJAL | D_isJALR; // | ...
        DE_ALUSrc2  <= D_ALUSrc2;
        DE_ALUfun   <= D_ALUFun;
        DE_funQual  <= D_funQual;
        DE_isJALR   <= D_isJALR;
        DE_Jump     <= D_Jump;
        DE_isBRANCH <= D_isBRANCH;
        DE_isCSR    <= D_isCSR;
        DE_isEBREAK <= D_isEBREAK;
        DE_error    <= D_error;
        DE_AUIPC    <= D_isAUIPC;
        DE_LUI      <= D_isLUI;

        DE_M_fwd_rs1 <= D_E_M_fwd_rs1;
        DE_M_fwd_rs2 <= D_E_M_fwd_rs2;
        DE_W_fwd_rs1 <= D_E_W_fwd_rs1;
        DE_W_fwd_rs2 <= D_E_W_fwd_rs2;

        if (Flush_E || FD_nop) begin
          DE_nop      <= 1'b1;
          DE_MemWrite <= 1'b0;
          DE_MemRead  <= 1'b0;
          DE_RegWrite <= 1'b0;
          //DE_ALUSrc1  <= 1'b0; 
          DE_ALUSrc2  <= 1'b0;
          DE_ALUfun   <= 1'b0;
          DE_funQual  <= 1'b0;
          DE_isJALR   <= 1'b0;
          DE_Jump     <= 1'b0;
          DE_isBRANCH <= 1'b0;
          DE_isCSR    <= 1'b0;
          DE_isEBREAK <= 1'b0;

          DE_error    <= 1'b0;
          DE_AUIPC    <= 1'b0;
          DE_LUI      <= 1'b0;
          // DE_M_fwd_rs1 <= 1'b0; // No serian necesarios darles un valor
          // DE_M_fwd_rs2 <= 1'b0; // cuando flush, pues no afectan el flujo del
          // DE_W_fwd_rs1 <= 1'b0; // procesador si se invalida su valor con nop...
          // DE_W_fwd_rs2 <= 1'b0;
        end
      end

    end  // ########################################################################
    reg [31:0] DE_rs1Data, DE_rs2Data, DE_imm;
    reg [31:0] DE_pc;
    reg [4:0] DE_rs1, DE_rs2, DE_rd;
    reg [3:0] DE_ALUCtrl;
    reg [2:0] DE_funct3;
    reg DE_nop, DE_MemWrite, DE_RegWrite, DE_MemRead, DE_ALUSrc1,
        DE_ALUSrc2, DE_isJALR, DE_Jump, DE_isBRANCH, DE_isEBREAK,
        DE_isCSR, DE_error, DE_LUI, DE_AUIPC, DE_funQual, DE_ALUfun,
        DE_M_fwd_rs1, DE_M_fwd_rs2, DE_W_fwd_rs1, DE_W_fwd_rs2;
  // -2- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%%%% -2-  


  // -3- %%%%%%%%%%%%%%%%%%%%%%%%%%*         *%%%%%%%%%%%%%%%%%%%%%%%%%% -3-
  // --------------------------***** Execute *****--------------------------
  
    // -- Multiplexores de la unidad de forwarding
    // Señales rs1 y rs2 traidas de la etapa M, W o D
    wire [31:0] E_rs1Data = DE_M_fwd_rs1 ? EM_resultado: // M (Prioridad en M)
                            DE_W_fwd_rs1 ? Wb_rdData   : // W
                                           DE_rs1Data  ; // D
    wire [31:0] E_rs2Data = DE_M_fwd_rs2 ? EM_resultado:
                            DE_W_fwd_rs2 ? Wb_rdData   :
                                           DE_rs2Data  ;

    // -------- ALU --------
    // --- Control
    wire [3:0] E_ALUCtrl = {DE_funQual, (DE_ALUfun ? DE_funct3 : 3'b0)};

    // --- Seleccion de entradas
    wire [31:0] E_ALUin1 = E_rs1Data; // (DE_ALUSrc1)?  DE_pc : E_rs1Data;
    wire [31:0] E_ALUin2 = DE_ALUSrc2 ? DE_imm : E_rs2Data;
    
    // --- Bloque ALU y Branch
    wire [31:0] E_ADDERout, E_ALUout;
    wire E_TakeBranch;
    ALU alu( 
      .ALUCtrl(E_ALUCtrl),
      .in1(E_ALUin1),
      .in2(E_ALUin2),
      .ALUout(E_ALUout),
      .ADDERout(E_ADDERout),
      .branch(E_TakeBranch));
    
    // -------- Bloque Salto --------
    // --- Suma de pc con inmediato
    wire [31:0] E_pcMasImm = DE_pc + DE_imm;
    // --- resultado sera DE_pc+4 si DE_Jump==1
    wire [31:0] E_pcMas4 = FD_pc; // en el contexto de los saltos, FD_pc = DE_pc+4 (no realizó una suma)
    // --- Direccion de salto definida por DE_isJALR
    wire [31:0] E_JumpAddr = DE_isJALR ? E_ADDERout : E_pcMasImm;
    // --- Control de Salto
    wire E_JumpOrBranch = DE_Jump | (DE_isBRANCH & E_TakeBranch);

    // ----- Asignacion de señales de control de salida -----
    assign end_prog = DE_isEBREAK;
    assign error = DE_error;

    // Registros de Segmentacion E->M ##############################################
    always @(posedge clk) begin
      if (rst) begin // señales de control
        EM_nop      <= 1'b1;
        EM_MemRead  <= 1'b0; // Memoria
        EM_MemWrite <= 1'b0;
        //EM_CSRRead  <= 1'b0; // CSR
        //EM_CSRWrite <= 1'b0;
        EM_isCSR    <= 1'b0;
        EM_RegWrite <= 1'b0;
      end else
      if (!Stall_M) begin
        // señales de datos
        EM_resultado <= DE_Jump ? E_pcMas4  : 
                        DE_AUIPC? E_pcMasImm: 
                        DE_LUI  ? DE_imm    : 
                                  E_ALUout  ;
        EM_rs2Data   <= E_rs2Data;
        //EM_csrDataIn <= DE_funct3[2] ? {27'b0,DE_rs1} // 1: inmediato extendido
        //                           : E_rs1Data;       // 0: Normal
        EM_csr      <= DE_imm[11:0];
        EM_rd       <= DE_rd;
        EM_funct3   <= DE_funct3;

        // señales de control
        EM_nop      <= DE_nop; // indica un nop
        EM_MemRead  <= DE_MemRead; // Memoria
        EM_MemWrite <= DE_MemWrite;
        EM_isCSR    <= DE_isCSR;
        EM_RegWrite <= DE_RegWrite;
        
        if (Flush_M || DE_nop) begin // señales de control
          EM_nop      <= 1'b1;
          EM_MemRead  <= 1'b0; // Memoria
          EM_MemWrite <= 1'b0;
          EM_isCSR    <= 1'b0;
          EM_RegWrite <= 1'b0;
        end
      end

    end  // ########################################################################
    reg [31:0] EM_resultado, EM_rs2Data, EM_csrDataIn;
    reg [11:0] EM_csr;
    reg [4:0]  EM_rd;
    reg [2:0]  EM_funct3;
    reg EM_nop, EM_MemRead, EM_MemWrite,
        EM_RegWrite, EM_isCSR;
  // -3- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%% -3-
  

  // -4- %%%%%%%%%%%%%%%%%%%%%%%%%%*        *%%%%%%%%%%%%%%%%%%%%%%%%%% -4-
  // --------------------------***** Memory *****--------------------------

    // -------- CSR --------
    // --- Lectura de CSR
    wire [31:0] M_CSRData; 

    wire [11:0] M_csr = (dbg_sel_PIPCSR) ? dbg_address[11:0] : EM_csr;
    wire M_Ucsr   = (M_csr[11:8] == 4'hC);
    wire M_Mcsr   = (M_csr[11:8] == 4'h3);
    wire M_Dbgcsr = (M_csr[11:5] == 7'b0111101);

    (* onehot *)wire [15:0] M_lsbytecsr = 16'b1 << M_csr[3:0];
      wire M_selcycle     = M_Ucsr & ~M_csr[7] & (M_lsbytecsr[1] | M_lsbytecsr[0]);
      wire M_selcycleh    = M_Ucsr &  M_csr[7] & (M_lsbytecsr[1] | M_lsbytecsr[0]);
      wire M_selinstret   = M_Ucsr & ~M_csr[7] & M_lsbytecsr[2];
      wire M_selinstreth  = M_Ucsr &  M_csr[7] & M_lsbytecsr[2];

      wire M_seldcsr      = M_Dbgcsr &  M_csr[4] & M_lsbytecsr[0];

    assign M_CSRData = (M_selcycle   ? cycle[31:0]    : 32'b0) |
                       (M_selinstret ? instret[31:0]  : 32'b0) |
                       (M_selcycleh  ? cycle[63:32]   : 32'b0) |
                       (M_selinstreth? instret[63:32] : 32'b0) |
                       (M_seldcsr    ? dcsr           : 32'b0) ;

    // -------- Bloque de Escritura Memoria RAM --------
    wire [31:0] M_address   = EM_resultado; 
    wire [31:0] M_WriteData = EM_rs2Data; 

    // --- Ajuste para escribir en la memoria
    StoretoMEM store (
      .addr_LSB(M_address[1:0]), // igualmente al bloque load
      .memWrite(EM_MemWrite), //
      .data_width(EM_funct3[1:0]),
      .data(M_WriteData), // Entrada de datos
      .wr_datatoMem(mem_out), // señales de escritura
      .mask_data(mem_mask));

    // --- Asignacion de los puertos I/O de CoreLeon
    assign mem_address = {M_address[31:2],2'b00}; // siempre buscará en memoria de manera alineada
    assign mem_read    = EM_MemRead; 
    assign mem_write   = EM_MemWrite;
    assign memStall    = Stall_W;
    // mem_out se asignó en store

    // Registros de Segmentacion M->Wb #############################################
    always @(posedge clk) begin
      if (rst) begin
        MW_nop      <= 1'b1;
        MW_MemRead  <= 1'b0;
        MW_RegWrite <= 1'b0;
      end else
      if(!Stall_W) begin
        // Señales de datos
        MW_address_LSB <= M_address[1:0];
        MW_resultado   <= EM_isCSR ? M_CSRData
                                   : EM_resultado;
        MW_funct3   <= EM_funct3;
        MW_rd       <= EM_rd;
        // señales de control
        MW_nop      <= EM_nop;
        MW_MemRead  <= EM_MemRead;
        MW_RegWrite <= EM_RegWrite;
        
        if (Flush_W || EM_nop) begin
          MW_nop      <= 1'b1;
          MW_MemRead  <= 1'b0;
          MW_RegWrite <= 1'b0;
        end
      end

    end // ########################################################################
    reg [31:0] MW_resultado;
    reg [ 4:0] MW_rd;
    reg [ 2:0] MW_funct3;
    reg [ 1:0] MW_address_LSB;
    reg MW_nop, MW_MemRead, MW_RegWrite;  
  // -4- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%% -4-


  // -5- %%%%%%%%%%%%%%%%%%%%%%%%%%*           *%%%%%%%%%%%%%%%%%%%%%%%%%% -5-
  // --------------------------***** WriteBack *****--------------------------
    
    // --- Bloque de ajuste de la lectura de la memoria.
    wire [31:0] Wb_MemoryData;
    LoadfromMEM load ( 
      .addr_LSB(MW_address_LSB), // solo 2 bits menos significativos...
      .data_width(MW_funct3[1:0]),
      .sin_signo(MW_funct3[2]),
      .data_mem(mem_in), // Entrada de datos
      .data_readed(Wb_MemoryData) ); // lectura final
    
    // --- Multiplexor de seleccion final
    assign Wb_RegWrite = MW_RegWrite; 
    assign Wb_rd = MW_rd;
    assign Wb_rdData = MW_MemRead ? Wb_MemoryData : // Agregar multiplexor del bus depurador
                                    MW_resultado  ;
  // -5- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%% -5-

  // *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

  //-------- Unidad de Deteccion de Peligro -------
    // --- Los peligros de Datos se detectan desde en la etapa D.
    // Para el forwarding, las señales se pasan por los registros D->E para ser usadas en E
    
    // --- Deteccion de Hazard por lecturas
    wire rs1Hazard  = D_rs1Read & D_rs1_eq_DE_rd; // 
    wire rs2Hazard  = D_rs2Read & D_rs2_eq_DE_rd; // 

    wire loadHazard = (DE_MemRead | DE_isCSR) & // Si ocurre lecturas de memoria
                      (rs1Hazard  | rs2Hazard); 

  //--------- Control del pipelining --------- 
    assign Flush_D = E_JumpOrBranch;// || Stall_CPU;
    assign Flush_E = E_JumpOrBranch | loadHazard;
    assign Flush_M = (err_ebreak); // Se hace un flush_M si es EBREAK
    assign Flush_W = 0;
    
    assign Stall_F = Stall_CPU | err_ebreak | loadHazard;
    assign Stall_D = Stall_CPU | err_ebreak | loadHazard;
    assign Stall_E = Stall_CPU | err_ebreak;
    assign Stall_M = Stall_CPU;
    assign Stall_W = Stall_CPU;

    wire Stall_CPU = InstrWait | memWait | dbg_mode;
  //--------- Deteccion de errores ---------
    wire err_ebreak = ((DE_isEBREAK & ~dbg_byOneStep) | DE_error);

  //-----

  //-------- Registros CSR ---------------

    wire cycle_en, instret_en; // Habilitadores de los contadores
    assign cycle_en =  ~(dbg_mode);
    assign instret_en = ~(MW_nop | Stall_CPU);

    //--- cycle/time_ e instret
    always @(posedge clk) begin   // Contadores de sistema
      if (rst) begin
        cycle <= 64'b0;
        instret <= 64'b0;
      end else begin
        if (cycle_en)
          cycle <= cycle + 1;
        if (instret_en) 
          instret <= instret + 1;
      end
    end

    //--- Debug Control and Status: (dcsr, 0x7b0)
    assign dcsr = {4'b1111,12'b0,dbg_ebreakm,3'b0,1'b0,2'b11,dbg_cause,3'b0,dbg_step,2'b11};
    
  // -+- %%%%%%%%%%%%%%%%%%%%%%%%%%*           *%%%%%%%%%%%%%%%%%%%%%%%%%% -+-
  // --------------------------***** Depurador *****--------------------------
    //--- Registros del modo depurador 
    reg dbg_mode=0, dbg_resumeack=0;
    reg dbg_step=0, dbg_ebreakm=0;
    reg [2:0] dbg_cause=0;
    
    //--- Deteccion de señales del depurador
    wire dbg_byEbreak     = D_isEBREAK & dbg_ebreakm; // ebreak si ebreakm activo
    wire dbg_byOneStep    = dbg_resumeack & dbg_step; // Deteccion de un paso
    wire dbg_Actdbgmode   = (dbg_haltreq | dbg_byEbreak | dbg_byOneStep) & ~(InstrWait | memWait);
    wire dbg_deActdbgmode = dbg_resumereq & dbg_mode;
    //--- Debug Mode Register
    always @(posedge clk) begin
      if (rst) begin
        dbg_mode <= 1'b0;
        dbg_resumeack <= 1'b0;
      end else begin
        dbg_resumeack <= dbg_deActdbgmode; // dbg_resumereq && dbg_mode;
        if (dbg_Actdbgmode) begin
          dbg_mode <= 1'b1;
        end
        if (dbg_deActdbgmode) begin //
          dbg_mode <= 1'b0;
        end
      end
    end

    reg dbg_isvalid_q;
    wire dbg_sel_CSR, dbg_sel_REG, dbg_sel_PIP,dbg_sel_PIPCSR;

    wire [31:0] dbg_out;
    wire wr_dcsr;
    
    assign dbg_sel_CSR = dbg_isvalid_q & (dbg_address[15:12] == 4'h0);
    // assign dbg_sel_REG_q = dbg_isvalid_q & (dbg_address[15:12] == 4'h1);
    assign dbg_sel_REG   = dbg_isvalid_q & (dbg_address[15:12] == 4'h1);
    assign dbg_sel_PIP = dbg_isvalid_q & (dbg_address[15:12] == 4'hC);

    assign dbg_sel_PIPCSR = dbg_sel_CSR | dbg_sel_PIP;
    //--Señales de escritura de los registros
     assign wr_dcsr   = dbg_wr & dbg_isvalid_q & (~dbg_sel_PIP) & M_seldcsr ; //(M_csr[7:0] == 8'hb0);
    
    //-- Validacion de lectura o escritura de los registros
    always @(posedge clk) begin
      dbg_isvalid_q <= dbg_isvalid & dbg_mode;
    end 

    //-- Multiplexor de salida
    assign dbg_out = (dbg_sel_CSR ? M_CSRData : 32'h0) |
                     (dbg_sel_REG ? D_rs1Data : 32'h0) |
                     (dbg_sel_PIP ? DBG_PIPES : 32'h0) ;

    //-- Interfaz con el bus depurador
    assign dbg_outdata = dbg_out;
    assign dbg_ready   = dbg_isvalid_q;
    assign dbg_halted  = dbg_mode;
    
    //-- Registros del dcsr
    always @(posedge clk) begin
      if (rst) begin
        dbg_step <= 0;  dbg_ebreakm <= 1;  dbg_cause <= 0;
      end else begin
        if (wr_dcsr) begin
          dbg_step    <= dbg_indata[2];
          dbg_ebreakm <= dbg_indata[15];
        end
        // Sabiendo que cuando ebreak está en E ocurre el halt:
        if (dbg_haltreq)        dbg_cause <= 3'd3;
        else if (dbg_byEbreak)  dbg_cause <= 3'd1;
        else if (dbg_byOneStep) dbg_cause <= 3'd4;
      end 
    end 

    wire [31:0] DBG_PIPES; 

    assign DBG_PIPES = (M_lsbytecsr[0]  ? { DE_error,E_JumpOrBranch, // otros (sobran 6 bits)
                 /* Detector de Hazard */   1'b0,rs1Hazard,rs2Hazard,loadHazard,
                /* Unidad de Forwarding */  DE_W_fwd_rs2, DE_W_fwd_rs1, DE_M_fwd_rs2, DE_M_fwd_rs1,
                       /* Stall */          3'b000, err_ebreak, err_ebreak|loadHazard, err_ebreak|loadHazard,
                       /* Flush */          Flush_W, Flush_M, Flush_E, Flush_D, 1'b0,
                        /* NOP */           MW_nop, EM_nop, DE_nop, FD_nop, 1'b0}    : 32'b0) | // sobran 6 bits
    /* Fetch */        (M_lsbytecsr[1]  ? F_pc     : 32'b0) |
    /* Decode */       (M_lsbytecsr[2]  ? FD_pc    : 32'b0) |
                       (M_lsbytecsr[3]  ? FD_instr : 32'b0) |
    /* Execute */      (M_lsbytecsr[4]  ? { DE_rs1,DE_rs2, DE_LUI,DE_AUIPC,DE_isEBREAK, // 5 + 5 + 3 (de control) bits
                                            DE_isCSR, DE_isBRANCH, DE_Jump, DE_isJALR, DE_funQual, // 5 )
                                             DE_ALUfun, DE_ALUSrc2,DE_rd,DE_funct3, // 2 (de control) + 5 + 3 + (3 de control abajo)
                                            DE_RegWrite, DE_MemRead, DE_MemWrite} : 32'b0) | // Sobra 1 bit
                       (M_lsbytecsr[5]  ? DE_pc        : 32'b0) |
                       (M_lsbytecsr[6]  ? DE_rs1Data   : 32'b0) |
                       (M_lsbytecsr[7]  ? DE_rs2Data   : 32'b0) |
                       (M_lsbytecsr[8]  ? DE_imm       : 32'b0) |
    /* Memory */       (M_lsbytecsr[9]  ? { EM_csr,EM_isCSR,// 12+1 bits
                                            EM_rd,EM_funct3,EM_RegWrite,EM_MemRead, // 5 + 3 + 3 bits
                                            EM_MemWrite}  : 32'b0) | // sobran 8 bits
                       (M_lsbytecsr[10] ? EM_resultado : 32'b0) |
                       (M_lsbytecsr[11] ? EM_rs2Data   : 32'b0) |
  /* WriteBack */      (M_lsbytecsr[12] ? { MW_address_LSB,MW_rd,MW_funct3,// 2+5+3(+ 3 abajo) bits 
                                            MW_RegWrite,MW_MemRead,1'b0}  : 32'b0) | // Sobran 19 bits
                       (M_lsbytecsr[13] ? MW_resultado  : 32'b0) |
                       (M_lsbytecsr[14] ? Wb_MemoryData : 32'b0) ;



  // -+- %%%%%%%%%%%%%%%%%%%%%%%%%%*%%%%%%%%%%%*%%%%%%%%%%%%%%%%%%%%%%%%%% -+-

endmodule