EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J?
U 1 1 613A12DB
P 2050 3000
F 0 "J?" H 2100 4117 50  0000 C CNN
F 1 "XTA Connector" H 2100 4026 50  0000 C CNN
F 2 "" H 2050 3000 50  0001 C CNN
F 3 "~" H 2050 3000 50  0001 C CNN
	1    2050 3000
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 613A4C8D
P 5700 2650
F 0 "U1" H 5056 2696 50  0000 R CNN
F 1 "ATmega328P-PU" H 5056 2605 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5700 2650 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5700 2650 50  0001 C CNN
	1    5700 2650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS299 U3
U 1 1 613A759E
P 5500 5700
F 0 "U3" H 5650 6500 50  0000 C CNN
F 1 "74LS299" H 5700 6400 50  0000 C CNN
F 2 "" H 5500 5700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS299" H 5500 5700 50  0001 C CNN
	1    5500 5700
	1    0    0    -1  
$EndComp
NoConn ~ 2350 3000
$Comp
L power:GND #PWR?
U 1 1 613A85D9
P 2450 4100
F 0 "#PWR?" H 2450 3850 50  0001 C CNN
F 1 "GND" H 2455 3927 50  0000 C CNN
F 2 "" H 2450 4100 50  0001 C CNN
F 3 "" H 2450 4100 50  0001 C CNN
	1    2450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4100 2450 4000
Wire Wire Line
	2450 2100 2350 2100
Wire Wire Line
	2350 2200 2450 2200
Connection ~ 2450 2200
Wire Wire Line
	2450 2200 2450 2100
Wire Wire Line
	2350 2300 2450 2300
Connection ~ 2450 2300
Wire Wire Line
	2450 2300 2450 2200
Wire Wire Line
	2350 2400 2450 2400
Connection ~ 2450 2400
Wire Wire Line
	2450 2400 2450 2300
Wire Wire Line
	2350 2500 2450 2500
Connection ~ 2450 2500
Wire Wire Line
	2450 2500 2450 2400
Wire Wire Line
	2350 2600 2450 2600
Connection ~ 2450 2600
Wire Wire Line
	2450 2600 2450 2500
Wire Wire Line
	2350 2700 2450 2700
Connection ~ 2450 2700
Wire Wire Line
	2450 2700 2450 2600
Wire Wire Line
	2350 2800 2450 2800
Connection ~ 2450 2800
Wire Wire Line
	2450 2800 2450 2700
Wire Wire Line
	2350 2900 2450 2900
Connection ~ 2450 2900
Wire Wire Line
	2450 2900 2450 2800
Wire Wire Line
	2350 3100 2450 3100
Connection ~ 2450 3100
Wire Wire Line
	2450 3100 2450 2900
Wire Wire Line
	2350 3200 2450 3200
Connection ~ 2450 3200
Wire Wire Line
	2450 3200 2450 3100
Wire Wire Line
	2350 3300 2450 3300
Connection ~ 2450 3300
Wire Wire Line
	2450 3300 2450 3200
Wire Wire Line
	2350 4000 2450 4000
Connection ~ 2450 4000
Wire Wire Line
	2450 4000 2450 3900
Wire Wire Line
	2350 3900 2450 3900
Connection ~ 2450 3900
Wire Wire Line
	2450 3900 2450 3800
Wire Wire Line
	2350 3800 2450 3800
Connection ~ 2450 3800
Wire Wire Line
	2450 3800 2450 3700
Wire Wire Line
	2350 3700 2450 3700
Connection ~ 2450 3700
Wire Wire Line
	2450 3700 2450 3600
Wire Wire Line
	2350 3600 2450 3600
Connection ~ 2450 3600
Wire Wire Line
	2450 3600 2450 3500
Wire Wire Line
	2350 3500 2450 3500
Connection ~ 2450 3500
Wire Wire Line
	2450 3500 2450 3400
Wire Wire Line
	2350 3400 2450 3400
Connection ~ 2450 3400
Wire Wire Line
	2450 3400 2450 3300
