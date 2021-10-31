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
L 00Custom:74LS245_One_Way U2
U 1 1 61779EE3
P 3150 2800
F 0 "U2" H 3350 3600 50  0000 C CNN
F 1 "74LVC245" H 3400 3500 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm_Socket" H 3150 2800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 3150 2800 50  0001 C CNN
	1    3150 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 6179270F
P 3150 3600
F 0 "#PWR08" H 3150 3350 50  0001 C CNN
F 1 "GND" H 3155 3427 50  0000 C CNN
F 2 "" H 3150 3600 50  0001 C CNN
F 3 "" H 3150 3600 50  0001 C CNN
	1    3150 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR07
U 1 1 61799FCA
P 3150 2000
F 0 "#PWR07" H 3150 1850 50  0001 C CNN
F 1 "+3.3V" H 3165 2173 50  0000 C CNN
F 2 "" H 3150 2000 50  0001 C CNN
F 3 "" H 3150 2000 50  0001 C CNN
	1    3150 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 617DC24E
P 2550 3600
F 0 "#PWR06" H 2550 3350 50  0001 C CNN
F 1 "GND" H 2555 3427 50  0000 C CNN
F 2 "" H 2550 3600 50  0001 C CNN
F 3 "" H 2550 3600 50  0001 C CNN
	1    2550 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 3300 2550 3300
Wire Wire Line
	2550 3300 2550 3600
$Comp
L power:+5V #PWR014
U 1 1 619C3A9B
P 6950 4750
F 0 "#PWR014" H 6950 4600 50  0001 C CNN
F 1 "+5V" H 6965 4923 50  0000 C CNN
F 2 "" H 6950 4750 50  0001 C CNN
F 3 "" H 6950 4750 50  0001 C CNN
	1    6950 4750
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 2 1 61A22FCF
P 5600 2300
F 0 "U1" H 5600 2617 50  0000 C CNN
F 1 "74HCT125" H 5600 2526 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5600 2300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 5600 2300 50  0001 C CNN
	2    5600 2300
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 4 1 61A24A99
P 5550 4100
F 0 "U1" H 5550 4417 50  0000 C CNN
F 1 "74HCT125" H 5550 4326 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5550 4100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 5550 4100 50  0001 C CNN
	4    5550 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 61A2BCE2
P 6950 5750
F 0 "#PWR015" H 6950 5500 50  0001 C CNN
F 1 "GND" H 6955 5577 50  0000 C CNN
F 2 "" H 6950 5750 50  0001 C CNN
F 3 "" H 6950 5750 50  0001 C CNN
	1    6950 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 61C62A1F
P 5400 5350
F 0 "C1" H 5515 5396 50  0000 L CNN
F 1 "0.1uF" H 5515 5305 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5438 5200 50  0001 C CNN
F 3 "~" H 5400 5350 50  0001 C CNN
F 4 " C24497" H 5400 5350 50  0001 C CNN "LCSC"
	1    5400 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 61C633FA
P 5400 5500
F 0 "#PWR029" H 5400 5250 50  0001 C CNN
F 1 "GND" H 5405 5327 50  0000 C CNN
F 2 "" H 5400 5500 50  0001 C CNN
F 3 "" H 5400 5500 50  0001 C CNN
	1    5400 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61C64D1D
P 5900 5350
F 0 "C2" H 6015 5396 50  0000 L CNN
F 1 "0.1uF" H 6015 5305 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 5938 5200 50  0001 C CNN
F 3 "~" H 5900 5350 50  0001 C CNN
F 4 " C24497" H 5900 5350 50  0001 C CNN "LCSC"
	1    5900 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR031
U 1 1 61C64D35
P 5900 5500
F 0 "#PWR031" H 5900 5250 50  0001 C CNN
F 1 "GND" H 5905 5327 50  0000 C CNN
F 2 "" H 5900 5500 50  0001 C CNN
F 3 "" H 5900 5500 50  0001 C CNN
	1    5900 5500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR030
U 1 1 61C64D3F
P 5900 5200
F 0 "#PWR030" H 5900 5050 50  0001 C CNN
F 1 "+3.3V" H 5915 5373 50  0000 C CNN
F 2 "" H 5900 5200 50  0001 C CNN
F 3 "" H 5900 5200 50  0001 C CNN
	1    5900 5200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 3 1 61A23D8E
P 5550 3200
F 0 "U1" H 5550 3517 50  0000 C CNN
F 1 "74HCT125" H 5550 3426 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5550 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 5550 3200 50  0001 C CNN
	3    5550 3200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U1
U 5 1 61A25588
P 6950 5250
F 0 "U1" H 7180 5296 50  0000 L CNN
F 1 "74HCT125" H 7180 5205 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 6950 5250 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 6950 5250 50  0001 C CNN
	5    6950 5250
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 617B445E
P 1250 1100
F 0 "#FLG0102" H 1250 1175 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 1273 50  0000 C CNN
F 2 "" H 1250 1100 50  0001 C CNN
F 3 "~" H 1250 1100 50  0001 C CNN
	1    1250 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J8
