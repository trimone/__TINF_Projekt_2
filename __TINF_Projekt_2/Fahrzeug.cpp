#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Fahrzeug.h"

#define COUT(x) cout << x << endl;


int Fahrzeug::anzahl = 0;	// Speicherbeschaffung für 'static'-Variable

double Fahrzeug::getAnzahl()
{
	return anzahl;		// hier dürfen nur 'static'-Variablen verwenden
}


//void Fahrzeug::fahren()
//{
//	COUT("Fahrzeug faehrt!");
//}

Fahrzeug::Fahrzeug(double vMax)
{
	anzahl++;
	COUT("Fahzeug erzeugt");

	this->v = 0;
	this->vMax = vMax;
}

Fahrzeug::Fahrzeug()
{
	COUT("Fahrzeug erzeugt");

	this->v = 0;
	this->vMax = 100;
	anzahl++;
}


Fahrzeug::~Fahrzeug()
{
	anzahl--;
	COUT("Fahzeug zerstört");
}

// Definition nicht mehr notwendig, da rein virtuell bzw wird nie aufgerufen
//void Fahrzeug::fahren()
//{
//	cout << endl << "Fahzeug faehrt mit Geschwindigkeit v = " << getV();
//}

bool Fahrzeug::setV(double v)
{
	bool ok = false;

	if (v >= 0)
	{
		if (v <= this->vMax)
		{
			this->v = v;
		}
		else
			this->v = vMax;
		ok = true;
	}

	return true;
}

double Fahrzeug::getV()
{
	return this->v;
}


// === METHODEN FÜR ABGELEITET KLASSEN ===

// --- Auto --
Auto::Auto(double v) : Fahrzeug(v)	// Konstruktoraufruf der Basisklasse
{
	cout << endl << "Auto erzeugt";
}

Auto::~Auto()
{
	cout << endl << "Auto zerstoert";
}

void Auto::autoFahren()
{
	cout << endl << "Auto faehrt mit Geschwindigkeit v = " << getV();
}

void Auto::fahren()
{
	COUT("Auto faehrt!");
}

// --- Schiff ---
//Schiff::Schiff(int f):Fahrzeug(f)
//{
//	cout << endl << "Schiff erzeugt";
//}

Schiff::Schiff(double vMax, double brt):Fahrzeug(vMax)
{
	if (brt > 0)
	{
		this->brt = brt;
	}
	else 
		this->brt = 1000;

	COUT("Schiff erzeugt");
}

Schiff::Schiff()
{
	this->v = 2;
	COUT("Schiff erzeugt");
}

Schiff::~Schiff()
{
	COUT("Schiff zerstoert");
}


void Schiff::schwimmen()
{
	cout << endl << "Schiff schwimmt mit Geschwindigkeit v = " << getV();
}

void Schiff::fahren()
{
	COUT(" Schiff schwimmt mit v = " << getV());

}

U_Boot::U_Boot(double vMax, double brt, double vMaxG):Schiff(vMax,brt)
{
	this->vMaxG = vMaxG;
	getaucht = false;
	COUT("UBoot erzeugt");
}

U_Boot::~U_Boot()
{
	COUT("UBoot zerstoert");
}
void U_Boot::tauchen()
{
	cout << endl << "U-Boot getauscht";
	getaucht = true;

	
	this->setV(vMaxG);
}

void U_Boot::auftauchen()
{
	cout << endl << "U-Boot aufgetaucht";

	getaucht = false;
}

void U_Boot::setV(double v)
{
	if (getaucht)
	{
		if (v <= vMaxG)
		Fahrzeug::setV(v);

		else Fahrzeug::setV(vMaxG);
		

	}
	else Fahrzeug::setV(v);
}

FlugBoot::FlugBoot()
{
	COUT("FlugBoot erzeugt");
}
Flugzeug::Flugzeug():Fahrzeug (0)
{
	COUT("Flugzeug erzeugt!");
}

Flugzeug::~Flugzeug()
{
	COUT("Flugzeug zerstoert");
}

void Flugzeug::fliegen()
{
	COUT("Fahrzeug fliegt");
}




double FlugBoot::getV()
{
	// return v; // geht nicht, mehrdeutiges Attribut (FlugBoot::v)
					// Es werden zwei Basisklassen erzeugt => 2 mal Fahrzeug
	return Fahrzeug::getV();
	
}

void FlugBoot::fahren()
{
	COUT("FlugBoot faehrt, v = " << getV());
}

 FlugBoot::~FlugBoot()
{
	COUT("FlugBoot zerstoert");
}
