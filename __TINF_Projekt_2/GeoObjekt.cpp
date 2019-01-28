#include "GeoObjekt.h"

#include <iostream>
#include <string>
using namespace std;

#define TAB	cout << "\t"
#define COUT(x) cout << x << endl

int GeoObjekt::anzahl = 0;


GeoObjekt::GeoObjekt(int x, int y)
{
	anzahl++;
	xPos = x;
	yPos = y;
	//zeichne(); // hier kann keine rein-virtuele Methode aufgerufen werde !! (Da noch kein Objekt vorhanden)
}


GeoObjekt::~GeoObjekt()
{
	anzahl--;
}

int GeoObjekt::getX()
{
	return this->xPos;
}

int GeoObjekt::getY()
{
	return this->yPos;
}

int GeoObjekt::getAnzahl()
{
	return anzahl;
}

void GeoObjekt::setKoo(int x, int y)
{
	if (xPos != x || yPos != y)
	{
	xPos = x;
	yPos = y;
	zeichne();
	}
}

Kreis::Kreis(double r, int x, int y) : GeoObjekt(x,y)
{
	if (r >= 0)
		radius = r;
	else radius = 0;
}

Kreis::Kreis(double r) : GeoObjekt(0,0)
{
	if (r >= 0)
		radius = r;
	else radius = 0;
}

void Kreis::zeichne()
{
	COUT("Kreis gezeichnet an Position x = " << getX() << " y = " << getY() << " mit Radius = " << this->radius);
}

// === Zylinder ===

Zylinder::Zylinder(double r, double h, int x, int y) : Kreis(r,x,y)
{
	if (h >= 0)
		hoehe = h;
	else hoehe = 0;
}

Zylinder::Zylinder(double r, double h) : Kreis(r)
{
	if( h >= 0)
		hoehe = h;
	else hoehe = 0;
}

void Zylinder::zeichne()
{
	COUT("Zylinder gezeichnet an Position x = " << getX() << " y = " << getY() 
		<< " mit Radius = " << this->radius << " und Hoehe = " << this->hoehe);

}

// === Rechteck ===

Rechteck::Rechteck(double l, double b, int x, int y) : GeoObjekt(x,y)
{
	laenge = l;
	breite = b;
}

Rechteck::Rechteck(double l, double b) : GeoObjekt(0,0)
{
	laenge = l;
	breite = b;
}

void Rechteck::zeichne()
{
	COUT("Rechteck gezeichnet an Position x = " << getX() << " y = " << getY() 
		<< " mit Laenge = " << this->laenge << " und Breite = " << this->breite);

}
