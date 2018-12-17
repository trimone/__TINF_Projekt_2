#ifndef F_CPU
#warning "F_CPU war noch nicht definiert, wird nun mit 14.7456MHz definiert"
#define F_CPU 14745600UL     /* ext Quarz mit 14.7456MHz */
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 
#include <math.h>				//sonst ist M_PI als "nichtdeklarierter Bezeichner" ausgewiesen!
#include <string.h>				// für String Funktionen

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <avr/eeprom.h>
//#include <avr/wdt.h>

#define max_string 30			// reservierter Speicher für den laengsten USART string 
#define temp_UBRR 7				// baud rate 115.2k

char command[max_string], recieved[max_string];	// per USART empfangene Zeichenfolge bzw. Puffer
volatile uint8_t UART_flag, r_pos = 0, status;			// Anzahl der Zeichen im Speicher
uint8_t Imax = 0;			// maximaler Ausgangsstrom in AMPERE (EEPROM), falls Imax < 1A muss das Programm geaendert werden!!

// 'volatile'
/*
In C und C++ spezifiziert dieser Typqualifikator, dass sich der Wert der Variable jederzeit ändern kann,
beispielsweise durch andere Prozesse, Threads oder externe Hardware.
Bei der Generierung des Maschinen-Codes aus einem in C oder C++ geschriebenen Programm verhindert die Kennzeichnung
einer Variablen als volatile eine in diesem Fall die Funktionalität beeinträchtigende Optimierung, so dass das Programm
immer auf den tatsächlich in der Hardware vorhandenen Wert zugreift.

==> Eine Variable wird nicht wegoptimiert !!!
*/

typedef struct {
	unsigned bipol : 1;
	unsigned POWER : 1;
	unsigned ERROR : 1;
}flag_t;
#define flag (*(volatile flag_t *)&GPIOR0)

#define DDR_SPI   DDRB
#define PORT_SPI  PORTB
#define SPI_MOSI  PB3		// Serial Data in
#define SPI_SCK   PB5		// Serial Clock
#define SPI_LE    PB2		// SPI Bus Master Slave select

#define PORT_LED  PORTC
#define LEDr      PC2
#define LEDg      PC3
#define PORT_PW   PORTC
#define PIN_PW    PINC
#define PWpos     PC4 // PCINT12
#define PWneg     PC5 // PCINT13

volatile uint16_t DAC; // DAC Register-Wert

#define EE_SN     0		//  0.. 7 Adresse der SN im EEPROM: identisch zu HF Seriennummer (6 Stellen)
#define EE_CFG    10	// 10..10 Flags:
#define CFG_bipol 0		//        BCS oder UCS?
#define EE_U      11	// 11..11 Spannnung 
#define EE_I      12	// 12..13 Strom

char dd[3], mm[3] = "00", yy[5];
#define IDN  "HighFinesse "	// ID String 
#define Vers "1"
#define NUL  0x00  // 00 '\0'
#define AK   0x06  // 06
#define NAK  0x15  // 21
#define LF	 0x0A  // 10 '\n'
#define CR	 0x0D  // 13 '\r'
#define ETX	 0x03

// *********************************************************************
// UART senden
void UART_char(char c)
{
	//while (!(UCSR0A & (1<<UDRE0))) {}		// warten bis Sendepuffer frei ist.	
	UDR0 = c;								// naechstes Zeichen in den Sendepuffer schreiben
}

// *********************************************************************
void UART_str(char *s)
{
	while (*s) // Wdh. bis StringENDEzeichen ('\0') erreicht 
	{
		UART_char(*s);
		s++;
	}
}

// *********************************************************************
// SPI senden
void SPI_char(char c)
{
	SPDR = c;								// naechstes Zeichen in den Sendepuffer schreiben
	while (!(SPSR & (1 << SPIF)));				// warten bis Sendepuffer frei ist.
}

