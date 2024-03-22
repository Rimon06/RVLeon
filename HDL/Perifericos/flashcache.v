// Este modulo implementa una memoria Caché de mapeo directo

// Cuando detecta un MISS, manda una señal de mem_rdstrb en conjunto con la dirección base de la linea.
// La memoria principal, a través de una especie de DMA, recibe dicha información inicial y envia al cache instruccion por instruccion
// cada vez que tiene lista una instrucción, manda como señal mem_next. Ademas, mem_rdstrb seguira activada en todo el proceso.

// Hay que esperar que las 16 instrucciones se carguen a memoria cache para que el cpu las lea. Cuando esto ocurre, mem_stop se activa para
// detener la lectura a memoria principal.

// ch_ready durante el proceso estará desactivado y en cuanto se detenga, volvera a activarse.

/*******************************************
      Notas sobre la interfaz
  Para que no genere errores la lectura del cache, cada dato debe venir con una señal de validacion:
  * cpu_addr y cpu_strobe: si cpu manda una direccion invalida, este se lo indicara al cache con cpu_strobe = 0
    y el cache no realizará un MISS ni un HIT, ignorando addr (casos donde ocurre un salto).
  * instr y ch_ready, de tal forma que instr debe ser ignorada por el cpu cuando ch_ready=0. 
  * mem_addr y mem_rdstrb. Inicialmente mem_rdstrb habilita la lectura de la memoria a partir de la direccion mem_addr entregada.
    mem_rdstrb se desactivará en el momento en que haya leído 16 instrucciones...
  * mem_instr y mem_next. Cuando la memoria principal posea la instruccion de la direccion indicada, mem_next se activara, indicando
    indicando que mem_instr es un dato valido a guardar en el cache.
  * El cpu debe asegurar que pc no cambie cuando cpu_stop = 1.
********************************************/

module Icache (
  input     clk,
  input     rst,
  // interfaz con el procesador riscv
  input     [19:0] cpu_addr,
  output    reg [31:0] instr,
  input     cpu_strobe,
  output    cpu_stop,
  input     cpu_rdEN,
  // Estado del cache
  output    ch_ready,
  output    ch_MISS, // para contadores
  output    ch_HIT,  // para contadores

  // interfaz con la memoria flash ha recibir cuando ocurra un cache MISS
  output    [19:0] mem_addr,
  input     [31:0] mem_instr,
  input     mem_valid,
  input     mem_next,
  output    mem_rdstrb,
  output    mem_stop
  );
  localparam S_IDLE = 0;
  localparam S_LOAD_CACHE = 1;
  

  //-- Memoria Cache
  reg [31:0] CACHE [0:1023]; // 4Kbyte de cache.
  reg valid     [0:15]; // valid sera uno, pero mantengamoslo por si acaso
  reg [7:0] tag [0:15]; // tag es uno, pero mantengamosolo.
  
  integer i; // inicializacion de memoria cache en simulacion
  `ifdef BENCH
  initial begin
    for(i=0;i<1023;i=i+1) begin
      if (i<16) begin
        valid[i] =1'd0;
        tag[i] = 12'd0;
      end
      CACHE[i] <= 32'd0;
    end
  end
  `endif
  
  wire [9:0]  index_o = cpu_addr[11: 2]; // linea + index ([11:8]+[7:2])
  wire [9:0] index_i = counter[9:0];
  always @(posedge clk) begin 
    if (cpu_rdEN)
      instr <= CACHE[index_o];
  
    if (write_cache)
      CACHE[index_i] <= mem_instr;
  end

  //-- Direccion que se mandara a leer de la memoria principal
  reg [7:0] tag_to_save = 0;
  assign mem_addr = {tag_to_save,counter[9:0],2'b00}; // {pc_tag,set,6'b0}

  //-- Deteccion de HIT
  wire [7:0] pc_tag  = cpu_addr[19:12]; // pc_tag
  wire       isValid = valid[index_o[9:6]]; //
  wire [7:0] ActTag = tag[index_o[9:6]];   
  
  wire HIT    = isValid & (pc_tag == ActTag);


  //-- Registro de estado y de contador. Escritura de Tag y valid
  reg state;
  reg [9:0] counter;
  reg mode=1;
  
  wire ov_line_cntr = &(counter[5:0]);
  wire ov_page_cntr = &(counter[9:6]); // counter == 10'b1111

  //-- Estado salida
  reg ch_ready, cpu_stop, mem_rdstrb, mem_stop, write_cache;
  reg ch_MISS, ch_HIT;

  always @(*) begin
    cpu_stop = 0; ch_ready = 0;  write_cache = 0; mem_rdstrb = 0;  mem_stop = 1;
    ch_MISS = 0; ch_HIT = 0;
    case (state)
      S_IDLE: begin
        ch_ready = 1;
        ch_MISS = ~HIT & cpu_strobe & mem_valid;
        ch_HIT  =  HIT & cpu_strobe & mem_valid; // Ocurre con cpu_strobe, pero al detener
        
        cpu_stop = ~HIT & cpu_strobe; // Ocurre un ch_MISS 
      end
      S_LOAD_CACHE: begin
        cpu_stop = 1; mem_rdstrb = 1; mem_stop = 0;
        if (mem_next) begin // Escribir en cache cuando dan valor
          write_cache = 1;
          if (ov_line_cntr && (ov_page_cntr || !mode)) begin // si overflow, detener lectura de flash
             mem_stop = 1;
             mem_rdstrb = 0;
          //   //cpu_stop = 0;
           end
        end
      end
    endcase
  end

  always @(posedge clk) begin
    if (rst) begin
      state <= S_IDLE;//bloque
      for (i=0; i<16;i=i+1) begin
        valid[i] <= 0;
      end
      mode <= 1;
    end else begin
      case(state)
        S_IDLE: begin
          if (ch_MISS) begin // Si ocurre un miss, debemos detener el procesador 
            state <= S_LOAD_CACHE;
            valid[index_o[9:6]] <= 0;

            counter <= (mode) ? 10'b0 : {cpu_addr[11:8],6'b0}; // Counter se puede inicializar en el valor donde ocurre el miss
            
            tag_to_save <= pc_tag;
            // Control
            // mem_rdstrb <= 1;
            // mem_stop <= 0;
          end
        end
        S_LOAD_CACHE: begin // cargar cache
          if (mem_next) begin // incrementar counter cuando dan valor
            counter <= counter+1;
            if (ov_line_cntr) begin // si counter esta en overflow, devolver estado
              valid[index_i[9:6]] <= 1;

              tag[  index_i[9:6]] <= tag_to_save;

              if (!mode) begin
                state <= S_IDLE;
                // mem_stop <= 1;
//                mem_rdstrb <= 0;
              end else if (ov_page_cntr) begin
                state <= S_IDLE;
                // mem_stop <= 1;
                // mem_rdstrb <= 0;
                mode <= 0;
              end
            end
          end
        end
      endcase
    end 
  end
  


endmodule