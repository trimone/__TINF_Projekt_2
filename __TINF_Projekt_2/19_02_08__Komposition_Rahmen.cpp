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
#include "Rahmen.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
#define ANZ 45 


// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);

void hey();
// === HAUPTPROGRAMM ===
void _19_02_08_Rahmen::main(void)
{
	// --- Lokale Variablen ---
	// ';' sehr wichtig !!!
	
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	Rahmen* rahmen;

	do
	{
		// === AUFGABE 1 ===
		hey();
		cout << endl << " " << endl;

		rahmen = new Rahmen(4, 2, 8, 4);
		//COUT("Rechteck innen Flaeche: " << Rahmen::re)
		COUT("Rahmenflaeche: " << rahmen->getFlaeche());
		

		_getch();

		delete rahmen;
		rahmen = nullptr;
		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

void hey()
{
	COUT("sdf ooo");
}