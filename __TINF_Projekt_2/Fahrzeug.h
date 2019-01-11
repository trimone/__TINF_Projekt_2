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
	virtual ~Fahrzeug();

	virtual void fahren();
	bool setV(double v);
	double getV();
	
	static double getAnzahl();
};

// === ABGELEITETE KLASSEN ===
// erben von Basisklasse

class Auto : public Fahrzeug
{
public:
	Auto(double v);
	virtual ~Auto();

	void autoFahren();
	virtual void fahren();
};

class Schiff : public Fahrzeug
{
private:
	double brt;	

public:
	Schiff(double vMax, double brt);
	virtual ~Schiff();

	void schwimmen();
	virtual void fahren();
};


class U_Boot : public Schiff
{
private:
	bool getaucht;
	double vMaxG;

public:
	U_Boot(double vMax, double brt, double vMaxG);
	~U_Boot();
	void tauchen();
	void auftauchen();
	void setV(double v);
};