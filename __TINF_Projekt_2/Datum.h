#pragma once	// Pr� dadurch werden Dateien nur einmal eingef�gt, falls doppelte includes, nicht genormt

// falls Compiler '#pragma once' nicht kennt
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

class Datum {
// --- ATTRIBUTE ---
private:
	int tag = 1;
	int monat = 1;
	int jahr = 2018;
	bool sj;

// --- METHODEN ---		==> Nur Prototypen in der Headerdatei
private:
	bool checkSchalt();
	bool hat_monat31(int m);
	void setJahr(int j);	// setzt das 'jahr' auf den �bergeben Wert
	bool setMonat(int m);
	bool setTag2(int t);
	void setTag(int t);

public:
	void einlesen(void);
	void ausgeben(void);
	int getJahr();		// gibt den Wert von 'jahr' zur�ck
	int getMonat();
	int getTag();
	bool setDatum(int t, int m, int j);
};


//#endif