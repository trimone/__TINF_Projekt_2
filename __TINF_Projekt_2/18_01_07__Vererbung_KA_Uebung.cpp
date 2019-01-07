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

#include "Fahrzeug.h"
//#include "KopierKarte.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 45 

// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);


// === HAUPTPROGRAMM ===
void main(void)
{
	// --- Lokale Variablen ---
	struct Datum		// neuen Datentyp anlegen
	{
		int tag;		// 
		int monat;
		int jahr;
	};				// ';' sehr wichtig !!!


	int nrP, eingabe;

	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	Auto* auto1 = new Auto(10);
	//ChipKarte* karte1 = new ChipKarte;
	// ChipKarte karte2 // automatische erzeugung, BESSER!!

	U_Boot* U_Obj[3];

	for (int i = 0; i < 3; i++)
	{
		U_Obj[i] = new U_Boot(6, 20, 2);
	}

	U_Obj[0]->setV(7);
	U_Obj[0]->schwimmen();

	_getch();

	U_Obj[0]->tauchen();
	U_Obj[0]->schwimmen();

	_getch();

	U_Obj[0]->setV(3);
	U_Obj[0]->schwimmen();

	_getch();

	U_Obj[0]->setV(1.5);
	U_Obj[0]->schwimmen();

	_getch();

	for (int i = 0; i < 3; i++)
	{
		delete U_Obj[i];
		U_Obj[i] = nullptr;
	}

	do
	{
		// === AUFGABE 1 ===

		cout << endl << "? " << endl;





		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

