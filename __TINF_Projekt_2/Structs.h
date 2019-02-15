#pragma once


// === Strukturen anlegen (global) ===
struct Datum		// neuen Datentyp anlegen, noch keine Variable
{
	int tag;		// Ausbau des Datentyps
	int monat;
	int jahr;
};				// ';' sehr wichtig !!!
typedef struct Datum Datum;	// Vorhandener Datentyp wird ersetzt // ABKÜRZUNG !!
							// Man muss nicht immer 'struct Datum' schreiben, 'Datum' reicht


// === PROTOTYPEN ===
void ausgeben(Datum dat);
void ausgeben_zg(Datum* dat);
Datum eingeben(void);
void eingeben_zg(Datum* dat);