U 1 1 617CD755
P 8050 2050
F 0 "J8" H 8100 2367 50  0000 C CNN
F 1 "REVERSE" H 8100 2276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 8050 2050 50  0001 C CNN
F 3 "~" H 8050 2050 50  0001 C CNN
	1    8050 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x07_Counter_Clockwise J3
U 1 1 617D642D
P 3700 4850
F 0 "J3" H 3750 5367 50  0000 C CNN
F 1 "Header" H 3750 5276 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 3700 4850 50  0001 C CNN
F 3 "~" H 3700 4850 50  0001 C CNN
	1    3700 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5150 3400 5150
Wire Wire Line
	3400 5150 3400 5250
$Comp
L power:GND #PWR09
U 1 1 617E90EB
P 3400 5250
F 0 "#PWR09" H 3400 5000 50  0001 C CNN
F 1 "GND" H 3405 5077 50  0000 C CNN
F 2 "" H 3400 5250 50  0001 C CNN
F 3 "" H 3400 5250 50  0001 C CNN
	1    3400 5250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR010
U 1 1 617E9AC3
P 4100 4450
F 0 "#PWR010" H 4100 4300 50  0001 C CNN
F 1 "+5V" H 4115 4623 50  0000 C CNN
F 2 "" H 4100 4450 50  0001 C CNN
F 3 "" H 4100 4450 50  0001 C CNN
	1    4100 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4450 4100 4550
Wire Wire Line
	4100 4550 4000 4550
Text GLabel 3500 4550 0    39   Input ~ 0
GATE0_~OE
Text GLabel 3500 4650 0    50   Input ~ 0
GATE0_IN
Text GLabel 3500 4750 0    50   Input ~ 0
GATE0_OUT
Text GLabel 3500 4850 0    39   Input ~ 0
GATE1_~OE
Text GLabel 3500 4950 0    50   Input ~ 0
GATE1_IN
Text GLabel 3500 5050 0    50   Input ~ 0
GATE1_OUT
Text GLabel 4000 4650 2    39   Input ~ 0
GATE3_~OE
Text GLabel 4000 4750 2    50   Input ~ 0
GATE3_IN
Text GLabel 4000 4850 2    50   Input ~ 0
GATE3_OUT
Text GLabel 4000 4950 2    39   Input ~ 0
GATE2_~OE
Text GLabel 4000 5050 2    50   Input ~ 0
GATE2_IN
Text GLabel 4000 5150 2    50   Input ~ 0
GATE2_OUT
Wire Wire Line
	5550 3550 5550 3450
Wire Wire Line
	5450 3550 5550 3550
Wire Wire Line
	5550 4450 5550 4350
Wire Wire Line
	5450 4450 5550 4450
Wire Wire Line
	5600 2650 5500 2650
Wire Wire Line
	5600 2550 5600 2650
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J7
U 1 1 61846043
P 7900 3800
F 0 "J7" H 7950 4117 50  0000 C CNN
F 1 "FORWARD" H 7950 4026 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 7900 3800 50  0001 C CNN
F 3 "~" H 7900 3800 50  0001 C CNN
	1    7900 3800
	-1   0    0    -1  
$EndComp
Text GLabel 5900 1400 2    50   Input ~ 0
GATE0_125_OUT
Text GLabel 5300 1400 0    50   Input ~ 0
GATE0_IN
Text GLabel 5500 1750 0    39   Input ~ 0
GATE0_~OE
Wire Wire Line
	5600 1750 5600 1650
Wire Wire Line
	5500 1750 5600 1750
$Comp
L 74xx:74LS125 U1
U 1 1 61A05A47
P 5600 1400
F 0 "U1" H 5600 1717 50  0000 C CNN
F 1 "74HCT125" H 5600 1626 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 5600 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 5600 1400 50  0001 C CNN
	1    5600 1400
	1    0    0    -1  
$EndComp
Text GLabel 5300 2300 0    50   Input ~ 0
GATE1_IN
Text GLabel 5500 2650 0    39   Input ~ 0
GATE1_~OE
Text GLabel 5250 3200 0    50   Input ~ 0
GATE2_IN
Text GLabel 5450 3550 0    39   Input ~ 0
GATE2_~OE
Text GLabel 5450 4450 0    39   Input ~ 0
GATE3_~OE
Text GLabel 5250 4100 0    50   Input ~ 0
GATE3_IN
Text GLabel 5900 2300 2    50   Input ~ 0
GATE1_125_OUT
Text GLabel 5850 3200 2    50   Input ~ 0
GATE2_125_OUT
Text GLabel 5850 4100 2    50   Input ~ 0
GATE3_125_OUT
Text GLabel 2650 2300 0    50   Input ~ 0
GATE0_OUT
Text GLabel 2650 2400 0    50   Input ~ 0
GATE1_OUT
Text GLabel 2650 2500 0    50   Input ~ 0
GATE2_OUT
Text GLabel 2650 2600 0    50   Input ~ 0
GATE3_OUT
Text GLabel 7600 3700 0    50   Input ~ 0
GATE0_125_OUT
Text GLabel 7600 3800 0    50   Input ~ 0
GATE1_125_OUT
Text GLabel 7600 3900 0    50   Input ~ 0
GATE2_125_OUT
Text GLabel 7600 4000 0    50   Input ~ 0
GATE3_125_OUT
Wire Wire Line
	2650 2700 2550 2700
