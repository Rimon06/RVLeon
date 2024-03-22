EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Placa LeonRV"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DB15 J?
U 1 1 651E4DFE
P 7950 2550
F 0 "J?" H 7970 3400 50  0000 C CNN
F 1 "DB15" H 7900 1700 50  0000 C CNN
F 2 "" H 7950 2550 50  0000 C CNN
F 3 "" H 7950 2550 50  0000 C CNN
	1    7950 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 651E4E34
P 7350 3350
F 0 "#PWR?" H 7350 3100 50  0001 C CNN
F 1 "GND" H 7350 3200 50  0000 C CNN
F 2 "" H 7350 3350 50  0000 C CNN
F 3 "" H 7350 3350 50  0000 C CNN
	1    7350 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1850 7350 3350
Wire Wire Line
	7350 2450 7500 2450
Wire Wire Line
	7500 2950 7350 2950
Connection ~ 7350 2950
Wire Wire Line
	7500 2250 7350 2250
Connection ~ 7350 2450
Wire Wire Line
	7500 2050 7350 2050
Connection ~ 7350 2250
Wire Wire Line
	7500 1850 7350 1850
Connection ~ 7350 2050
NoConn ~ 7500 1950
NoConn ~ 7500 3150
NoConn ~ 7500 2650
NoConn ~ 7500 2750
NoConn ~ 7500 2550
$EndSCHEMATC
