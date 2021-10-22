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
L power:GND #PWR0101
U 1 1 613A85D9
P 3800 3300
F 0 "#PWR0101" H 3800 3050 50  0001 C CNN
F 1 "GND" H 3805 3127 50  0000 C CNN
F 2 "" H 3800 3300 50  0001 C CNN
F 3 "" H 3800 3300 50  0001 C CNN
	1    3800 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3300 2150 3000
Wire Wire Line
	2150 1100 2050 1100
Wire Wire Line
	2050 1200 2150 1200
Connection ~ 2150 1200
Wire Wire Line
	2150 1200 2150 1100
Wire Wire Line
	2050 1300 2150 1300
Connection ~ 2150 1300
Wire Wire Line
	2150 1300 2150 1200
Wire Wire Line
	2050 1400 2150 1400
Connection ~ 2150 1400
Wire Wire Line
	2150 1400 2150 1300
Wire Wire Line
	2050 1500 2150 1500
Connection ~ 2150 1500
Wire Wire Line
	2150 1500 2150 1400
Wire Wire Line
	2050 1600 2150 1600
Connection ~ 2150 1600
Wire Wire Line
	2150 1600 2150 1500
Wire Wire Line
	2050 1700 2150 1700
Connection ~ 2150 1700
Wire Wire Line
	2150 1700 2150 1600
Wire Wire Line
	2050 1800 2150 1800
Connection ~ 2150 1800
Wire Wire Line
	2150 1800 2150 1700
Wire Wire Line
	2050 1900 2150 1900
Connection ~ 2150 1900
Wire Wire Line
	2150 1900 2150 1800
Wire Wire Line
	2050 2100 2150 2100
Connection ~ 2150 2100
Wire Wire Line
	2150 2100 2150 1900
Wire Wire Line
	2050 2200 2150 2200
Connection ~ 2150 2200
Wire Wire Line
	2150 2200 2150 2100
Wire Wire Line
	2050 2300 2150 2300
Connection ~ 2150 2300
Wire Wire Line
	2150 2300 2150 2200
Wire Wire Line
	2050 3000 2150 3000
Connection ~ 2150 3000
Wire Wire Line
	2150 3000 2150 2900
Wire Wire Line
	2050 2900 2150 2900
Connection ~ 2150 2900
Wire Wire Line
	2150 2900 2150 2800
Wire Wire Line
	2050 2800 2150 2800
Connection ~ 2150 2800
Wire Wire Line
	2050 2600 2150 2600
Connection ~ 2150 2600
Wire Wire Line
	2150 2600 2150 2500
Wire Wire Line
	2050 2500 2150 2500
Connection ~ 2150 2500
Wire Wire Line
	2150 2500 2150 2400
Wire Wire Line
	2050 2400 2150 2400
Connection ~ 2150 2400
Wire Wire Line
	2150 2400 2150 2300
Text GLabel 1250 2900 0    39   Input ~ 0
~CS
Text GLabel 1250 3000 0    39   Input ~ 0
~DRIVE_ACTIVE
Text GLabel 1250 2800 0    50   Input ~ 0
A0
Text GLabel 1250 2700 0    50   Input ~ 0
A1
Text GLabel 1250 1100 0    39   Input ~ 0
~RESET
Text GLabel 1250 1200 0    50   Input ~ 0
D7
Text GLabel 1250 1300 0    50   Input ~ 0
D6
Text GLabel 1250 1400 0    50   Input ~ 0
D5
Text GLabel 1250 1500 0    50   Input ~ 0
D4
Text GLabel 1250 1600 0    50   Input ~ 0
D3
Text GLabel 1250 1800 0    50   Input ~ 0
D1
Text GLabel 1250 1900 0    50   Input ~ 0
D0
Text GLabel 1250 1700 0    50   Input ~ 0
D2
$Comp
L power:GND #PWR0102
U 1 1 613B07D2
P 750 3300
F 0 "#PWR0102" H 750 3050 50  0001 C CNN
F 1 "GND" H 755 3127 50  0000 C CNN
F 2 "" H 750 3300 50  0001 C CNN
F 3 "" H 750 3300 50  0001 C CNN
	1    750  3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 2000 750  2000
Wire Wire Line
	750  2000 750  3300
Text GLabel 1250 2100 0    50   Input ~ 0
AEN
Text GLabel 1250 2200 0    39   Input ~ 0
~IOW
Text GLabel 1250 2300 0    39   Input ~ 0
~IOR
Text GLabel 1250 2400 0    39   Input ~ 0
~DACK
Text GLabel 1250 2500 0    50   Input ~ 0
DRQ
Text GLabel 1250 2600 0    50   Input ~ 0
IRQ
$Comp
L 00Custom:XTA_Connector J1
U 1 1 616B1E7B
P 1650 2000
F 0 "J1" H 1650 3165 50  0000 C CNN
F 1 "XTA_Connector" H 1650 3074 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Horizontal" H 1650 3050 50  0001 C CNN
F 3 "" H 1650 3050 50  0001 C CNN
	1    1650 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2600 2150 2800
NoConn ~ 2050 2700
$Comp
L 00Custom:IBM_8bit_DBA J2
U 1 1 616BC629
P 3200 2000
F 0 "J2" H 3200 3165 50  0000 C CNN
F 1 "IBM_8bit_DBA" H 3200 3074 50  0000 C CNN
F 2 "" H 3200 3050 50  0001 C CNN
F 3 "" H 3200 3050 50  0001 C CNN
	1    3200 2000
	1    0    0    -1  
