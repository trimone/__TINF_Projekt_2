#pragma once

/*======================================================================================================

NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018

KLASSE:	Recheck

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

// --- Basisklasse ---
class KopierKarte
{
// --- Attribute ---
private:
	bool ok;
	int pinEingabe;
	int pinNummer;

// --- Methoden --- 
public:
	KopierKarte();
	~KopierKarte();

	bool vergleiche();
	void setPinNummer(int NrP);
	int getPinNummer();
	void setPinEingabe(int NrP);
	int getPinEingabe();
	
};

// --- Abgeleitete Klasse ---

class ChipKarte:public KopierKarte // ':public Basisklasse' Vererbung!!
{
private: 
	int kontoStand;

public:
	ChipKarte();

	void setKontoStand(int k);
	int getKontoStand();
	bool kopieren();
};

