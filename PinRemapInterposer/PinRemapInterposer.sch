EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
L 00Custom:RPI_PICO U5
U 1 1 616E2BFC
P 6400 4500
F 0 "U5" H 6400 5665 50  0000 C CNN
F 1 "Raspberry Pi Pico" H 6400 5574 50  0000 C CNN
F 2 "Pico:RPi_Pico_SMD_TH" H 6400 5500 50  0001 C CNN
F 3 "" H 6400 5500 50  0001 C CNN
	1    6400 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 616E500E
P 8800 5800
F 0 "#PWR017" H 8800 5550 50  0001 C CNN
F 1 "GND" H 8805 5627 50  0000 C CNN
F 2 "" H 8800 5800 50  0001 C CNN
F 3 "" H 8800 5800 50  0001 C CNN
	1    8800 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 616E680C
P 7000 5600
F 0 "#PWR019" H 7000 5350 50  0001 C CNN
F 1 "GND" H 7005 5427 50  0000 C CNN
F 2 "" H 7000 5600 50  0001 C CNN
F 3 "" H 7000 5600 50  0001 C CNN
	1    7000 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 5600 5800 5300
Wire Wire Line
	5800 3800 5900 3800
Wire Wire Line
	5900 4300 5800 4300
Connection ~ 5800 4300
Wire Wire Line
	5800 4300 5800 3800
Wire Wire Line
	5900 4800 5800 4800
Connection ~ 5800 4800
Wire Wire Line
	5800 4800 5800 4300
Wire Wire Line
	5900 5300 5800 5300
Connection ~ 5800 5300
Wire Wire Line
	5800 5300 5800 4800
Wire Wire Line
	7000 5600 7000 5300
Wire Wire Line
	7000 3800 6900 3800
Wire Wire Line
	6900 5300 7000 5300
Connection ~ 7000 5300
Wire Wire Line
	7000 5300 7000 4800
Wire Wire Line
	6900 4800 7000 4800
Connection ~ 7000 4800
Wire Wire Line
	7000 4800 7000 4300
Wire Wire Line
	6900 4300 7000 4300
Connection ~ 7000 4300
Wire Wire Line
	7000 4300 7000 3800
$Comp
L power:+3.3V #PWR020
U 1 1 616F5B8D
P 7100 3500
F 0 "#PWR020" H 7100 3350 50  0001 C CNN
F 1 "+3.3V" H 7115 3673 50  0000 C CNN
F 2 "" H 7100 3500 50  0001 C CNN
F 3 "" H 7100 3500 50  0001 C CNN
	1    7100 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4000 7100 4000
Wire Wire Line
	7100 4000 7100 3500
Text GLabel 5700 4600 0    50   Input ~ 0
D0_3V3
Text GLabel 5700 4700 0    50   Input ~ 0
D1_3V3
Text GLabel 5700 4900 0    50   Input ~ 0
D2_3V3
Text GLabel 5700 5000 0    50   Input ~ 0
D3_3V3
Wire Wire Line
	5700 4000 5900 4000
Text GLabel 5700 5100 0    50   Input ~ 0
D4_3V3
Wire Wire Line
	5700 4100 5900 4100
Text GLabel 5700 5200 0    50   Input ~ 0
D5_3V3
Wire Wire Line
	5700 4200 5900 4200
Text GLabel 5700 5400 0    50   Input ~ 0
D6_3V3
Wire Wire Line
	5700 4400 5900 4400
Text GLabel 5700 5500 0    50   Input ~ 0
D7_3V3
Text GLabel 7100 4900 2    50   Input ~ 0
A0_3V3
Wire Wire Line
	5700 4600 5900 4600
Text GLabel 7100 4700 2    50   Input ~ 0
A1_3V3
Wire Wire Line
	5700 4700 5900 4700
Wire Wire Line
	5700 4900 5900 4900
