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
P 4500 4300
F 0 "#PWR0101" H 4500 4050 50  0001 C CNN
F 1 "GND" H 4505 4127 50  0000 C CNN
F 2 "" H 4500 4300 50  0001 C CNN
F 3 "" H 4500 4300 50  0001 C CNN
	1    4500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4100 2750 4000
Wire Wire Line
	2750 2100 2650 2100
Wire Wire Line
	2650 2200 2750 2200
Connection ~ 2750 2200
Wire Wire Line
	2750 2200 2750 2100
Wire Wire Line
	2650 2300 2750 2300
Connection ~ 2750 2300
Wire Wire Line
	2750 2300 2750 2200
Wire Wire Line
	2650 2400 2750 2400
Connection ~ 2750 2400
Wire Wire Line
	2750 2400 2750 2300
Wire Wire Line
	2650 2500 2750 2500
Connection ~ 2750 2500
Wire Wire Line
	2750 2500 2750 2400
Wire Wire Line
	2650 2600 2750 2600
Connection ~ 2750 2600
Wire Wire Line
	2750 2600 2750 2500
Wire Wire Line
	2650 2700 2750 2700
Connection ~ 2750 2700
Wire Wire Line
	2750 2700 2750 2600
Wire Wire Line
	2650 2800 2750 2800
Connection ~ 2750 2800
Wire Wire Line
	2750 2800 2750 2700
Wire Wire Line
	2650 2900 2750 2900
Connection ~ 2750 2900
Wire Wire Line
	2750 2900 2750 2800
Wire Wire Line
	2650 3100 2750 3100
Connection ~ 2750 3100
Wire Wire Line
	2750 3100 2750 2900
Wire Wire Line
	2650 3200 2750 3200
Connection ~ 2750 3200
Wire Wire Line
	2750 3200 2750 3100
Wire Wire Line
	2650 3300 2750 3300
Connection ~ 2750 3300
Wire Wire Line
	2750 3300 2750 3200
Wire Wire Line
	2650 4000 2750 4000
Connection ~ 2750 4000
Wire Wire Line
	2750 4000 2750 3900
Wire Wire Line
	2650 3900 2750 3900
Connection ~ 2750 3900
Wire Wire Line
	2750 3900 2750 3800
Wire Wire Line
	2650 3800 2750 3800
Connection ~ 2750 3800
Wire Wire Line
	2650 3600 2750 3600
Connection ~ 2750 3600
Wire Wire Line
	2750 3600 2750 3500
Wire Wire Line
	2650 3500 2750 3500
Connection ~ 2750 3500
Wire Wire Line
	2750 3500 2750 3400
Wire Wire Line
	2650 3400 2750 3400
Connection ~ 2750 3400
Wire Wire Line
	2750 3400 2750 3300
Text GLabel 1850 3900 0    39   Input ~ 0
~CS
Text GLabel 1850 4000 0    39   Input ~ 0
~DRIVE_ACTIVE
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
L power:GND #PWR0102
U 1 1 613B07D2
P 1350 4100
F 0 "#PWR0102" H 1350 3850 50  0001 C CNN
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
L 00Custom:XTA_Connector J1
U 1 1 616B1E7B
P 2250 3000
F 0 "J1" H 2250 4165 50  0000 C CNN
F 1 "XTA_Connector" H 2250 4074 50  0000 C CNN
F 2 "" H 2250 4050 50  0001 C CNN
F 3 "" H 2250 4050 50  0001 C CNN
	1    2250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3600 2750 3800
NoConn ~ 2650 3700
$Comp
L 00Custom:IBM_8bit_DBA J2
U 1 1 616BC629
P 3900 3000
F 0 "J2" H 3900 4165 50  0000 C CNN
F 1 "IBM_8bit_DBA" H 3900 4074 50  0000 C CNN
F 2 "" H 3900 4050 50  0001 C CNN
F 3 "" H 3900 4050 50  0001 C CNN
	1    3900 3000
	1    0    0    -1  
