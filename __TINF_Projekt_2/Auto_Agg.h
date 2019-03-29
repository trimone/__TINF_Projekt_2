#pragma once

#include <iostream>
#include <string>
using namespace std;

/// !!!
// Automatisch erzeugte Komponenten Objekte müssen vor der zusammengesetzten Klasse definiert  werden !!

class Fahrer;


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
	// Konstruktoren mit Parametern der Komponenten Klasse können nicht genutzt werden
	// im Konstruktor
	Fahrzeugschein* schein;	// dynamisch Komponenten werden in der zusammengesetzten Klasse erzeugt 
							// wird nicht automatisch erzeugt, erst beim 'anmelden()'
							// muss im ~Destruktor wieder löschen
							// doppeltes anmelden vermeiden
	// Aggregation
	Motor* mot;

	// Assoziation
	Fahrer* meinFahrer;	
public:
	Auto_Agg(int nr);
	Auto_Agg(Motor* mot, int nr);	// Aggregation: dem Konstruktor wird ein Objekt aus 'main()' übergeben
									// Objekt 'Auto' hat Zugriff auf 'Motor'
	~Auto_Agg();

	void anmelden();
	void abmelden();

	void motorAusbauen();
	void motorEinbauen(Motor* mot);

	// Assoziation
	void bemannen(Fahrer* meinFahrer);	// stellt Assoziation her
	void fahren(void);
	void verlassen(void);	// Assoziation lösen
};


class Fahrer
{
private:
	string name;
	Auto_Agg* meinAuto;	// ungerichtet Assoziation. Bindung hält länger als nur eine Methode
public:
	Fahrer(string name);
	//Fahrer(const char* str);
	//~Fahrer();

	void fahren(Auto_Agg* meinAuto);	// stellt Assoziation her
	void aussteigen(void);	// Assoziation lösen
	string getName(void);

};




