/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM: 19.03.2019

PROJEKT: ABSCHLUSSPRÜfUNG SOMMER 2014

Ihre Aufgabe besteht in der Entwicklung eines Simulationsprogrammes für eine E-Mail Kommunikation.
Dabei dient ein Teilnehmer als Nachrichtenquelle, wenn er eine E-Mail versendet. Hierbei wird eine neue E-Mail erzeugt. 
Ein Teilnehmer, der eine E-Mail empfängt, dient als Nachrichtensenke. 
Die E-Mail wird auf dem Bildschirm ausgegeben und danach zerstört. Die XSA ist ein Teilnehmer ohne Nachrichtensenke. 
Empfängt die XSA eine Nachricht, so wird diese ausgewertet aber nicht zerstört. Die Zustellung erfolgt über das Internet
Für dieses Programm existieren bereits ein UML-Klassendiagramm und eine Beschreibung der Methoden.


[l]	Entwerfen Sie die Klasse EMail. Für den Teilnehmer muss eine Vorabdeklaration stattfinden.
[2]	Entwerfen Sie die Klasse Teilnehmer. Für die Klasse Internet muss eine Vorabdeklaration stattfinden.
[3]	Entwerfen Sie die Klasse Internet.
[4]	Entwerfen Sie die Klasse Xsa.
[5]	Testen Sie die Simulation indem Sie das mitgelieferte Testprogramm TestEMail.cpp zu Ihrem Projekt hinzufügen und das Programm starten!

======================================================================================================*/

#pragma once

#include <conio.h>

#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 
#
#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

#include "my_biblio.h"			// Eigene Bibliothek
#include "Email.h"


// === MAKROS ===
#define xHoch2(x) ((x)*(x)) // BESSERES Makros !!!
#define TAB	cout << "\t"
#define COUT(x) cout << x << endl	// 'cout' verkürzen => LOG (X);
#define ANZ 45 


// === STRUCT-KONSTRUKT ===	// für Menüsteuerung benötigt
// zur Ausführung Instanz in '_MAIN().cpp' erzeugen !!
// Kapselt die .cpp ab

// === PROTOTYPEN ===
// ==> im Struct Header

// === SUB MAIN ===
void _19_03_15_Sommer_14::main(void)
{
	// --- Programm Einleitung ---
	cout << endl << "======================================================================" << endl;
	cout << endl << " Abschluss Pruefung Sommer 2014" << endl;
	cout << endl << "======================================================================" << endl;
	// 'endl' = 'end line' = '\n'

	do
	{
		Internet provider;
		Xsa geheimDienst("NSA", &provider);	// Zeiger übergeben
		Teilnehmer keinath("Keinath", &provider);
		Teilnehmer herrmann("Herrmann", &provider);

		provider.setGeheimdienst(&geheimDienst);
		herrmann.senden(&keinath); 
		_getch();

		




	} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===


// === STRUCT ENDE ===