// *********************************************************************
// DAC Wert konvertieren
unsigned int atou16(char *str)
{
	uint16_t val = 0;
	while (*str) // Wdh. bis StringENDEzeichen ('\0') erreicht 
	{
		val = 10 * val + (*str - 0x30);
		str++;
	}
	return val;
}

// *********************************************************************
// DAC Wert schreiben
void DAC_write(uint16_t val)
{
	// Sync Pin high (!invertierte logik!)
	PORT_SPI |= (1 << SPI_LE);

	SPI_char(~0x00); // (!invertierte logik!)
	SPI_char(((val) >> 8)); // nachgeschalter OpAmp invertiert nochmals!
	SPI_char((val & 0x00FF)); // nachgeschalter OpAmp invertiert nochmals!
	PORT_SPI &= ~(1 << SPI_LE);	// Sync Pin low (!invertierte logik!)
}

// *********************************************************************
//__DATE__ & __TIME__
//uint8_t HH,MM,SS;
void DATE(void)
{
	// Tag
	strlcpy(dd, __DATE__ + 4, 3);
	if (dd[0] == ' ') { dd[0] = '0'; }

	// Monat
	switch (__DATE__[0])
	{
	case 'J': // Jan Jun Jul
		if (__DATE__[1] == 'a') { mm[1] = '1'; }
		else
			if (__DATE__[2] == 'n') { mm[1] = '6'; }
			else { mm[1] = '7'; }
		break;
	case 'F': // Feb
		mm[1] = '2';
		break;
	case 'M': // Mar May
		if (__DATE__[2] == 'r') { mm[1] = '3'; }
		else { mm[1] = '4'; }
		break;
	case 'A': // Apr Aug
		if (__DATE__[2] == 'r') { mm[1] = '5'; }
		else { mm[1] = '8'; }
		break;
	case 'S': // Sep
		mm[1] = '9';
		break;
	case 'O': // Oct
		mm[0] = '1';
		mm[1] = '0';
		break;
	case 'N': // Nov
		mm[0] = '1';
		mm[1] = '1';
		break;
	case 'D': // Dez
		mm[0] = '1';
		mm[1] = '2';
		break;
	default:
		mm[0] = '-';
		mm[1] = '-';
		break;
	} // ENDE switch

	// Jahr
	strlcpy(yy, __DATE__ + 7, 5);
}
// *********************************************************************

void watchdog_reset()
{
	asm volatile ("wdr");
}

// *********************************************************************
// Standard Werte setzen
void load_defaults(void)
{
	// Werte aus EEPROM laden
	Imax = eeprom_read_byte((uint8_t*)EE_I);
	flag.bipol = (eeprom_read_byte((uint8_t*)EE_I) >> CFG_bipol) & 0x01;

	// DAC initialisieren: Ausgangsstrom Null!
	if (flag.bipol)
	{
		DAC_write(0x7FFF);
	}
	else {
		DAC_write(0);
	}

	// Compile Datum erzeugen
	DATE();
}


