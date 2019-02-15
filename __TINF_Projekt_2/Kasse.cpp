

/*======================================================================================================
'.ccp' Datei zu Klasse 'Rechteck'
======================================================================================================*/

// === INCLUDE ===

#include <iostream>
#include <string>
using namespace std;


#define TAB	cout << "\t"
#define COUT(x) cout << x << endl
#define ZETTEL(name , preis) cout << "\t" << name << "\t" << preis << " Euro" << endl


#include "Kasse.h"


// === DEFIDITION DER METHODEN ===

Kasse::Kasse()
{
	anzahl = 0;

	/*for (int i = 0; i < 1000; i++)
	{
		
		einkauf[i] = nullptr;
		
	}*/
}


Kasse::~Kasse()
{
	
	for(int i = 0; i < anzahl; i++)
	{
		delete einkauf[i];
		einkauf[i] = nullptr;
		COUT("putput");
	}
	//anzahl = 0;
	
}

void Kasse::gepackteWare()
{
	einkauf[anzahl] = new GepackteWare;
	einkauf[anzahl]->einlesen();
	anzahl++;
}

void Kasse::loseWare()
{
	einkauf[anzahl] = new LoseWare;
	einkauf[anzahl]->einlesen();
	anzahl++;
}

void Kasse::kassenZettelAusgeben()
{
	double gesPreis = 0;
	COUT("==== KASSENZETTEL ====");
	COUT("\tArtikel:" << "\t Preis:");
	for (int i = 0; i < anzahl; i++)
	{
		ZETTEL(einkauf[i]->getBezeichnung(), "\t" << einkauf[i]->getPreis());
		gesPreis += einkauf[i]->getPreis();
	}
	COUT("_________________");
	COUT("Gesammt: \t\t" << gesPreis << " Euro");
}

Produkt::Produkt()
{
	
	setBezeichnung(" ");
}
void Produkt::setBezeichnung(string bez)
{
	bezeichnung = bez;
}

string Produkt::getBezeichnung()
{
	return bezeichnung;
}

void Produkt::einlesen()
{
	COUT("Bezeichnung fuer Artikel eingeben:");
	TAB;
	cin >> bezeichnung;
}

void Produkt::ausgeben()
{
	COUT("Artikelbezeichnung: " << bezeichnung);
}

LoseWare::LoseWare()
{
	setKiloPreis(0.0);
	setGewicht(0.0);

}

void LoseWare::setKiloPreis(double kp)
{
	if (kp > 0)
	{
		kiloPreis = kp;
	}
}

double LoseWare::getKiloPreis()
{
	return kiloPreis;
}

void LoseWare::setGewicht(double kg)
{
	if (kg >= 0)
	{
		gewicht = kg;
	}
}

double LoseWare::getGewicht()
{
	return gewicht;
}

void LoseWare::einlesen()
{
	string bez;
	double preis, kg;

	COUT("Bezeichnung fuer Artikel eingeben:");
	TAB;
	cin >> bez;
	setBezeichnung(bez);

	COUT("Preis pro Kilo: "); TAB;
	cin >> preis;
	setKiloPreis(preis);

	COUT("Gewicht: "); TAB;
	cin >> kg;
	setGewicht(kg);
}

void LoseWare::ausgeben()
{
	COUT("Artikel: " << getBezeichnung() << "Preis: " << getPreis());
}

double LoseWare::getPreis()
{
	return (kiloPreis * gewicht);
}

GepackteWare::GepackteWare()
{
	setPreis(0);
}

void GepackteWare::setPreis(double p)
{
	if (p > 0)
	{
		preis = p;
	}
}

void GepackteWare::einlesen()
{
	string bez;
	double preis;

	COUT("Bezeichnung fuer Artikel eingeben:");
	TAB;
	cin >> bez;
	setBezeichnung(bez);

	COUT("Preis: "); TAB;
	cin >> preis;
	setPreis(preis);
}

void GepackteWare::ausgeben()
{
	COUT("Artilel: " << getBezeichnung() << "Preis: " << getPreis());
}

double GepackteWare::getPreis()
{
	return preis;
}