Wire Wire Line
	2550 2700 2550 2800
Wire Wire Line
	2650 2800 2550 2800
Connection ~ 2550 2800
Wire Wire Line
	2550 2800 2550 2900
Wire Wire Line
	2650 2900 2550 2900
Connection ~ 2550 2900
Wire Wire Line
	2550 2900 2550 3000
Wire Wire Line
	2650 3000 2550 3000
Text GLabel 8100 3700 2    50   Input ~ 0
GATE0_OUT
Text GLabel 8100 3800 2    50   Input ~ 0
GATE1_OUT
Text GLabel 8100 3900 2    50   Input ~ 0
GATE2_OUT
Text GLabel 8100 4000 2    50   Input ~ 0
GATE3_OUT
Text GLabel 7850 1950 0    50   Input ~ 0
GATE0_245_OUT
Text GLabel 7850 2050 0    50   Input ~ 0
GATE1_245_OUT
Text GLabel 7850 2150 0    50   Input ~ 0
GATE2_245_OUT
Text GLabel 7850 2250 0    50   Input ~ 0
GATE3_245_OUT
Text GLabel 3650 2300 2    50   Input ~ 0
GATE0_245_OUT
Text GLabel 3650 2400 2    50   Input ~ 0
GATE1_245_OUT
Text GLabel 3650 2500 2    50   Input ~ 0
GATE2_245_OUT
Text GLabel 3650 2600 2    50   Input ~ 0
GATE3_245_OUT
NoConn ~ 3650 2700
NoConn ~ 3650 2800
NoConn ~ 3650 2900
NoConn ~ 3650 3000
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 61946000
P 1550 1250
F 0 "J1" H 1630 1292 50  0000 L CNN
F 1 "Conn_01x01" H 1630 1201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1550 1250 50  0001 C CNN
F 3 "~" H 1550 1250 50  0001 C CNN
	1    1550 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 619467CE
P 800 1100
F 0 "#PWR01" H 800 950 50  0001 C CNN
F 1 "+3.3V" H 815 1273 50  0000 C CNN
F 2 "" H 800 1100 50  0001 C CNN
F 3 "" H 800 1100 50  0001 C CNN
	1    800  1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1250 1250 1250
Wire Wire Line
	800  1250 800  1100
Wire Wire Line
	1250 1100 1250 1250
Connection ~ 1250 1250
Wire Wire Line
	1250 1250 800  1250
$Comp
L power:PWR_FLAG #FLG02
U 1 1 61961E05
P 4400 4450
F 0 "#FLG02" H 4400 4525 50  0001 C CNN
F 1 "PWR_FLAG" H 4400 4623 50  0000 C CNN
F 2 "" H 4400 4450 50  0001 C CNN
F 3 "~" H 4400 4450 50  0001 C CNN
	1    4400 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4550 4400 4550
Wire Wire Line
	4400 4550 4400 4450
Connection ~ 4100 4550
$Comp
L power:PWR_FLAG #FLG01
U 1 1 6196BC0A
P 3050 5250
F 0 "#FLG01" H 3050 5325 50  0001 C CNN
F 1 "PWR_FLAG" H 3050 5423 50  0000 C CNN
F 2 "" H 3050 5250 50  0001 C CNN
F 3 "~" H 3050 5250 50  0001 C CNN
	1    3050 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 5150 3050 5150
Wire Wire Line
	3050 5150 3050 5250
Connection ~ 3400 5150
$Comp
L power:+5V #PWR012
U 1 1 61976212
P 5400 5200
F 0 "#PWR012" H 5400 5050 50  0001 C CNN
F 1 "+5V" H 5415 5373 50  0000 C CNN
F 2 "" H 5400 5200 50  0001 C CNN
F 3 "" H 5400 5200 50  0001 C CNN
	1    5400 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0101
U 1 1 619F5B6F
P 2100 2000
F 0 "#PWR0101" H 2100 1850 50  0001 C CNN
F 1 "+3.3V" H 2115 2173 50  0000 C CNN
F 2 "" H 2100 2000 50  0001 C CNN
F 3 "" H 2100 2000 50  0001 C CNN
	1    2100 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2000 2100 3200
Wire Wire Line
	2100 3200 2650 3200
Wire Wire Line
	2550 3000 2550 3300
Connection ~ 2550 3000
Connection ~ 2550 3300
Text GLabel 8350 1950 2    39   Input ~ 0
GATE0_~OE
Text GLabel 8350 2050 2    39   Input ~ 0
GATE1_~OE
Text GLabel 8350 2150 2    39   Input ~ 0
GATE2_~OE
Text GLabel 8350 2250 2    39   Input ~ 0
GATE3_~OE
$EndSCHEMATC
