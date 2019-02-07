

/*======================================================================================================
'.ccp' datei zu klasse 'rechteck'
======================================================================================================*/

// === include ===

#include <iostream>
#include <string>
using namespace std;


#include "Rahmen.h"

#define TAB	cout << "\t"
#define COUT(x) cout << x << endl


// === defidition der methoden ===





Rechteck::Rechteck()
{
	laenge = 1;
	breite = 1;

	COUT("Rechteck erstellt");
}

Rechteck::Rechteck(double l, double b)
{
	setAbmessungen(l, b);
	COUT("Rechteck erstellt");
	/// was ist wenn werte ungültig
	/// erstellen abbrechen!!!???
}

Rechteck::~Rechteck()
{
	COUT("Rechteck zerstoert");
}

void Rechteck::setAbmessungen(double l, double b)
{
	if (l > 0 && b > 0)
	{
		laenge = l;
		breite = b;
		COUT("Abmesungen von Rechteg gesetzt:"); TAB;
		COUT("Laenge = " << laenge << "Breite = " << breite);
	}
	else COUT("Werte ungueltig!!");
}

double Rechteck::getFlaeche()
{
	return flaeche = laenge * breite;
}

double Rechteck::getUmfang()
{
	umfang = 2 * laenge + 2 * breite;
	return umfang;
}

Quader::Quader()
{
	COUT("Quader erstellt");
}

Quader::Quader(double l, double b, double h) : Rechteck(l, b)
{
	setHoehe(h);
	COUT("Quader erstellt");

}

Quader::~Quader()
{
	COUT("Quader zerstört");
}

void Quader::setHoehe(double h)
{
	if (hoehe > 0)
	{
		hoehe = h;
	}
	else COUT("Wert ungueltig!!");
}

double Quader::getVolumen()
{
	return (getFlaeche() * hoehe);
}

Rahmen::Rahmen(double li, double bi, double la, double ba)
{
	innen.setAbmessungen(li, bi);
	aussen.setAbmessungen(la, ba);
	COUT("Rahmen erstellt")
}

Rahmen::~Rahmen()
{
	COUT("Rahmen zerstoert");
}

double Rahmen::getFlaeche()
{
	double rahmenF = aussen.getFlaeche() - innen.getFlaeche();
	return rahmenF;
}
