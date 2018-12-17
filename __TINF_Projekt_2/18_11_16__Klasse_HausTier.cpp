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
#include "HausTier.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 5 

// === PROTOTYPEN ===
void fibonacci(int fib_vektor[]);
void fib_ausgeben(int fib_vektor[], int laenge);

void tiereErzeugen(HausTier* ht[]);
void ausgabe(HausTier* ht[]);
void objekteKaputt(HausTier* ht[]);


// === HAUPTPROGRAMM ===
void main(void)  
{
	// --- Lokale Variablen ---
			// ';' sehr wichtig !!!
	
	int i=0;
	

	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
		// === AUFGABE 1 ===

		cout << endl << " " << endl;

		HausTier olaf("Olaf", 120);	// auto
		//HausTier* fiech;	// automatisch
		HausTier* haustier = new HausTier("auto",100);	// dynamisch

		HausTier* ht[ANZ];

		tiereErzeugen(ht);

		ausgabe(ht);

		objekteKaputt(ht);
		
	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

void tiereErzeugen(HausTier* ht[])
{
	int i;
	string name;
	double optGewicht;

	for (i = 0; i < ANZ; i++)
	{

		cout << endl << "Werte fur HausTier " << i+1 << " eingeben";

		cout << endl << "\tName eingeben: ";
		cin >> name;
		cout << endl << "\tOptimales Gewicht eingeben: ";
		cin >> optGewicht;
		cin.ignore(); // Eingabe ignorieren
		ht[i] = new HausTier(name, optGewicht);
		//ht[i] = nullptr;
	}
}

void ausgabe(HausTier* ht[])
{
	int i;

	for (i = 0; i < ANZ; i++)
	{
		cout << endl << "HausTier " << i+1 << " mit dem Namen " << ht[i]->getName();
		cout << "hat einen Glueckswert von " << ht[i]->getGlueck() << endl;
	}
}

void objekteKaputt(HausTier* ht[])
{
	int i;

	for (i = 0; i < ANZ; i++)
	{
		delete (ht[i]);
		ht[i] = nullptr;
	}

}