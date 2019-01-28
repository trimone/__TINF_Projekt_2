#pragma once

// --- Abstrakte Basisklasse ---
class GeoObjekt
{
private:
	int xPos;
	int yPos;
	static int anzahl;

public:
	GeoObjekt(int x, int y);
	virtual ~GeoObjekt();	// wenn 'virtual' Methoden, dann immer 'virtual'-Destruktor

	int getX();
	int getY();

	static int getAnzahl();
	void setKoo(int x, int y);	// Koordinaten setzen
	virtual void zeichne() = 0;	// rein virtuele Methode, rein abstrakte Basisklasse => keine Objekte von 'GeoObjekt' !!
};

class Kreis : public GeoObjekt
{
protected:
	double radius;

public:
	Kreis(double r, int x, int y);
	Kreis(double r);
	virtual void zeichne();
};

class Zylinder : public Kreis
{
private:
	double hoehe;

public:
	Zylinder(double r, double h, int x, int y);
	Zylinder(double r, double h);
	virtual void zeichne();
};

class Rechteck : public GeoObjekt
{
private:
	double laenge;
	double breite;

public:
	Rechteck(double l, double b, int x, int y);
	Rechteck(double l, double b);
	virtual void zeichne();

};