$EndComp
Text GLabel 3400 2100 0    39   Input ~ 0
~RESET
Text GLabel 3400 2900 0    50   Input ~ 0
D7
Text GLabel 3400 2800 0    50   Input ~ 0
D6
Text GLabel 3400 2700 0    50   Input ~ 0
D5
Text GLabel 3400 2600 0    50   Input ~ 0
D4
Text GLabel 3400 2500 0    50   Input ~ 0
D3
Text GLabel 3400 2300 0    50   Input ~ 0
D1
Text GLabel 3400 2200 0    50   Input ~ 0
D0
Text GLabel 3400 2400 0    50   Input ~ 0
D2
Text GLabel 3400 3000 0    39   Input ~ 0
~IOR
Text GLabel 3400 3100 0    39   Input ~ 0
~IOW
Text GLabel 3400 3200 0    39   Input ~ 0
~CS
NoConn ~ 3400 3300
Text GLabel 3400 3400 0    50   Input ~ 0
A0
Text GLabel 3400 3500 0    50   Input ~ 0
A1
NoConn ~ 3400 3600
NoConn ~ 3400 4100
NoConn ~ 3400 4200
NoConn ~ 4400 4000
NoConn ~ 4400 4100
Text GLabel 3400 3700 0    39   Input ~ 0
~DACK
Text GLabel 3400 3800 0    50   Input ~ 0
DRQ
Text GLabel 3400 3900 0    50   Input ~ 0
IRQ
NoConn ~ 3400 4000
$Comp
L power:GND #PWR01
U 1 1 616C3ED0
P 2750 4100
F 0 "#PWR01" H 2750 3850 50  0001 C CNN
F 1 "GND" H 2755 3927 50  0000 C CNN
F 2 "" H 2750 4100 50  0001 C CNN
F 3 "" H 2750 4100 50  0001 C CNN
	1    2750 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2200 4500 2200
Wire Wire Line
	4500 2200 4500 2300
Wire Wire Line
	4400 2300 4500 2300
Connection ~ 4500 2300
Wire Wire Line
	4500 2300 4500 2400
Wire Wire Line
	4400 2400 4500 2400
Connection ~ 4500 2400
Wire Wire Line
	4500 2400 4500 2500
Wire Wire Line
	4500 2500 4400 2500
Connection ~ 4500 2500
Wire Wire Line
	4500 2500 4500 2600
Wire Wire Line
	4400 2600 4500 2600
Connection ~ 4500 2600
Wire Wire Line
	4500 2600 4500 2700
Wire Wire Line
	4400 2700 4500 2700
Connection ~ 4500 2700
Wire Wire Line
	4500 2700 4500 2800
Wire Wire Line
	4400 2800 4500 2800
Connection ~ 4500 2800
Wire Wire Line
	4500 2800 4500 2900
Wire Wire Line
	4400 2900 4500 2900
Connection ~ 4500 2900
Wire Wire Line
	4500 2900 4500 3000
Wire Wire Line
	4400 3000 4500 3000
Connection ~ 4500 3000
Wire Wire Line
	4500 3000 4500 3100
Wire Wire Line
	4400 3100 4500 3100
Connection ~ 4500 3100
Wire Wire Line
	4500 3100 4500 3200
Wire Wire Line
	4400 3200 4500 3200
Connection ~ 4500 3200
Wire Wire Line
	4400 3300 4500 3300
Wire Wire Line
	4500 3200 4500 3300
Connection ~ 4500 3300
Wire Wire Line
	4500 3300 4500 3400
Wire Wire Line
	4400 3400 4500 3400
Connection ~ 4500 3400
Wire Wire Line
	4500 3400 4500 3700
Wire Wire Line
	4400 3700 4500 3700
Connection ~ 4500 3700
Wire Wire Line
	4500 3700 4500 3800
Wire Wire Line
	4400 3800 4500 3800
Connection ~ 4500 3800
Wire Wire Line
	4500 3800 4500 3900
Wire Wire Line
	4400 3900 4500 3900
Connection ~ 4500 3900
Wire Wire Line
	4500 3900 4500 4300
$Comp
L power:+5V #PWR02
U 1 1 616CFEF6
P 4600 2000
F 0 "#PWR02" H 4600 1850 50  0001 C CNN
F 1 "+5V" H 4615 2173 50  0000 C CNN
F 2 "" H 4600 2000 50  0001 C CNN
F 3 "" H 4600 2000 50  0001 C CNN
	1    4600 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2000 4600 3500
Wire Wire Line
	4600 3500 4400 3500
Wire Wire Line
	4400 3600 4600 3600
Wire Wire Line
	4600 3600 4600 3500
Connection ~ 4600 3500
Wire Wire Line
	4400 4200 4600 4200
Text GLabel 4600 4200 2    50   Input ~ 0
12V_SENSE
Connection ~ 4500 2200
Wire Wire Line
	4500 2100 4500 2200
Wire Wire Line
	4400 2100 4500 2100
$EndSCHEMATC
