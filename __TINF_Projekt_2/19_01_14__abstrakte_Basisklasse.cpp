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
#include "GeoObjekt.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
#define ANZ 3 

// === PROTOTYPEN ===


// === HAUPTPROGRAMM ===
void main(void)  
{
	// --- Lokale Variablen ---
	
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	GeoObjekt* geo[ANZ];	// Zeiger auf Elemente

	geo[0] = new Kreis(4, 0, 0);		// dynamisch
	geo[1] = new Rechteck(5, 4, 3, 4);
	geo[2] = new Zylinder(5, 5, 6, 7);

	for (int i = 0; i < GeoObjekt::getAnzahl(); i++)
	{
		geo[i]->zeichne();
	}

	_getch();
	COUT("");

	for (int i = 0; i < GeoObjekt::getAnzahl(); i++)
	{
		geo[i]->setKoo(12, 23);
		//geo[i]->zeichne();	// nicht benötigt, 'zeichne()' wird in 'setKoo()' aufgerufen
	}
		
	_getch();
	COUT("");
	for (int i = 0; i < GeoObjekt::getAnzahl(); i++)
	{
		COUT(" Anzahl an Objekten: " << GeoObjekt::getAnzahl());
		delete geo[i];
		geo[i] = nullptr;
	}

	do
	{
		// === AUFGABE 1 ===

		cout << endl << " " << endl;



		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

