#pragma once
// ===== my_biblio.h =====

/*= ==========================================================================================
TINF
NAME : ALEX HUBER	KLASSE : FTE1	DATUM :	03.03.2018

		EIGENE BIBLIOTHEK HEADER-DATEI

		In der Headerdatei werden die Funktionsprototypen aufgelistet
		Bei Prototypen-Deklaration ist immer Strichpunkt ";" notwendig !!
=========================================================================================== */

#include <string>				// f�r string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'

// === PROTOTYPEN ===

// --- Abfrage, ob das Programm beendet werden soll ---
int main_beenden(); // Programm beenden??
		/*	Einbindung durch eine 'do while' Schleife.
			Liefert eine '1' wenn das Programm beendet werden soll
				
				do {
					...
					...	
					...
				} while (main_beenden() != 1);	// Solange die 1 nicht gedr�ckt wird, wiederholt sich die 'do'-Schleife
		*/
void vek_init_double( double vek[], int anzahl);	// Vektor mit Nullen f�hlen
void vek_init_int(int vek[], int anzahl);



// === STRUCKT KONSTRUKT ===
// ben�tigt f�r die Men�steuerung mit allen sub main in '__MAIN().cpp'
struct _main_struct
{
	// Virtuele Methoden werden von den jeweiligen 'main()' �berschrieben
	// Rein virtuelle Methoden k�nnen nicht verwendet werden, da von '_main_stuct' Instanzen in '__MAIN().cpp' ben�tigt werden
	// 'virtual void main() = 0' => geht nicht !!

	virtual void main() {}	// 'sub main()' wird ausgef�hrt
	virtual string get_main_name() { return "----------"; }	// Name der .cpp zur�ckgeben
	
	// ==> einmal virtuell => immer virtuell ==> wird virtuell vererbt !!
	//'vitual' wegen Struct-Konstrukt ==> Aufruf dieser 'main()' in Men�streuerung in '_MAIN( ).cpp'
};

struct _19_02_12_Supermarkt : public _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name() { return "19_02_12__KA_Uebung_Supermarkt"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
	void hey();
};

struct _19_02_08_Rahmen : _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name(void) { return "19_02_08__Komposition_Rahmen"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _18_10_01_Marothon : _main_struct
	{
		// --- .cpp Name wird zur�ckgegeben ---
		string get_main_name() { return "18_10_01__Marathonlauf_(Strukturen)"; }	// f�r Men�steureung ben�tigt
	
	   // === HAUPTPROGRAMM ===
		void main(void);
	};

struct _19_02_22__KA2 : _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name(void); // { return "19_02_22__KA2_Vererbung_Komposition"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _19_02_22_Assoziation : _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name();// { return "19_02_22_Assoziation"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

struct _19_03_15_Sommer_14 : _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name() { return "19_03_15__Pruefung_Sommer_2014"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
};

//
struct VORLAGE : _main_struct
{
	// --- .cpp Name wird zur�ckgegeben ---
	string get_main_name() { return "VORLAGE"; }	// f�r Men�steureung ben�tigt

   // === HAUPTPROGRAMM ===
	void main(void);
};
