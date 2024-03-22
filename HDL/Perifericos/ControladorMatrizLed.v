/* - Controlador de Matrices LED -
 *
 *  El controlador de matrices LED utiliza multiplexación para poder activar y desactivar una columna a la vez.
 *
 *  Recibe cuatro entradas de 8 bits que representan los valores que mostrará leds_row cuando uno y solo uno de los 
 *  bits de act_row se active en bajo. Además, posee un parámetro pwm, que va de 0 a 1023 que regula la intensidad de
 *  los leds. Estos 4 valores se mostrarán en la fila respectiva que representan.
*/


module ControladorMatrizLed #(parameter PWM = 10'd924) (
  input clk12Mhz,
  input rst, 
  input [7:0] leds1,    
  input [7:0] leds2,
  input [7:0] leds3,
  input [7:0] leds4,
  output [7:0] leds, 
  output [3:0] lcol
);
  //reg [9:0] pwm = PWM; 
  // Divisor de frecuencia del reloj
  reg [11:0] timer = 12'b0;
  always @(posedge clk12Mhz)
    if (rst)
      timer = 12'b0;
    else
      timer = timer+1;

  // Registros interno de los diodos y la fila activa
  reg [3:0] act_row; // Fila Activa
  reg [7:0] row; // Fila de diodos
  assign leds = row;
  assign lcol = act_row;

  // señal pwm para disminuir la intensidad de los leds
  wire act;
  assign act = (timer[9:0] > PWM); // Se activa cuando timer es mayor al valor del pwm

  // Multiplexacion de las señales de entrada!
  always @(posedge clk12Mhz) begin
    if (act) begin // la señal de activacion de la fila de led y no rst
      case (timer[11:10])
          2'b00: begin
              act_row <= 4'b1110;
              row <= ~leds1;
          end
          2'b01: begin
              act_row <= 4'b1101;
              row <= ~leds2;
          end
          2'b10: begin
              act_row <= 4'b1011;
              row <= ~leds3;
          end
          2'b11: begin
              act_row <= 4'b0111;
              row <= ~leds4;
          end
      endcase
    end else begin
      act_row <= 4'b1111;
      row <= 8'b1111_1111;
    end
  end

endmodule
