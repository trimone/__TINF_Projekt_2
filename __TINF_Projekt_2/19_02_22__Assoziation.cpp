/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	15.03.2019

PROJEKT:	Assoziation

======================================================================================================*/

#pragma once
#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 

#include <string>				// f�r string als Datentyp
#include <conio.h>
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'


#include "my_biblio.h"			// Eigene Bibliothek
#include "Auto_Agg.h"

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verk�rzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// f�r Men�steureung ben�tigt
// zur Ausf�hrung Instanz in '_MAIN().cpp' erzeugen !!
// Kapselt die .cpp ab
string _19_02_22_Assoziation::get_main_name() { return "19_02_22_Assoziation"; }
// === PROTOTYPEN ===
// ==> im Struct Header

// === SUB MAIN ===
void _19_02_22_Assoziation::main(void)
{
	// --- Lokale Variablen ---


	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " ASSOZIATION" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'
	string name;
	name = "Dude";
	Fahrer fahrer(name);
	Motor* brumbrum = new Motor(232);
	Motor* motor2 = new Motor(120);

	Auto_Agg* automobil = new Auto_Agg(brumbrum, 1);
	Auto_Agg* autombil_2 = new Auto_Agg(motor2, 2);


	do
	{
		fahrer.fahren(automobil);
		//fahrer.aussteigen();

		//system("wait");
		_getch();
		fahrer.fahren(autombil_2);
		//fahrer.aussteigen();




	} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do while'-Schleife

	delete automobil;
	automobil = nullptr;
	delete brumbrum;
	brumbrum = nullptr;
}

// === FUNKTIONEN ===


// === STRUCT ENDE ===