$EndComp
Text GLabel 2700 1100 0    39   Input ~ 0
~RESET
Text GLabel 2700 1900 0    50   Input ~ 0
D7
Text GLabel 2700 1800 0    50   Input ~ 0
D6
Text GLabel 2700 1700 0    50   Input ~ 0
D5
Text GLabel 2700 1600 0    50   Input ~ 0
D4
Text GLabel 2700 1500 0    50   Input ~ 0
D3
Text GLabel 2700 1300 0    50   Input ~ 0
D1
Text GLabel 2700 1200 0    50   Input ~ 0
D0
Text GLabel 2700 1400 0    50   Input ~ 0
D2
Text GLabel 2700 2000 0    39   Input ~ 0
~IOR
Text GLabel 2700 2100 0    39   Input ~ 0
~IOW
Text GLabel 2700 2200 0    39   Input ~ 0
~CS
NoConn ~ 2700 2300
Text GLabel 2700 2400 0    50   Input ~ 0
A0
Text GLabel 2700 2500 0    50   Input ~ 0
A1
NoConn ~ 2700 2600
NoConn ~ 2700 3100
NoConn ~ 2700 3200
NoConn ~ 3700 3000
NoConn ~ 3700 3100
Text GLabel 2700 2700 0    39   Input ~ 0
~DACK
Text GLabel 2700 2800 0    50   Input ~ 0
DRQ
Text GLabel 2700 2900 0    50   Input ~ 0
IRQ
NoConn ~ 2700 3000
$Comp
L power:GND #PWR01
U 1 1 616C3ED0
P 2150 3300
F 0 "#PWR01" H 2150 3050 50  0001 C CNN
F 1 "GND" H 2155 3127 50  0000 C CNN
F 2 "" H 2150 3300 50  0001 C CNN
F 3 "" H 2150 3300 50  0001 C CNN
	1    2150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1200 3800 1200
Wire Wire Line
	3800 1200 3800 1300
Wire Wire Line
	3700 1300 3800 1300
Connection ~ 3800 1300
Wire Wire Line
	3800 1300 3800 1400
Wire Wire Line
	3700 1400 3800 1400
Connection ~ 3800 1400
Wire Wire Line
	3800 1400 3800 1500
Wire Wire Line
	3800 1500 3700 1500
Connection ~ 3800 1500
Wire Wire Line
	3800 1500 3800 1600
Wire Wire Line
	3700 1600 3800 1600
Connection ~ 3800 1600
Wire Wire Line
	3800 1600 3800 1700
Wire Wire Line
	3700 1700 3800 1700
Connection ~ 3800 1700
Wire Wire Line
	3800 1700 3800 1800
Wire Wire Line
	3700 1800 3800 1800
Connection ~ 3800 1800
Wire Wire Line
	3800 1800 3800 1900
Wire Wire Line
	3700 1900 3800 1900
Connection ~ 3800 1900
Wire Wire Line
	3800 1900 3800 2000
Wire Wire Line
	3700 2000 3800 2000
Connection ~ 3800 2000
Wire Wire Line
	3800 2000 3800 2100
Wire Wire Line
	3700 2100 3800 2100
Connection ~ 3800 2100
Wire Wire Line
	3800 2100 3800 2200
Wire Wire Line
	3700 2200 3800 2200
Connection ~ 3800 2200
Wire Wire Line
	3700 2300 3800 2300
Wire Wire Line
	3800 2200 3800 2300
Connection ~ 3800 2300
Wire Wire Line
	3800 2300 3800 2400
Wire Wire Line
	3700 2400 3800 2400
Connection ~ 3800 2400
Wire Wire Line
	3800 2400 3800 2700
Wire Wire Line
	3700 2700 3800 2700
Connection ~ 3800 2700
Wire Wire Line
	3800 2700 3800 2800
Wire Wire Line
	3700 2800 3800 2800
Connection ~ 3800 2800
Wire Wire Line
	3800 2800 3800 2900
Wire Wire Line
	3700 2900 3800 2900
Connection ~ 3800 2900
Wire Wire Line
	3800 2900 3800 3300
Wire Wire Line
	3900 2500 3700 2500
Wire Wire Line
	3700 2600 3900 2600
Wire Wire Line
	3900 2600 3900 2500
Wire Wire Line
	3700 3200 3900 3200
Text GLabel 3900 3200 2    50   Input ~ 0
IBM_SENSE_12V
Connection ~ 3800 1200
Wire Wire Line
	3800 1100 3800 1200
Wire Wire Line
	3700 1100 3800 1100
$Comp
L 00Custom:RPI_PICO U4
U 1 1 616E2BFC
P 9200 4450
F 0 "U4" H 9200 5615 50  0000 C CNN
F 1 "RPI_PICO" H 9200 5524 50  0000 C CNN
F 2 "Pico:RPi_Pico_SMD_TH" H 9200 5450 50  0001 C CNN
F 3 "" H 9200 5450 50  0001 C CNN
	1    9200 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 616E500E
P 8600 5550
F 0 "#PWR017" H 8600 5300 50  0001 C CNN
F 1 "GND" H 8605 5377 50  0000 C CNN
F 2 "" H 8600 5550 50  0001 C CNN
F 3 "" H 8600 5550 50  0001 C CNN
	1    8600 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 616E680C
P 9800 5550
F 0 "#PWR019" H 9800 5300 50  0001 C CNN
F 1 "GND" H 9805 5377 50  0000 C CNN
F 2 "" H 9800 5550 50  0001 C CNN
F 3 "" H 9800 5550 50  0001 C CNN
	1    9800 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 5550 8600 5250
Wire Wire Line
	8600 3750 8700 3750
Wire Wire Line
	8700 4250 8600 4250
Connection ~ 8600 4250
Wire Wire Line
	8600 4250 8600 3750
Wire Wire Line
	8700 4750 8600 4750
Connection ~ 8600 4750
Wire Wire Line
	8600 4750 8600 4250
Wire Wire Line
	8700 5250 8600 5250
Connection ~ 8600 5250
Wire Wire Line
	8600 5250 8600 4750
Wire Wire Line
	9800 5550 9800 5250
Wire Wire Line
	9800 3750 9700 3750
Wire Wire Line
	9700 5250 9800 5250
Connection ~ 9800 5250
Wire Wire Line
	9800 5250 9800 4750
Wire Wire Line
	9700 4750 9800 4750
Connection ~ 9800 4750
Wire Wire Line
	9800 4750 9800 4250
Wire Wire Line
	9700 4250 9800 4250
Connection ~ 9800 4250
Wire Wire Line
	9800 4250 9800 3750
NoConn ~ 9700 3550
$Comp
L power:+3.3V #PWR020
U 1 1 616F5B8D
P 9900 3450
F 0 "#PWR020" H 9900 3300 50  0001 C CNN
F 1 "+3.3V" H 9915 3623 50  0000 C CNN
F 2 "" H 9900 3450 50  0001 C CNN
F 3 "" H 9900 3450 50  0001 C CNN
	1    9900 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 3950 9900 3950
