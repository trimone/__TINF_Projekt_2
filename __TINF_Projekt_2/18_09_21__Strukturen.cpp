/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTE1	DATUM:

PROJEKT:

======================================================================================================*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 
#include <math.h>				//sonst ist M_PI als "nichtdeklarierter Bezeichner" ausgewiesen!
#include <string.h>				// für String Funktionen
#include <ctype.h>
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 45 

// === Strukturen anlegen (global) ===
struct Datum		// neuen Datentyp anlegen, noch keine Variable
{
	int tag;		// Ausbau des Datentyps
	int monat;
	int jahr;
};				// ';' sehr wichtig !!!
typedef struct Datum Datum;	// Vorhandener Datentyp wird ersetzt // ABKÜRZUNG !!
							// Man muss nicht immer 'struct Datum' schreiben, 'Datum' reicht


// === PROTOTYPEN ===
void ausgeben(Datum dat);
void ausgeben_zg(Datum* dat);
Datum eingeben(void);
void eingeben_zg(Datum* dat);

// === HAUPTPROGRAMM ===
void main(void)
{
	// --- Lokale Variablen ---
	
	// --- Ausführlich ----
	struct Datum gebTag;	// neue Variable von Typ 'Datum'

	// Inhalt bestimmen
	gebTag.tag = 23;		
	gebTag.monat = 03;
	gebTag.jahr = 1991;

	// --- Abgekürtzt ---
	Datum heute = { 21, 9, 2018 };

	// Zeiger		// Zeigerübergabe spart Platz und Zeit
	Datum* d_zg;
	d_zg = &heute;	// 'dat_zg' zeigt auf 'heute'

	//heute.tag = 21;
	//(*d_zg).tag = 21;
	d_zg->tag = 21;		// bessere Schreibweise
	
	
	// --- Programm Einleitung ---
	printf("\n======================================================================\n");
	printf("\n ");
	printf("\n======================================================================\n");
	do
	{
		// === AUFGABE 1 ===

		ausgeben(heute);

		//heute = eingeben();
		eingeben_zg(&heute); // Zeiger // '&heute' Adresse von heute

		//ausgeben(heute);
		ausgeben_zg(&heute);


	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

void ausgeben(Datum dat)
{
	printf("\n %i.%i.%i\n", dat.tag, dat.monat, dat.jahr);	
}

void ausgeben_zg(Datum* dat)
{
	printf("\n %i.%i.%i\n", dat->tag, dat->monat, dat->jahr);
}

Datum eingeben(void)
{
	Datum dat;
	printf("\n Datum eingeben (DD.MM.JJJJ):");
	scanf_s("%d.%d.%d", &dat.tag, &dat.monat, &dat.jahr);	// DD.MM.JJJJ wird vorgegeben
						// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal
										

	return dat;
}

// mit Zeiger
void eingeben_zg(Datum* dat)
{
	printf("\n Datum eingeben (DD.MM.JJJJ):");
	scanf_s("%d.%d.%d", &dat->tag, &dat->monat, &dat->jahr);	// DD.MM.JJJJ wird vorgegeben
					// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal

	//return (dat);
}

