#include "Widerstand.h"

#include <stdio.h>

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

int Widerstand::anzahl = 0;		// -> Speicherplatz reservieren | Deklaration der Klassenvariable und Initialisierung in '.ccp'
int Widerstand::getAnzahl(void)
{
	return anzahl;
}

Widerstand::Widerstand()
{
	r = 0;
	u = 0;
	i = 0;
	p = 0;
	anzahl++;

	cout << "Objekt mit Widerstand R =  " << r << " Ohm erstellt!" << endl;

}


Widerstand::~Widerstand()
{
	
	anzahl--;
	cout << "Objekt mit Widerstand R = " << r << " Ohm zerstoert!" << endl;
	/*
	Anweisungen, die ausgeführt werden sollen, wenn ein Objekt der Klasse zerstört werden soll*/
}


Widerstand::Widerstand(double wid)
{
	u = 0;
	setR(wid);
	anzahl++;	
	cout << "Objekt mit Widerstand R =  " << r << " Ohm erstellt!" << endl;

}
Widerstand::Widerstand(double wid, double sp)
{
	u = sp;
	setR(wid);
	//setU(sp);

	anzahl++;
	cout << "Objekt mit Widerstand R = " << r << "  Ohm & Spannung U = " << u << " V erstellt!" << endl;

}
void Widerstand::setR(double r)
{
	if (r > 0)
	{
		// r = wid; 
		this->r = r;	// Attribut r = lokale Variable r
		i = u / r;		// eig muss 'this->r' hin		
		p = u * i;
	}
	else 
	{
		this->r = 0;	// !!!
		i = 0;
		p = 0;
	}

}
void Widerstand::setU(double sp)
{
	u = sp;
	if (r > 0)
	{ 
		i = u / r;
		p = u * i;
	}
	else
	{
		i = 0;
		p = 0;
	}

}
double Widerstand::getI(void)
{	
	return i;
}
double Widerstand::getP(void)
{
	return p;
}