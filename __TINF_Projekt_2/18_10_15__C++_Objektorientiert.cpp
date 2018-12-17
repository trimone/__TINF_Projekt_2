/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTE1	DATUM:

PROJEKT:	C++ objektorientierte Programmierung
			
			Klasse 'Datum'

======================================================================================================*/

// ===> 'include "all.h" !!!
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

#include "Datum.h"				// Klasse
#include "Kreis.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 45 

// === PROTOTYPEN ===
//void fibonacci(int fib_vektor[]);
//void fib_ausgeben(int fib_vektor[], int laenge);



// === HAUPTPROGRAMM ===
void main(void)
{
	// --- Lokale Variablen ---
	

	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung Objektorientiert " << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
		// === AUFGABE 1 ===

		//cout << endl << " " << endl;
		Datum dat;

		Kreis* dK1 = NULL;		// 'NULL' oder 'nullptr' dient zum Schutz, damit man keine Fehler macht
		Kreis* dK2 = nullptr;	// bzw. damit Fehler mit Zeigern auffallen

		Kreis kreis1, kreis2(5), kreis3; // ==> Konstruktor wird automatisch aufgerufen | NIE SELBER AUFRUFEN !!!
						// 'kreis2(5)' ==> 'r = 5' | wenn mit Übergabewert wird Individualkostruktor automatisch aufgerufen
		//dat.einlesen();
		//dat.ausgeben();
		//dat.checkSchalt();
		/*dat.setJahr(2019);
		dat.setMonat(4);
		dat.setTag(31);*/

		/*dat.setDatum(30, 02, 2000);
		dat.ausgeben();*/

		// Kreis 1
		cout << endl << " Kreis 1:" << endl;
		if (kreis1.setRadius(2.45))
		{
		/*cout << endl << kreis1.getRadius();
		cout << endl << kreis1.getUmfang();
		cout << endl << kreis1.getFlaeche();*/
		kreis1.ausgabe();
		}

		// Kreis 2		
		cout << endl << endl << " Kreis 2:" << endl;
		if (kreis2.setFlaeche(-24.5))
		{
		/*cout << endl << kreis2.getRadius();
		cout << endl << kreis2.getUmfang();
		kreis2.getFlaeche();*/
		kreis2.ausgabe();
		}

		// Kreis 3
		cout << endl << endl << " Kreis 3:" << endl;
		if(kreis3.setUmfang(25))
		{
		kreis3.getRadius();
		kreis3.getUmfang();
		kreis3.getFlaeche();
		kreis3.ausgabe();
		}

		dK1 = new Kreis;
		dK2 = new Kreis(5);

		dK1->ausgabe();	// '->' benutzen!
		dK2->ausgabe();

		delete(dK1);
		delete (dK2);
		dK1 = NULL;	// Speicherplatz freigeben, damit compiler Objekt nach dem Löschen nicht aufrufen kann
					// sonst wird auf etwas zugegrifen was nicht mehr exestiert
		dK2 = NULL;
		// dK1->getRadius() // UNZULÄSSIG
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===



