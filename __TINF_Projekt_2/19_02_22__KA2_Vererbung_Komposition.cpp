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
#include <string.h>				// f�r String Funktionen

#include <string>				// f�r string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'

#include <ctype.h>
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek
#include "__all_mains.h"

#include "KA_Rechteck.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verk�rzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// f�r Men�steureung ben�tigt
// zur Ausf�hrung Instanz in '_MAIN().cpp' erzeugen !!
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
		double l, b, h, x, y;	// f�r User Input

	// --- Eingabe der Werte f�r Quader 2 ---
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


		// �bergabe von Werten an Objekt
		KA_Quader qd2(l, b, h, x, y);	// mit Individual Konstruktor

		KA_Quader qd1;		// mit Standard Konstruktor

		// --- Ausgabe qd1 ---
		cout << endl << "Quader 1:";
		cout << endl << "\t Volumen: " << qd1.getVolume();
		//cout << endl << "\t Position: x = " << qd1.pos.getX(); // geht nicht ;(
		//cout << endl << "\t Position: y = " << qd1.pos.getY();

		//		// 'pos' Objekt wird zur�ck gegeben und die Methoden k�nnen verwendet werden
		cout << endl << "\t Position: x = " << qd1.getPosition().getX(); // Methoden von Objekt 'pos' wird aufgerufen
		cout << endl << "\t Position: x = " << qd1.getPosition().getY(); 

		// --- Ausgabe qd1 ---
		cout << endl << "Quader 2:";
		cout << endl << "\t Volumen: " << qd2.getVolume();

		getch();



	} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===


// === STRUCT ENDE ===
