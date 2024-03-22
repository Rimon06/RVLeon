EESchema Schematic File Version 4
LIBS:leonrv-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "RVLeon: Modulo de Computacion"
Date "2023-10-17"
Rev "v01"
Comp ""
Comment1 "ARQUITECTURA RISC-V "
Comment2 "MÓDULO DE COMPUTACIÓN INTERACTIVO UTILIZANDO FPGA BASADO EN LA"
Comment3 "Trabajo Especial de Grado:"
Comment4 "Autor: Ricardo Moncayo"
$EndDescr
$Comp
L power:GND #PWR0101
U 1 1 651E4E34
P 2250 2600
F 0 "#PWR0101" H 2250 2350 50  0001 C CNN
F 1 "GND" H 2400 2550 50  0000 C CNN
F 2 "" H 2250 2600 50  0000 C CNN
F 3 "" H 2250 2600 50  0000 C CNN
	1    2250 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector:DB15_Female_HighDensity_MountingHoles J3
U 1 1 6520D530
P 2650 1900
F 0 "J3" H 2650 2767 50  0000 C CNN
F 1 "DB15_Female_HighDensity_MountingHoles" H 2650 2676 50  0000 C CNN
F 2 "Connector_Dsub:DSUB-15-HD_Female_Horizontal_P2.29x1.98mm_EdgePinOffset3.03mm_Housed_MountingHolesOffset4.94mm" H 1700 2300 50  0001 C CNN
F 3 " ~" H 1700 2300 50  0001 C CNN
	1    2650 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1800 2250 1600
Wire Wire Line
	2250 1400 2250 1600
Connection ~ 2250 1800
Wire Wire Line
	2250 2300 2250 2200
NoConn ~ 2950 1500
NoConn ~ 2350 2100
NoConn ~ 2350 2000
NoConn ~ 2950 1700
NoConn ~ 2950 2300
Wire Wire Line
	6150 3450 6350 3450
Connection ~ 6350 4250
Text Notes 5050 1150 0    157  ~ 31
iceFUN
Wire Wire Line
	6350 4250 6350 4600
Wire Wire Line
	6350 4250 6150 4250
Wire Wire Line
	6350 3450 6350 4250
Text Label 6450 1550 0    50   ~ 0
vga_red2
Text Label 6450 1650 0    50   ~ 0
vga_red1
Text Label 6450 1750 0    50   ~ 0
vga_red0
$Comp
L Device:R R1
U 1 1 65290062
P 1350 1000
F 0 "R1" V 1450 1000 50  0000 C CNN
F 1 "470" V 1350 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 1000 50  0001 C CNN
F 3 "~" H 1350 1000 50  0001 C CNN
	1    1350 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6550 4350 6150 4350
Wire Wire Line
	4550 4250 4400 4250
Text Label 4150 3550 0    50   ~ 0
serial_RX
Text Label 4150 3650 0    50   ~ 0
serial_TX
Text Label 6450 3950 0    50   ~ 0
teclado_hab
Text Label 6450 3850 0    50   ~ 0
usb_D-
Text Label 6450 3750 0    50   ~ 0
usb_D+
Text Label 6450 3650 0    50   ~ 0
fpga_P10
Text Label 6450 2450 0    50   ~ 0
vga_hsync
Text Label 6450 2350 0    50   ~ 0
vga_vsync
Text Label 6450 2250 0    50   ~ 0
vga_blue0
Text Label 6450 2150 0    50   ~ 0
vga_blue1
Text Label 6450 2050 0    50   ~ 0
vga_green0
Text Label 6450 1950 0    50   ~ 0
vga_green1
Text Label 6450 1850 0    50   ~ 0
vga_green2
Wire Wire Line
	6150 1550 6800 1550
Wire Wire Line
	6150 1650 6800 1650
Wire Wire Line
	6150 1750 6800 1750
Wire Wire Line
	6150 1850 6800 1850
Wire Wire Line
	6150 1950 6800 1950
Wire Wire Line
	6150 2050 6800 2050
Wire Wire Line
	6150 2150 6800 2150
Wire Wire Line
	6150 2250 6800 2250
Wire Wire Line
	6150 2350 6800 2350
Wire Wire Line
	6150 2450 6800 2450
Wire Wire Line
	6150 3650 6800 3650
Wire Wire Line
	6150 3750 6800 3750
Wire Wire Line
	6150 3850 6800 3850
$Comp
L Device:R R2
U 1 1 652D2BFF
P 1350 1200
F 0 "R2" V 1450 1200 50  0000 C CNN
F 1 "1.1k" V 1350 1200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 1200 50  0001 C CNN
F 3 "~" H 1350 1200 50  0001 C CNN
	1    1350 1200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 652D2C23