Text GLabel 1850 3900 0    39   Input ~ 0
~CS
Text GLabel 1850 4000 0    39   Input ~ 0
~DRIVE_ACTIvE
Text GLabel 1850 3800 0    50   Input ~ 0
A0
Text GLabel 1850 3700 0    50   Input ~ 0
A1
Text GLabel 1850 2100 0    39   Input ~ 0
~RESET
Text GLabel 1850 2200 0    50   Input ~ 0
D7
Text GLabel 1850 2300 0    50   Input ~ 0
D6
Text GLabel 1850 2400 0    50   Input ~ 0
D5
Text GLabel 1850 2500 0    50   Input ~ 0
D4
Text GLabel 1850 2600 0    50   Input ~ 0
D3
Text GLabel 1850 2800 0    50   Input ~ 0
D1
Text GLabel 1850 2900 0    50   Input ~ 0
D0
Text GLabel 1850 2700 0    50   Input ~ 0
D2
$Comp
L power:GND #PWR?
U 1 1 613B07D2
P 1350 4100
F 0 "#PWR?" H 1350 3850 50  0001 C CNN
F 1 "GND" H 1355 3927 50  0000 C CNN
F 2 "" H 1350 4100 50  0001 C CNN
F 3 "" H 1350 4100 50  0001 C CNN
	1    1350 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 3000 1350 3000
Wire Wire Line
	1350 3000 1350 4100
Text GLabel 1850 3100 0    50   Input ~ 0
AEN
Text GLabel 1850 3200 0    39   Input ~ 0
~IOW
Text GLabel 1850 3300 0    39   Input ~ 0
~IOR
Text GLabel 1850 3400 0    39   Input ~ 0
~DACK
Text GLabel 1850 3500 0    50   Input ~ 0
DRQ
Text GLabel 1850 3600 0    50   Input ~ 0
IRQ
$Comp
L 00Custom:GAL22V10 U2
U 1 1 613A167E
P 7750 1800
F 0 "U2" H 7950 2550 50  0000 C CNN
F 1 "GAL22V10" H 8000 2450 50  0000 C CNN
F 2 "" H 7750 1800 50  0001 C CNN
F 3 "" H 7750 1800 50  0001 C CNN
	1    7750 1800
	1    0    0    -1  
$EndComp
Text GLabel 6000 6200 2    50   Input ~ 0
D7
Text GLabel 6000 6100 2    50   Input ~ 0
D6
Text GLabel 6000 6000 2    50   Input ~ 0
D5
Text GLabel 6000 5900 2    50   Input ~ 0
D4
Text GLabel 6000 5800 2    50   Input ~ 0
D3
Text GLabel 6000 5600 2    50   Input ~ 0
D1
Text GLabel 6000 5500 2    50   Input ~ 0
D0
Text GLabel 6000 5700 2    50   Input ~ 0
D2
$Comp
L power:GND #PWR?
U 1 1 613A7C15
P 5500 6600
F 0 "#PWR?" H 5500 6350 50  0001 C CNN
F 1 "GND" H 5505 6427 50  0000 C CNN
F 2 "" H 5500 6600 50  0001 C CNN
F 3 "" H 5500 6600 50  0001 C CNN
	1    5500 6600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 613A85C5
P 5500 4900
F 0 "#PWR?" H 5500 4750 50  0001 C CNN
F 1 "VCC" H 5515 5073 50  0000 C CNN
F 2 "" H 5500 4900 50  0001 C CNN
F 3 "" H 5500 4900 50  0001 C CNN
	1    5500 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 613A8EC8
P 5700 4150
F 0 "#PWR?" H 5700 3900 50  0001 C CNN
F 1 "GND" H 5705 3977 50  0000 C CNN
F 2 "" H 5700 4150 50  0001 C CNN
F 3 "" H 5700 4150 50  0001 C CNN
	1    5700 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 613A9294
P 7750 2600
F 0 "#PWR?" H 7750 2350 50  0001 C CNN
F 1 "GND" H 7755 2427 50  0000 C CNN
F 2 "" H 7750 2600 50  0001 C CNN
F 3 "" H 7750 2600 50  0001 C CNN
	1    7750 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1150 5800 1100
