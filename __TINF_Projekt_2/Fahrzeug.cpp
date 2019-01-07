#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Fahrzeug.h"

int Fahrzeug::anzahl = 0;

Fahrzeug::Fahrzeug(double vMax)
{
	anzahl++;
	cout << endl << "Fahzeug erzeugt";

	this->v = 0;
	this->vMax = vMax;


}


Fahrzeug::~Fahrzeug()
{
	anzahl--;
	cout << endl << "Fahzeug zerstört";
}

void Fahrzeug::fahren()
{
	cout << endl << "Fahzeug faehrt mit Geschwindigkeit v = " << this->v;
}

bool Fahrzeug::setV(double v)
{
	if (v <= this->vMax)
	{
		this->v = v;		
	}
	else
		this->v = vMax;

	return true;
}

double Fahrzeug::getV()
{
	return this->v;
}

double Fahrzeug::getAnzahl()
{
	return anzahl;
}

// === METHODEN FÜR ABGELEITET KLASSEN ===

// --- Auto --
Auto::Auto(int f): Fahrzeug(f)	// Konstruktoraufruf der Basisklasse
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

// --- Schiff ---
//Schiff::Schiff(int f):Fahrzeug(f)
//{
//	cout << endl << "Schiff erzeugt";
//}

Schiff::Schiff(double vMax, double brt):Fahrzeug(vMax)
{
	this->brt = brt;
}

Schiff::~Schiff()
{
	cout << endl << "Schiff zerstoert";
}


void Schiff::schwimmen()
{
	cout << endl << "Schiff schwimmt mit Geschwindigkeit v = " << getV();

}

U_Boot::U_Boot(double vMax, double brt, double vMaxG):Schiff(vMax,brt)
{
	this->vMaxG = vMaxG;
	getaucht = false;
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
