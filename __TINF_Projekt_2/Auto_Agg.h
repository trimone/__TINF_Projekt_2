#pragma once

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

class Fahrzeugschein : public Auto_Agg
{
private:
	int nr;
public:
	Fahrzeugschein();
	~Fahrzeugschein();
	int getNr();

};





class Auto_Agg
{
private:
	// Komposition
	Fahrzeugbrief brief;	// muss vorher definiert werden!
	// Komponente wird automatisch erzeugt, wenn Objekt der zusammengesetzten Klasse (Auto) erzeugt wird.
	// Konstruktoren mit Parametern der Komponeten Klasse können nicht genutzt werden
	
	Fahrzeugschein* schein;	// dynamisch Komponenten werden in der zusammengesetzten Klasse erzeugt 
	int nr;
public:
	Auto_Agg(int nr);
	~Auto_Agg();

	void anmelden();
	void abmelden();
};