Wire Wire Line
	9900 3950 9900 3450
NoConn ~ 9700 3850
NoConn ~ 9700 4050
$Comp
L Switch:SW_Push SW3
U 1 1 61708BD1
P 10600 4550
F 0 "SW3" H 10600 4700 50  0000 C CNN
F 1 "Reset" H 10600 4450 50  0000 C CNN
F 2 "" H 10600 4750 50  0001 C CNN
F 3 "~" H 10600 4750 50  0001 C CNN
	1    10600 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 6170CD99
P 10900 5550
F 0 "#PWR021" H 10900 5300 50  0001 C CNN
F 1 "GND" H 10905 5377 50  0000 C CNN
F 2 "" H 10900 5550 50  0001 C CNN
F 3 "" H 10900 5550 50  0001 C CNN
	1    10900 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10900 5550 10900 4550
Wire Wire Line
	10900 4550 10800 4550
Wire Wire Line
	10400 4550 9700 4550
Text GLabel 8500 3850 0    50   Input ~ 0
D0_3V3
Text GLabel 8500 3950 0    50   Input ~ 0
D1_3V3
Text GLabel 8500 4050 0    50   Input ~ 0
D2_3V3
Wire Wire Line
	8500 3850 8700 3850
Text GLabel 8500 4150 0    50   Input ~ 0
D3_3V3
Wire Wire Line
	8500 3950 8700 3950
Text GLabel 8500 4350 0    50   Input ~ 0
D4_3V3
Wire Wire Line
	8500 4050 8700 4050
Text GLabel 8500 4450 0    50   Input ~ 0
D5_3V3
Wire Wire Line
	8500 4150 8700 4150
Text GLabel 8500 4550 0    50   Input ~ 0
D6_3V3
Wire Wire Line
	8500 4350 8700 4350
Text GLabel 8500 4650 0    50   Input ~ 0
D7_3V3
Wire Wire Line
	8500 4450 8700 4450
Text GLabel 8500 4850 0    50   Input ~ 0
A0_3V3
Wire Wire Line
	8500 4550 8700 4550
Text GLabel 8500 4950 0    50   Input ~ 0
A1_3V3
Wire Wire Line
	8500 4650 8700 4650
Text Notes 7000 6850 0    39   ~ 0
On GP26-28, there is a clamp diode\nto 3.3v, should one be needed.
Wire Wire Line
	8500 4850 8700 4850
Text GLabel 8500 5050 0    50   Input ~ 0
AEN_3V3
Text GLabel 8500 5150 0    39   Input ~ 0
~DACK~_3V3
Text GLabel 8500 5350 0    39   Input ~ 0
~DRQ~_3V3
Text GLabel 8500 5450 0    39   Input ~ 0
~IRQ~_3V3
Text GLabel 9900 4950 2    39   Input ~ 0
~IOR~_3V3
Text GLabel 9900 4850 2    39   Input ~ 0
~IOW~_3V3
Text GLabel 9900 4450 2    39   Input ~ 0
~RESET~_3V3
Wire Wire Line
	8500 4950 8700 4950
Wire Wire Line
	8700 5050 8500 5050
Wire Wire Line
	8500 5150 8700 5150
Wire Wire Line
	9900 5150 9700 5150
Wire Wire Line
	8500 5450 8700 5450
Wire Wire Line
	8700 5350 8500 5350
Text GLabel 9900 4350 2    39   Input ~ 0
~CS~_3V3
Wire Wire Line
	9900 5450 9700 5450
$Comp
L 74xx:74LS245 U1
U 1 1 61777D2A
P 1550 5000
F 0 "U1" H 1700 5800 50  0000 C CNN
F 1 "74LVC245" H 1750 5700 50  0000 C CNN
F 2 "" H 1550 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 1550 5000 50  0001 C CNN
	1    1550 5000
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS245 U2
U 1 1 61779EE3
P 3200 5000
F 0 "U2" H 3400 5800 50  0000 C CNN
F 1 "74LVC245" H 3450 5700 50  0000 C CNN
F 2 "" H 3200 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 3200 5000 50  0001 C CNN
	1    3200 5000
	1    0    0    -1  
$EndComp
Text GLabel 2050 4500 2    50   Input ~ 0
D0_3V3
Text GLabel 2050 4600 2    50   Input ~ 0
D1_3V3
Text GLabel 2050 4700 2    50   Input ~ 0
D2_3V3
Text GLabel 2050 4800 2    50   Input ~ 0
D3_3V3
Text GLabel 2050 4900 2    50   Input ~ 0
D4_3V3
Text GLabel 2050 5000 2    50   Input ~ 0
D5_3V3
Text GLabel 2050 5100 2    50   Input ~ 0
D6_3V3
Text GLabel 2050 5200 2    50   Input ~ 0
D7_3V3
Text GLabel 1050 5200 0    50   Input ~ 0
D7
Text GLabel 1050 5100 0    50   Input ~ 0
D6
Text GLabel 1050 5000 0    50   Input ~ 0
D5
Text GLabel 1050 4900 0    50   Input ~ 0
D4
Text GLabel 1050 4800 0    50   Input ~ 0
D3
Text GLabel 1050 4600 0    50   Input ~ 0
D1
Text GLabel 1050 4500 0    50   Input ~ 0
D0
Text GLabel 1050 4700 0    50   Input ~ 0
D2
$Comp
L power:GND #PWR04
U 1 1 6178EEF3
P 1550 5800
F 0 "#PWR04" H 1550 5550 50  0001 C CNN
F 1 "GND" H 1555 5627 50  0000 C CNN
F 2 "" H 1550 5800 50  0001 C CNN
F 3 "" H 1550 5800 50  0001 C CNN
	1    1550 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 6179270F
P 3200 5800
F 0 "#PWR08" H 3200 5550 50  0001 C CNN
F 1 "GND" H 3205 5627 50  0000 C CNN
F 2 "" H 3200 5800 50  0001 C CNN
F 3 "" H 3200 5800 50  0001 C CNN
	1    3200 5800
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 617960B6
P 1550 4200
F 0 "#PWR03" H 1550 4050 50  0001 C CNN
F 1 "+3.3V" H 1565 4373 50  0000 C CNN
F 2 "" H 1550 4200 50  0001 C CNN
F 3 "" H 1550 4200 50  0001 C CNN
	1    1550 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR07
