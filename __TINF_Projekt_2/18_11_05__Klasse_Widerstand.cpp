/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	05.11.2018

PROJEKT:	Klasse Widerstand
			Eine Klasse Wiederstand soll entworfen und getestet werden
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
#include "Widerstand.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 3

// === PROTOTYPEN ===

void ausgabeR(Widerstand* r[]);
void objekteKaputt(Widerstand* r[]);
void ausgabeAnzahl();

// === HAUPTPROGRAMM ===
void main(void)
{
	// --- Lokale Variablen ---
	
	int i;
	Widerstand*r[ANZ];	// Vektor auf Objekte

	for ( i = 0; i < ANZ; i++)
	{
		r[i] = NULL;	// 'NULL' -> '#include <stdio.h>' notwendig
	}
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
		// === AUFGABE 1 ===

		//cout << endl << " " << endl;
		ausgabeAnzahl();

		r[0] = new Widerstand();
		r[1] = new Widerstand(2000);
		r[2] = new Widerstand(300.0, 12.0);

		ausgabeAnzahl();

		ausgabeR(r);

		r[0]->setR(100);
		r[0]->setU(10);

		ausgabeR(r);

		// Objekte zerstören
		objekteKaputt(r);
		ausgabeAnzahl();

	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

// --- Widerstände ausgeben ---
void ausgabeR(Widerstand * r[])
{
	cout << endl;	// Zeilenabstand

	for (int i = 0; i < ANZ; i++)
	{
		cout << "Widerstand " << i + 1 << endl
			<< "\t Strom I in A: " << r[i]->getI() << endl
			<< "\t Leistung P in W: " << r[i]->getP() << endl;
	}
}

void objekteKaputt(Widerstand* r[])
{
	cout << endl;
	for (int i = 0; i < ANZ; i++)
	{
		delete(r[i]);
		r[i] = NULL;
		//r[i] = nullptr;
	}
}

void ausgabeAnzahl()
{
	cout << endl << "Anzahl an Widerstand-Objekten: " << Widerstand::getAnzahl() << endl;
}
