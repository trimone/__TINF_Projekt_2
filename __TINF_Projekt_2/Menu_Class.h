#pragma once

#include <string>				// f�r string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// f�r 'cin' & 'cout'
//

class Menu_Class	// Klasse f�r Men�inhalt
{
private:
	static int count;
	string main_name;

public:
	// Gibt die Anzahl der .ccp aus
	static int get_main_count()
	{
		return count;
	}

	// Erh�ht die .cpp Anzahl
	void inc_count()
	{
		count++;
	}

	// Setzt den Namen des Men�punkts
	void set_main_name(string main_name)
	{
		this->main_name = main_name;
	}

	// Gibt den Namen des Men�punkts zur�ck
	string get_main_name()
	{
		return this->main_name;
	}
};

int Menu_Class::count = 0;	// statische Variable