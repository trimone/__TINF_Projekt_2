#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Fahrzeug.h"



Fahrzeug::Fahrzeug(int f)
{
	cout << endl << "Fahzeug erzeugt";
}


Fahrzeug::~Fahrzeug()
{
	cout << endl << "Fahzeug zerstört";
}

void Fahrzeug::fahren()
{
	cout << endl << "Fahzeug faehrt mit Geschwindigkeit v = " << this->v;
}

void Fahrzeug::setV(double geschwindigkeit)
{
	v = geschwindigkeit;
}

double Fahrzeug::getV()
{
	return this->v;
}

// === METHODEN FÜR ABGELEITET KLASSEN ===

// --- Auto --
Auto::Auto(int f): Fahrzeug(f)
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
Schiff::Schiff(int f):Fahrzeug(f)
{
	cout << endl << "Schiff erzeugt";
}

Schiff::~Schiff()
{
	cout << endl << "Schiff zerstoert";
}


void Schiff::schwimmen()
{
	cout << endl << "Schiff schwimmt mit Geschwindigkeit v = " << getV();

}