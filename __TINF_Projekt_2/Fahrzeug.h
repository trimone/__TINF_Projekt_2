#pragma once

// === BASISKLASSE ===
class Fahrzeug
{

private:	// abgeleitete Klassen haben keinen Zugriff
	double v;
	double vMax;
	static int anzahl;

protected:	// abgeleitete Klassen haben Zugriff
	int farbe;


public:
	Fahrzeug(double vMax);
	~Fahrzeug();

	void fahren();
	bool setV(double v);
	double getV();
	
	static double getAnzahl();
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
private:
	double brt;

public:
	Schiff(double vMax, double brt);
	~Schiff();

	void schwimmen();
};


class U_Boot : public Schiff
{
private:
	bool getaucht;
	double vMaxG;

public:
	U_Boot(double vMax, double brt, double vMaxG);
	void tauchen();
	void auftauchen();
	void setV(double v);
};