// *********************************************************************
// *********************************************************************
// MAIN
int main(void)
{
	// watchdog deaktivieren
	//wdt_disable(); aus <avr/wdt.h>

	//__disable_interrupt(); // noch nicht aktiv!
	watchdog_reset();
	/* Clear WDRF Flag in MCUSR */ //liefert "reset condition"!
	/*Bit 3 – WDE: Watchdog System Reset Enable
	WDE is overridden by WDRF in MCUSR. This means that WDE is always set when WDRF is set.
	To clear WDE, WDRF must be cleared first. This feature ensures multiple resets during conditions causing
	failure, and a safe startup after the failure.
	*/
	MCUSR &= ~(1 << WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */

	/*
	WDRF:?Watchdog System Reset Flag
	This bit is set if a Watchdog System Reset occurs. The bit is reset by a Power-on Reset, or by writing a '0'
	to it.
	*/

	WDTCSR |= (1 << WDCE) | (1 << WDE);
	/* Turn off WDT : TIMING !!*/
	WDTCSR = 0x00;	// Sinn???

	/*
	 If the Watchdog is accidentally enabled, for example by a runaway pointer or
	 brown-out condition, the device will be reset and the Watchdog Timer will stay enabled.
	 If the code is not set up to handle the Watchdog, this might lead to an eternal loop of timeout
	 resets. To avoid this situation, the application software should always clear the
	 Watchdog System Reset Flag (WDRF) and the WDE control bit in the initialization
	 routine, even if the Watchdog is not in use.
	*/

	// IO Ports initialisieren
	// IO Richtung
	DDRB = 0b00000110; // PB6+PB7 Quarz, PB2+PB3+PB4+PB5: SPI, PB1: TRG
	PORTB = 0b00000000; // ..pull-up
	DDRC = 0b00001100; // PC4+PC5: Optokoppler +-15V, PC2+PC3: Status LEDs
	PORTC = 0b00110000; // ..pull-up
	DDRD = 0b00000000; // UART (PD0+PD1)
	PORTD = 0b00000000; // ..pull-up

	// LEDs ausschalten
	PORT_LED |= (1 << LEDg) | (1 << LEDr); // AVR-LEDs(2) | Teiler? | Lock!

	// SPI 
	// IO Register
	DDR_SPI |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_LE);
	// enable MASTER SPI, clock = /16
	SPCR = (0 << SPIE) | (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (1 << SPR0);	// interrupt ; enable ; data order ; master/slave ; clock pol ; clock phase ; clock rate (2 bits)
	SPSR |= (1 << SPI2X); // double speed 2x

	// UART
	UBRR0 = temp_UBRR;

	UCSR0B |= (1 << RXCIE0) | (0 << TXCIE0) | (0 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0); // recieve/transmit/transmit buffer complete interrupt; receiver und transmitter aktivieren
	UCSR0C |= (0 << USBS0) | (0 << UCSZ02) | (1 << UCSZ01) | (1 << UCSZ00);            // frame format setzen: 8data, 1stop bit (8N1)

	// TIMER1 (8-bit): Systemueberwachung
	TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1);

	TCCR1A |= (0 << WGM11) | (0 << WGM10);
	TCCR1B |= (0 << WGM12) | (1 << CS12) | (0 << CS11) | (1 << CS10); // CLK div 1024

	//	OCR1A  = 0x3FFF; // bei 1/4
	OCR1A = 0x1FFF; // bei 1/8
	OCR1B = 0x7FFF; // bei 1/2
	// overflow=0xFF  bei 1/1

	// Ueberwachung der Betriebsspannungen
	PCICR |= (1 << PCIE1);
	PCMSK1 = (1 << PCINT12) | (1 << PCINT13);

	load_defaults();

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

	// Schreiben freigeben, TIMING beachten!! 
	WDTCSR |= (1 << WDCE) | (1 << WDE);
	// nun darf WDCE <nicht> gesetzt werden!
	WDTCSR = (0 << WDE) | (1 << WDIE) | (0 << WDP3) | (1 << WDP2) | (1 << WDP1) | (0 << WDP0); // watchdog interrupt enable => UART Timeout, Prescaler 0110b (ca. 1sec)
	/*	Bit 6 – WDIE: Watchdog Interrupt Enable
		Bits 2:0 – WDP[2:0]: Watchdog Timer Prescaler 2, 1, and 0 => 1s
	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	// power reduction
	PRR |= ((1<<PRTWI)|(1<<PRTIM2)|(0<<PRTIM1)|(1<<PRTIM0));
/*	Power Reduction Register; TWI = I²C; TIM = Timer
	'1' => Shut down ; '0' => Reset
*/
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

// Interrupts global aktivieren 
	sei();	// __enable_interrupt(); 

	while (1)
	{
		UART_flag = 1;
		// Kommando vom PC (UART) verarbeiten
		if (UART_flag > 0)
		{
			flag.ERROR = 0; // Fehler flag loeschen

		// SCPI Commands (common commands)
		// *IDN? -- Identifikation: Hersteller, Modell, Firmware "HF, µPlex, V07012012"
		// *RST  -- Reset
		// *CLS  -- Clear

// Identifikation: OK
			if (strncasecmp(command, "*IDN?", 5) == 0)	// 'strncasecmp' = Compare Strings without Case Sensitivity // return 0, wenn gleich
			{
				uint8_t tmpVal;
				uint32_t tmpSN;
				char tmpStr[10];

				// IDN String		
				UART_str(IDN);
				if (eeprom_read_byte((uint8_t*)EE_I)&(1 << CFG_bipol))
				{
					UART_char('B'); // Bipolar
				}
				else {
					UART_char('U'); // Unipolar
				}
				UART_char('C'); // Current
				UART_char('S'); // Source


				// Strom
				tmpVal = eeprom_read_byte((uint8_t*)EE_I);
				utoa(tmpVal, tmpStr, 10);
				UART_str(tmpStr);

				UART_char('/');

				// Spannung
				tmpVal = eeprom_read_byte((uint8_t*)EE_U);
				utoa(tmpVal, tmpStr, 10);
				UART_str(tmpStr);

				// S/N
				tmpSN = eeprom_read_dword((uint32_t*)EE_SN);
				ultoa(tmpSN, tmpStr, 10);
				UART_str(" S/N");
				// fuehrende Nullen ergaenzen
				if (tmpSN < 9) { UART_str("000000"); }
				else
					if (tmpSN < 99) { UART_str("00000"); }
					else
						if (tmpSN < 999) { UART_str("0000"); }
						else
							if (tmpSN < 9999) { UART_str("000"); }
							else
								if (tmpSN < 99999) { UART_str("00"); }
								else
									if (tmpSN < 999999) { UART_str("0"); }
				UART_str(tmpStr);

				// Datum
				UART_char('-');
				UART_str(yy);
				UART_str(mm);
				UART_str(dd);

				UART_char(CR);
			}
			else

				// Clear
				if (strncasecmp(command, "*CLS ", 4) == 0)
				{
					load_defaults();
					UART_char(AK);
					UART_char(CR);
				}
				else

					// Reset
					if (strncasecmp(command, "*RST ", 4) == 0)
					{
						PORT_LED &= ~((0 << LEDg) | (1 << LEDr)); // high side LEDs!
						PORT_LED |= ((1 << LEDg) | (0 << LEDr)); // => inverse Logik!
						_delay_ms(100);
						// watchdog ?? => zusätzliche "avr/wdt.h"
						watchdog_reset();
						// Schreiben freigeben, TIMING beachten!! 
						WDTCSR |= (1 << WDCE) | (1 << WDE);
						// nun darf WDCE <nicht> gesetzt werden!
						WDTCSR = (1 << WDE); // watchdog sytem reset enable
						// direkte Zuweisung setzt implizit: Prescaler WDP[3:0]= 0 0 0 0 => 16ms
					}
					else

						// Current
						if (strncasecmp(command, "CUR", 3) == 0)
						{
							switch (command[3])
							{
							case ' ':
							{
								int32_t I = 0;
								int8_t n = 0, dezi = 100, multi = 0, posneg = 1; // n=Anzahl der konvertierten Ziffern, dezi=Position des Dezimaltrennzeichens, mehrfache Dezimaltrennzeichen?
								int8_t err = 0;
								char* str = command + 4;

								//while((*str=='0')&(str[1]!=NUL)){str++;}; // führende Nullen uebergehen; Vorsicht, falls val=0!
								if (*str == '-') { posneg = -1; str++; }
								if (*str == '+') { posneg = 1; str++; }

								while (*str) // Wdh. bis StringENDEzeichen ('\0')
								{
									// ersten Block konvertieren: vor Dezimaltrennzeichen bzw. Zehnerpotenz
									switch (*str)
									{
									case '0': if (I == 0) { str++; break; } // fuehrende Nullen
									case '1':
									case '2':
									case '3':
									case '4':
									case '5':
									case '6':
									case '7':
									case '8':
									case '9':
										I = 10 * I + (*str - 0x30);
										n++;
										str++;
										break;
									case '.':
									case ',':
										dezi = n;
										multi++;		// Dezimaltrennzeichen zaehlen >> spaeter pruefen, ob mehr als eins??
										str++;
										break;
									case 'u':			// 'u','m','A' duerfen nur am Ende (Einheit) vorkommen, danach Schleife beenden
										dezi -= 3;
									case 'm':
										dezi -= 3;
										if (!((str[1] == NUL) | ((str[1] == 'A')&(str[2] == NUL)))) { err |= (1 << 1); } // String nicht ordnungsgemaess beendet (es muss \0 oder A+\0 folgen!)
										break;
									case 'A':
										if (!(str[1] == NUL)) { err |= (1 << 2); } // String nicht ordnungsgemaess beendet (es muss \0 folgen)
										break;
									default:
										err |= (1 << 3);	// keine anderen Zeichen zulaessig
										*str = NUL;		// kein str++; => NULL fuehrt zum Schleifenabbruch
									}
								}

								I *= posneg;

								if (n > 9) { err |= (1 << 4); }  // Zahlenbereich moeglicherweise ueberschritten
								if (multi > 1) { err |= (1 << 5); }  // mehrere Dezimaltrennzeichen

								// command kann max. 30 Zeichen enthalten: vgl. max_string
								// bei korrektem Befehl:
								// * falls Dezimaltrennzeichen gefunden: dezi=[-6..9]
								// * falls kein Dezimaltrennzeichen gefunden: dezi=[94..100]
								// * max. 9 Stellen werden ausgewertet >> 10^9 uA = 10^3A = 1000A!
								// * milli/micro schiebt zusaetzlich um -3 bzw. -6
								int8_t e;
								if (dezi > 10)
								{
									e = (100 - dezi - 6); // Zehlerpotenzen schieben, Darstellung in Micro-Ampere
								}
								else {
									e = (n - dezi - 6); // Zehlerpotenzen schieben, Darstellung in Micro-Ampere
								}

								if (e > 0)
								{
									while (e)
									{
										e--;
										I /= 10;
									}
								}
								else {
									while (e)
									{
										e++;
										I *= 10;
									}
								}

								// Strombegrenzung!
								if (flag.bipol)
								{ // Bipolar
									if ((I > 1000000 * (int32_t)Imax) | (I < -1000000 * (int32_t)Imax))  // Bereich +3A >= I > -3A , neg Seite schließt -3A nicht ein! >> 2er Komplement :-( >> Behandlung im if(posneg<0)
									{                                                         // TODO Imax umbauen auf 16bit ? >> Vorbereitung auf erweiterten Strombereich uA, mA, A,...
										err |= (1 << 6);
									}
									else {
										// Rundungsfehler kompensieren: Ganzzahldivision schneidet Nachkommastellen ab! +0.5*FullSpan simuliert Rundung!
										// bipolar: FullSpan = 2*Imax[uA]=2*Imax*1e6, in Bits: /2^16 >> 0.5*2*Imax*1E6>>16 = Imax>>16
										if (posneg < 0) { I -= (Imax * 1000000) >> 16; }
										else { I += (Imax * 1000000) >> 16; }
										DAC = ((((I / Imax) << 11) / 2000) << 5) / 1000 + 0x7FFF;
										if ((posneg < 0)&(DAC == 0xFFFF)) { DAC = 0; } // Speicherueberlauf bei -Imax!
									}
								}
								else { // unipolar
									if ((I > 1000000 * (int32_t)Imax) | (I < 0)) // Bereich +3A >= I > 0A  // TODO Imax umbauen auf 16bit ? >> Vorbereitung auf erweiterten Strombereich uA, mA, A,...
									{
										err |= (1 << 6);
									}
									else {
										I += (Imax * 1000000) >> 17;	// Rundungsfehler kompensieren: Ganzzahldivision schneidet Nachkommastellen ab! +0.5*FullSpan simuliert Rundung!
																	// unipolar: FullSpan = Imax[uA]= Imax*1e6, in Bits: /2^16 >> 0.5*Imax*1E6>>16 = Imax>>17
										DAC = ((((I / Imax) << 11) / 1000) << 5) / 1000;
									}
								}
								// Aufgabe: Skalierung Strom >> Bitmuster: DAC=I/Imax*Bits
								// I/Imax ergibt Wert 0..1 => nicht darstellbar :-(
								// I[uA] / Imax[A] => 0..1E6, erfordert 20bit!
								// (I[uA] / Imax[A])*11Bit => erfordert 31bit! !!max 31 bit ausschoepfen!! sonst Uberlauf bei Unipolar!!
								// ((I[uA] / Imax[A])*11Bit)/1e3 => erfordert 21bit!
								// (((I[uA] / Imax[A])*11Bit)/1e3)*5bit => erfordert 26bit!
								// ((((I[uA] / Imax[A])*11Bit)/1e3)*5bit)/1e3 => erfordert 16bit!

								if (err >= (1 << 5)) { UART_char(NAK); UART_char(err); UART_str("out of range"); UART_char(CR); break; }
								else
									if (err > 0) { UART_char(NAK); UART_char(err); UART_char(CR); flag.ERROR = 1; break; }
								// else .. hier nicht notwendig, da break; bei Fehlern
								DAC_write(DAC);
								// hier kein break; >> Ausgabe des tatsaechlich eingestellten Wertes, identische Methode zu 'cur?'
							}
							case '?':
							{
								char buffer[10];

								if (flag.bipol) {
									ltoa(((((((int32_t)(DAC)-0x7FFF)*Imax * 20000) >> 8) * 100) >> 8), buffer, 10);
									// DAC                 : 16bit
									// ...-0x7FFF          : 16bit
									// ...*Imax            : 23bit (bei Imax=100A) 
									// ...*2               : 24bit
									// ...*1000            : 25bit
									// ...>>8              : 15bit
									// ...*1000            : 25bit
									// ...>>8              : 17bit
								}
								else {
									ltoa((((((int32_t)(DAC)*Imax * 10000) >> 8) * 100) >> 8), buffer, 10);
								}
								UART_char(AK);
								UART_str(buffer);
								UART_char(CR);
								break;
							}
							default:
								flag.ERROR = 1;
								UART_char(NAK);
								UART_char(CR);
							}

						}
						else
							// S/N setzen: OK
							if (strncasecmp(command, "S/N!", 4) == 0)
							{
								if (eeprom_read_dword((uint32_t*)EE_SN) == 0xFFFFFFFF) // EEPROM leer
								{
									uint32_t tmp;
									tmp = atol(command + 4);
									if (tmp < 0xFFFFFFFF) // S/N größer als 2^16-1 ?=> mehr als 1 Byte
									{
										eeprom_write_dword((uint32_t*)EE_SN, (uint32_t)tmp);
										UART_char(AK);
										UART_char(CR);
									}
									else {
										UART_char(NAK);
										UART_char(CR);
									}
								}
								else {
									UART_char(NAK);
									UART_str("SN war gesetzt");
									UART_char(CR);
								}
							}
							else
								// Konfiguration setzen: OK
								// IU!xxxyyyz
								// Strom 8bit / 3 Stellen
								// Spannung 8bit / 3 Stellen
								// BCS/UCS ? => Flag
								if (strncasecmp(command, "IU!", 3) == 0)
								{
									int16_t I, U;
									uint8_t bipol = 0xFF, err = 0, tmp;

									if (!(eeprom_read_byte((uint8_t*)EE_U) == 0xFF)) // ~(EEPROM leer)
									{
										err += (1 << 0);
									}

									// Polaritaet: Bestueckung beachten! RESET to midscale?
									if (command[9] == 'U') { bipol = 0; }
									else
										if (command[9] == 'B') { bipol = 1; }
										else { err += (1 << 1); }
									command[9] = NUL; // String-Terminierung fuer weiteres parsen...

									U = atoi(command + 7);
									command[6] = NUL; // String-Terminierung fuer weiteres parsen...
									if ((U > 0xFF) | (U < 0)) { err += (1 << 2); } // out of range... 

									I = atoi(command + 4);
									//command[10]=NUL; // String-Terminierung fuer weiteres parsen...
									if ((I > 0xFF) | (I < 0)) { err += (1 << 3); } // out of range...

									if (!err)
									{
										eeprom_write_byte((uint8_t*)EE_I, (uint8_t)I);
										eeprom_write_byte((uint8_t*)EE_U, (uint8_t)U);
										tmp = eeprom_read_byte((uint8_t*)EE_CFG);
										tmp &= ~(1 << CFG_bipol);
										tmp &= ~(bipol << CFG_bipol); // OK, da bipol oben nur auch 1 oder 0 gesetzt wird
										eeprom_write_byte((uint8_t*)EE_CFG, (uint8_t)tmp);
										UART_char(AK);
										UART_char(CR);
									}
									else {
										UART_char(NAK);
										UART_char(err + 0x30); // Fehlernummer senden, int > ASCII via +0x30
										UART_str("ERR");
										UART_char(CR);
									}
								}//else


			UART_flag = 0;
		} // UART Kommando vollstaendig verarbeitet

		if ((PIN_PW & ((1 << PWpos) | (1 << PWneg))) == 0)
		{	// Stromquelle ist AUSgeschaltet
			flag.POWER = 0;
			PORT_LED |= (1 << LEDr);
			PORT_LED &= ~(1 << LEDg);
		}
		else {	// Stromquelle ist EINgeschaltet
			flag.POWER = 1;
			if (flag.bipol) { DAC = 0x7FFF; }
			else { DAC = 0x0000; };
			PORT_LED &= ~(1 << LEDr);
			PORT_LED |= (1 << LEDg);
		}

	} // ENDE while(1)

} // ENDE main()



