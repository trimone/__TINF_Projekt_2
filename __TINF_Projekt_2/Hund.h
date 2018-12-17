#pragma once
#include <string>
using namespace std;


class Hund
{
private:
	string name;
	static int anzahl;
	Hund*papaHund;
	Hund*babyHund;

public:
	
	~Hund();
	Hund(string name);
	string getName();
	void papaBekommtBaby(string name);
	void setPapaHund(Hund* deinPapa);
	Hund* getBabyHund();
	static int getAnzahl();

};

