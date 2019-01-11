#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Fahrzeug.h"

#define LOG(x) cout << x << endl;


int Fahrzeug::anzahl = 0;	// Speicherbeschaffung für 'static'-Variable

double Fahrzeug::getAnzahl()
{
	return anzahl;		// hier dürfen nur 'static'-Variablen verwenden
}


Fahrzeug::Fahrzeug(double vMax)
{
	anzahl++;
	LOG("Fahzeug erzeugt");

	this->v = 0;
	this->vMax = vMax;
}


Fahrzeug::~Fahrzeug()
{
	anzahl--;
	LOG("Fahzeug zerstört");
}

void Fahrzeug::fahren()
{
	cout << endl << "Fahzeug faehrt mit Geschwindigkeit v = " << getV();
}

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
	LOG("Auto faehrt!");
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

	LOG("Schiff erzeugt");
}

Schiff::~Schiff()
{
	LOG("Schiff zerstoert");
}


void Schiff::schwimmen()
{
	cout << endl << "Schiff schwimmt mit Geschwindigkeit v = " << getV();

}

void Schiff::fahren()
{
	LOG(" Schiff schwimmt");
}

U_Boot::U_Boot(double vMax, double brt, double vMaxG):Schiff(vMax,brt)
{
	this->vMaxG = vMaxG;
	getaucht = false;
	LOG("UBoot erzeugt");
}

U_Boot::~U_Boot()
{
	LOG("UBoot zerstoert");
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
