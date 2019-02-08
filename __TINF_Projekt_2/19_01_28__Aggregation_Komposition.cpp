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
#include "Auto_Agg.h"
// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
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
	
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	TAB; COUT("Aggregation und Komposition");
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	Motor* motor = new Motor(123);

	Auto_Agg* brumbrum = new Auto_Agg(23);
	Auto_Agg* brumbrum_mit_motor = new Auto_Agg(motor, 42);
	Auto_Agg* mercedes = new Auto_Agg(motor, 723);	// Motor ist 2 Fahrzeugen !!!!!
													// NICHT  ERLAUBT !!!!
	brumbrum->anmelden();
	brumbrum_mit_motor->anmelden();
	
	_getch();
	brumbrum->anmelden();	// doppeltes anmelben nicht möglich
	COUT("__________________________");
	brumbrum_mit_motor->motorAusbauen();

	mercedes->motorEinbauen(motor);

	COUT("__________________________");
	delete brumbrum;
	brumbrum = nullptr;

	delete brumbrum_mit_motor;
	brumbrum_mit_motor = nullptr;

	delete mercedes;
	mercedes = nullptr;

	_getch();
	COUT("__________________________");
	delete motor;
	motor = nullptr;

	do
	{
		// === AUFGABE 1 ===

		//cout << endl << " " << endl;



		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

