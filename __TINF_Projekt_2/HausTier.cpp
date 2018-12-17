#include "HausTier.h"

#include <iostream>
#include <string>
using namespace std;


int HausTier::anzahl = 0;	// SUPER WICHTG!!!

int HausTier::getAnzahl()		// 'static' löschen
{
	return anzahl;
}

HausTier::HausTier(string name, double optGewicht)
{
	this->name = name;
	this->optGewicht = optGewicht;
	anzahl++;
	this->gewicht = 1.0;
	cout << this->name << " ertellt" << endl;
	if (anzahl < 3)
	{
		this->glueck = 5;
	}
	else this->glueck = 1;
}


HausTier::~HausTier()
{
	anzahl--;
	cout << this->name << " kaputt" << endl;

}



string HausTier::getName()
{
	return name;
}
int HausTier::getGlueck()
{
	return glueck;
}
void HausTier::fuettern(double kg) 
{
	gewicht = gewicht + kg;
	if (gewicht <= optGewicht)
	{
		glueck++;
	}
	else glueck = glueck - 2;
}
