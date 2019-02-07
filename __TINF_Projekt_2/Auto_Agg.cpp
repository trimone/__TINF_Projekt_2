


/*======================================================================================================
'.ccp' Datei zu Klasse 'Auto_agg'
======================================================================================================*/

// === INCLUDE ===

#include "Auto_Agg.h"
#include <iostream>
#include <string>
using namespace std;

#define TAB	cout << "\t"
#define COUT(x) cout << x << endl


// === DEFIDITION DER METHODEN ===
// Zwegs der übersichtilichkeit werden die Methoden ausgelagert
// 'Class::' ==> Methode gehört zu Klasse


Auto_Agg::Auto_Agg(int nr)
{
	if (nr >= 0)
	{
		this->nr = nr;
		COUT("Auto erzeugt Nr: " << this->nr);

		// Hier im Konstruktor Attribute für die Komponente setzen 
		brief.setNr(this->nr);
	}


}

Auto_Agg::~Auto_Agg()
{
	COUT("Auto zerstoert"); 
	
	abmelden();
}

void Auto_Agg::anmelden()
{
	//if (schein == nullptr)
	schein = new Fahrzeugschein;

	COUT("Fahrzeug angemeldet");
	
}

void Auto_Agg::abmelden()
{
	if (schein != nullptr)
	{
		delete schein;
		schein = nullptr;

		COUT("Fahrzeug abgemeldet");
	}
}

Fahrzeugbrief::Fahrzeugbrief()
{
	// hier werden keine Attribute gesetzt
	COUT("Fahrzeugbrief erzeugt");
}

Fahrzeugbrief::~Fahrzeugbrief()
{
	COUT("Fahrzeugbrief zerstoert Nr: " << this->nr);
}

void Fahrzeugbrief::setNr(int nr)
{
	if (nr >= 0)
		this->nr = nr;
}

int Fahrzeugbrief::getNr()
{
	//Auto_Agg::abmelden();
	return this->nr;
}

Fahrzeugschein::Fahrzeugschein()
{
	COUT("Fahrzeugschein erstellt");
	//this->nr = 
}

Fahrzeugschein::~Fahrzeugschein()
{
	COUT("Fahrzeugschein zerstoert");
}

int Fahrzeugschein::getNr()
{
	return this->nr;
}