Text GLabel 7100 5000 2    50   Input ~ 0
AEN_3V3
Text GLabel 7100 5500 2    39   Input ~ 0
~DACK~_3V3
Text GLabel 7100 4500 2    39   Input ~ 0
~DRQ~_3V3
Text GLabel 7100 4400 2    39   Input ~ 0
~IRQ~_3V3
Text GLabel 7100 5400 2    39   Input ~ 0
~IOR~_3V3
Text GLabel 7100 5200 2    39   Input ~ 0
~IOW~_3V3
Text GLabel 7100 4200 2    39   Input ~ 0
~RESET~_3V3
Wire Wire Line
	5700 5000 5900 5000
Wire Wire Line
	5900 5100 5700 5100
Wire Wire Line
	5700 5200 5900 5200
Wire Wire Line
	7100 5200 6900 5200
Wire Wire Line
	5700 5500 5900 5500
Wire Wire Line
	5900 5400 5700 5400
Text GLabel 7100 5100 2    39   Input ~ 0
~CS~_3V3
Wire Wire Line
	7100 5500 6900 5500
Text GLabel 5150 4500 0    50   Input ~ 0
DATA_DIR
Wire Wire Line
	7100 5100 6900 5100
Text GLabel 7750 3700 2    50   Input ~ 0
VSYS
Wire Wire Line
	7750 3700 7650 3700
Text GLabel 5700 4000 0    50   Input ~ 0
SPI_TX
Wire Wire Line
	7100 5000 6900 5000
Wire Wire Line
	7100 4900 6900 4900
Wire Wire Line
	7100 4500 6900 4500
Wire Wire Line
	7100 4400 6900 4400
Wire Wire Line
	7100 4700 6900 4700
Wire Notes Line
	8300 6500 4750 6500
Wire Notes Line
	8300 3200 8300 6500
Text Notes 4200 3500 0    79   ~ 0
RASPBERRY\nPI PICO
Wire Notes Line
	8300 3200 4150 3200
Wire Notes Line
	4150 3200 4150 3650
Wire Notes Line
	4150 3650 4750 3650
Wire Notes Line
	4750 3650 4750 6500
Text GLabel 5700 4100 0    50   Input ~ 0
SD1_CS
Wire Wire Line
	6900 4200 7100 4200
Wire Wire Line
	6900 5400 7100 5400
$Comp
L Connector_Generic:Conn_02x20_Counter_Clockwise J1
U 1 1 617F5D95
P 9900 4650
F 0 "J1" H 9950 5767 50  0000 C CNN
F 1 "Header" H 9950 5676 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm_Socket" H 9900 4650 50  0001 C CNN
F 3 "~" H 9900 4650 50  0001 C CNN
	1    9900 4650
	1    0    0    -1  
$EndComp
Text GLabel 9700 3750 0    50   Input ~ 0
CFG_DATA
Text GLabel 9700 3850 0    39   Input ~ 0
~DRIVE_ACTIVE~_3V3
Text GLabel 9700 4050 0    50   Input ~ 0
SD0_CS
Wire Wire Line
	9700 3950 8800 3950
Wire Wire Line
	8800 3950 8800 4450
Wire Wire Line
	9700 4450 8800 4450
Connection ~ 8800 4450
Wire Wire Line
	8800 4450 8800 4950
Wire Wire Line
	9700 4950 8800 4950
Connection ~ 8800 4950
Wire Wire Line
	9700 5450 8800 5450
Wire Wire Line
	8800 4950 8800 5450
Connection ~ 8800 5450
Wire Wire Line
	8800 5450 8800 5800
$Comp
L power:GND #PWR06
U 1 1 6184698D
P 11100 5800
F 0 "#PWR06" H 11100 5550 50  0001 C CNN
F 1 "GND" H 11105 5627 50  0000 C CNN
F 2 "" H 11100 5800 50  0001 C CNN
F 3 "" H 11100 5800 50  0001 C CNN
	1    11100 5800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 3950 11100 3950
Wire Wire Line
	11100 3950 11100 4450
Wire Wire Line
	10200 4450 11100 4450
