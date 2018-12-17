

/*======================================================================================================
'.ccp' datei zu klasse 'rechteck'
======================================================================================================*/

// === Includes ===
#include "KopierKarte.h"	// header-datei der klasse einfügen


// === defidition der methoden ===

// Konstruktor der Basisklasse
KopierKarte::KopierKarte()
{
	setPinNummer(1234);
}


KopierKarte::~KopierKarte()
{
}

bool KopierKarte::vergleiche()
{
	if (getPinNummer() == getPinEingabe())
	{
		ok = true;
	}
	else
		ok = false;

	return ok;
}

void KopierKarte::setPinNummer(int NrP)
{
	this->pinNummer = NrP;
}

int KopierKarte::getPinNummer()
{

	return this->pinNummer;
}

void KopierKarte::setPinEingabe(int NrP)
{
	this->pinEingabe = NrP;
}

int KopierKarte::getPinEingabe()
{
	return this->pinEingabe;
}



ChipKarte::ChipKarte()
{
	setKontoStand(500);
}

void ChipKarte::setKontoStand(int k)
{
	kontoStand = k;
}

int ChipKarte::getKontoStand()
{
	return this->kontoStand;
}

bool ChipKarte::kopieren()
{
	bool ok;
	if (vergleiche() && kontoStand != 0)
	{
		this->kontoStand--;
		ok = true;
	}
	else
		ok = false;
	return ok;
}
