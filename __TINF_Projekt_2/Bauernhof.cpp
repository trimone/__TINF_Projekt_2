
/*======================================================================================================
'.ccp' Datei zu Klasse 'Bauernhof'
======================================================================================================*/

// === INCLUDE ===

#include <iostream>
#include <string>
using namespace std;

#define TAB	cout << "\t"
#define COUT(x) cout << x << endl


#include "Bauernhof.h"

Tier::Tier()
{
	gewicht = 1;
}

void Kuh::fressen(double kg)
{
	if (kg > 0)
	{
		gewicht += kg;
		COUT("Gewicht vom Kuh auf " << this->gewicht << " erhoeht");
	}
}

double Kuh::produzieren()
{
	double nutzen = 0;
	if (gewicht > 4.5)
	{
		nutzen = 4.5;
		this->gewicht -= nutzen;
	}
	return nutzen;
}

void Schwein::fressen(double kg)
{
	if (kg > 0)
	{
		gewicht += kg;
		COUT("Gewicht vom Schwein auf " << this->gewicht << " erhoeht");
	}
}

double Schwein::produzieren()
{
	double nutzen = 0;
	if (gewicht > 4.5)
	{
		nutzen = 4.5;
		this->gewicht -= nutzen;
	}
	return nutzen;
}

Bauernhof::Bauernhof()
{
	anzahlTier = 0;
	nutzen = 0.0;
	for(Tier* &tier : nutzTiere)
	{
		tier = nullptr;
	}

}


Bauernhof::~Bauernhof()
{
	anzahlTier = 0;
	for (Tier* &tier : nutzTiere)
	{
		delete tier;
		tier = nullptr;
	}
}

void Bauernhof::neuesTier(int art)
{
	if (anzahlTier < 200)
	{
		if (art == 0)
		{
			nutzTiere[anzahlTier] = new Kuh;
			anzahlTier++;
			COUT("Dem Bauernhof wurde eine Kuh hinzugefuegt");
		}
		else if (art == 1)
		{
			nutzTiere[anzahlTier] = new Schwein;
			anzahlTier++;
			COUT("Dem Bauernhof wurde ein Schwein hinzugefuegt");
		}
	}
	else { COUT("Maximale Anzahl an Nutztieren erreicht"); }
}

void Bauernhof::tiere_fuettern()
{
	for(auto tier : nutzTiere)
	{
		if(tier != nullptr)
		{
			tier->fressen(4.5);
			COUT("Tier hat gefressen");
		}
	}
}

void Bauernhof::produzieren()
{
	for (auto &tier : nutzTiere)
	{
		if (tier != nullptr)
		{
			nutzen += tier->produzieren();
			COUT("Tier hat produziert | Nutzen: " << nutzen);
		}
	}
}

void Bauer::hof_bekommen(Bauernhof* hof)
{
	if (meinHof != nullptr)
	{
		meinHof = hof;
	}
}

void Bauer::hof_bewirtschaften()
{
	if (meinHof != nullptr)
	{
		meinHof->tiere_fuettern();
		meinHof->produzieren();
	}
}

void Bauer::neuesTier(int art)
{
	if (meinHof != nullptr)
	{
		meinHof->neuesTier(art); 
	}
}
