
`default_nettype none
module DebugModule(
  input  clk,
  input  rst,
  // DMI: Interfaz del modulo depurador
  input        dmi_req_valid,
  input [ 6:0] dmi_req_addr,
  input [31:0] dmi_req_data,
  input [ 1:0] dmi_req_op,
  output [31:0] dmi_rsp_data,
  output        dmi_rsp_valid,
  // Estado del procesador
  input cpu_halted,
  input cpu_error, // No hace nada
  // Señales de cambio de estado 
  output cpu_haltreq,
  output cpu_resumereq,
  output cpu_ndmreset,
  // Señales del depurador
  output [15:0] cpu_addr,
  input [31:0] cpu_datatoread,
  output [31:0] cpu_datatowrite,
  output cpu_rd,
  output cpu_wr,
  output cpu_isvalid,
  input  cpu_ready
  );
  
  localparam [1:0] DMI_REQ_NOP_C = 2'b00; // no operation
  localparam [1:0]  DMI_REQ_RD_C = 2'b01; // read access
  localparam [1:0]  DMI_REQ_WR_C = 2'b10; // write access

  localparam [4:0] ADDR_DATA0        = 5'h04;
  localparam [4:0] ADDR_DMCONTROL    = 5'h10;
  localparam [4:0] ADDR_DMSTATUS     = 5'h11;
  localparam [4:0] ADDR_ABSTRACTCS   = 5'h16;
  localparam [4:0] ADDR_COMMAND      = 5'h17;
  localparam [4:0] ADDR_ABSTRACTAUTO = 5'h18;
  //-----------------------------------------------------------
 
  wire rst_dm   = rst | ~dmcontrol_dmactive;

  //###############- Bus del DTM (DMI) -#######################

    // Señales para lectura o escritura valida
    wire dmi_wren = dmi_req_op[1] & dmi_req_valid; // write: op=2'b10
    wire dmi_rden = dmi_req_op[0] & dmi_req_valid; // read: op=2'b01
    
    //--- Decodificador de direcciones
    wire In_data0        = (dmi_req_addr[4:0] == ADDR_DATA0);
    wire In_dmcontrol    = (dmi_req_addr[4:0] == ADDR_DMCONTROL);
    wire In_dmstatus     = (dmi_req_addr[4:0] == ADDR_DMSTATUS);
    wire In_abstractcs   = (dmi_req_addr[4:0] == ADDR_ABSTRACTCS);
    wire In_command      = (dmi_req_addr[4:0] == ADDR_COMMAND);
    wire In_abstractauto = (dmi_req_addr[4:0] == ADDR_ABSTRACTAUTO);

    //-- Multiplexor, de los registros a traves  registros mediante la direccion..
    reg [31:0] rsp_data;
    //(* parallel_case *) // Acuerdate que esto lo pusiste aqui
    always @(*) begin
      case(1'b1)
        In_data0    :    rsp_data = data0;
        In_dmcontrol:    rsp_data = dmcontrol;
        In_dmstatus :    rsp_data = dmstatus;
        In_abstractcs:   rsp_data = abstractcs;
        In_command:      rsp_data = 32'b0;  //command;
        In_abstractauto: rsp_data = abstractauto;
        default:         rsp_data = 32'b0;
      endcase
    end
    // assign dmi_rsp_data = rsp_data;
    assign dmi_rsp_data = 
            (In_data0        ? data0        : 32'b0) |
            (In_dmcontrol    ? dmcontrol    : 32'b0) |
            (In_dmstatus     ? dmstatus     : 32'b0) |
            (In_abstractcs   ? abstractcs   : 32'b0) |
            (In_command      ? command      : 32'b0) |
            (In_abstractauto ? abstractauto : 32'b0) ;

    reg rsp_valid;
    always @(posedge clk)   rsp_valid <= dmi_req_valid;
  
    assign dmi_rsp_valid = rsp_valid; //

  //###########################################################
  
  //###################- Bus Depurador -#######################
    assign cpu_addr = cmd_regno;
    assign cpu_datatowrite = data0;
    assign cpu_rd = cmd_transfer & (~cmd_write);
    assign cpu_wr = cmd_transfer & cmd_write;
    assign cpu_isvalid = set_valid; //(cmd_state == S_ejecutar);
  //###########################################################

  
  //--- dmstatus:
  wire [31:0] dmstatus = {
    12'b0, // 7'b0,ndmresetpending,stickyunavail,impebreak,2'b0,
    {2{dm_havereset}},     // allhavereset, anyhavereset,
    {2{dm_resumeack}},       // allresumeack, anyresumeack
    2'b0,                  // allnonexistent, anynonexistent
    {2{dmcontrol_ndmreset}}, // allunavail,anyunavail
    {2{!cpu_halted}},        // allrunning,anyrunning
    {2{cpu_halted}},         // allhalted,anyhalted
    1'b1,1'b0, // authenticated, authbusy // DM no necesita modo de autenticacion
    1'b1,1'b0, // hasresethaltreq, confstrptrvalid // config string no disponibles
    4'b1111 }; // version
  //-----------------------------------------------------------

  //###################- Control del reset -###################
    reg hart_rst_prv=0, dm_havereset=0;
    always @(posedge clk) begin: rst_control
      if (rst_dm) begin
        dm_havereset <= 1'b0;
      end else begin
        dm_havereset <= (dm_havereset | hart_rst_done)
                      & (~dmcontrol_ackhavereset);
      end
      hart_rst_prv <= dmcontrol_ndmreset;
    end
    
    wire hart_rst_done = hart_rst_prv & ~dmcontrol_ndmreset;
    
    assign cpu_ndmreset = dmcontrol_ndmreset;
  //###########################################################

  //--- dmcontrol:
    wire [31:0] dmcontrol = {
      2'b0,         // haltreq,resumereq (Solo escritura)
      1'b0,         // hartreset (no implementado)
      2'b0,         // ackhavereset, ackunavail,
      1'b0,         // hasel (Solo hay un hart)
      20'b0,        // hartsel lo,hi (un unico hart, vale 0)
      2'b0,         // setkeepalive, clrkeepalive, ( no implementado)
      2'b0,         // setresethaltreq, clrresethaltreq, ( no implementado)
      dmcontrol_ndmreset,  // ndmreset (r/w)
      dmcontrol_dmactive}; // dmactive (r/w)

    reg dm_haltOnReset, dmcontrol_haltreq, dmcontrol_dmactive;
    reg dmcontrol_ndmreset, dmcontrol_ackhavereset, dmcontrol_resumereq;

    always @(posedge clk) begin: dmcontrol_regs
      if (rst_dm) begin
        dmcontrol_dmactive  <= 1'b0;
        // dmactive está pendiente de activarse
        if (!rst && dmi_wren && In_dmcontrol) 
          dmcontrol_dmactive <= dmi_req_data[0]; 
        
        dmcontrol_ndmreset  <= 1'b0; 
        dm_haltOnReset <= 1'b0;
        dmcontrol_ackhavereset <= 1'b0;
        dmcontrol_resumereq <= 1'b0;
        dmcontrol_haltreq   <= 1'b0;
      end else begin
        dmcontrol_haltreq  <= 1'b0;
        dmcontrol_resumereq <= 1'b0;
        dmcontrol_ackhavereset <= 1'b0;
        
        if (dmi_wren && In_dmcontrol) begin
          dmcontrol_dmactive  <= dmi_req_data[0];
          dmcontrol_ndmreset  <= dmi_req_data[1];
          dm_haltOnReset <= ~dmi_req_data[2] //
                          & (dm_haltOnReset | dmi_req_data[3]);
          dmcontrol_ackhavereset <= dmi_req_data[28];
          dmcontrol_resumereq <= dmi_req_data[30] & ~dmi_req_data[31];
          dmcontrol_haltreq   <= dmi_req_data[31];
        end
      end
    end
  //-----------------------------------------------------------

  //################- Run/Halt Controller -####################
    reg dm_haltreq_sticky, dm_resumereq_sticky, dm_resumeack;
    always @(posedge clk) begin: runhalt_control
      if (rst_dm ) begin
        dm_haltreq_sticky <= 1'b0;
        dm_resumereq_sticky <= 1'b0;
        dm_resumeack      <= 1'b0;
      end else begin
        // Se detiene si aún no está detenida y si se manda una señal del depurador o si acaba de salir del reset
        dm_haltreq_sticky <= (~cpu_halted) & // Si no está detenida,  revisar...
                             ( dm_haltreq_sticky | dmcontrol_haltreq |
                              (dm_haltOnReset & hart_rst_done)); // Detener
        dm_resumereq_sticky <= (dm_resumereq_sticky & cpu_halted) |
                               (dmcontrol_resumereq);
        dm_resumeack <= (~dmcontrol_resumereq) &
                        (dm_resumeack | (~cpu_halted & dm_resumereq_sticky));
      end
    end
    
    assign cpu_haltreq = dm_haltreq_sticky;
    assign cpu_resumereq = dm_resumereq_sticky;
  //###########################################################

  // Definiendo señales Entrada/Salida para el FSM:
  // Salida: exceptuando por abstractcs_busy y cpu_isvalid, ya definidos.
  reg set_cmderr, cmd_load, cmd_incregno, set_valid;
  // Entrada: exceptuando por cmd_postinc y cpu_ready, ya definidos.
  wire active_command, wr_cmd, is_cmd_valid, cmderr_zero, access_data0;
  
  //--- abstractauto:
    wire [31:0] abstractauto = {
      16'b0, // autoexecprogbuf // No se implementa
      4'b0,
      11'b0,autoexecdata0}; // autoexecdata solo [0] es r/w
    
    reg autoexecdata0;
    always @(posedge clk) begin: autoexecdata_reg
      if (rst_dm) 
        autoexecdata0 <= 1'b0;
      else if (dmi_wren && In_abstractauto)
        autoexecdata0 <= dmi_req_data[0];
    end
  //-----------------------------------------------------------
  
  //--- abtractscs: 
    wire [31:0] abstractcs = {
      19'b0,                  // 3'b0, progbufsize=0, 11'b0,
      abstractcs_busy,1'b1 ,  // busy, relaxedpriv
      abstractcs_cmderr[2:1],1'b0,4'b0, //cmderr, reservado
      4'd1};                  // data registers == 1
    wire abstractcs_busy;

    // El bit 0 nunca será 1. No se agrega.
    reg [2:1] abstractcs_cmderr = 2'b0;
    always @(posedge clk) begin
      if (rst_dm) begin
        abstractcs_cmderr <= 2'b0;
      end else if (dmi_wren && In_abstractcs) begin
        if (dmi_req_data[10:8] == 3'b111)    abstractcs_cmderr <= 2'b0;
      end else if (set_cmderr) begin
        if (!cpu_halted || dmcontrol_ndmreset) 
          abstractcs_cmderr[2] <= 1'b1; // cmderr <= 4 (haltresume)
        else
          abstractcs_cmderr[1] <= 1'b1; // cmderr <= 2 (Comando no soportado)
      end
    end

    assign cmderr_zero = ~(abstractcs_cmderr[2] | abstractcs_cmderr[1]);
  //-----------------------------------------------------------
  
  //--- data0:
    reg [31:0] data0; 
    always @(posedge clk) begin
      if (rst_dm) begin
        data0 <= 32'b0;
      end else if (dmi_wren && In_data0 && !abstractcs_busy) begin
        data0 <= dmi_req_data;
      end else if (cpu_ready && cpu_rd) begin // Cuando se lee o escribe con autoexecdata0, se pierde la información escrita
        data0 <= cpu_datatoread;        
      end
    end
    
    assign access_data0 = dmi_req_valid & In_data0 & autoexecdata0;
  //-----------------------------------------------------------
  
  //---command:
    reg cmd_AccessReg, cmd_transfer, cmd_write, cmd_postinc;
    reg [15:0] cmd_regno;

    always @(posedge clk) begin
      if (rst_dm) begin
        cmd_AccessReg <= 1'b0;
        cmd_postinc   <= 1'b0;
        cmd_transfer  <= 1'b0;
        cmd_write     <= 1'b0;
        //cmd_regno     <= 16'b0;
      end else if (cmd_load) begin
        cmd_AccessReg <= (dmi_req_data[31:24] == 8'd0); // Señal de comando valido
                      // & (dmi_req_data[22:20] == 3'd2) // debe comprobar esto...
                      // & ~dmi_req_data[18];
        cmd_postinc   <= dmi_req_data[19];
        cmd_transfer  <= dmi_req_data[17];
        cmd_write     <= dmi_req_data[16];
        //cmd_regno     <= dmi_req_data[15:0];
      end 
      
      if (cmd_load) begin
        cmd_regno     <= dmi_req_data[15:0];
      end else if (cmd_incregno) begin
        cmd_regno[4:0] <= cmd_regno[4:0] + 1;
      end
    end
    wire [31:0] command = {12'h002,cmd_postinc,1'b0,cmd_transfer,cmd_write,cmd_regno};

    assign wr_cmd = dmi_wren & In_command;
    assign active_command = access_data0 | wr_cmd;
    assign is_cmd_valid = cmd_AccessReg & cpu_halted & (~dmcontrol_ndmreset);
  //-----------------------------------------------------------
  
  //##############- FSM comando abstracto -####################
    localparam S_idle = 0;
    localparam S_validar = 1;
    localparam S_ejecutar = 2;
    localparam S_esperar = 3;
    localparam S_error = 4;
    
    reg [2:0] cmd_state, cmd_nxtstate;

    //-- FSM del Debug Module
    always @(posedge clk) begin: cmd_state_REG
      if (rst_dm)   cmd_state <= S_idle;
      else          cmd_state <= cmd_nxtstate;
    end

    always @(*) begin: nxtstateOutput_logic
      cmd_nxtstate = cmd_state; set_cmderr = 0; cmd_load=0; cmd_incregno=0; set_valid=0;
      case (cmd_state)
        S_idle: begin // No se ejecuta comando
          if (active_command)   cmd_nxtstate = S_validar;

          if (wr_cmd)   cmd_load = 1;
        end
        S_validar: begin // validar datos iniciales
          if (is_cmd_valid)   cmd_nxtstate = S_ejecutar;
          else begin
            cmd_nxtstate = S_error;
            set_cmderr = 1;
          end
        end
        S_ejecutar: begin // Ejecución del comando (manda set_valid)
          set_valid = 1;
          cmd_nxtstate = S_esperar;
        end
        S_esperar: begin // Espera respuesta del procesador (lectura o escritura efectuada en uno de los tres tipos de registros)
          if (cpu_ready) begin
            cmd_nxtstate = S_idle;
            if (cmd_postinc)  cmd_incregno = 1;
          end
        end
        S_error: if (cmderr_zero)  cmd_nxtstate = S_idle; //Si ocurre un error en el comando, La ejecución del comando no termina hasta limpiar error

        default: cmd_nxtstate = S_idle;
      endcase
    end

    // Salidas
    assign abstractcs_busy = (cmd_state != S_idle);
  //###########################################################

endmodule