U 1 1 61799FCA
P 3200 4200
F 0 "#PWR07" H 3200 4050 50  0001 C CNN
F 1 "+3.3V" H 3215 4373 50  0000 C CNN
F 2 "" H 3200 4200 50  0001 C CNN
F 3 "" H 3200 4200 50  0001 C CNN
	1    3200 4200
	1    0    0    -1  
$EndComp
Text GLabel 3700 4500 2    50   Input ~ 0
A0_3V3
Text GLabel 3700 4600 2    50   Input ~ 0
A1_3V3
Text GLabel 3700 4700 2    50   Input ~ 0
AEN_3V3
Text GLabel 3700 4800 2    39   Input ~ 0
~DACK~_3V3
Text GLabel 4800 5750 0    39   Input ~ 0
~IRQ~_3V3
Text GLabel 3700 5100 2    39   Input ~ 0
~IOR~_3V3
Text GLabel 3700 5200 2    39   Input ~ 0
~IOW~_3V3
Text GLabel 2700 5100 0    39   Input ~ 0
~IOR
Text GLabel 2700 5200 0    39   Input ~ 0
~IOW
Text GLabel 2700 4900 0    39   Input ~ 0
~CS
Text GLabel 2700 4500 0    50   Input ~ 0
A0
Text GLabel 2700 4600 0    50   Input ~ 0
A1
Text GLabel 2700 4800 0    39   Input ~ 0
~DACK
Text GLabel 5200 5400 2    50   Input ~ 0
IRQ
Text GLabel 2700 4700 0    50   Input ~ 0
AEN
$Comp
L power:GND #PWR06
U 1 1 617DC24E
P 2600 5800
F 0 "#PWR06" H 2600 5550 50  0001 C CNN
F 1 "GND" H 2605 5627 50  0000 C CNN
F 2 "" H 2600 5800 50  0001 C CNN
F 3 "" H 2600 5800 50  0001 C CNN
	1    2600 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5400 2600 5400
Wire Wire Line
	2600 5400 2600 5500
Wire Wire Line
	2700 5500 2600 5500
Connection ~ 2600 5500
Wire Wire Line
	2600 5500 2600 5800
$Comp
L power:GND #PWR02
U 1 1 617E7BDD
P 950 5800
F 0 "#PWR02" H 950 5550 50  0001 C CNN
F 1 "GND" H 955 5627 50  0000 C CNN
F 2 "" H 950 5800 50  0001 C CNN
F 3 "" H 950 5800 50  0001 C CNN
	1    950  5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5500 950  5500
Wire Wire Line
	950  5500 950  5800
Text GLabel 9900 4650 2    50   Input ~ 0
DATA_DIR
Text GLabel 1050 5400 0    50   Input ~ 0
DATA_DIR
Text GLabel 6350 2150 2    50   Input ~ 0
IBM_SENSE_3V3
Text GLabel 3700 5000 2    39   Input ~ 0
~RESET~_3V3
Text GLabel 3700 4900 2    39   Input ~ 0
~CS~_3V3
Text GLabel 2700 5000 0    39   Input ~ 0
~RESET
Text GLabel 5750 1100 0    50   Input ~ 0
IBM_SENSE_12V
Text GLabel 6550 4400 2    39   Input ~ 0
~DRIVE_ACTIVE
Wire Wire Line
	9900 5050 9700 5050
Text GLabel 6150 4750 0    39   Input ~ 0
~DRIVE_ACTIVE~_3V3
$Comp
L Device:R R1
U 1 1 619004C3
P 6700 5400
F 0 "R1" V 6600 5400 50  0000 C CNN
F 1 "120R" V 6700 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6630 5400 50  0001 C CNN
F 3 "~" H 6700 5400 50  0001 C CNN
F 4 "C17909" V 6700 5400 50  0001 C CNN "LCSC"
	1    6700 5400
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 61901414
P 7150 5300
F 0 "J4" H 7230 5292 50  0000 L CNN
F 1 "LED" H 7230 5201 50  0000 L CNN
F 2 "" H 7150 5300 50  0001 C CNN
F 3 "~" H 7150 5300 50  0001 C CNN
	1    7150 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 61907FFF
P 6850 5050
F 0 "R2" V 6750 5050 50  0000 C CNN
F 1 "120R" V 6850 5050 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6780 5050 50  0001 C CNN
F 3 "~" H 6850 5050 50  0001 C CNN
F 4 "C17909" V 6850 5050 50  0001 C CNN "LCSC"
	1    6850 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5200 6850 5300
Wire Wire Line
	6850 5300 6950 5300
Wire Wire Line
	6850 5400 6950 5400
Text GLabel 10000 3650 2    50   Input ~ 0
VSYS
Text GLabel 4000 2500 2    50   Input ~ 0
IBM_5V_POWER
Wire Wire Line
	4000 2500 3900 2500
Connection ~ 3900 2500
Wire Wire Line
	10000 3650 9700 3650
$Comp
L power:+5V #PWR014
U 1 1 619C3A9B
P 6150 6450
F 0 "#PWR014" H 6150 6300 50  0001 C CNN
F 1 "+5V" H 6165 6623 50  0000 C CNN
F 2 "" H 6150 6450 50  0001 C CNN
F 3 "" H 6150 6450 50  0001 C CNN
	1    6150 6450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR016
U 1 1 619CA0AA
P 6850 4900
F 0 "#PWR016" H 6850 4750 50  0001 C CNN
F 1 "+5V" H 6865 5073 50  0000 C CNN
F 2 "" H 6850 4900 50  0001 C CNN
F 3 "" H 6850 4900 50  0001 C CNN
	1    6850 4900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U3
U 1 1 61A05A47
P 6250 4400
F 0 "U3" H 6250 4717 50  0000 C CNN
F 1 "74HCT125" H 6250 4626 50  0000 C CNN
F 2 "" H 6250 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 6250 4400 50  0001 C CNN
	1    6250 4400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U3
