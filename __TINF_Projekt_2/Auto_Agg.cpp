


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
	this->mot = nullptr;
	schein = nullptr;	// es gibt keinen Fahrzeugschein
	meinFahrer = nullptr;
	if (nr >= 0)
	{
		this->nr = nr;
		COUT("Auto erzeugt Nr: " << this->nr);

		// Hier im Konstruktor Attribute für die Komponente setzen 
		brief.setNr(this->nr);

		motorEinbauen(mot);
	}
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

void Auto_Agg::bemannen(Fahrer* meinFahrer)
{
	this->meinFahrer = meinFahrer;
}

void Auto_Agg::fahren(void)
{
	COUT("Fahrer " << meinFahrer->getName() 
		<<" faehrt Auto mit Nr. " << nr 
		<< " mit " << mot->getPS() << " PS");
	COUT("_____________________________________");
}

void Auto_Agg::verlassen()
{
	meinFahrer = nullptr;
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
	setEingebaut(false);
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
	return ps;
}

bool Motor::getEingebaut()
{
	return _eingebau;
}

void Motor::setEingebaut(bool e)
{
	_eingebau = e;
}

Fahrer::Fahrer(string name)
{
	this->name = name;
	this->meinAuto = nullptr;
}

void Fahrer::fahren(Auto_Agg * meinAuto)
{
	if( this->meinAuto == nullptr)
	{ 
		COUT("Fahrer " << getName() << " faehrt mit Auto " );
		this->meinAuto = meinAuto;	// länger Bildung
		meinAuto->bemannen(this);	// Objekt übergibt einen Zeiger auf sich selbst
		meinAuto->fahren();
	}
	else COUT("Fahrer faehrt schon ein Auto");
}

void Fahrer::aussteigen()
{
	COUT("Fahrer verlaest das Auto ");
	meinAuto->verlassen();	// Assoziation beim 'Auto' lösen
	meinAuto = nullptr;
}

string Fahrer::getName(void)
{
	return name;
}
