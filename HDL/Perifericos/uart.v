// `include "uart.vh"
//-- Constantes para obtener las velocidades estándares
  // BAUD=115200 - 104
  // BAUD=57600  - 208
  // BAUD=38400  - 313
  // BAUD=19200  - 625
  // BAUD=9600   - 1250

/* Modulo generador de baudios*/
module BaudClock #(parameter BAUD=115200, CLK_GEN=12000000)
  (
    input clk,
    input clk_ena,
    output clk_out
  );
  //---- GENERADOR DE BAUDIOS
   //-- Ciclos de reloj para la velocidad de transmisión y freqcuencia del reloj
  localparam BAUDRATE = (CLK_GEN/BAUD); //con 12000000/115200 ~= 104 ciclos de reloj
  localparam N = $clog2(BAUDRATE); //-- Numero de bits para almacenar BAUDRATE

  //-- Contador para implementar el divisor
  //-- Es un contador modulo BAUDRATE
  reg [N-1:0] divcounter = BAUDRATE-1;

  //-- Cable de reset para el contador
  wire reset = clk_out | (!clk_ena);

  //-- Contador con reset
  always @(posedge clk)
    if (reset)   divcounter <= BAUDRATE-1;
    else         divcounter <= divcounter - 1;

  //-- Tic de salida
  wire clk_out = (divcounter == 0);
endmodule

module serialTX #(parameter BAUD=115200, CLK_GEN=12000000)
  ( input clk,
    input [7:0] data,
    input txmit,
    output TX,
    output busy,
    output done
  );

  //--
  wire shift;
  BaudClock #(BAUD, CLK_GEN) bclk (
    .clk(clk),
    .clk_ena(state),
    .clk_out(shift));

  //-- Detector de flancos de subida
  reg q_re = 0;
  wire txmit_tic;
  always @(posedge clk)  q_re <= txmit;

  assign txmit_tic = (~q_re & txmit); 

  //-- Controlador: Estado de transmisor
  reg state = 0; //-- 0: Parado; 1: Ocupado (transmitiendo)
  always @(posedge clk)
    if (txmit) //-- Empieza la transmision: ocupado
      state <= 1'b1;
    else if (ov) //-- Acaba la transmision: libre    
      state <= 1'b0;

  //-- REGISTRO DESPLAZAMIENTO
  //-- Registro de desplazamiento de 9 bits
  reg [8:0] q = 9'h1FF; //-- Inicializado todo a 1s
  reg TX = 1; //-- Salida serie. Inicialmete a 1 (reposo) 
  always @(posedge clk) begin
    if (txmit_tic) //-- Carga del registro
      q <= {data, 1'b0};    
    else if (shift) //-- Desplazamiento. Rellenar con 1 (bit de stop)
      q <= {1'b1, q[8:1]};

    TX <= q[0]; //-- Sacar el bit de menor peso por serial-out    
  end

  //-- Comprobar si se ha transmitido el último bit (overflow)
  wire ov = (bits == 10);   //-- 1 bit de start + 8 bits de datos + 1 bit de stop
  //-- La señal de ocupado es el estado del transmisor
  assign busy = state;
  //-- Contador de bits enviados
  reg [3:0] bits = 0;
  reg done=0; //-- Registro done; Con un ciclo de retraso
  always @(posedge clk) begin
    if (ov) //-- Si la cuenta ha terminado... volver a 0
      bits <= 2'b00;
    else if (shift)
      bits <= bits + 1;

    done <= ov;
  end
endmodule

module serialRX #(parameter BAUD=115200, CLK_GEN=12000000)(
  input clk,
  input RX,
  output [7:0] data,
  output busy,
  output rcv
  );

  // Sincronizacion. Evitar problema de la metaestabilidad
  //-- Din contiene el dato serie de entrada listo para usarse   
  reg d1, din, q_t0 = 0;
  always @(posedge clk) begin
    d1   <= RX;
    din  <= d1;
    q_t0 <= din;
  end
  //------ Detector de flanco de bajada de RX
  wire din_fe = (q_t0 & ~din); // bit de start

  //-------- ESTADO DEL RECEPTOR
  reg state = 0; //-- 0: Apagado; 1: Encendido.
  always @(posedge clk)
    if (din_fe)
      state <= 1'b1; // empieza a recibir datos
    else if (rst_state) //-- Se pasa al estado inactivo al contar 9 tics (se espera haber recibido el dato correctamnete)
      state <= 1'b0; // 

//------------------ GENERADOR DE BAUDIOS -----------------------------
  
  //-- Constante para calcular los baudios
  localparam BAUDRATE = CLK_GEN/BAUD;
  localparam BAUD2 = (BAUDRATE >> 1); // La mitad del BAUDRATE, pa un valor de retraso luego del flanco de bajada
  localparam N = $clog2(BAUD2); //-- numero de bits para almacenar BAUDRATE

  //-- Contador del sistema, activa el BaudClock principal a partir de la mitad, para el muestreo.
  reg [N-1: 0] div2counter = 0;
  reg baudCLK, // Reloj de Baudios
      enclk; //
  always @(posedge clk) begin
    if (state && !ena2) begin  //-- Contar
      div2counter <= div2counter - 1; 
    end else begin
      div2counter <= BAUD2;
    end

    if (!state) begin
      baudCLK <= 0;
      enclk <= 0;
    end else if (ena2) begin
      baudCLK <= ~baudCLK;
      enclk <= 1; //
    end
  end

  wire ena2 = (div2counter == 0);
  //--- GENERADOR DE BAUDIOS PRINCIPAL
  wire bit_tic = ena2 & ~baudCLK & enclk; // Detector de flanco de subida

//-------- REGISTRO DE DESPLAZAMIENTO -----------
  //-- Es un registro de 9 bits: 8 bits de datos + bit de stop. El bit de start no se almacena

  reg [8:0] sr = 0;
  always @(posedge clk) begin 
    if (bit_tic) sr <= {din, sr[8:1]};
  end
      
  //-- El dato recibido se encuentran en los 8 bits menos significativos
  //-- una vez recibidos los 9 bits

//-------- CONTADOR de bits recibidos
  reg [3:0] cont = 0;
  always @(posedge clk)
    if ((state==0) || rst_state) begin
      cont <= 0;
    end else if (bit_tic)  //-- Receptor activado: Si llega un bit se incrementa
      cont <= cont + 1;
        
  //-- Comprobar overflow, indica el final de recepcion
  wire rst_state = (cont == 9);

//----- REGISTRO DE DATOS -------------------
  //-- Registro de 8 bits que almacena el dato final

  //-- Bus de salida con el dato recibido
  // assign data = sr[7:0];
  reg rcv = 0;
  reg [7:0] data;
  always @(posedge clk) begin
    rcv <= rst_state; //-- Comunicar que se ha recibido un dato
    if (rst_state)
      data <= sr[7:0];
  end

  //-- La señal de busy es directamente el estado del receptor
  assign busy = state;


endmodule