U 2 1 61A22FCF
P 6250 5400
F 0 "U3" H 6250 5717 50  0000 C CNN
F 1 "74HCT125" H 6250 5626 50  0000 C CNN
F 2 "" H 6250 5400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 6250 5400 50  0001 C CNN
	2    6250 5400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U3
U 4 1 61A24A99
P 4900 5400
F 0 "U3" H 4900 5717 50  0000 C CNN
F 1 "74HCT125" H 4900 5626 50  0000 C CNN
F 2 "" H 4900 5400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 4900 5400 50  0001 C CNN
	4    4900 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 61A2BCE2
P 6150 7450
F 0 "#PWR015" H 6150 7200 50  0001 C CNN
F 1 "GND" H 6155 7277 50  0000 C CNN
F 2 "" H 6150 7450 50  0001 C CNN
F 3 "" H 6150 7450 50  0001 C CNN
	1    6150 7450
	1    0    0    -1  
$EndComp
Text GLabel 6150 5750 0    39   Input ~ 0
~DRIVE_ACTIVE~_3V3
Wire Wire Line
	4900 5650 4900 5750
Wire Wire Line
	4900 5750 4800 5750
$Comp
L power:+5V #PWR010
U 1 1 61A79D79
P 4500 5300
F 0 "#PWR010" H 4500 5150 50  0001 C CNN
F 1 "+5V" H 4515 5473 50  0000 C CNN
F 2 "" H 4500 5300 50  0001 C CNN
F 3 "" H 4500 5300 50  0001 C CNN
	1    4500 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4300 4500 4400
Wire Wire Line
	4500 5300 4500 5400
Wire Wire Line
	4500 5400 4600 5400
$Comp
L power:GND #PWR018
U 1 1 61A8B095
P 5850 2500
F 0 "#PWR018" H 5850 2250 50  0001 C CNN
F 1 "GND" H 5855 2327 50  0000 C CNN
F 2 "" H 5850 2500 50  0001 C CNN
F 3 "" H 5850 2500 50  0001 C CNN
	1    5850 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 61A8B9EC
P 5850 1350
F 0 "R3" V 5750 1350 50  0000 C CNN
F 1 "10K" V 5850 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5780 1350 50  0001 C CNN
F 3 "~" H 5850 1350 50  0001 C CNN
F 4 "C17902" V 5850 1350 50  0001 C CNN "LCSC"
	1    5850 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 61A8C2DA
P 5850 1650
F 0 "R4" V 5750 1650 50  0000 C CNN
F 1 "10K" V 5850 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5780 1650 50  0001 C CNN
F 3 "~" H 5850 1650 50  0001 C CNN
F 4 "C17902" V 5850 1650 50  0001 C CNN "LCSC"
	1    5850 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 61A8C681
P 5850 1950
F 0 "R5" V 5750 1950 50  0000 C CNN
F 1 "10K" V 5850 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5780 1950 50  0001 C CNN
F 3 "~" H 5850 1950 50  0001 C CNN
F 4 "C17902" V 5850 1950 50  0001 C CNN "LCSC"
	1    5850 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 61A8C9C2
P 5850 2350
F 0 "R6" V 5750 2350 50  0000 C CNN
F 1 "10K" V 5850 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5780 2350 50  0001 C CNN
F 3 "~" H 5850 2350 50  0001 C CNN
F 4 "C17902" V 5850 2350 50  0001 C CNN "LCSC"
	1    5850 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1100 5850 1100
Wire Wire Line
	5850 1100 5850 1200
Wire Wire Line
	5850 2100 5850 2150
Wire Wire Line
	5850 2150 6250 2150
Connection ~ 5850 2150
Wire Wire Line
	5850 2150 5850 2200
$Comp
L power:GND #PWR013
U 1 1 61ACD819
P 5950 5400
F 0 "#PWR013" H 5950 5150 50  0001 C CNN
F 1 "GND" H 5955 5227 50  0000 C CNN
F 2 "" H 5950 5400 50  0001 C CNN
F 3 "" H 5950 5400 50  0001 C CNN
	1    5950 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 61ACDDAB
P 5950 4400
F 0 "#PWR012" H 5950 4150 50  0001 C CNN
F 1 "GND" H 5955 4227 50  0000 C CNN
F 2 "" H 5950 4400 50  0001 C CNN
F 3 "" H 5950 4400 50  0001 C CNN
	1    5950 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 4750 6250 4750
Wire Wire Line
	6250 4750 6250 4650
Wire Wire Line
	6150 5750 6250 5750
Wire Wire Line
	6250 5750 6250 5650
Text GLabel 9900 5450 2    50   Input ~ 0
SD_DO
Text GLabel 9900 5050 2    50   Input ~ 0
SD_DI
Text GLabel 9900 5150 2    50   Input ~ 0
SD_SCK
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 61700DAF
P 9100 6300
F 0 "J5" V 8972 6580 50  0000 L CNN
F 1 "Debug" V 9063 6580 50  0000 L CNN
F 2 "" H 9100 6300 50  0001 C CNN
F 3 "~" H 9100 6300 50  0001 C CNN
	1    9100 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 5650 9100 6100
Wire Wire Line
	9300 5650 9300 6100
Wire Wire Line
	9200 6100 9200 5750
Wire Wire Line
	8900 6100 8900 5750
Wire Wire Line
	8900 5750 9200 5750
Connection ~ 9200 5750
Wire Wire Line
	9200 5750 9200 5650
Text GLabel 8800 6100 1    50   Input ~ 0
DBG_RX
Text GLabel 9000 6100 1    50   Input ~ 0
DBG_TX
Wire Wire Line
	9900 4950 9700 4950
Wire Wire Line
	9900 4850 9700 4850
Wire Wire Line
	9900 4450 9700 4450
Wire Wire Line
	9900 4350 9700 4350
$Comp
L 74xx:74HC165 U5
U 1 1 617B9142
P 10000 1750
F 0 "U5" H 10200 2650 50  0000 C CNN
F 1 "74HC165" H 10250 2550 50  0000 C CNN
F 2 "" H 10000 1750 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT165.pdf" H 10000 1750 50  0001 C CNN
	1    10000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4650 9700 4650
$Comp
L power:+3.3V #PWR025
U 1 1 617C23B1
P 10000 850
F 0 "#PWR025" H 10000 700 50  0001 C CNN
F 1 "+3.3V" H 10015 1023 50  0000 C CNN
F 2 "" H 10000 850 50  0001 C CNN
F 3 "" H 10000 850 50  0001 C CNN
	1    10000 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 617C3DB3