P 1350 1400
F 0 "R3" V 1450 1400 50  0000 C CNN
F 1 "2.2k" V 1350 1400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 1400 50  0001 C CNN
F 3 "~" H 1350 1400 50  0001 C CNN
	1    1350 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 1000 1500 1200
Wire Wire Line
	1500 1200 1500 1400
Connection ~ 1500 1200
$Comp
L Device:R R4
U 1 1 652F1CD8
P 1350 1600
F 0 "R4" V 1450 1600 50  0000 C CNN
F 1 "470" V 1350 1600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 1600 50  0001 C CNN
F 3 "~" H 1350 1600 50  0001 C CNN
	1    1350 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 652F1CDF
P 1350 1800
F 0 "R5" V 1450 1800 50  0000 C CNN
F 1 "1.1k" V 1350 1800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 1800 50  0001 C CNN
F 3 "~" H 1350 1800 50  0001 C CNN
	1    1350 1800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 652F1CE6
P 1350 2000
F 0 "R6" V 1450 2000 50  0000 C CNN
F 1 "2.2k" V 1350 2000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 2000 50  0001 C CNN
F 3 "~" H 1350 2000 50  0001 C CNN
	1    1350 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 1600 1500 1800
Wire Wire Line
	1500 1800 1500 2000
Connection ~ 1500 1800
$Comp
L Device:R R7
U 1 1 652F3DF6
P 1350 2200
F 0 "R7" V 1450 2200 50  0000 C CNN
F 1 "470" V 1350 2200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 2200 50  0001 C CNN
F 3 "~" H 1350 2200 50  0001 C CNN
	1    1350 2200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R8
U 1 1 652F3DFD
P 1350 2400
F 0 "R8" V 1450 2400 50  0000 C CNN
F 1 "910" V 1350 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 2400 50  0001 C CNN
F 3 "~" H 1350 2400 50  0001 C CNN
	1    1350 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 1800 1750 1800
Wire Wire Line
	2050 1900 2350 1900
Wire Wire Line
	1500 2200 1500 2300
Wire Wire Line
	1750 1800 1750 1700
Wire Wire Line
	1750 1700 2350 1700
Wire Wire Line
	2050 1900 2050 2300
Wire Wire Line
	2050 2300 1500 2300
Connection ~ 1500 2300
Wire Wire Line
	1500 2300 1500 2400
Wire Wire Line
	2350 1500 1750 1500
Wire Wire Line
	1750 1500 1750 1200
Wire Wire Line
	1750 1200 1500 1200
$Comp
L power:GND #PWR0102
U 1 1 652EF3A9
P 4500 4600
F 0 "#PWR0102" H 4500 4350 50  0001 C CNN
F 1 "GND" H 4505 4427 50  0000 C CNN
F 2 "" H 4500 4600 50  0001 C CNN
F 3 "" H 4500 4600 50  0001 C CNN
	1    4500 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4150 4550 4150
Connection ~ 4500 4600
Wire Wire Line
	4500 4150 4500 4600
Wire Wire Line
	4500 4600 6350 4600
$Comp
L Device:R R9
U 1 1 6534F172
P 1350 2800
F 0 "R9" V 1450 2800 50  0000 C CNN
F 1 "100" V 1350 2800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 2800 50  0001 C CNN
F 3 "~" H 1350 2800 50  0001 C CNN
	1    1350 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R10
U 1 1 65351A69
P 1350 2950
F 0 "R10" V 1450 2950 50  0000 C CNN
F 1 "100" V 1350 2950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 1280 2950 50  0001 C CNN
F 3 "~" H 1350 2950 50  0001 C CNN
	1    1350 2950
	0    -1   1    0   
$EndComp
Wire Wire Line
	1500 2800 3050 2800
Wire Wire Line
	3050 2800 3050 2100
Wire Wire Line
	3050 2100 2950 2100
Wire Wire Line
	1500 2950 3100 2950
Wire Wire Line
	3100 2950 3100 1900
Wire Wire Line
	3100 1900 2950 1900
Connection ~ 2250 2200
Wire Wire Line
	2350 2300 2250 2300
Wire Wire Line
	2350 2200 2250 2200
Connection ~ 2250 1600
Wire Wire Line
	2350 1400 2250 1400
Wire Wire Line
	2250 1600 2350 1600
Wire Wire Line
	2250 1800 2350 1800
Wire Wire Line
	2250 2200 2250 1800