Connection ~ 11100 4450
Wire Wire Line
	11100 4450 11100 4950
Wire Wire Line
	10200 4950 11100 4950
Connection ~ 11100 4950
Wire Wire Line
	10200 5450 11100 5450
Wire Wire Line
	11100 4950 11100 5450
Connection ~ 11100 5450
Wire Wire Line
	11100 5450 11100 5800
Text GLabel 10200 3850 2    50   Input ~ 0
VSYS
Text GLabel 10200 4350 2    39   Input ~ 0
~DRQ~_3V3
Text GLabel 10200 4550 2    39   Input ~ 0
~IRQ~_3V3
Text GLabel 10200 4650 2    39   Input ~ 0
~CS~_3V3
Text GLabel 10200 4850 2    50   Input ~ 0
DATA_DIR
Text GLabel 10200 5150 2    39   Input ~ 0
~IOR~_3V3
Text GLabel 10200 5550 2    39   Input ~ 0
~IOW~_3V3
Text GLabel 10200 5050 2    39   Input ~ 0
~RESET~_3V3
Text GLabel 10200 5650 2    50   Input ~ 0
SPI_RX
Text GLabel 10200 5250 2    50   Input ~ 0
SPI_TX
Text GLabel 10200 5350 2    50   Input ~ 0
SPI_SCK
Text GLabel 9700 4250 0    50   Input ~ 0
D0_3V3
Text GLabel 9700 4350 0    50   Input ~ 0
D1_3V3
Text GLabel 9700 4550 0    50   Input ~ 0
D2_3V3
Text GLabel 9700 4650 0    50   Input ~ 0
D3_3V3
Text GLabel 9700 4750 0    50   Input ~ 0
D4_3V3
Text GLabel 9700 4850 0    50   Input ~ 0
D5_3V3
Text GLabel 9700 5050 0    50   Input ~ 0
D6_3V3
Text GLabel 9700 5150 0    50   Input ~ 0
D7_3V3
Text GLabel 9700 5250 0    50   Input ~ 0
A0_3V3
Text GLabel 9700 5350 0    50   Input ~ 0
A1_3V3
Text GLabel 9700 5550 0    50   Input ~ 0
AEN_3V3
Text GLabel 9700 5650 0    39   Input ~ 0
~DACK~_3V3
Text GLabel 9700 4150 0    50   Input ~ 0
SD1_CS
Text GLabel 10200 4250 2    50   Input ~ 0
ADC_VREF
Text GLabel 10200 3750 2    50   Input ~ 0
VBUS
$Comp
L power:GND #PWR02
U 1 1 618794A7
P 5800 5600
F 0 "#PWR02" H 5800 5350 50  0001 C CNN
F 1 "GND" H 5805 5427 50  0000 C CNN
F 2 "" H 5800 5600 50  0001 C CNN
F 3 "" H 5800 5600 50  0001 C CNN
	1    5800 5600
	1    0    0    -1  
$EndComp
Text GLabel 7200 3600 2    50   Input ~ 0
VBUS
Wire Wire Line
	6900 3600 7200 3600
Text GLabel 10200 4050 2    50   Input ~ 0
3V3_EN
Wire Wire Line
	10200 4150 10650 4150
Wire Wire Line
	10650 4150 10650 3750
$Comp
L power:+3.3V #PWR05
U 1 1 6189FEDB
P 10650 3750
F 0 "#PWR05" H 10650 3600 50  0001 C CNN
F 1 "+3.3V" H 10665 3923 50  0000 C CNN
F 2 "" H 10650 3750 50  0001 C CNN
F 3 "" H 10650 3750 50  0001 C CNN
	1    10650 3750
	1    0    0    -1  
