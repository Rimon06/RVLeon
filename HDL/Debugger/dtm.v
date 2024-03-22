// Modulo de transporte del depurador
`default_nettype none
//--
module DTM(
  input clk,
  input rst,
  // Bus UART
  input  RX,
  output TX,
  output CTS_n,
  // Bus DMI
  output        dmi_req_valid,
  output [ 6:0] dmi_req_addr,
  output [31:0] dmi_req_data,
  output [ 1:0] dmi_req_op,
  input         dmi_rsp_valid,
  input [31:0]  dmi_rsp_data
);
  //-- Registros internos del DTM
  reg [4:0] dtm_addr;
  (*onehot*)reg [3:0] dtm_dbyte = 4'b1;
  reg dtm_wr, dtm_valid; // registros de un bit
  reg [31:0] dtm_data; // Buffer de 32 bits
  //-- Señales del FSM
  reg [2:0] dtm_state, dtm_nextstate; // Estado
  wire dtm_ov_dbyte, rxRCV, txdone; // Entrada del FSM
  reg CTS,load_addr,load_data,set_valid,set_txmit,inc_dbyte; // Salida del FSM
  //-- Señales del UART
  wire [7:0] rxdata; 
  reg [7:0] txdata;
  reg txmit;
  
  //##################- Interfaz Bus DMI -###################
    //-- Buffer de direcciones y señales internas
    always @(posedge clk) begin: dmi_regs
      if (rst) begin // :
        dtm_dbyte <= 4'b01;
      end else if (inc_dbyte) begin
        dtm_dbyte <= {dtm_dbyte[2:0],dtm_dbyte[3]};
      end
      dtm_valid <= set_valid;
      if (load_addr)  begin
        dtm_addr <= rxdata[4:0];
        dtm_wr <= rxdata[7];
      end
    end
    
    //-- Buffer de datos de 32 bits
    always @(posedge clk) begin: data_buffer
      if (load_data) begin
        if (dtm_wr) begin
          if (dtm_dbyte[0])  dtm_data[ 7: 0] <= rxdata;
          if (dtm_dbyte[1])  dtm_data[15: 8] <= rxdata;
          if (dtm_dbyte[2])  dtm_data[23:16] <= rxdata;
          if (dtm_dbyte[3])  dtm_data[31:24] <= rxdata;
        end else begin  
          dtm_data <= dmi_rsp_data;
        end
      end
    end
    //-- bus dmi
    assign dmi_req_valid = dtm_valid;
    assign dmi_req_addr  = {2'b0,dtm_addr[4:0]};
    assign dmi_req_data  = dtm_data;
    assign dmi_req_op    = {dtm_wr,~dtm_wr};
    //-- Entrada del FSM:
    assign dtm_ov_dbyte = dtm_dbyte[3];
  //#########################################################
  
  //##########################- FSM -########################
    localparam [2:0] S_idle      = 3'b000,
                     S_DM_read   = 3'b001,
                     S_send_data = 3'b011,
                     S_rcv_data  = 3'b100, // Estado de escritura a registro
                     S_DM_write  = 3'b101; // Estado de escritura a registro
    // dtm_state: 2 1 0
    // dtm_state[2] activo representa escritura/~lectura
    // assign dtm_wr = dtm_state[2];
    // dtm_state[1] activo representa que el transmisor puede usarse
    // assign txvalid = dtm_state[1];
    // dtm_state[0] activo representa que CTS = 1
    // assign CTS = dtm_state[0];

    //-- Registro de Estado
    always @ (posedge clk) begin: dtm_state_reg
      if (rst)  dtm_state <= S_idle;
      else      dtm_state <= dtm_nextstate;
    end
    //-- Logica de estado siguiente y de salida
    always @(*) begin: dtm_fsm_next
      CTS = 1; dtm_nextstate = dtm_state; load_addr = 0; load_data = 0; 
      set_valid = 0; set_txmit=0; inc_dbyte = 0;
      case (dtm_state)
        S_idle: begin // Descanso
          CTS = 0;
          if (rxRCV) begin
            dtm_nextstate = (rxdata[7])? S_rcv_data : S_DM_read;
            load_addr = 1;
            set_valid = ~(rxdata[7]);
          end
        end
        S_DM_read: begin // Lee registros del DM
          CTS = 1;
          if (dmi_rsp_valid) begin
            dtm_nextstate = S_send_data;
            load_data = 1;  set_txmit = 1;
          end
        end
        S_send_data: begin // Envia dato leído
          CTS = 1;
          if (txdone) begin
            if (dtm_ov_dbyte)  dtm_nextstate = S_idle;
            else               set_txmit = 1;
            
            inc_dbyte = 1;
          end
        end
        S_rcv_data: begin // Recibe dato a escribir
          CTS = 0;
          if (rxRCV) begin
            load_data = 1; inc_dbyte = 1;
            if (dtm_ov_dbyte) begin
              dtm_nextstate = S_DM_write;
              set_valid = 1;
            end
          end
        end
        S_DM_write: begin // Escribe registro del DM
          CTS = 1;
          if (dmi_rsp_valid)
            dtm_nextstate = S_idle;
        end
        default: begin
          dtm_nextstate = S_idle;
        end
      endcase
    end
  //#########################################################
  
  //#####################- Bus UART -########################
    //(*onehot*) wire [3:0] act_byte = 4'b1 << dtm_dbyte;
    //-- CTS: si rst está activo, tampoco se recibe informacion
    assign CTS_n = CTS | rst; 
    //-- Modulo RX
    serialRX UART_RX(
      .clk(clk),
      .RX(RX),
      .data(rxdata),
      .rcv(rxRCV));
    //--Señal de activacion de transmisión
    always @(posedge clk) txmit <= set_txmit;

    //-- Dato a transmitir
    (*full_case,parallel_case*)
    always @(*) begin: txdata_mux
      case (1'b1)
        dtm_dbyte[0]: txdata = dtm_data[ 7: 0];
        dtm_dbyte[1]: txdata = dtm_data[15: 8];
        dtm_dbyte[2]: txdata = dtm_data[23:16];
        dtm_dbyte[3]: txdata = dtm_data[31:24];
        default:      txdata = 8'b0;
      endcase
    end
    //-- Modulo TX
    serialTX UART_TX(
      .clk(clk),
      .data(txdata),
      .txmit(txmit), // 
      .TX(TX),
      .done(txdone));
  //#########################################################
endmodule

