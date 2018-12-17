/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018

KLASSE:	Kreis
		Berechnet Radius, Umfang und Fläche von einem Kreis
		Radius, Umfang und Fläche können einzelnd geändert werden, der Rest wird automatisch berechnet
======================================================================================================*/

#pragma once


// === Klasse Kreis ===

class Kreis {

// --- ATTRIBUTE ---
private:
	double radius;
	double umfang;
	double flaeche;

// --- METHODEN ---		==> Nur Prototypen in der Headerdatei
private:
	double calUmfang(double r);
	double calFlaeche(double r);
	double calRadius(double r);
public:	
	// Konstruktor // ==> Konstruktor wird automatisch aufgerufen | NIE SELBER AUFRUFEN !!!
	Kreis(void);		// Standartkonstruktor ohne Übergabeparameten
	Kreis(double r);	// Individualkonstruktor // 'kreis2(5)' ==> 'r = 5' 
						//wenn mit Übergabewert wird Individualkostruktor automatisch aufgerufen

	// Destruktor	// wird ausgeführt, wenn Speicherplatz freigegeben wird
					// 
	~Kreis();

	bool setRadius(double r);
	double getRadius();
	bool setUmfang(double u);
	double getUmfang();
	bool setFlaeche(double f);
	double getFlaeche();
	void ausgabe();
};

