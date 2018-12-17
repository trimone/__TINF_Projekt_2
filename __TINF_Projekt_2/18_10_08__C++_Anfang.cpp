/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTE1	DATUM: 08.10.2018

PROJEKT:	C++
			'string' Kommandos

			=> 'C' unnd 'C++' funktionen sollten nicht gemischt werden 
				zB 'cout/cin' und 'printf/sanf' 

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

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 45 

// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);

// --- default - Werte bei Funktionen ---
int tueNichts(int i = 5);

// --- �berladen von Funktionen ---
void typ(int i);		// !!! geht nicht mit 2 default Werten, nur einer, da sonst nicht eindeutig
void typ(double x);		// Compiler erkennt automatisch welche Funktion benutzt werden soll, anhand vom Datentyp

// --- Referenzen ---
void vertauschen(int& a, int &b);


// === HAUPTPROGRAMM ===
void main(void)
{
	// --- Lokale Variablen ---
	

	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" <<endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
				
		// --- default - Werte bei Funktionen ---
		int i = 3, j;
		cout << endl << " default - Werte bei Funktionen";
		j = tueNichts(i);	// 'i' wird �bergeben
		j = tueNichts();	// Default-Wert wird �bergeben
		
		// 'cout/cin' mit 'printf/sanf' nicht mischen !!!
		//printf("\n j = %i\n", j);			// C Schreibweise
		cout << endl << " j = " << j;		// C++ Schreibweise


		// --- �berladen von Funktionen ---
		cout << endl << " �berladen von Funktionen";

		int k = 4;
		double x = 42.423;

		typ(k);	// int
		typ(x);	// double

// --- string als Datentyp ---
		// verwaltet sich selbst, zB. L�nge
		string txt = "Hallo";		// std::string txt	// altenativ, muss bei jedem neuem 'string' eingetragen werden
		string txt2 = "FTED2";
		char c;
		cout << endl << txt << " Fester Text " << i << endl;	// 'endl' = 'end line'
		cout << " Zahl eingeben: ";
		cin >> i;
		
//		cin.clear;
		cout << " Zahl = " << i << endl;

		// Zeilen einlesen
		cout << " Text eingeben: ";
		getline(cin, txt2);
		cout << endl << txt2;

		// === Referenzen ===

		int a = 23, b = 42;		// Deklaration 'echte Veriable', Speicherplatz wird belegt
		int& auch_a = a;
		int& auch_b = b;		/*Referenzen auf 'a: auch_a' ist die selbe Variable wie 'a'
									Regel:
										- Referenz muss bei der Deklaration auf die echte Variable gesetzt werden
										- Die Zuordnung kann nicht mehr ge�ndert werden
										- Typ der Referenz = Typ der echten Variable
										*/
							// Referenzen	
							/*	- zus�tzlcih zu Zeigern, oft besser
								- haben eine feste Bildung an die Variable
									(<-> Zeiger "niegendwohin")
								- keine Dereferenzierung wie bei Zeigern n�tig '*a'
								- bei �bergabe an Funktionen keine Kopie der Variable ( zB bei gro�en Strukturen)
								- Referenzen auf "alles"
								- keine Felder von Referenzen m�glich
								- kein Typ "Zeiger auf Referenz" m�glich
								- wenn die echte Variable zerst�rz wird (zB lokale Variable in einer Funktion), dann hat  die Referenz ihren Wert verloren!
							*/

		cout << endl << " a = " << a  << " b = " << b << endl;

		vertauschen(a, b);
		cout << endl << " Vertauscht:";
		cout << endl << " a = " << a << " b = " << b << endl;

// === dynamische Speicherverwaltung ===
		int anzahl;
		double* d_zeiger = NULL;

		cout << endl << " Anzahl der Elemente im Vektor: " << endl;
		cin >> anzahl;

		d_zeiger = new double[anzahl];	// Vektor hat eine variable L�nge

		for (i = 0; i < anzahl; i++)
		{
			d_zeiger[i] = i;
			cout << d_zeiger[i] << " ";
		}

		// !!! Super heftig wichtig !!! sonst wird unn�tiger Speicherplatz belegt
		delete[] d_zeiger;		// Speicherplatzt wird freigegeben/ Inhalt gel�scht
								// '[]' Damit der ganze Vektor freigegeben wird!
		d_zeiger = NULL; // Vorsichtsma�nahme gegen doppelt freigeben!

		for (i = 0; i < anzahl; i++)
		{
			//d_zeiger[i] = i;
			cout << endl << d_zeiger[i] << " ";
		}
				
				// --- Hinweise ---
				/*	- dynamische angeforderten Speicherplatz wieder freigeben 
					  (zu jedem 'new' ein 'delete')!
					- nur freigeben, was mit 'new' erzeugt wurde!
					- nur einmal freigeben! */

				// --- Empfelungen ---
				/*	- Zeiger mit 'NULL' initialisieren
					- Zeiger nach Freigeben auf 'NULL' setzen 
					  (Zeiger mit dem Wert 'NULL' k�nnen immer freigegeben werden)
					- Bei gro�en Speicherpaltzreservierungen pr�fen, ob Reservierung erfolgreich war
				*/

	} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

// --- default - Werte bei Funktionen ---
int tueNichts(int i)
{
	i++;
	return i;
}
// --- �berladen von Funktionen ---
void typ(int i)
{
	cout << endl << " Integer " << i << endl;
}

void typ(double x)
{
	cout << endl << " Double " << x << endl;

}

void vertauschen(int & a, int & b)
{
	int tmp = a;		// Vareablen vertauschen
	a = b;
	b = tmp;	
}