Wire Wire Line
	5800 1100 5700 1100
Wire Wire Line
	5700 1100 5700 1150
Wire Wire Line
	5700 1100 5700 1050
Connection ~ 5700 1100
$Comp
L power:VCC #PWR?
U 1 1 613ADC07
P 5700 1050
F 0 "#PWR?" H 5700 900 50  0001 C CNN
F 1 "VCC" H 5715 1223 50  0000 C CNN
F 2 "" H 5700 1050 50  0001 C CNN
F 3 "" H 5700 1050 50  0001 C CNN
	1    5700 1050
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 613AE2A8
P 7750 1100
F 0 "#PWR?" H 7750 950 50  0001 C CNN
F 1 "VCC" H 7765 1273 50  0000 C CNN
F 2 "" H 7750 1100 50  0001 C CNN
F 3 "" H 7750 1100 50  0001 C CNN
	1    7750 1100
	1    0    0    -1  
$EndComp
Text GLabel 7250 1500 0    39   Input ~ 0
~CS
Text GLabel 7250 1400 0    50   Input ~ 0
A0
Text GLabel 7250 1300 0    50   Input ~ 0
A1
Text GLabel 7250 1600 0    50   Input ~ 0
AEN
Text GLabel 7250 1700 0    39   Input ~ 0
~IOW
Text GLabel 7250 1800 0    39   Input ~ 0
~IOR
Text GLabel 7250 1900 0    39   Input ~ 0
~DACK
Text GLabel 6300 2950 2    39   Input ~ 0
~RESET
$Comp
L Device:Crystal 20MHz18pF
U 1 1 613B18BA
P 6700 2100
F 0 "20MHz18pF" V 6654 2231 50  0000 L CNN
F 1 "Crystal" V 6745 2231 50  0000 L CNN
F 2 "" H 6700 2100 50  0001 C CNN
F 3 "~" H 6700 2100 50  0001 C CNN
	1    6700 2100
	0    1    1    0   
$EndComp
$Comp
L Device:C 22pF
U 1 1 613B227E
P 6700 1700
F 0 "22pF" H 6815 1746 50  0000 L CNN
F 1 "C" H 6815 1655 50  0000 L CNN
F 2 "" H 6738 1550 50  0001 C CNN
F 3 "~" H 6700 1700 50  0001 C CNN
	1    6700 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C 22pF
U 1 1 613B304C
P 6700 2500
F 0 "22pF" H 6815 2546 50  0000 L CNN
F 1 "C" H 6815 2455 50  0000 L CNN
F 2 "" H 6738 2350 50  0001 C CNN
F 3 "~" H 6700 2500 50  0001 C CNN
	1    6700 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2050 6450 2050
Wire Wire Line
	6450 2050 6450 1950
Wire Wire Line
	6450 1950 6700 1950
Wire Wire Line
	6300 2150 6400 2150
Wire Wire Line
	6400 2150 6400 2250
Wire Wire Line
	6400 2250 6700 2250
Wire Wire Line
	6700 2250 6700 2350
Connection ~ 6700 2250
Wire Wire Line
	6700 1950 6700 1850
Connection ~ 6700 1950
$Comp
L power:GND #PWR?
U 1 1 613B6EA3
P 6850 1350
F 0 "#PWR?" H 6850 1100 50  0001 C CNN
F 1 "GND" H 6855 1177 50  0000 C CNN
F 2 "" H 6850 1350 50  0001 C CNN
F 3 "" H 6850 1350 50  0001 C CNN
	1    6850 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 1550 6700 1250
Wire Wire Line
	6700 1250 6850 1250
Wire Wire Line
	6850 1250 6850 1350
$Comp
L power:GND #PWR?
U 1 1 613B853A
P 6700 2650
F 0 "#PWR?" H 6700 2400 50  0001 C CNN
F 1 "GND" H 6705 2477 50  0000 C CNN
F 2 "" H 6700 2650 50  0001 C CNN
F 3 "" H 6700 2650 50  0001 C CNN
	1    6700 2650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
