/*======================================================================================================
'.ccp' Datei zu Klasse 'Kreis'
======================================================================================================*/

// === INCLUDE ===
#include <stdio.h>
#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

#define _USE_MATH_DEFINES
#include <math.h>

#include "Kreis.h"

double Kreis::calUmfang(double r)
{
	umfang = 2 * M_PI * r;
	return umfang;
}

double Kreis::calFlaeche(double r)
{
	flaeche = M_PI * (radius * radius);
	return flaeche;
}

//double calRadius(double)
//{
//	u / (2 * M_PI)
//		sqrt(f / M_PI)
//}
bool Kreis::setRadius(double r) 
{
	bool ok = false;

	if (r >= 0)
	{
		radius = r;
		ok = true;
		calUmfang(radius);
		calFlaeche(radius);
	}
	else {
		cout << endl << "Uebergebener Wert ungueltig!" << endl;
	}

	return ok;
}

double Kreis::getRadius()
{
	return radius;
}
bool Kreis::setUmfang(double u)
{
	bool ok = false;
	if (setRadius(u / (2 * M_PI)))	// Zuerst wird der Radius berechnet, 
									// in 'setRadius()' wird abgefragt, ob gültige Werte übergeben wurden
	{
	//umfang = u;
	//radius = u /( 2 * M_PI );
	//calFlaeche(radius);
	ok = true;
	}

	return ok;
}
double Kreis::getUmfang()
{
	return umfang;

}
bool Kreis::setFlaeche(double f)
{
	bool ok = false;

	if (setRadius(sqrt(f / M_PI)))
	{
		//flaeche = f;
		//radius = u /( 2 * M_PI );
		//calUmfang(radius);
		ok = true;
	}

	return ok;

}
double Kreis::getFlaeche()
{
	return flaeche;
}

void Kreis::ausgabe()
{
	cout << "\t Radius: " << radius << endl
		<< "\t Umfang: " << umfang << endl
		<< "\t Flaeche: " << flaeche << endl;

}

// --- Konstruktoren 
Kreis::Kreis(void)
{
	radius = 0;
	umfang = 0;
	flaeche = 0;

	// setRadius(0);	// oder nur die Methode

}

Kreis::Kreis(double r)
{
	setRadius(r);
}

// --- Destruktoren ---
Kreis::~Kreis()
{
	cout << "Kreis mit Radius " << radius << " zerstoert" << endl;
	/*
	Anweisungen, die ausgeführt werden sollen, wenn ein Objekt der Klasse zerstört werden soll*/
}



