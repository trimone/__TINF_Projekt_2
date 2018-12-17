
/*======================================================================================================
TINF				

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	

PROJEKT:	

======================================================================================================*/


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
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 45 

#define NUL  0x00  // 00 '\0'

// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);



typedef struct {
	unsigned bipol : 1;
	unsigned POWER : 1;
	unsigned _ERROR : 1;
}flag_t;

#define flag (*(volatile flag_t *))

// === HAUPTPROGRAMM ===
void main(void)
{

	volatile uint16_t DAC; // DAC Register-Wert
	char Imax = 3;			// maximaler Ausgangsstrom in AMPERE (EEPROM), falls Imax < 1A muss das Programm geaendert werden!!

	
		char command[30];
		//cin >> command;
		//scanf_s("%s", command);
		command[0] = 'C';
		command[1] = 'U';
		command[2] = 'R';
		command[3] = ' ';
		command[4] = '0';
		command[5] = '.';
		command[6] = '4';
		command[7] = 'm';
		command[8] = 'A';

		command[9] = NUL;

		if (strncmp(command, "CUR",3) == 0)
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
							case '0': if (I == 0) 
										{ 
											str++; break; 
										} // fuehrende Nullen
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
								//str++;
							case 'm':
								dezi -= 3;
								str++;
								if (((str[1] == NUL) | ((str[1] == 'A')&(str[2] == NUL))))
								{ 
									err |= (1 << 1);	/// setzt 'err' auf 2 ??
								} // String nicht ordnungsgemaess beendet (es muss \0 oder A+\0 folgen!)
								break;
							case 'A':
								
								if (!(str[1] == NUL)) 
								{ 
									err |= (1 << 2); 
								} // String nicht ordnungsgemaess beendet (es muss \0 folgen)
								str++;
								break;
							default:
								err |= (1 << 3);	// keine anderen Zeichen zulaessig
								*str = NUL;		// kein str++; => NULL fuehrt zum Schleifenabbruch
								break;
						}
						//return 0;
					} 


					I *= posneg;

					if (n > 9) 
					{ 
						err |= (1 << 4); 
					}  // Zahlenbereich moeglicherweise ueberschritten
					if (multi > 1) 
					{ err |= (1 << 5); }  // mehrere Dezimaltrennzeichen

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
					if (1)
					//if (flag.bipol)
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


				}






			}
			_getch;
		} //while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
	}

	// === FUNKTIONEN ===




