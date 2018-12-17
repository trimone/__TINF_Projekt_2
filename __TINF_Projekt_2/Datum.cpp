

#include <stdio.h>
			
#include <string.h>				// für String Funktionen

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

//#include <ctype.h>

#include "Datum.h"

// === DEFIDITION DER METHODEN ===
// Zwegs der übersichtilichkeit werden die Methoden ausgelagert

// 'Datum::' ==> Methode gehört zu Klasse
bool Datum::setDatum(int t, int m, int j)
{
	bool ok = false;
	setJahr(j);
	if (setMonat(m))	// liefert 'true' wenn Monat gesetzt wurde
		if (setTag2(t))	// liefert 'true' wenn Tag gesetzt wurde
			ok = true;
	/* // alternative
	if(setMonat(m) && (setTag2(t))
	ok = true;
	*/
	return ok;
}
void Datum::einlesen(void)	
{
	int t, m, j;
	cout << endl << "Tag eingeben: ";
	cin >> t;
	cout << endl << "Monat eingeben: ";
	cin >> m;
	cout << endl << "Jahr eingeben: ";
	cin >> j;

	if (!setDatum(t, m, j))
	{
		cout << "Fehler" << endl;
	}
}

void Datum::ausgeben(void)
{
	cout << endl << "Datum:" << endl << tag << "." << monat << "." << jahr;
}

void Datum::setJahr(int j)	// setzt das 'jahr' auf den übergeben Wert
{
	jahr = j;
}

int Datum::getJahr()	// gibt den Wert von 'jahr' zurück
{
	return jahr;
}

bool Datum::setMonat(int m)
{
	bool ok = false;
	if (m > 0 && m <= 12)
	{
		/*if (m == 2 && (tag != 31 || tag != 30))

			if (!hat_monat31(m) && tag != 31)*/
				monat = m;
				ok = true;
	}
	/*else
	cout << endl << "Monat ungueltig";*/
	return ok;
}

int Datum::getMonat()
{
	return monat;
}

int Datum::getTag()
{
	return tag;
}

void Datum::setTag(int t)
{
	if (monat == 2)
	{
		checkSchalt();
		if (sj == true && (t > 0 && t <= 29))	// falls Schaltjahr und kleiner gleich 29
			tag = t;
		else if (sj == false && (t > 0 && t <= 28))	// falls kein Schaltjahr und kleiner gleich 28
			tag = t;
	}
	else if (hat_monat31(monat))
	{
		if (t > 0 && t <= 31)
			tag = t;
	}
	else
	{
		if (t > 0 && t <= 30)
			tag = t;
	}
}

bool Datum::setTag2(int t)
{
	bool ok = false;
	int maxTag = 31;

	switch (monat)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		maxTag = 30;
		break;
	case 2:
		if (checkSchalt())
		{
			maxTag = 29;
		}
		else maxTag = 28;
		break;
	}

	if (t <= maxTag && t>0)	// ist gültiger Tag
	{
		tag = t;
		ok = true;
	}

	return ok;
}

bool Datum::checkSchalt()
{
	// if ( ( (jahr%4==0) && (jahr%100!=0) ) || (jahr%400==0) ) 
	sj = false;
	if (jahr % 4 == 0)	// Ein Jahr ist ein Schaltjahr, wenn es restlos durch 4 teilbar ist.
	{
		if (jahr % 100 == 0)	// Falls sich die Jahrzahl durch 100 restlos teilen lässt, ist es kein Schaltjahr.
			sj = false;

		else sj = true;
	}
	if (jahr % 400 == 0)	// Falls auch eine Teilung durch 400 ganzzahlig möglich ist, dann ist es ein Schaltjahr.
		sj = true;

	return sj;
}

bool Datum::hat_monat31(int m)
{
	bool m31;
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && m != 2)
	{
		m31 = true;
	}
	else
		m31 = false;

	return m31;
}
