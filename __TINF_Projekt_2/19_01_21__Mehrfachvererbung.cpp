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
#include <string.h>				// f�r String Funktionen

#include <string>				// f�r string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'

#include <ctype.h>
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek
#include "Fahrzeug.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verk�rzen => LOG (X);
#define ANZ 45 

// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);


// === HAUPTPROGRAMM ===
void main(void)  
{
	// --- Lokale Variablen ---
		
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'
	FlugBoot* mfb = new FlugBoot;
	FlugBoot* antonov = new FlugBoot;

	COUT("Anzahl Fahrzeuge: " << Fahrzeug::getAnzahl());

	antonov->setV(23);
	antonov->fahren();

	_getch();
	delete mfb;
	mfb = nullptr;
	delete antonov;
	antonov = nullptr;
	do
	{
		// === AUFGABE 1 ===

		cout << endl << " " << endl;



		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

