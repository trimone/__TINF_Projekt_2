/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:

PROJEKT:	Klassenarbeit 2

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
#include "__all_mains.h"

#include "KA_Rechteck.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// für Menüsteureung benötigt
// zur Ausführung Instanz in '_MAIN().cpp' erzeugen !!
// Kapselt die .cpp ab
string _19_02_22__KA2::get_main_name(void) { return "19_02_22__KA2_Vererbung_Komposition"; }

// === PROTOTYPEN ===
// ==> im Struct Header

// === SUB MAIN ===
void _19_02_22__KA2::main(void)
{
	// --- Lokale Variablen ---


	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " KA vom 15.02.2019" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
		double l, b, h, x, y;	// für User Input

	// --- Eingabe der Werte für Quader 2 ---
		cout << endl << "Werte fuer Quader 2 eingeben: ";
		cout << endl << "\t Laenge: ";
		cin >> l;
		cout << endl << "\t Breite: ";
		cin >> b;
		cout << endl << "\t Hoehe: ";
		cin >> h;
		cout << endl << "\t x Position: ";
		cin >> x;
		cout << endl << "\t y Position: ";
		cin >> y;


		// Übergabe von Werten an Objekt
		KA_Quader qd2(l, b, h, x, y);	// mit Individual Konstruktor

		KA_Quader qd1;		// mit Standard Konstruktor

		// --- Ausgabe qd1 ---
		cout << endl << "Quader 1:";
		cout << endl << "\t Volumen: " << qd1.getVolume();
		//cout << endl << "\t Position: x = " << qd1.pos.getX(); // geht nicht ;(
		//cout << endl << "\t Position: y = " << qd1.pos.getY();

		//		// 'pos' Objekt wird zurück gegeben und die Methoden können verwendet werden
		cout << endl << "\t Position: x = " << qd1.getPosition().getX(); // Methoden von Objekt 'pos' wird aufgerufen
		cout << endl << "\t Position: x = " << qd1.getPosition().getY(); 

		// --- Ausgabe qd1 ---
		cout << endl << "Quader 2:";
		cout << endl << "\t Volumen: " << qd2.getVolume();

		getch();



	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===


// === STRUCT ENDE ===
