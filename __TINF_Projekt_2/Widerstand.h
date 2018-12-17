#pragma once

class Widerstand
{
private:
	double	r, // Widerstand in Ohm
			u, // Spannung in V
			i, // Strom in A
			p; // Leistung in W
	static int anzahl;

public:
	Widerstand();			// Standard Konstruktor
	~Widerstand();			// Standard Destruktor
	Widerstand(double wid);	// Überladener Individual Konstruktor
	Widerstand(double wid, double sp);	// "-"

	static int getAnzahl(void);

	void setR(double r);	// Widerstand setzen
	void setU(double sp);	// Spannung setzen
	double getI(void);		// Stom berechnen
	double getP(void);		// Leistung berechnen
};

