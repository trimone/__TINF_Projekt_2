#pragma once

#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'
//

class Menu_Class	// Klasse für Menüinhalt
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

	// Erhöht die .cpp Anzahl
	void inc_count()
	{
		count++;
	}

	// Setzt den Namen des Menüpunkts
	void set_main_name(string main_name)
	{
		this->main_name = main_name;
	}

	// Gibt den Namen des Menüpunkts zurück
	string get_main_name()
	{
		return this->main_name;
	}
};

int Menu_Class::count = 0;	// statische Variable