// *********************************************************************
// interrupt service routine UART recieve
// Kommunikation per RS232/RS485
ISR(USART_RX_vect)
{
	// WDT reset!
	watchdog_reset();

	// wenn UDR gelesen wird, wird interrupt Flag zurückgesetzt
	uint8_t tmpChar;
	tmpChar = UDR0;

	recieved[r_pos] = tmpChar;
	r_pos++;
	r_pos %= max_string; // wenn ein anderes Geraet mit laengerem Protokoll angesprochen wird darf nicht beliebiger Speicher beschrieben werden

	switch (tmpChar)
	{ // Kommando beendet ? --> vollstaendigen Befehl zur weiteren Verarbeitung an main() übergeben
	case CR: // kein break => gleiche Aktion wie bei LF
	case LF:
		for (uint8_t j = 0; j < r_pos; j++) { command[j] = recieved[j]; } // Schleife nur bis j<r_pos, da zuvor schon r_pos++ !!
		command[r_pos - 1] = '\0';  // StingENDEzeichen ('\r' durch '\0' ersetzen)
		UART_flag = r_pos;
		r_pos = 0;
	} // ENDE switch
}

// *********************************************************************
// interrupt service routine watchdog
// timeout fuer UART string => reset
ISR(WDT_vect)
{
	// nur eine Anweisung(?) => cli/sei nicht notwendig
	// es ist eine ISR => kann nicht unterbrochen werden
	//cli;
	watchdog_reset();
	r_pos = 0;
	//sei;
}

// *********************************************************************
// interrupt service routine COMPB Timer0 (8bit)
// Systemueberwachung
ISR(TIMER1_COMPA_vect)
{
}

// *********************************************************************
// interrupt service routine COMPB Timer0 (8bit)
// Systemueberwachung
ISR(TIMER1_COMPB_vect)
{
}

// *********************************************************************
// interrupt service routine Overflow Timer0 (8bit)
// Systemueberwachung
ISR(TIMER1_OVF_vect)
{
}

// *********************************************************************
// interrupt service routine PCINT
// Ueberwachung der Betriebsspannungen
ISR(PCINT1_vect)
{
}
