

/*======================================================================================================

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018

KLASSE:	Kasse

======================================================================================================*/

#pragma once	/*	Pr�prozessor Anweisung: 
dadurch werden Dateien nur einmal eingef�gt,
falls doppelte includes vorhanden sind, nicht genormt*/

/* // falls Compiler '#pragma once' nicht kennt, werden doppelte Include-Dateien wie folgt rausgefiltert
/*
#ifndef CLASSDATUM
#define CLASSDATUM
#endif // !CLASSDATUM
*/

// === KLASSE ===
/*
- Attribute und Methoden sind in einer 'Klasse' gekapselt
- Attribute sind f�r die Methoden zug�nglich (wie fr�her globale Variable)
- �bergabe und R�ckgabe sind nicht mehr zwingend notwendig*/


	
/*
//#endif	// */


class Produkt
{
private:
	string bezeichnung;

public:
	Produkt();
	void setBezeichnung(string bez);
	string getBezeichnung();
	virtual void einlesen();
	virtual void ausgeben();
	virtual double getPreis() = 0;

};

class LoseWare : virtual public  Produkt
{
private:
	double kiloPreis;
	double gewicht;

public:
	LoseWare();
	void setKiloPreis(double kp);
	double getKiloPreis();
	void setGewicht(double kg);
	double getGewicht();
	virtual void einlesen();
	virtual void ausgeben();
	virtual double getPreis();
};

class GepackteWare : virtual public Produkt
{
private:
	double preis;
	
public:
	GepackteWare();
	void setPreis(double p);
	virtual void einlesen();
	virtual void ausgeben();
	virtual double getPreis();
};


class Kasse
{
// --- ATTRIBUTE ---	Attribute => 'private'
private: 
	Produkt* einkauf[1000];	// Komposition
	int anzahl;

public:
	Kasse();
	~Kasse();
	void gepackteWare();
	void loseWare();
	void kassenZettelAusgeben();
};

