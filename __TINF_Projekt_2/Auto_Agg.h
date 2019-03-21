#pragma once

#include <string>

/// !!!
// Automatisch erzeugte Komponenten Objekte müssen vor der zusammengesetzten Klasse definiert  werden !!



class Fahrzeugbrief
{
private:
	int nr;
public:
	Fahrzeugbrief();
	~Fahrzeugbrief();

	void setNr(int nr);
	int getNr();
};

class Fahrzeugschein 
{
private:
	int nr;
public:
	Fahrzeugschein();
	~Fahrzeugschein();
	int getNr();

};

class Motor
{
private:
	int ps;
	bool _eingebau;
public:
	Motor(int ps);
	~Motor();
	int getPS();

	// Doppelte verwendung von Motor verhindert
	bool getEingebaut();
	void setEingebaut(bool e);
};




class Auto_Agg
{
private:
	int nr;
	bool angemeldet;

	// Komposition
	Fahrzeugbrief brief;	// muss vorher definiert werden!
	// Komponente wird automatisch erzeugt, wenn Objekt der zusammengesetzten Klasse (Auto) erzeugt wird.
	// Konstruktoren mit Parametern der Komponeten Klasse können nicht genutzt werden
	// im Konstruktor
	Fahrzeugschein* schein;	// dynamisch Komponenten werden in der zusammengesetzten Klasse erzeugt 
							// wird nicht autoatisch erzeugt, erst beim 'anmelden()'
							// muss im ~Destruktror wieder löschen
							// doppeltes anmelden vermeiden
	// Aggregatation
	Motor* mot;
public:
	Auto_Agg(int nr);
	Auto_Agg(Motor* mot, int nr);	// Aggregation: dem Konstruktor wird ein Objekt aus 'main()' übergeben
									// Objekt 'Auto' hat zugrief auf 'Motor'
	~Auto_Agg();

	void anmelden();
	void abmelden();

	void motorAusbauen();
	void motorEinbauen(Motor* mot);	

	void fahren(void);
};


class Fahrer
{
private:
	string name;
public:
	Fahrer(string* name);
	//~Fahrer();

	void fahren(Auto_Agg* meinAuto);
	string* getName(void);

};