$EndComp
Text GLabel 10200 4750 2    50   Input ~ 0
RUN
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 618A1B3C
P 9950 5900
F 0 "J2" V 9914 5712 50  0000 R CNN
F 1 "Conn_01x03" V 9823 5712 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 9950 5900 50  0001 C CNN
F 3 "~" H 9950 5900 50  0001 C CNN
	1    9950 5900
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 618A3033
P 9950 6100
F 0 "#PWR04" H 9950 5850 50  0001 C CNN
F 1 "GND" V 9950 5900 50  0000 C CNN
F 2 "" H 9950 6100 50  0001 C CNN
F 3 "" H 9950 6100 50  0001 C CNN
	1    9950 6100
	-1   0    0    -1  
$EndComp
Text GLabel 10050 6100 3    50   Input ~ 0
SWDIO
Text GLabel 9850 6100 3    50   Input ~ 0
SWCLK
$Comp
L power:GND #PWR03
U 1 1 618C70A5
P 6400 5700
F 0 "#PWR03" H 6400 5450 50  0001 C CNN
F 1 "GND" V 6400 5500 50  0000 C CNN
F 2 "" H 6400 5700 50  0001 C CNN
F 3 "" H 6400 5700 50  0001 C CNN
	1    6400 5700
	-1   0    0    -1  
$EndComp
Text GLabel 6500 5700 3    50   Input ~ 0
SWDIO
Text GLabel 6300 5700 3    50   Input ~ 0
SWCLK
Text GLabel 7200 3900 2    50   Input ~ 0
3V3_EN
Text GLabel 7200 4100 2    50   Input ~ 0
ADC_VREF
Wire Wire Line
	7200 3900 6900 3900
Wire Wire Line
	6900 4100 7200 4100
Text GLabel 5700 3600 0    50   Input ~ 0
SPI_RX
Text GLabel 5700 3700 0    50   Input ~ 0
SD0_CS
Text GLabel 5700 3900 0    50   Input ~ 0
SPI_SCK
Wire Wire Line
	5700 3600 5900 3600
Wire Wire Line
	5900 3700 5700 3700
Wire Wire Line
	5700 3900 5900 3900
Text GLabel 5700 4200 0    39   Input ~ 0
~DRIVE_ACTIVE~_3V3
Text GLabel 5700 4400 0    50   Input ~ 0
CFG_DATA
$Comp
L Device:R R1
U 1 1 61942954
P 5200 4750
F 0 "R1" V 5150 4550 50  0000 C CNN
F 1 "10K" V 5200 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5130 4750 50  0001 C CNN
F 3 "~" H 5200 4750 50  0001 C CNN
F 4 "C17902" V 5200 4750 50  0001 C CNN "LCSC"
	1    5200 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 61943325
P 5200 5600
F 0 "#PWR01" H 5200 5350 50  0001 C CNN
F 1 "GND" H 5205 5427 50  0000 C CNN
F 2 "" H 5200 5600 50  0001 C CNN
F 3 "" H 5200 5600 50  0001 C CNN
	1    5200 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4500 5200 4500
Wire Wire Line
	5200 4600 5200 4500
Connection ~ 5200 4500
Wire Wire Line
	5200 4500 5900 4500
Wire Wire Line
	5200 4900 5200 5600
Text GLabel 7100 4600 2    50   Input ~ 0
RUN
Wire Wire Line
	6900 4600 7100 4600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 619BCDBA
P 7650 3700
F 0 "#FLG0101" H 7650 3775 50  0001 C CNN
F 1 "PWR_FLAG" H 7650 3873 50  0000 C CNN
F 2 "" H 7650 3700 50  0001 C CNN
F 3 "~" H 7650 3700 50  0001 C CNN
	1    7650 3700
	1    0    0    -1  
$EndComp
Connection ~ 7650 3700
Wire Wire Line
	7650 3700 6900 3700
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 619BD3E3
P 8800 3950
F 0 "#FLG0102" H 8800 4025 50  0001 C CNN
F 1 "PWR_FLAG" H 8800 4123 50  0000 C CNN
F 2 "" H 8800 3950 50  0001 C CNN
F 3 "~" H 8800 3950 50  0001 C CNN
	1    8800 3950
	1    0    0    -1  
$EndComp
Connection ~ 8800 3950
$EndSCHEMATC
