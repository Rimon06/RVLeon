

module hid_reader (
  input clk,
  input resetn,

  input [1:0] usb_type, 
  input usb_report,
  input read,
  input [63:0] hid_report,

  output reg [7:0] key_modifiers,
  output reg [7:0] key1, key2, key3, key4,

  output reg[7:0] mouse_btn,
  output reg signed [7:0] mouse_dx,
  output reg signed [7:0] mouse_dy,

  output report_no_readed,
  output report_lost_data
);

  wire act_keybrd = usb_type[0];
  wire act_mouse  = usb_type[1];


  reg report_no_readed, report_lost_data;

  // Reporte de datos leidos/perdidos
  always @(posedge clk) begin : report_signals
    if (usb_report) begin
      report_no_readed <= 1'b1;
    end

    if (report_no_readed && usb_report)
      report_lost_data <= 1'b1;

    if (read || !resetn|| (usb_type==0)) begin
      report_no_readed <= 1'b0;
      report_lost_data <= 1'b0;
    end

  end

  // Registros de datos del teclado
  always @(posedge clk) begin : keys_data
    if (!resetn || !act_keybrd) begin
      key1 <= 0; key2 <= 0; key3 <= 0; key4 <= 0;
      key_modifiers <= 0;
    end else if (usb_report) begin  // keyboard
      // Guarda los 4 scancodes, y el modificador
      key1 <= hid_report[23:16];
      key2 <= hid_report[31:24];
      key3 <= hid_report[39:32];
      key4 <= hid_report[47:40];
      key_modifiers <= hid_report[7:0];
    end
  end

  //-- Registros de Datos del raton
  always @(posedge clk) begin : mouse_data
    if (!resetn || !act_mouse) begin
      mouse_btn <= 0;
      mouse_dx  <= 0;
      mouse_dy  <= 0;
    end else if (usb_report) begin
      mouse_btn <= hid_report[7:0]; // {5'bx, middle, right, left}
      mouse_dx  <= hid_report[15:8];
      mouse_dy  <= hid_report[23:16];
    end else if (read) begin
      mouse_dx <= 0;
      mouse_dy <= 0;
    end
  end

endmodule