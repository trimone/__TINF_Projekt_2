#pragma once

// === BASISKLASSE ===
class Fahrzeug
{

private:	// abgeleitete Klassen haben Zugriff
	double v;

protected:	// abgeleitete Klassen haben Zugriff
	int farbe;


public:
	Fahrzeug(int f);
	~Fahrzeug();

	void fahren();
	void setV(double geschwindigkeit);
	double getV();
};

// === ABGELEITETE KLASSEN ===
// erben von Basisklasse

class Auto : public Fahrzeug
{
public:
	Auto(int f);
	~Auto();

	void autoFahren();
};

class Schiff : public Fahrzeug
{
	Schiff(int f);
	~Schiff();

	void schwimmen();
};