Wire Wire Line
	2250 2600 2650 2600
Wire Wire Line
	2250 2300 2250 2600
Connection ~ 2250 2300
Connection ~ 2250 2600
Text Label 850  2800 0    50   ~ 0
vga_vsync
Wire Wire Line
	850  2800 1200 2800
Text Label 850  2950 0    50   ~ 0
vga_hsync
Wire Wire Line
	850  2950 1200 2950
Wire Wire Line
	1200 2400 850  2400
Text Label 850  2400 0    50   ~ 0
vga_blue0
Text Label 850  2200 0    50   ~ 0
vga_blue1
Wire Wire Line
	850  2200 1200 2200
Wire Wire Line
	800  2000 1200 2000
Wire Wire Line
	800  1800 1200 1800
Wire Wire Line
	800  1600 1200 1600
Wire Wire Line
	850  1400 1200 1400
Wire Wire Line
	850  1200 1200 1200
Wire Wire Line
	850  1000 1200 1000
Text Label 850  1000 0    50   ~ 0
vga_red2
Text Label 850  1200 0    50   ~ 0
vga_red1
Text Label 850  1400 0    50   ~ 0
vga_red0
Text Label 800  1600 0    50   ~ 0
vga_green2
Text Label 800  1800 0    50   ~ 0
vga_green1
Text Label 800  2000 0    50   ~ 0
vga_green0
$Comp
L Connector:USB_A J2
U 1 1 65396976
P 1750 4000
F 0 "J2" H 1650 4350 50  0000 C CNN
F 1 "USB_A" H 1900 3650 50  0000 C CNN
F 2 "digikey-footprints:USB_A_Female_UE27AC54100" H 1900 3950 50  0001 C CNN
F 3 " ~" H 1900 3950 50  0001 C CNN
	1    1750 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 65399DA8
P 1650 4500
F 0 "#PWR0103" H 1650 4250 50  0001 C CNN
F 1 "GND" H 1655 4327 50  0000 C CNN
F 2 "" H 1650 4500 50  0001 C CNN
F 3 "" H 1650 4500 50  0001 C CNN
	1    1650 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4400 1750 4500
Text Label 2450 4100 0    50   ~ 0
usb_D-
Text Label 2450 4000 0    50   ~ 0
usb_D+
Wire Wire Line
	2450 4000 2150 4000
Wire Wire Line
	2050 4100 2350 4100
$Comp
L power:+5V #PWR0104
U 1 1 653A3F3F
P 2200 3750
F 0 "#PWR0104" H 2200 3600 50  0001 C CNN
F 1 "+5V" H 2200 3900 50  0000 C CNN
F 2 "" H 2200 3750 50  0001 C CNN
F 3 "" H 2200 3750 50  0001 C CNN
	1    2200 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3750 2200 3800
Wire Wire Line
	2200 3800 2050 3800
$Comp
L power:+5V #PWR0105
U 1 1 653A77CA
P 6550 4350
F 0 "#PWR0105" H 6550 4200 50  0001 C CNN
F 1 "+5V" H 6550 4500 50  0000 C CNN
F 2 "" H 6550 4350 50  0001 C CNN
F 3 "" H 6550 4350 50  0001 C CNN
	1    6550 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 653AB137
P 2150 4300
F 0 "R11" V 2250 4300 50  0000 C CNN
F 1 "15k" V 2150 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 2080 4300 50  0001 C CNN
F 3 "~" H 2150 4300 50  0001 C CNN
	1    2150 4300
	1    0    0    1   
$EndComp
$Comp
L Device:R R12
U 1 1 653B5B5D
P 2350 4300
F 0 "R12" V 2450 4300 50  0000 C CNN
F 1 "15k" V 2350 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 2280 4300 50  0001 C CNN
F 3 "~" H 2350 4300 50  0001 C CNN
	1    2350 4300
	1    0    0    1   
$EndComp
Wire Wire Line
	1750 4500 1650 4500
Wire Wire Line
	1650 4400 1650 4500
Connection ~ 1650 4500
Wire Wire Line
	2150 4450 2150 4500
Wire Wire Line
	2150 4500 1750 4500
Connection ~ 1750 4500
Wire Wire Line
	2150 4500 2350 4500
Wire Wire Line
	2350 4500 2350 4450
Connection ~ 2150 4500
Wire Wire Line
	2350 4150 2350 4100
Connection ~ 2350 4100
Wire Wire Line
	2350 4100 2450 4100
Wire Wire Line
	2150 4150 2150 4000
Connection ~ 2150 4000
Wire Wire Line
	2150 4000 2050 4000
