/*
https://github.com/narendiran1996/vga_controller/blob/main/vga_timing_specs.csv
http://martin.hinner.info/vga/timing.html
http://www.tinyvga.com/vga-timing/640x480@60Hz
detalles con los colores:
  https://en.wikipedia.org/wiki/List_of_8-bit_computer_hardware_graphics#8-bit_RGB_palettes
  * Niveles de colores RGB de 3-3-2 a 8-8-8
    3'b000 -> 8'h00  |  2'b00  8'h00
    3'b001 -> 8'h24  |  2'b01  8'h55
    3'b010 -> 8'h49  |  2'b10  8'hAA
    3'b011 -> 8'h6D  |  2'b11  8'hFF
    3'b100 -> 8'h92
    3'b101 -> 8'hB6
    3'b110 -> 8'hDB
    3'b111 -> 8'hFF
*/
`default_nettype none

`define MY_VGA_DEFAULT_PARAMS parameter \
  /* VGA_640_480_73Hz   */    \
  VPOL            = 0,        \
  HPOL            = 0,        \
  FRAME_RATE      = 73,       \
  /* horizontal timing frame*/\
  HACTIVE         = 640,      \
  HFP             =  24,      \
  HSYNCLEN        =  40,      \
  HBP             =  128,      \
  /* vertical timing frame */ \
  VACTIVE         = 480,      \
  VFP             =  9,      \
  VSYNCLEN        =  2,      \
  VBP             =  29 
  // /* VGA_640_480_60Hz   */    \
  // VPOL            = 0,        \
  // HPOL            = 0,        \
  // FRAME_RATE      = 60,       \
  // /* horizontal timing frame*/\
  // HACTIVE         = 640,      \
  // HFP             =  16,      \
  // HSYNCLEN        =  96,      \
  // HBP             =  48,      \
  // /* vertical timing frame */ \
  // VACTIVE         = 480,      \
  // VFP             =  10,      \
  // VSYNCLEN        =   2,      \
  // VBP             =  33      