P 10000 2750
F 0 "#PWR026" H 10000 2500 50  0001 C CNN
F 1 "GND" H 10005 2577 50  0000 C CNN
F 2 "" H 10000 2750 50  0001 C CNN
F 3 "" H 10000 2750 50  0001 C CNN
	1    10000 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 617CC8E0
P 9400 2750
F 0 "#PWR024" H 9400 2500 50  0001 C CNN
F 1 "GND" H 9405 2577 50  0000 C CNN
F 2 "" H 9400 2750 50  0001 C CNN
F 3 "" H 9400 2750 50  0001 C CNN
	1    9400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2450 9400 2450
Wire Wire Line
	9400 2450 9400 2750
Text GLabel 9300 2350 0    50   Input ~ 0
CFG_CLK
NoConn ~ 10500 1250
Text GLabel 10500 1150 2    50   Input ~ 0
CFG_DATA
Text GLabel 9200 1050 0    50   Input ~ 0
IBM_SENSE_3V3
$Comp
L Device:D_Schottky D2
U 1 1 61833A4A
P 6250 1900
F 0 "D2" H 6300 2000 50  0000 R CNN
F 1 "MBR120/130" H 6450 1750 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-123" H 6250 1900 50  0001 C CNN
F 3 "~" H 6250 1900 50  0001 C CNN
	1    6250 1900
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR022
U 1 1 61834C07
P 6250 1750
F 0 "#PWR022" H 6250 1600 50  0001 C CNN
F 1 "+3.3V" H 6265 1923 50  0000 C CNN
F 2 "" H 6250 1750 50  0001 C CNN
F 3 "" H 6250 1750 50  0001 C CNN
	1    6250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2050 6250 2150
Connection ~ 6250 2150
Wire Wire Line
	6250 2150 6350 2150
Wire Wire Line
	9500 1150 9400 1150
Connection ~ 9400 2450
Wire Wire Line
	9500 1250 9300 1250
Wire Wire Line
	9300 1250 9300 1050
Wire Wire Line
	9300 1050 9200 1050
$Comp
L Device:R R7
U 1 1 619074AD
P 7800 1250
F 0 "R7" V 7750 1050 50  0000 C CNN
F 1 "10K" V 7800 1250 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7730 1250 50  0001 C CNN
F 3 "~" H 7800 1250 50  0001 C CNN
F 4 "C17902" V 7800 1250 50  0001 C CNN "LCSC"
	1    7800 1250
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 61908537
P 7800 1350
F 0 "R8" V 7750 1150 50  0000 C CNN
F 1 "10K" V 7800 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7730 1350 50  0001 C CNN
F 3 "~" H 7800 1350 50  0001 C CNN
F 4 "C17902" V 7800 1350 50  0001 C CNN "LCSC"
	1    7800 1350
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 61911193
P 7800 1450
F 0 "R9" V 7750 1250 50  0000 C CNN
F 1 "10K" V 7800 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7730 1450 50  0001 C CNN
F 3 "~" H 7800 1450 50  0001 C CNN
F 4 "C17902" V 7800 1450 50  0001 C CNN "LCSC"
	1    7800 1450
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 61911316
P 7800 1550
F 0 "R10" V 7750 1350 50  0000 C CNN
F 1 "10K" V 7800 1550 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7730 1550 50  0001 C CNN
F 3 "~" H 7800 1550 50  0001 C CNN
F 4 "C17902" V 7800 1550 50  0001 C CNN "LCSC"
	1    7800 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 619114A7
P 7800 1750
F 0 "R11" V 7750 1550 50  0000 C CNN
F 1 "10K" V 7800 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7730 1750 50  0001 C CNN
F 3 "~" H 7800 1750 50  0001 C CNN
F 4 "C17902" V 7800 1750 50  0001 C CNN "LCSC"
	1    7800 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 1250 7450 1250
Wire Wire Line
	7450 1250 7450 1150
Wire Wire Line
	7450 1250 7450 1350
Connection ~ 7450 1250
Wire Wire Line
	7650 1550 7450 1550
Connection ~ 7450 1550
Wire Wire Line
	7450 1550 7450 1750
Wire Wire Line
	7650 1450 7450 1450
Connection ~ 7450 1450
Wire Wire Line
	7450 1450 7450 1550
Wire Wire Line
	7650 1350 7450 1350
Connection ~ 7450 1350
Wire Wire Line
	7450 1350 7450 1450
$Comp
L power:+3.3V #PWR023
U 1 1 61952AA4
P 7450 1150
F 0 "#PWR023" H 7450 1000 50  0001 C CNN
F 1 "+3.3V" H 7465 1323 50  0000 C CNN
F 2 "" H 7450 1150 50  0001 C CNN
F 3 "" H 7450 1150 50  0001 C CNN
	1    7450 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2150 9500 2150
Wire Wire Line
	9500 2350 9300 2350
Text Label 8800 1350 0    50   ~ 0
RESET_INVERT
Text Label 8800 1450 0    50   ~ 0
DRIVE_SIZE_0
Text Label 8800 1550 0    50   ~ 0
DRIVE_SIZE_2
Text Label 8800 1650 0    50   ~ 0
DRIVE_SIZE_3
$Comp
L power:GND #PWR027
U 1 1 619B6D52
P 8150 2750
F 0 "#PWR027" H 8150 2500 50  0001 C CNN
F 1 "GND" H 8155 2577 50  0000 C CNN
F 2 "" H 8150 2750 50  0001 C CNN
F 3 "" H 8150 2750 50  0001 C CNN
	1    8150 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2550 8150 2750
Text Label 8800 1750 0    50   ~ 0
BOOT_INTERNAL
$Comp
L Switch:SW_DIP_x04 SW1
U 1 1 618767D9
P 8250 1450
F 0 "SW1" H 8250 1917 50  0000 C CNN
F 1 "Config" H 8250 1826 50  0000 C CNN
F 2 "" H 8250 1450 50  0001 C CNN
F 3 "~" H 8250 1450 50  0001 C CNN
F 4 "" H 8250 1450 50  0001 C CNN "LCSC"
F 5 "" H 8250 1450 50  0001 C CNN "Part options"
	1    8250 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1750 9500 1750
