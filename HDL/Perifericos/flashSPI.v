
// Modulo flash SPI. La lectura de las instrucciones se realizara aca.
// 
`default_nettype none
`timescale 1ns/1ps

module flashSPI ( // 
  // interfaz con bus riscv
  input     wire clk,
  input     wire rst,

  input     rd_strb,
  input     stop,
  input     wire [21:0] addr, // 4MWord

  output    wire [31:0] data,
  output    wire  ready,
  output    valid,

  // Comunicacion con el Bus SPI de la placa
  output  spi_cs_n,
  input   spi_miso,
  output  spi_mosi,
  output  spi_sclk
  );
  // Estados
  localparam S_idle     = 0;
  localparam S_sendcomm = 1;
  localparam S_rcvData  = 2;
  // Valores iniciales de los registros cargados por el FPGA
  reg [1 :0] state = S_idle;
  reg [4 :0] shift_cnt;
  reg [31:0] shift_reg = 32'hFFFF_FFFF,
             rcv_buff = 32'b0;
  reg spi_cs_n = 1,
      valid    = 0;

  // Salida de datos. Reordenados pues el byte 0 entró primero en el registro de desplazamiento
  assign data = {rcv_buff[7:0],rcv_buff[15:8],rcv_buff[23:16],rcv_buff[31:24]};
  // salidas por spi
  assign spi_sclk = !clk && !spi_cs_n;
  assign spi_mosi = shift_reg[31];
  // salida de estado
  assign ready = spi_cs_n;

  wire shift_cnt_eq_zero = shift_cnt == 0;
  always @(posedge clk) begin
    if (rst) begin // Estado Reset
      state     <= S_idle;
      spi_cs_n  <= 1'b1;
      valid     <= 1'b0;
    end else begin
      case (state)
        S_idle: begin
          spi_cs_n <= 1'b1;
          valid  <= 1'b0;
          if (rd_strb) begin // Señal de lectura -> Inicializa regs de control/dato y cambia de estado
            shift_cnt <= 31;
            shift_reg <= {8'h03, 2'b00, addr[21:2],2'b00}; // Fast Read 0x03
            spi_cs_n <= 1'b0;
            state <= S_sendcomm;
          end
        end
        S_sendcomm: begin // Estado de mandar comando
          shift_cnt <= shift_cnt - 1;
          shift_reg <= {shift_reg[30:0], 1'b1};
          if (shift_cnt_eq_zero) begin // Mando el comando
            //shift_cnt <= 31;
            state <= S_rcvData; 
          end
        end
        S_rcvData: begin // Estado de recibir datos
          shift_cnt <= shift_cnt - 1;
          rcv_buff <= {rcv_buff[30:0], spi_miso};
          
          if (shift_cnt_eq_zero) // manda un pulso de un ciclo de reloj
            valid <= 1'b1; // en el siguiente ciclo
          else
            valid <= 1'b0;
          
          if (stop) begin // Si se activa stop, detiene la recepcion de datos
            state <= S_idle;
            spi_cs_n <= 1'b1;
          end
        end
      endcase     
    end
  end
  //---
endmodule