module VGA #(`MY_VGA_DEFAULT_PARAMS, TILESIZE = 8
  )(
  input clk,
  input rst,
  input i_sel_mode,
  input [10:0] i_wraddr,
  input [31:0] i_data,
  input i_wr,
  input [3:0] i_wmask,
  input [7:0] i_color_txt,
  input [7:0] i_color_bkn,
  // salidas
  output o_blank,
  output [2:0] o_red,
  output [2:0] o_green,
  output [1:0] o_blue,
  output o_hsync,
  output o_vsync,
  );

  localparam HTILES       = HACTIVE/TILESIZE; // 640 / 8 = 80
  localparam VTILES       = VACTIVE/TILESIZE; // 480 / 8 = 60
  localparam BIT_USE      = $clog2(TILESIZE); // 3 para 8
  localparam FBUFFER_SIZE = HTILES*VTILES; // 4800 bytes
  localparam VTOTAL    = VACTIVE + VFP + VSYNCLEN + VBP;
  localparam HTOTAL    = HACTIVE + HFP + HSYNCLEN + HBP;
  
  localparam FBUFFER_ADDR_LENGTH = $clog2(FBUFFER_SIZE); // ~12.22 -> 13 bits de longitud
  localparam HTILES_bits = $clog2(HTILES); // ~6.32 -> 7
  localparam VTILES_bits = $clog2(VTILES); // ~5.9 -> 6

  wire px_clk; // 25MHz ~

  /**
  * PLL configuration
  * Given input frequency:        12.000 MHz
  * Requested output frequency:   31.5 MHz
  * Achieved output frequency:    31.5 MHz
  */
  SB_PLL40_CORE #(
    .FEEDBACK_PATH("SIMPLE"),
    .DIVR(4'b0000),   // DIVR =  0
    .DIVF(7'b1010011),  // DIVF = 83
    .DIVQ(3'b101),    // DIVQ =  5
    .FILTER_RANGE(3'b001) // FILTER_RANGE = 1
  ) PLL(
    .REFERENCECLK(clk),
    .PLLOUTGLOBAL(px_clk),
    .RESETB(1'b1),
    .BYPASS(1'b0)
  );

  //-- Contador horizontal y vertical y Generador de sincronismo
  wire hsync, vsync, blank;
  wire [9:0] hcnt, vcnt;
  sync_vga  sync_gen (
    .px_clk(px_clk),
    .rst(px_rst2),
    .o_hcnt(hcnt),
    .o_vcnt(vcnt),
    .o_hsync(hsync),
    .o_vsync(vsync),
    .o_blank(blank));

    //-- Codificador de indice a direccion
  wire [12:0] address;

  wire [HTILES_bits -1 : 0] index_x = hcnt[9:3];// >> BIT_USE; // 7 bits de lUsara hcnt[9:3]
  wire [VTILES_bits -1 : 0] index_y = vcnt[8:3];// >> BIT_USE; // 6 bits de longitud
  // assign index = hcnt[9:BIT_USE]+HTILES*vcnt[8:BIT_USE];
  assign address = index_x + HTILES*index_y;

  //-- framebuffer de 5120 bytes, (Se usaran exactamente HTILES*VTILES=4800 + 18 (16 de paleta de colores + color de letra y banckground)
  reg [31:0] framebuffer  [0:1279];//FBUFFER_SIZE-1];

  //Escritura
  always @(posedge clk) begin // Se usa el reloj del sistema, pues aqui es la interfaz para escritura
    if (i_wr) begin
      if (i_wmask[0]) framebuffer[i_wraddr][ 7: 0] <= i_data[ 7: 0];
      if (i_wmask[1]) framebuffer[i_wraddr][15: 8] <= i_data[15: 8];
      if (i_wmask[2]) framebuffer[i_wraddr][23:16] <= i_data[23:16];
      if (i_wmask[3]) framebuffer[i_wraddr][31:24] <= i_data[31:24];
    end
  end
  
  // lectura
  // -- Segmentacion
  reg [7:0] character;
  reg hsync_q = !HPOL,
      vsync_q = !VPOL,
      blank_q = 0;
  reg [2:0] px_x=0,px_y=0; // para TILESIZE=8, [2:0] (3 bis)

  (*onehot*) reg [3:0] lsb_address;

  reg [31:0] full_data;
  
  reg px_rst2=1, px_rst1=1;
  always @(posedge px_clk) begin
    px_rst1 <= rst;
    px_rst2 <= px_rst1;
    full_data <= framebuffer[address[12:2]];
    lsb_address <= 1 << address[1:0];
    hsync_q   <= hsync;
    vsync_q   <= vsync;
    blank_q   <= blank | px_rst2;
    px_x      <= hcnt[2:0]; 
    px_y      <= vcnt[2:0];
  end

  //--Seleccion del caracter
  always @* begin
    case (1'b1)
      lsb_address[0]: character = full_data[ 7: 0];
      lsb_address[1]: character = full_data[15: 8];
      lsb_address[2]: character = full_data[23:16];
      lsb_address[3]: character = full_data[31:24];
      default: character = 0;
    endcase
  end
  
  
  //-- Generador de patrones 8x8
  wire [63:0] letra;
  asciiTo8x8_ Gen_patron( 
   .character(character),
   .letra(letra)); 

  reg [7:0] px_fila;
  reg px_bit;
  wire [7:0] px_color, px_txt;
  wire [7:0] sel_color;

  //-- Decodificacion
  always @(*) begin
    case(px_y[2:0]) 
      7: px_fila = letra[ 7: 0];
      6: px_fila = letra[15: 8];
      5: px_fila = letra[23:16];
      4: px_fila = letra[31:24];
      3: px_fila = letra[39:32];
      2: px_fila = letra[47:40];
      1: px_fila = letra[55:48];
      0: px_fila = letra[63:56];
    endcase

    px_bit = px_fila >> px_x;

  end
 
  assign px_txt = px_bit? i_color_txt: i_color_bkn;
  assign px_color = character;
  
  //-- Seleccion del color
  reg isel;
  always @(posedge px_clk) begin 
      isel <= i_sel_mode;
  end

  assign sel_color = isel ? px_color : px_txt;

  SB_IO #(
    .PIN_TYPE(6'b0101_00) // 0101: latched output / 00: no input
  ) user_IO[9:0] (         // Yes, in Verilog you can declare 4 pins in 1 decl
    .PACKAGE_PIN( {o_red[2:0],o_green[2:0],o_blue[1:0],  o_vsync, o_hsync}),
    .D_OUT_0({blank_q? 8'b0 : sel_color[7:0], vsync_q, hsync_q}),
    .OUTPUT_CLK({10{px_clk}})
  );
  assign o_blank = blank_q;

endmodule

// Entrega hsync, vsync y blank en base al valor actual del contador 
module sync_vga #(`MY_VGA_DEFAULT_PARAMS) (
  input px_clk,
  input rst,
  output reg [9:0] o_hcnt = 0,
  output reg [9:0] o_vcnt = 0,
  output o_hsync,
  output o_vsync,
  output o_blank
  );

  localparam VTOTAL    = VACTIVE + VFP + VSYNCLEN + VBP;
  localparam HTOTAL    = HACTIVE + HFP + HSYNCLEN + HBP;
  reg vsync, hsync, blank;

  assign o_vsync  = vsync;
  assign o_hsync  = hsync; 
  assign o_blank  = (o_hcnt >= HACTIVE) || (o_vcnt >= VACTIVE);

  always @(*) begin
    if ( (o_vcnt >= VACTIVE + VFP) && (o_vcnt < VACTIVE + VFP + VSYNCLEN ))
      vsync =  VPOL; 
    else begin
      vsync = !VPOL;
    end
    if ( (o_hcnt >= HACTIVE + HFP) &&  (o_hcnt < HACTIVE + HFP + HSYNCLEN ))
      hsync = HPOL;
    else 
      hsync = !HPOL;
  end

  wire hcycle = ((o_hcnt == (HTOTAL -1)) || rst);
  wire vcycle = (o_vcnt == (VTOTAL -1)) || rst;

  always @(posedge px_clk) begin
    if (hcycle) begin
      o_hcnt <= 0;
      if (vcycle) o_vcnt <= 0;
      else        o_vcnt <= o_vcnt + 1;
    end else begin
      o_hcnt <= o_hcnt + 1;
    end
  end

endmodule