Wire Wire Line
	9400 1150 9400 1850
Wire Wire Line
	8550 1250 8800 1250
Wire Wire Line
	8800 1250 8800 1350
Wire Wire Line
	8800 1350 9500 1350
Wire Wire Line
	8550 1350 8750 1350
Wire Wire Line
	8750 1350 8750 1450
Wire Wire Line
	8750 1450 9500 1450
Wire Wire Line
	8700 1450 8700 1550
Wire Wire Line
	8700 1550 9500 1550
Wire Wire Line
	8550 1450 8700 1450
Wire Wire Line
	8550 1550 8650 1550
Wire Wire Line
	8650 1550 8650 1650
Wire Wire Line
	8650 1650 9500 1650
Wire Wire Line
	7650 1750 7450 1750
Wire Wire Line
	7950 1750 8150 1750
Connection ~ 8150 1750
Wire Wire Line
	8150 1750 8150 2150
$Comp
L Device:C C1
U 1 1 61C62A1F
P 3050 7000
F 0 "C1" H 3165 7046 50  0000 L CNN
F 1 "0.1uF" H 3165 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3088 6850 50  0001 C CNN
F 3 "~" H 3050 7000 50  0001 C CNN
F 4 " C24497" H 3050 7000 50  0001 C CNN "LCSC"
	1    3050 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 61C633FA
P 3050 7150
F 0 "#PWR029" H 3050 6900 50  0001 C CNN
F 1 "GND" H 3055 6977 50  0000 C CNN
F 2 "" H 3050 7150 50  0001 C CNN
F 3 "" H 3050 7150 50  0001 C CNN
	1    3050 7150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR028
U 1 1 61C63910
P 3050 6850
F 0 "#PWR028" H 3050 6700 50  0001 C CNN
F 1 "+3.3V" H 3065 7023 50  0000 C CNN
F 2 "" H 3050 6850 50  0001 C CNN
F 3 "" H 3050 6850 50  0001 C CNN
	1    3050 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61C64D1D
P 3550 7000
F 0 "C2" H 3665 7046 50  0000 L CNN
F 1 "0.1uF" H 3665 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3588 6850 50  0001 C CNN
F 3 "~" H 3550 7000 50  0001 C CNN
F 4 " C24497" H 3550 7000 50  0001 C CNN "LCSC"
	1    3550 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR031
U 1 1 61C64D35
P 3550 7150
F 0 "#PWR031" H 3550 6900 50  0001 C CNN
F 1 "GND" H 3555 6977 50  0000 C CNN
F 2 "" H 3550 7150 50  0001 C CNN
F 3 "" H 3550 7150 50  0001 C CNN
	1    3550 7150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR030
U 1 1 61C64D3F
P 3550 6850
F 0 "#PWR030" H 3550 6700 50  0001 C CNN
F 1 "+3.3V" H 3565 7023 50  0000 C CNN
F 2 "" H 3550 6850 50  0001 C CNN
F 3 "" H 3550 6850 50  0001 C CNN
	1    3550 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 61C703B1
P 4050 7000
F 0 "C3" H 4165 7046 50  0000 L CNN
F 1 "0.1uF" H 4165 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 4088 6850 50  0001 C CNN
F 3 "~" H 4050 7000 50  0001 C CNN
F 4 " C24497" H 4050 7000 50  0001 C CNN "LCSC"
	1    4050 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR033
U 1 1 61C70A27
P 4050 7150
F 0 "#PWR033" H 4050 6900 50  0001 C CNN
F 1 "GND" H 4055 6977 50  0000 C CNN
F 2 "" H 4050 7150 50  0001 C CNN
F 3 "" H 4050 7150 50  0001 C CNN
	1    4050 7150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR032
U 1 1 61C70A31
P 4050 6850
F 0 "#PWR032" H 4050 6700 50  0001 C CNN
F 1 "+3.3V" H 4065 7023 50  0000 C CNN
F 2 "" H 4050 6850 50  0001 C CNN
F 3 "" H 4050 6850 50  0001 C CNN
	1    4050 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 61C7BDDB
P 4550 7000
F 0 "C4" H 4665 7046 50  0000 L CNN
F 1 "0.1uF" H 4665 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 4588 6850 50  0001 C CNN
F 3 "~" H 4550 7000 50  0001 C CNN
F 4 " C24497" H 4550 7000 50  0001 C CNN "LCSC"
	1    4550 7000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR035
U 1 1 61C7C481
P 4550 7150
F 0 "#PWR035" H 4550 6900 50  0001 C CNN
F 1 "GND" H 4555 6977 50  0000 C CNN
F 2 "" H 4550 7150 50  0001 C CNN
F 3 "" H 4550 7150 50  0001 C CNN
	1    4550 7150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR034
U 1 1 61C87915
P 4550 6850
F 0 "#PWR034" H 4550 6700 50  0001 C CNN
F 1 "+5V" H 4565 7023 50  0000 C CNN
F 2 "" H 4550 6850 50  0001 C CNN
F 3 "" H 4550 6850 50  0001 C CNN
	1    4550 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4400 4600 4400
$Comp
L power:+5V #PWR09
U 1 1 61A79327
P 4500 4300
F 0 "#PWR09" H 4500 4150 50  0001 C CNN
F 1 "+5V" H 4515 4473 50  0000 C CNN
F 2 "" H 4500 4300 50  0001 C CNN
F 3 "" H 4500 4300 50  0001 C CNN
	1    4500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4750 4900 4650
Wire Wire Line
	4800 4750 4900 4750
$Comp
L 74xx:74LS125 U3
U 3 1 61A23D8E
P 4900 4400
F 0 "U3" H 4900 4717 50  0000 C CNN
F 1 "74HCT125" H 4900 4626 50  0000 C CNN
F 2 "" H 4900 4400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 4900 4400 50  0001 C CNN
	3    4900 4400
	1    0    0    -1  
$EndComp
Text GLabel 5200 4400 2    50   Input ~ 0
DRQ
Text GLabel 4800 4750 0    39   Input ~ 0
~DRQ~_3V3
Wire Wire Line
	8500 3750 8500 3650