$Comp
L Device:C C1
U 1 1 653D9F1B
P 1400 3950
F 0 "C1" H 1286 3904 50  0000 R CNN
F 1 "0.1uF" H 1286 3995 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 1438 3800 50  0001 C CNN
F 3 "~" H 1400 3950 50  0001 C CNN
	1    1400 3950
	1    0    0    1   
$EndComp
Wire Wire Line
	1400 4100 1400 4500
Wire Wire Line
	1400 4500 1650 4500
Wire Wire Line
	1400 3800 1400 3600
Wire Wire Line
	2050 3600 2050 3800
Wire Wire Line
	1400 3600 2050 3600
Connection ~ 2050 3800
Text Notes 1300 3500 0    118  ~ 24
Teclado USB
Text Notes 1300 850  0    118  ~ 24
Pantalla VGA
$Comp
L power:+3V3 #PWR0106
U 1 1 653012BE
P 4400 4250
F 0 "#PWR0106" H 4400 4100 50  0001 C CNN
F 1 "+3V3" H 4250 4300 50  0000 C CNN
F 2 "" H 4400 4250 50  0001 C CNN
F 3 "" H 4400 4250 50  0001 C CNN
	1    4400 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 65321F50
P 8350 3500
F 0 "J5" H 8350 3700 50  0000 C CNN
F 1 "Conn_01x03" V 8450 3500 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 8350 3500 50  0001 C CNN
F 3 "~" H 8350 3500 50  0001 C CNN
	1    8350 3500
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J4
U 1 1 6532B256
P 8250 2100
F 0 "J4" H 8250 2400 50  0000 C CNN
F 1 "Conn_01x06" V 8350 2100 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 8250 2100 50  0001 C CNN
F 3 "~" H 8250 2100 50  0001 C CNN
	1    8250 2100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9000 1900 8450 1900
Wire Wire Line
	9000 2100 8450 2100
Wire Wire Line
	9000 2000 8450 2000
Wire Wire Line
	9000 2300 8450 2300
Text Label 8450 1900 0    50   ~ 0
serialDBG_DTR
Text Label 8450 2100 0    50   ~ 0
serialDBG_RX
Text Label 8450 2000 0    50   ~ 0
serialDBG_TX
Text Label 8450 2300 0    50   ~ 0
serialDBG_CTS
$Comp
L power:GND #PWR0109
U 1 1 65356492
P 8450 2400
F 0 "#PWR0109" H 8450 2150 50  0001 C CNN
F 1 "GND" H 8455 2227 50  0000 C CNN
F 2 "" H 8450 2400 50  0001 C CNN
F 3 "" H 8450 2400 50  0001 C CNN
	1    8450 2400
	1    0    0    -1  
$EndComp
Text Notes 7400 1700 0    118  ~ 24
Slot Depurador FTDI232H
$Comp
L power:GND #PWR0110
U 1 1 6535B956
P 8550 3600
F 0 "#PWR0110" H 8550 3350 50  0001 C CNN
F 1 "GND" H 8555 3427 50  0000 C CNN
F 2 "" H 8550 3600 50  0001 C CNN
F 3 "" H 8550 3600 50  0001 C CNN
	1    8550 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3400 8550 3400
Wire Wire Line
	8950 3500 8550 3500
Text Label 8550 3400 0    50   ~ 0
serial_RX
Text Label 8550 3500 0    50   ~ 0
serial_TX
NoConn ~ 8450 2200
Text Label 2100 1500 0    50   ~ 0
red
Text Label 2100 1700 0    50   ~ 0
green
Text Label 2100 1900 0    50   ~ 0
blue
Text Label 2100 2800 0    50   ~ 0
vsync
Text Label 2100 2950 0    50   ~ 0
hsync
$Comp
L icefun:icefun U1
U 1 1 6532D52A
P 5350 2950
F 0 "U1" H 5350 4665 50  0000 C CNN
F 1 "icefun" H 5350 4574 50  0000 C CNN
F 2 "icefun:icefun-DIP" H 5450 4550 50  0001 C CNN
F 3 "" H 5450 4550 50  0001 C CNN
	1    5350 2950
	1    0    0    -1  
$EndComp
Text Notes 8100 3100 0    118  ~ 24
Puerto Serial 
$Comp
L Device:R R14
U 1 1 654F6692
P 3200 3750
F 0 "R14" V 3100 3700 50  0000 L CNN
F 1 "1.1k" V 3300 3700 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 3130 3750 50  0001 C CNN
F 3 "~" H 3200 3750 50  0001 C CNN
	1    3200 3750
	0    1    1    0   
