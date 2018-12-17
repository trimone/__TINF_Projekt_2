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
#include "KopierKarte.h"

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
	ChipKarte* karte1 = new ChipKarte;
	// ChipKarte karte2 // automatische erzeugung, BESSER!!


	do
	{
		// === AUFGABE 1 ===

		cout << endl << " " << endl;

		
		auto1->fahren();



		// === CHIP KARTE ===

		cout << endl << "Pin eingebnen: " << endl;
		cin >> nrP;
		karte1->setPinEingabe(nrP);

		if (karte1->vergleiche())
		{
			bool ok = false;
			cout << "Kontostand: " << karte1->getKontoStand() << endl;
			do {
				cout << "\t Kopieren? [Druecken Sie die '1']: ";
				cin >> eingabe;
				if (eingabe)
				{

					if (ok = karte1->kopieren())
					{
						cout << "\t Kopiert ..."
							<< "Kontostand: " << karte1->getKontoStand() << endl;
					}

					else if (!ok)
					{
						cout << "\t Kopiert nicht moeglich!"
							<< "Kontostand: " << karte1->getKontoStand() << endl;
						//break;
					}
					//karte1->kopieren;
				}
			} while (ok);
		}
		else
			cout << "Pin falsch!";
		delete(auto1);

		delete(karte1);
		karte1 = nullptr;
		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

