


/*======================================================================================================
'.ccp' Datei zu Klasse 'Rechteck'
======================================================================================================*/

// === INCLUDE ===

#include "Hund.h"

#include <stdio.h>

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

// --- static Vaariable definieren ---
int Hund::anzahl = 0;

// === DEFIDITION DER METHODEN ===

int Hund::getAnzahl()
{
	return anzahl;
}

Hund::Hund(string name)
{
	anzahl++;
	this->name = name;	// !!!!
	cout << "Hund " << this->name << " geboren" << endl;
	papaHund = nullptr;	// NULL Pointer
	babyHund = nullptr;
}

Hund::~Hund()
{
	anzahl--;
	cout << "Hund " << this->name << " gestorben" << endl;
	if (babyHund != nullptr)	// baby ist da	// 'NULL'
	{
		delete(babyHund);	// töte Baby
		babyHund = nullptr;
	}
}

string Hund::getName()
{
	return name;
}
void Hund::papaBekommtBaby(string name)
{
	if (babyHund == nullptr)	// noch kein Baby
	{
		babyHund = new Hund(name);
		babyHund->setPapaHund(this);	// ??
	}
	//babyHund->papaHund = this;	// ?!?
}
void Hund::setPapaHund(Hund* deinPapa)
{
	papaHund = deinPapa;
}
Hund* Hund::getBabyHund()
{
	return babyHund;
}
