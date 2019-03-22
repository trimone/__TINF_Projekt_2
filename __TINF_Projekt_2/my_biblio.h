#pragma once
// ===== my_biblio.h =====

/*= ==========================================================================================
TINF
NAME : ALEX HUBER	KLASSE : FTE1	DATUM :	03.03.2018

		EIGENE BIBLIOTHEK HEADER-DATEI

		In der Headerdatei werden die Funktionsprototypen aufgelistet
		Bei Prototypen-Deklaration ist immer Strichpunkt ";" notwendig !!
=========================================================================================== */

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

// === PROTOTYPEN ===

// --- Abfrage, ob das Programm beendet werden soll ---
int main_beenden(); // Programm beenden??
		/*	Einbindung durch eine 'do while' Schleife.
			Liefert eine '1' wenn das Programm beendet werden soll
				
				do {
					...
					...	
					...
				} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do'-Schleife
		*/
void vek_init_double( double vek[], int anzahl);	// Vektor mit Nullen fühlen
void vek_init_int(int vek[], int anzahl);



// === STRUCKT KONSTRUKT ===
// benötigt für die Menüsteuerung mit allen sub main in '__MAIN().cpp'
struct _main_struct
{
	// Virtuele Methoden werden von den jeweiligen 'main()' überschrieben
	// Rein virtuelle Methoden können nicht verwendet werden, da von '_main_stuct' Instanzen in '__MAIN().cpp' benötigt werden
	// 'virtual void main() = 0' => geht nicht !!

	virtual void main() {}	// 'sub main()' wird ausgeführt
	virtual string get_main_name() { return "----------"; }	// Name der .cpp zurückgeben
	
	// ==> einmal virtuell => immer virtuell ==> wird virtuell vererbt !!
	//'vitual' wegen Struct-Konstrukt ==> Aufruf dieser 'main()' in Menüstreuerung in '_MAIN( ).cpp'
};

struct _19_02_12_Supermarkt : public _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name() { return "19_02_12__KA_Uebung_Supermarkt"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
	void hey();
};

struct _19_02_08_Rahmen : _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name(void) { return "19_02_08__Komposition_Rahmen"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _18_10_01_Marothon : _main_struct
	{
		// --- .cpp Name wird zurückgegeben ---
		string get_main_name() { return "18_10_01__Marathonlauf_(Strukturen)"; }	// für Menüsteureung benötigt
	
	   // === HAUPTPROGRAMM ===
		void main(void);
	};

struct _19_02_22__KA2 : _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name(void); // { return "19_02_22__KA2_Vererbung_Komposition"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _19_02_22_Assoziation : _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name();// { return "19_02_22_Assoziation"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _19_03_15_Sommer_14 : _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name() { return "19_03_15__Pruefung_Sommer_2014"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

//
struct VORLAGE : _main_struct
{
	// --- .cpp Name wird zurückgegeben ---
	string get_main_name() { return "VORLAGE"; }	// für Menüsteureung benötigt

   // === HAUPTPROGRAMM ===
	void main(void);
};
