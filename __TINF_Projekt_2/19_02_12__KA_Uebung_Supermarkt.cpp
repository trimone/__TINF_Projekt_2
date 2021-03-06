/*======================================================================================================
TINF				

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	12.02.2019

PROJEKT:	Supermarkt
			KA �bung

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
#include "Kasse.h"
//#include "__all_mains.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verk�rzen => LOG (X);
#define ANZ 45 

#define ZETTEL(name , preis) cout << "\tArtikel: " << name << "\tPreis: " << preis << endl

// === STRUCT-KONSTRUKT ===
//struct _19_02_12_Supermarkt : public _main_struct	// Kapselt die .cpp ab
//{
// string get_main_name(){ return "19_02_12__KA_Uebung_Supermarkt"; }
//
//// === PROTOTYPEN ===
//
 

void  _19_02_12_Supermarkt::hey()
{
	COUT("sdf ooo");
}

// === HAUPTPROGRAMM ===
 void _19_02_12_Supermarkt::main(void)		
{
	// --- Lokale Variablen ---
	 hey();
	
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " C++ Programmierung" << endl;
	COUT("Supermarkt Einkauf");
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	int menu;

	Kasse einkauf;
	do
	{
		COUT("=== Auswahlmenue ===");
		COUT("[1] Neue Gepackte Ware");
		COUT("[2] Neue Lose Ware");
		COUT("[3] Kassenzettel");
		COUT("[4] Einkauf beenden");
		cin >> menu;

		switch (menu)
		{
		case 1:
			einkauf.gepackteWare();
			break;
		case 2:
			einkauf.loseWare();
			break;
		case 3:
			einkauf.kassenZettelAusgeben();
		case 4:	// beenden
			break;
		default:
			COUT("Falschen Eingabe");
			break;
		}
				
	} while (menu != 4);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife
	_getch();
}

// === FUNKTIONEN ===


//}; // === STRUCT ENDE ===


