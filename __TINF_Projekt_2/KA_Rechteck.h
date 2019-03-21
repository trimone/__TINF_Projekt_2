#pragma once
	/*
=== ALEX HUBER === FTED2 ==== 15.02.2019 ====
=== KA2 === C++ Programmierung ==============
=== Rechteck.h ==============================
*/

#pragma once

// === Klasse Position ===
class Position
{
private:
	double x;
	double y;
public:
	Position();
	bool setPosition(double x, double y);	// besser mit bool ruturn Wert
	double getX();
	double getY();
};

// === Klasse Rechteck ===
class KA_Rechteck
{
protected:
	Position pos; // Komposition

private:
	double laenge;
	double breite;

public:
	KA_Rechteck(void);
	//~Rechteck(void);

	bool setAbmesseungen(double l, double b);
	double getFlaeche();
	double getUmfang();

	Position getPosition(void);	// Objekt als return value
};

// === Klasse Quader ===
class KA_Quader : public KA_Rechteck	// erbt von Rechteck
{
private:
	double hoehe;
public:
	KA_Quader();
	KA_Quader(double l, double b, double h, double x, double y);
	
	bool setHoehe(double h);
	double getVolume();
};



