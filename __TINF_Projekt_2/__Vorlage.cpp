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
#include <string.h>				// f�r String Funktionen

#include <string>				// f�r string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'

#include <ctype.h>
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verk�rzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// f�r Men�steureung ben�tigt
// zur Ausf�hrung Instanz in '_MAIN().cpp' erzeugen !!

struct VORLAGE : public _main_struct	// Kapselt die .cpp ab
{
	// --- .cpp Name wird zur�chgegen ---
	string get_main_name() { return "VORLAGE"; }	// f�r Men�steureung ben�tigt

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




		} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife
	}

	// === FUNKTIONEN ===


}; // === STRUCT ENDE ===
