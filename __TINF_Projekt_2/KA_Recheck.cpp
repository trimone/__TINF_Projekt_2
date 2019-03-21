/*
=== ALEX HUBER === FTED2 ==== 15.02.2019 ====
=== KA2 === C++ Programmierung ==============
=== Recheck.cpp =============================
*/

#include "KA_Rechteck.h"

// === Klasse Position ===

// Konstruktor
Position::Position()
{
	this->x = 0;
	this->y = 0;
}

// setz die Position vom Objekt
bool Position::setPosition(double x, double y)
{
	bool ok = false;
	if (x >= 0 && y >= 0)
	{
		ok = true;
		this->x = x;
		this->y = y;		
	}
	return ok;
}

// Positionswerte zur�ckgeben
double Position::getX()
{
	return this->x;
}
double Position::getY()
{
	return this->y;
}

// === Klasse Rechteck ===
// Konstruktor
KA_Rechteck::KA_Rechteck(void)
{
	this->breite = 1;
	this->laenge = 1;
}

/* // wird nicht ben�tigt
Rechteck::~Rechteck(void)
{

}*/

// Setz Abmessungen
bool KA_Rechteck::setAbmesseungen(double l, double b)
{
	bool ok = false;
	if (l >= 0 && b >= 0)
	{
		laenge = l;
		breite = b;
		ok = true;
	}

	return (ok);
}

// Gibt Fl�che zur�ck
double KA_Rechteck::getFlaeche()
{
	return (laenge * breite); // Berechnung der Fl�che
}

// Gibt Umfang zur�ck
double KA_Rechteck::getUmfang()
{
	return (2 * (laenge + breite)); // Berechnung des Umfangs
}

// === Klasse Quader ===

// Standart Konstuktor
KA_Quader::KA_Quader()
{
	// Default Werte setzen
	setAbmesseungen(1.0, 1.0);
	setHoehe(1.0);
}

// Individual Konstruktor
KA_Quader::KA_Quader(double l, double b, double h, double x, double y)
{
	// Werte an Methoden �bergeben
	setAbmesseungen(l, b);
	setHoehe(h);
	pos.setPosition(x, y); // Position �ber Objekt 'pos'
}

// H�he vom Quader setzen
bool KA_Quader::setHoehe(double h)
{
	bool ok = false;
	if (h >= 0)
	{
		hoehe = h;
		ok = true;
	}

	return (ok);
}

// Gibt Volumen zur�ck
double KA_Quader::getVolume()
{
	return (getFlaeche() * hoehe); // Berechnung des Volumen
}

Position KA_Rechteck::getPosition(void)
{
	return (pos);	// gibt das Objekt zur�ck
}