$EndComp
$Comp
L Device:LED_ALT D1
U 1 1 654F669F
P 3350 3900
F 0 "D1" V 3450 3800 50  0000 C CNN
F 1 "LED_ALT" H 3342 3736 50  0001 C CNN
F 2 "LED_THT:LED_D5.0mm" H 3350 3900 50  0001 C CNN
F 3 "~" H 3350 3900 50  0001 C CNN
	1    3350 3900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 3750 2550 3750
NoConn ~ 4550 3950
NoConn ~ 4550 4050
NoConn ~ 6150 4050
NoConn ~ 6150 4150
Wire Wire Line
	6150 3950 6800 3950
Text Label 2550 3750 0    50   ~ 0
teclado_hab
NoConn ~ 6150 3250
NoConn ~ 6150 3350
NoConn ~ 6150 3550
NoConn ~ 4550 2850
NoConn ~ 4550 2350
NoConn ~ 4550 2250
$Comp
L power:GND #PWR0117
U 1 1 6535B5AE
P 3350 4050
F 0 "#PWR0117" H 3350 3800 50  0001 C CNN
F 1 "GND" H 3355 3877 50  0000 C CNN
F 2 "" H 3350 4050 50  0001 C CNN
F 3 "" H 3350 4050 50  0001 C CNN
	1    3350 4050
	1    0    0    -1  
$EndComp
Text Label 4250 1850 2    50   ~ 0
serialDBG_DTR
Text Label 4250 1650 2    50   ~ 0
serialDBG_RX
Text Label 4250 1750 2    50   ~ 0
serialDBG_TX
Text Label 4250 1550 2    50   ~ 0
serialDBG_CTS
Wire Wire Line
	4550 1550 3900 1550
Wire Wire Line
	4550 1750 3900 1750
Wire Wire Line
	4550 1650 3900 1650
Wire Wire Line
	4550 1850 3900 1850
NoConn ~ 4550 2450
NoConn ~ 4550 2550
NoConn ~ 4550 2650
NoConn ~ 4550 2750
NoConn ~ 4550 2950
Wire Wire Line
	3900 3550 4550 3550
Wire Wire Line
	3900 3650 4550 3650
NoConn ~ 4550 2150
NoConn ~ 4550 2050
Text Notes 3800 3700 0    50   ~ 0
---->\n\n<----
Text Notes 8950 3550 0    50   ~ 0
---->\n\n<----
Text Notes 3400 1750 0    50   ~ 0
---->\n<----
Text Notes 9350 2100 2    50   ~ 0
<----\n---->
NoConn ~ 6150 2550
NoConn ~ 6150 2650
NoConn ~ 6150 2750
NoConn ~ 6150 2850
NoConn ~ 6150 2950
NoConn ~ 6150 3050
NoConn ~ 6150 3150
NoConn ~ 4550 3450
NoConn ~ 4550 3850
NoConn ~ 4550 3750
NoConn ~ 4550 3350
NoConn ~ 4550 3250
NoConn ~ 4550 3150
NoConn ~ 4550 3050
$Comp
L Device:R R15
U 1 1 65D6DC78
P 9850 2450
F 0 "R15" V 9750 2400 50  0000 L CNN
F 1 "1.1k" V 9950 2400 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 9780 2450 50  0001 C CNN
F 3 "~" H 9850 2450 50  0001 C CNN
	1    9850 2450
	0    1    1    0   
$EndComp
$Comp
L Device:LED_ALT D2
U 1 1 65D6DC7F
P 10000 2600
F 0 "D2" V 10100 2500 50  0000 C CNN
F 1 "LED_ALT" H 9992 2436 50  0001 C CNN
F 2 "LED_THT:LED_D5.0mm" H 10000 2600 50  0001 C CNN
F 3 "~" H 10000 2600 50  0001 C CNN
	1    10000 2600
	0    -1   -1   0   
$EndComp
Text Label 4350 1950 2    50   ~ 0
serialDBG_halted
$Comp
L power:GND #PWR0107
U 1 1 65D6DC88
P 10000 2750
F 0 "#PWR0107" H 10000 2500 50  0001 C CNN
F 1 "GND" H 10005 2577 50  0000 C CNN
F 2 "" H 10000 2750 50  0001 C CNN
F 3 "" H 10000 2750 50  0001 C CNN
	1    10000 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1950 4550 1950
Text Label 9550 2450 2    50   ~ 0
serialDBG_halted
Wire Wire Line
	9550 2450 9700 2450
$EndSCHEMATC
