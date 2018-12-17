#pragma once

#include <string>
using namespace std;

class HausTier
{
private:
	double gewicht;
	double optGewicht;
	int glueck;
	string name;
	static int anzahl;

public:	
	
	static int getAnzahl();

	HausTier(string name, double optGewicht);
	~HausTier();

	string getName();
	int getGlueck();
	void fuettern(double kg);
	

};

