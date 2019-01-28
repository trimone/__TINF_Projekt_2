#pragma once

// === BASISKLASSE ===
class Fahrzeug
{

private:	// abgeleitete Klassen haben keinen Zugriff
	
	static int anzahl;

protected:	// abgeleitete Klassen haben Zugriff
	int farbe;
	double v;
	double vMax;

public:
	Fahrzeug(double vMax);
	Fahrzeug();
	virtual ~Fahrzeug();
	//void fahren();
	
	virtual void fahren() = 0;	// rein virtuelle Methode ( keine Definition in .cpp notwendig/ nicht erlaubt)
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

class Schiff : virtual public Fahrzeug
{
private:
	double brt;	

public:
	Schiff(double vMax, double brt);
	Schiff();
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
	//U_Boot();
	~U_Boot();
	void tauchen();
	void auftauchen();
	void setV(double v);
};


// === Mehrfachvererbung ===

class Flugzeug : virtual public Fahrzeug
{
public:
	Flugzeug();
	virtual ~Flugzeug();
	void fliegen();
};

class FlugBoot : virtual public Flugzeug, 
				virtual public Schiff	// Keine Mehrdeutigkeit, 'late binding' => Attributwerte von letzter Vererbung
{
public:
	FlugBoot();
	virtual ~FlugBoot();
	double getV();
	virtual void fahren();
};

//class FlugBoot : public Flugzeug, public Schiff	// erbt von zwei Klassen!!
//{
//public:
//	double getV();
//};