/*======================================================================================================
TINF				

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	

PROJEKT:	

======================================================================================================*/

#pragma once
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
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// für Menüsteureung benötigt
// zur Ausführung Instanz in '_MAIN().cpp' erzeugen !!

struct VORLAGE : public _main_struct	// Kapselt die .cpp ab
{
	// --- .cpp Name wird zurüchgegen ---
	string get_main_name() { return "VORLAGE"; }	// für Menüsteureung benötigt

// === PROTOTYPEN ===
	void fibonacci(int fib_vektor[]);
	void fib_ausgeben(int fib_vektor[], int laenge);


// === SUB MAIN ===
	void main(void)
	{
		// --- Lokale Variablen ---
		struct Datum		// neuen Datentyp anlegen
		{
			int tag;		// 
			int monat;
			int jahr;
		};				// ';' sehr wichtig !!!

		// --- Programm Einleitung ---
		cout << endl << "======================================================================" << endl;
		cout << endl << " " << endl;
		cout << endl << "======================================================================" << endl;
		// 'endl' = 'end line' = '\n'

		do
		{
			// === AUFGABE 1 ===

			cout << endl << " " << endl;




		} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
	}

	// === FUNKTIONEN ===


}; // === STRUCT ENDE ===
