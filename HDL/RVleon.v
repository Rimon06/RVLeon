 
`default_nettype none

/*top*/
module RVleon(
  input clk12MHz,
  // Perifericos dentro de la placa icefun
  input [3:0] key,
  output [7:0] led,
  output [3:0] lcol,
  
  // Buzzer
  //output spkp, 
  //output spkm,
  output teclado_hab,
  output dbg_ON,

  // Transmision Serial
  input RXD,
  output TXD,

  // flash spi
  output flash_sclk,
  input  flash_miso,
  output flash_mosi,
  output flash_cs_n,

  // USB
  inout usbdm,
  inout usbdp,

  // VGA
  output [2:0] vga_red, 
  output [2:0] vga_green,
  output [1:0] vga_blue,
  output       vga_hsync,
  output       vga_vsync,

  // Puerto Serie, Depurador
  input  dbg_RXD,
  output dbg_TXD
  );//#############################################################################################
  
  wire error,end_prog;
  wire [31:0] pc, DataRead, DatatoWrite, mem_address;
  wire [3:0] Wmask;
  wire mem_read,mem_write;

  // --- inicializador ---
  wire cpu_rst;
  reg rst=1;
  reg [8:0] Espera=8'b0; // La espera es de 256 ciclos de reloj para que la memoria BRAM esté funcional
  always @(posedge clk12MHz) begin // 
    if (Espera[8]) 
      rst <= 0;
    else  Espera <= Espera+1;
  end // Inicializador lo tomara el DM

  assign cpu_rst = rst | dbg_ndmreset;

  // LEDS indicadores
  assign teclado_hab = KBRD_status[0] | MOUSE_status[0];
  assign dbg_ON = dbg_halted;
  // #################################################################################################

  wire [31:0] cpu_instr;
  wire [31:0] hitcnt, misscnt, DBG;
  wire [63:0] instret;
  wire cpu_valid_ch, cpu_stall, cpu_InstrStall, mem_stall;
  reg flag = 0;

   // --- Procesador (RV32i_Zicsr_Sdext) 
  CoreLeon #(.INIT_ADDRESS(32'h0100_0000)) RV32I (
    .clk(clk12MHz),
    .rst(cpu_rst), // Control entrada
    
    .InstrWait(cpu_stall),
    
    .error(error), // Control salida
    .end_prog(end_prog),
    
    .InstrAddr(pc), 
    .InstrData(cpu_instr), // Bus de memoria de instrucciones
    .InstrValid(cpu_valid_ch),
    .InstrStall(cpu_InstrStall),
    
    .mem_in(DataRead), // datos de entrada    
    .mem_out(DatatoWrite), //datos de salida
    .mem_address(mem_address),  // bus de direcciones
    .mem_mask(Wmask), // mascara del byte a escribir
    .mem_read(mem_read),// señal de lectura de memoria
    .mem_write(mem_write), // señal de escritura de la memoria
    .memStall(mem_stall),
    .memWait(1'b0),

    .dbg_address(dbg_address), // Bus depurador 
    .dbg_indata(dbg_datatowrite),
    .dbg_outdata(dbg_datatoread),
    .dbg_rd(dbg_rd),
    .dbg_wr(dbg_wr),
    .dbg_isvalid(dbg_isvalid),
    .dbg_ready(dbg_ready),
    .dbg_haltreq(dbg_haltreq),
    .dbg_resumereq(dbg_resumereq),
    .dbg_halted(dbg_halted)
  );

  // #################################################################################################
  // ------ zona del depurador -------------
  wire dbg_wr, dbg_rd, dbg_isvalid, dbg_ready, dbg_haltreq, dbg_resumereq, dbg_halted, dbg_ndmreset;
  wire dmi_rsp_valid, dmi_req_valid;
  wire [1:0] dmi_req_op;
  wire [6:0] dmi_req_addr;
  wire [15:0] dbg_address;
  wire [31:0] dmi_req_data, dbg_datatoread;
  wire [31:0] dmi_rsp_data, dbg_datatowrite;

  //--- Modulo depurador (DM)
  DebugModule dbgmodule(
    .clk(clk12MHz),
    .rst(rst),
    // DMI: Interfaz del modulo depurador
    .dmi_req_valid(dmi_req_valid),
    .dmi_req_addr(dmi_req_addr),
    .dmi_req_data(dmi_req_data),
    .dmi_req_op(dmi_req_op),
    .dmi_rsp_valid(dmi_rsp_valid),
    .dmi_rsp_data(dmi_rsp_data),
    // Estado del procesador
    .cpu_halted(dbg_halted),
    // Señales de cambio de estado 
    .cpu_haltreq(dbg_haltreq),
    .cpu_resumereq(dbg_resumereq),
    .cpu_ndmreset(dbg_ndmreset),
    // Señales del depurador
    .cpu_addr(dbg_address), //o
    .cpu_datatoread(dbg_datatoread),//i
    .cpu_datatowrite(dbg_datatowrite),//o
    .cpu_rd(dbg_rd),//o
    .cpu_wr(dbg_wr),//o
    .cpu_isvalid(dbg_isvalid),//o
    .cpu_ready(dbg_ready)); //i

  //--- Modulo de transporte del depurador
  DTM dbgSerialInt(
    .clk(clk12MHz),
    .rst(rst),
    // Bus UART
    .RX(dbg_RXD),
    .TX(dbg_TXD),
    //.CTS_n(dbg_CTSn),
    // Bus DMI
    .dmi_req_valid(dmi_req_valid),
    .dmi_req_addr(dmi_req_addr),
    .dmi_req_data(dmi_req_data),
    .dmi_req_op(dmi_req_op),
    .dmi_rsp_valid(dmi_rsp_valid),
    .dmi_rsp_data(dmi_rsp_data));

  // #################################################################################################
  // -------- Espacio para memoria de programa --------
 
    wire [31:0] ch_instr;
    //reg [31:0] ROM_instr;
    wire sel_instr_rom, sel_instr_ch, instr_rom_val, instr_ch_val;
    //--- Seleccionar instruccion (decodificacion)
    assign instr_ch_val = (pc[31:19] == 13'b0000_0001_0000_0);
    assign instr_rom_val = 0;
    assign cpu_instr = ch_instr;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
  // --* Direccion del flash: 0x0100_0000 al 0x0107_FFFF ( 8*64 KiB = 512 KiB === 131072 instrucciones )
    wire [23:0] ch_addr, flash_addr;
    wire ch_valid, ch_ready;
    wire [31:0] flash_data;
    wire flash_valid, flash_stop, flash_rdstrb, flash_ready;

    //--- Cache de mapeo directo de 4 KiB (mapea de 512 KiB a 4KiB)
    Icache CACHE(
      .clk(clk12MHz),
      .rst(cpu_rst),
      // interfaz con el procesador riscv
      .cpu_addr(pc[19:0]),
      .instr(ch_instr),
      .cpu_strobe(cpu_valid_ch && instr_ch_val),
      .cpu_stop(cpu_stall),

      .cpu_rdEN(!cpu_InstrStall),

      // Estado del cache
      .ch_ready(ch_ready),

      // interfaz con la memoria flash
      .mem_addr(ch_addr[19:0]),
      .mem_instr(flash_data),
      .mem_next(flash_valid),
      .mem_valid(flash_ready),
      .mem_rdstrb(flash_rdstrb),
      .mem_stop(flash_stop)
    );
    //--- Ajuste a dirección real en la memoria flash (pues se usan del sector 8 al 15)
    assign flash_addr = {4'b0,1'b1,ch_addr[18:0]};
    //--- Maestro Flash SPI. Permite despertar y leer hasta que externamente se mande señal de stop.
    flashSPI flash(
      .clk(clk12MHz),
      .rst(cpu_rst),
      
      .rd_strb(flash_rdstrb),
      .stop(flash_stop),
      .addr(flash_addr[21:0]),
      
      .data(flash_data),
      .valid(flash_valid),

      .ready(flash_ready),
      
      .spi_cs_n(flash_cs_n),
      .spi_miso(flash_miso),
      .spi_mosi(flash_mosi),
      .spi_sclk(flash_sclk)
      );
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  // #################################################################################################
  // #################################################################################################
  
  // ----- Espacio para memoria de datos -----
    localparam TAM_RAM = 1024;//1536; // 4092 bytes - 1024 palabras 
    localparam TAM_BUS_RAM = $clog2(TAM_RAM); // El cual debe dar 10
    wire [TAM_BUS_RAM-1:0] RAM_address = mem_address[TAM_BUS_RAM+1:2];    

    
    wire [15:0] IO_address = mem_address[17:2];
    wire [31:0] RAM_data, LEDS_data, LEDS_config_data, UART_data;
    
    // -- Decodificacion de las direcciones de datos
    wire ram_valid        = ({mem_address[31],mem_address[14:12]} == 4'b0);
    wire io_valid         = (mem_address[31]  ==  1'b1);

    (*onehot*) wire [15:0] valid_deco;
    wire vga_data_val     = mem_address[13];

    assign valid_deco = (io_valid && !vga_data_val) ? (1'b1 << mem_address[6:2]) : 16'b0;
    wire boton_val        = valid_deco[0]; // (mem_address[17:2] == 16'd0);
    wire leds_val         = valid_deco[1]; // (mem_address[17:2] == 16'd1); 4
    //  wire leds_config_val  = valid_deco[2]; // (mem_address[17:2] == 16'd2); 8
    wire uart_val         = valid_deco[3]; // (mem_address[17:2] == 16'd3); C
    wire kbrd_status_val  = valid_deco[4]; // (mem_address[17:2] == 16'd4); 10
    wire kbrd_keys_val    = valid_deco[5]; // (mem_address[17:2] == 16'd5); 14
    wire mice_status_val  = valid_deco[6]; // (mem_address[17:2] == 16'd6); 18
    wire mice_data_val    = valid_deco[7]; // (mem_address[17:2] == 16'd7); 1C
    //  wire oled_comm_val    = valid_deco[8]; // (mem_address[17:2] == 16'd8);  20
    //  wire oled_data_val    = valid_deco[9]; // (mem_address[17:2] == 16'd9); 24
    wire vga_regs_val     = valid_deco[10]; // (mem_address[17:2] == 16'd10); 28


    // -- Registro de lectura de I/O, con io multiplexado
    reg [31:0] IO_data;
    reg IO_sig, ram_sig;
    // los datos I/O pasaran a través de un registro de lectura, esto para que la etapa Wb tenga el valor correcto...
    always @(posedge clk12MHz) begin 
      if (cpu_rst) begin
        IO_sig <= 0;
        ram_sig <= 0;
      end else if (!mem_stall) begin // 
        IO_sig  <= io_valid;
        ram_sig <= ram_valid;
      end
      if (!mem_stall)
        IO_data <= IO_in;
    end
    // -- multiplexor final...
    assign DataRead = ((ram_sig) ? RAM_data: 32'b0) |
                      ((IO_sig)  ? IO_data : 32'b0) ;

    wire [31:0] IO_in;

    assign IO_in = ((boton_val)      ? {24'b0,4'b0,~key}     :32'b0) | // Lee botones aqui
                   ((leds_val)       ? LEDS_data             :32'b0) |
                   ((uart_val)       ? UART_data             :32'b0) |
                   ((kbrd_status_val)? {16'b0,KBRD_status}   :32'b0) |
                   ((kbrd_keys_val)  ? KBRD_keys             :32'b0) |
                   ((mice_status_val)? {24'b0,MOUSE_status}  :32'b0) |
                   ((mice_data_val)  ? MOUSE_data            :32'b0) |
                   ((vga_regs_val)   ? VGA_status            :32'b0) ;

  // #################################################################################################

  // --* memoria BRAM: 0x0000_0000 al 0x0000_17FF (6KiB)
  // --> Lectura y escritura por mem_address
    // -- Bloque RAM
    memory #(TAM_RAM) RAM_6KiB ( 
      .clk(clk12MHz),
      .rst(cpu_rst),
      .valid(ram_valid && !mem_stall),
      .read(mem_read),
      .WRmask(Wmask),
      // Bus de direcciones
      .Addr(RAM_address), 
      .DataIn(DatatoWrite),
      .DataOut(RAM_data)
    );
    
  // --* Espacio de memoria para la matriz led
  // 0x8000_0004 al 0x8000_0007: Registros de datos (leds)

    //--- registro de datos leds1 a leds4    
    reg [7:0] leds1,leds2,leds3,leds4;
    assign LEDS_data = {leds4,leds3,leds2,leds1};

    always @(posedge clk12MHz) begin 
      if (cpu_rst) begin
        {leds4,leds3,leds2,leds1} <= 32'h00000000;
      end else if (leds_val) begin
        if (Wmask[3]) leds4<=DatatoWrite[31:24];
        if (Wmask[2]) leds3<=DatatoWrite[23:16];
        if (Wmask[1]) leds2<=DatatoWrite[15:8];
        if (Wmask[0]) leds1<=DatatoWrite[7:0];
      end
    end

    //--- Controlador de Matrices led ...
    ControladorMatrizLed LEDS8_4(
      .clk12Mhz(clk12MHz),
      .rst(cpu_rst),//&(!leds_en)), 
      .leds1(leds1),    
      .leds2(leds2),
      .leds3(leds3),
      .leds4(leds4),
      .leds(led), 
      .lcol(lcol)
    );
  
  // --* Espacio de Bloque UART 
  // TX/RX: 0x8000_000C
  // control-estado: 0x8000_000D al 0x8000_000F
    wire txBusy,txDone;
    reg tx_ready;
    // -- Bloque emisor
    serialTX UART_TX(
      .clk(clk12MHz),
      .data(DatatoWrite[7:0]),
      .txmit(uart_val&Wmask[0]),
      .TX(TXD),
      .busy(txBusy),
      .done(txDone) );
    
    // registro tx_ready
    always @(posedge clk12MHz) begin
      if (cpu_rst)     tx_ready <= 1;
      else if (txBusy) tx_ready <= 0;
      else if (txDone) tx_ready <= 1;
    end

    wire rxBusy,rxRCV;
    wire [7:0] rxData;
    reg [7:0] SerialData;

    // -- Bloque receptor
    serialRX UART_RX(
      .clk(clk12MHz),
      .RX(RXD),
      .data(rxData),
      .busy(rxBusy),
      .rcv(rxRCV) );

    reg rx_readed = 1; 
    always @(posedge clk12MHz) begin
      if (cpu_rst) begin
        rx_readed <= 1;
      end else if (rxRCV) begin
        rx_readed <= 0;
      end else if (mem_read && uart_val && Wmask[0]) begin
        rx_readed <= 1;
      end
    end

    // idealmente, cuando ocurre un rxRCV, SerialData debe colocar su nuevo valor...
    always @(posedge clk12MHz) begin
      if (rxRCV)
        SerialData <= rxData;
      else if (rx_readed | cpu_rst)
        SerialData <= 8'b0;
    end
      
   assign UART_data = {15'b0,rx_readed,7'b0,tx_ready,SerialData}; // No implementado RX todavia 

  // --* Espacio de memoria para la pantalla oled
  //  0x8000_0010 al 0x8000_0017: Registros del Teclado USB
  //  0x8000_0018 al 0x8000_001F: Registros del raton USB

  wire [15:0] KBRD_status;
  wire [31:0] KBRD_keys, MOUSE_data;
  wire [7:0] MOUSE_status;
  UKPtoRVLeon USB_KBRD_MOUSE (
    .clk(clk12MHz),
    .rstn(~cpu_rst),
    .cpu_rdstrb(mem_read),
    .cpu_valid((kbrd_keys_val | mice_data_val)), 
    .HID_printer_status(), // [7:0] 
    // keyboard
    .KBRD_status(KBRD_status),
    .KBRD_keys(KBRD_keys),
    //mouse
    .MOUSE_status(MOUSE_status),
    .MOUSE_data(MOUSE_data),
    // USB
    .usbdm(usbdm),
    .usbdp(usbdp)
);

  // --* Espacio de memoria para la pantalla oled
  // 0x8000_0020 al 0x8000_0023: Enviar comando y registro de estado busy
  // 0x8000_0024 al 0x8000_0027: Enviar Caracter

  // --* Espacio para la pantalla VGA
  // 0x8000_0028 al 0x8000_002B: Registros de control y de color
  // 0x8001_0000 al 0x8001_12BF: Framebuffer
 
    reg [7:0] vga_color_bkn = {3'b111,3'b111,2'b11}; // color fondo
    reg [7:0] vga_color_txt = {3'b000,3'b000,2'b00}; // color texto

    reg vga_hab, vga_sel_mode=0;
    wire vga_blank;
    always @(posedge clk12MHz) begin
      if (cpu_rst) begin
        vga_color_txt   <= 8'b000_000_00; // (blanco)
        vga_color_bkn   <= 8'b111_111_11; // (negro)
        {vga_sel_mode, vga_hab} <= 2'b00;
      end else if (vga_regs_val) begin
        if (Wmask[3]) vga_color_bkn <= DatatoWrite[31:24];
        if (Wmask[2]) vga_color_txt <= DatatoWrite[23:16];
        if (Wmask[0]) {vga_sel_mode, vga_hab} <= DatatoWrite[1:0];
      end
    end

    wire [31:0] VGA_status = {vga_color_bkn,vga_color_txt,8'b0,5'b0,vga_blank,vga_sel_mode,vga_hab};

    VGA pantalla__UUT (
      .clk(clk12MHz),
      .rst(!vga_hab),
      .i_sel_mode(vga_sel_mode),
      .i_wraddr(mem_address[12:2]),
      .i_data(DatatoWrite),
      .i_wmask(Wmask),
      .i_wr(vga_data_val),
      .i_color_bkn(vga_color_bkn),
      .i_color_txt(vga_color_txt),
      .o_red(vga_red),
      .o_green(vga_green),
      .o_blue(vga_blue),
      .o_hsync(vga_hsync),
      .o_vsync(vga_vsync),
      .o_blank(vga_blank)
      //.o_framecnt(framecnt)
    );
//#################################3
endmodule //#########################################################################################

// memory instancia un bloque de TAM x 32. Este debe de ser menor a 16384
module memory #(
  parameter TAM = 2048,
  parameter Addrbits =$clog2(TAM) // bit mas significativo de la direccion de memoria
  )(
  input clk,
  // Señales de control
  input rst,
  input [3:0] WRmask, // Señales de escritura
  input valid, // señal si dato es valido
  input read, // Señal de lectura
  // Bus de direcciones
  input [Addrbits-1:0] Addr, 
  // Bus de Datos de entrada/salida
  input  [31:0] DataIn,
  output [31:0] DataOut
  );//################################################################################################

  reg [31:0] memArray [TAM-1:0]; // Bloque de memoria de TAMx32 bits

  // La memoria de datos solo escribe si WRmask!=0 y es valido 
  wire dWE = (!rst) & valid;  // Write Enable & (|WRmask) (no es necesario )
  wire dRE = (!rst) & read & valid; // Read Enable
  reg [31:0] DataOut;
  
  initial begin
    $readmemh("data.hex", memArray);
  end
  
  // Bloque de escritura de datos
  always @(posedge clk) begin
    if (dWE) begin
      if (WRmask[0]) memArray[Addr][7:0]   <= DataIn[ 7: 0]; 
      if (WRmask[1]) memArray[Addr][15:8]  <= DataIn[15: 8];
      if (WRmask[2]) memArray[Addr][23:16] <= DataIn[23:16];
      if (WRmask[3]) memArray[Addr][31:24] <= DataIn[31:24];
    end
    if (dRE)
      DataOut <= memArray[Addr];
  end

  //--
endmodule //######################################################################################