Connection ~ 8500 3650
Wire Notes Line
	550  550  550  3600
Wire Notes Line
	550  3600 4700 3600
Wire Notes Line
	4700 3600 4700 550 
Wire Notes Line
	4700 550  550  550 
Text Notes 600  700  0    79   ~ 0
INTERFACE CONNECTORS
Wire Notes Line
	11100 6450 7550 6450
Wire Notes Line
	11100 3150 11100 6450
Wire Notes Line
	550  3700 7450 3700
Wire Notes Line
	7450 3700 7450 6100
Wire Notes Line
	7450 6100 550  6100
Wire Notes Line
	550  6100 550  3700
Text Notes 600  3850 0    79   ~ 0
5V / 3.3V CONVERSION
NoConn ~ 1050 6950
Wire Wire Line
	1050 7250 1300 7250
Wire Wire Line
	1150 7150 1150 7350
Connection ~ 1150 7150
Wire Wire Line
	1050 7150 1150 7150
Wire Wire Line
	1150 7050 1150 7150
Wire Wire Line
	1050 7050 1150 7050
$Comp
L power:GND #PWR05
U 1 1 61833F15
P 1150 7350
F 0 "#PWR05" H 1150 7100 50  0001 C CNN
F 1 "GND" H 1155 7177 50  0000 C CNN
F 2 "" H 1150 7350 50  0001 C CNN
F 3 "" H 1150 7350 50  0001 C CNN
	1    1150 7350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS125 U3
U 5 1 61A25588
P 6150 6950
F 0 "U3" H 6380 6996 50  0000 L CNN
F 1 "74HCT125" H 6380 6905 50  0000 L CNN
F 2 "" H 6150 6950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS125" H 6150 6950 50  0001 C CNN
	5    6150 6950
	1    0    0    -1  
$EndComp
Connection ~ 2000 7250
Wire Wire Line
	2100 7250 2000 7250
Text GLabel 2100 7250 2    50   Input ~ 0
VSYS
Wire Wire Line
	1850 7250 2000 7250
Text GLabel 1400 6750 2    50   Input ~ 0
IBM_5V_POWER
Wire Wire Line
	2000 7250 2000 7150
$Comp
L Device:D_Schottky D1
U 1 1 616FE730
P 1700 7250
F 0 "D1" H 1750 7350 50  0000 R CNN
F 1 "MBR120/130" H 1950 7150 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-123" H 1700 7250 50  0001 C CNN
F 3 "~" H 1700 7250 50  0001 C CNN
	1    1700 7250
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 616FC25E
P 2000 7150
F 0 "#PWR011" H 2000 7000 50  0001 C CNN
F 1 "+5V" H 2015 7323 50  0000 C CNN
F 2 "" H 2000 7150 50  0001 C CNN
F 3 "" H 2000 7150 50  0001 C CNN
	1    2000 7150
	1    0    0    -1  
$EndComp
Wire Notes Line
	6900 6200 6900 7700
Wire Notes Line
	6900 7700 550  7700
Wire Notes Line
	550  7700 550  6200
Wire Notes Line
	550  6200 6900 6200
Text Notes 600  6350 0    79   ~ 0
POWER
Text Notes 4850 700  0    79   ~ 0
CONFIGURATION
Wire Notes Line
	4800 550  11100 550 
Wire Notes Line
	11100 550  11100 3050
Wire Notes Line
	11100 3050 4800 3050
Wire Notes Line
	4800 3050 4800 550 
Text Notes 7000 3450 0    79   ~ 0
RASPBERRY\nPI PICO
Wire Notes Line
	11100 3150 6950 3150
Wire Notes Line
	6950 3150 6950 3600
Wire Notes Line
	6950 3600 7550 3600
Wire Notes Line
	7550 3600 7550 6450
Text GLabel 9300 2150 0    50   Input ~ 0
CFG_LATCH
Wire Wire Line
	1400 6750 1300 6750
Wire Wire Line
	1300 6750 1300 7250
Connection ~ 1300 7250
Wire Wire Line
	1300 7250 1550 7250
Wire Wire Line
	9900 5350 9700 5350
Text GLabel 9900 5350 2    50   Input ~ 0
SD0_CS
Text Notes 7000 6700 0    39   ~ 0
The PICO already has a 47uF cap on both the 5v and 3.3v\nside of the regulator, so none is included in this design.
Text GLabel 9900 4150 2    50   Input ~ 0
CFG_DATA
Text GLabel 8400 3450 0    50   Input ~ 0
DBG_RX
Text GLabel 8400 3550 0    50   Input ~ 0
DBG_TX
Wire Wire Line
	8400 3650 8500 3650
Text GLabel 8400 3750 0    39   Input ~ 0
~DRIVE_ACTIVE~_3V3
Wire Wire Line
	8400 3750 8500 3750
Text GLabel 8400 3650 0    50   Input ~ 0
CFG_CLK
Wire Wire Line
	8500 3650 8700 3650
Wire Wire Line
	9900 4150 9700 4150
Wire Wire Line
	8400 3550 8500 3550
Wire Wire Line
	8500 3550 8500 3650
Wire Wire Line
	8400 3450 8600 3450
Wire Wire Line
	8600 3450 8600 3550
Wire Wire Line
	8600 3550 8700 3550
$Comp
L Switch:SW_Push SW2
U 1 1 619AC049
P 8150 2350
F 0 "SW2" H 8150 2500 50  0000 C CNN
F 1 "Boot Internal" H 8150 2250 50  0000 C CNN
F 2 "" H 8150 2550 50  0001 C CNN
F 3 "~" H 8150 2550 50  0001 C CNN
	1    8150 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	9500 1850 9400 1850
Connection ~ 9400 1850
Wire Wire Line
	9400 1850 9400 1950
Wire Wire Line
	9500 1950 9400 1950
Connection ~ 9400 1950
Wire Wire Line
	9400 1950 9400 2450
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 618296A7
P 850 7050
F 0 "J3" H 768 7367 50  0000 C CNN
F 1 "XTA Power" H 768 7276 50  0000 C CNN
F 2 "w_conn_pc:conn_hdd_15-24-4441" H 850 7050 50  0001 C CNN
F 3 "~" H 850 7050 50  0001 C CNN
	1    850  7050
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
