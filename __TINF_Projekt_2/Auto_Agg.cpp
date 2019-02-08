


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
	schein = nullptr;	// es gibt keinen Fahrzeugschein
	angemeldet = false;	// ...dann nicht notwendig
	mot = nullptr;

}

Auto_Agg::Auto_Agg(Motor * mot, int nr)
{
	if (nr >= 0)
	{
		this->nr = nr;
		COUT("Auto erzeugt Nr: " << this->nr);

		// Hier im Konstruktor Attribute für die Komponente setzen 
		brief.setNr(this->nr);

		motorEinbauen(mot);
	}
	schein = nullptr;	// es gibt keinen Fahrzeugschein

}

Auto_Agg::~Auto_Agg()
{
	COUT("Auto zerstoert"); 
	abmelden();
	if (mot != nullptr)
	{
		motorAusbauen();
	}
}

void Auto_Agg::anmelden()
{
	//if (schein == nullptr)
	if( schein == nullptr)
	{
		schein = new Fahrzeugschein;
		COUT("Fahrzeug angemeldet");
		angemeldet = true;
	}
	
}

void Auto_Agg::abmelden()
{
	if (schein != nullptr)	// nur wenn angemeldet => aber, leere Zeiger können belibig oft gelöscht werden
	{
		delete schein;
		schein = nullptr;
		angemeldet = false;

		COUT("Fahrzeug abgemeldet");
	}
}

void Auto_Agg::motorAusbauen()
{
	this->mot->setEingebaut(false);
	TAB; COUT("Motor ausgebaut PS: " << mot->getPS());
	this->mot = nullptr;	// Motor wird nicht zerstört ! nur entkoppelt
}

void Auto_Agg::motorEinbauen(Motor * mot)
{
	if (this->mot == nullptr && !mot->getEingebaut())
	{
		this->mot = mot;	// Objekt der Klasse übergeben 
		this->mot->setEingebaut(true);
		TAB; COUT("Motor eingebaut PS: " << mot->getPS());
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

Motor::Motor(int ps)
{
	if (ps > 0)
	{
		this->ps = ps;

	}
	COUT("Motor erstellt");
}

Motor::~Motor()
{
	COUT("Motor zerstoer");
}

int Motor::getPS()
{
	return this->ps;
}

bool Motor::getEingebaut()
{
	return _eingebau;
}

void Motor::setEingebaut(bool e)
{
	_eingebau = e;
}
