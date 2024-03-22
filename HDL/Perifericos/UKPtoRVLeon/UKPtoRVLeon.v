//
// Example using the usb_hid_host core, for iCEBreaker board
// based on the icesugar-pro example by nand2mario, 9/2023
//

`default_nettype none
module UKPtoRVLeon (
    input  clk,
    input  rstn,

    input  cpu_rdstrb,
    input  cpu_valid,

    output [7:0]  HID_printer_status,
    output [15:0] KBRD_status,
    output [31:0] KBRD_keys,
  
    output [7:0]  MOUSE_status,
    output [31:0] MOUSE_data,
    // USB
    inout  usbdm,
    inout  usbdp
);

  wire [1:0] usb_type;
  wire [7:0] key_modifiers, key1, key2, key3, key4;
  wire [7:0] mouse_btn;
  wire signed [7:0] mouse_dx, mouse_dy;
  wire [63:0] hid_report;
  wire usb_report, usb_conerr;
  wire report_no_readed, report_lost_data;

  usb_hid_host usb (
    .usbclk(clk), .usbrst_n(rstn),
    .usb_dm(usbdm), .usb_dp(usbdp),	
    .typ(usb_type), .report(usb_report),
    .conerr(usb_conerr), .dbg_hid_report(hid_report)
  );

  hid_reader show (
    .clk(clk),.resetn(rstn),
    .usb_type(usb_type), .usb_report(usb_report), 
    .read(cpu_rdstrb && cpu_valid),
    .hid_report(hid_report),

    .key_modifiers(key_modifiers), .key1(key1), .key2(key2), .key3(key3), .key4(key4),

    .mouse_btn(mouse_btn), .mouse_dx(mouse_dx), .mouse_dy(mouse_dy),

    .report_no_readed(report_no_readed),
    .report_lost_data(report_lost_data)
  );

  // Lectura de Status
  assign HID_printer_status = {4'b0,report_lost_data,report_no_readed,usb_type[1],usb_type[0]};
  assign KBRD_status = {key_modifiers,5'b0,report_lost_data,report_no_readed, usb_type[0]};
  assign KBRD_keys   = {key4,key3,key2,key1};
  
  assign  MOUSE_status = {5'b0,report_lost_data,report_no_readed,usb_type[1]};
  assign  MOUSE_data   = {mouse_dy,mouse_dx,8'b0,mouse_btn};

endmodule
