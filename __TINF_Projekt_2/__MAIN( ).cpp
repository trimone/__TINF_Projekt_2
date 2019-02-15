#pragma once

#include <windows.h>			// Sleep()
#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'

//#include "19_02_12__KA_Uebung_Supermarkt.cpp"

// === alle Prototpen für main() ===
#include "__all_mains.h"	// Prototypen für jeweilige .cpp 
#include "my_biblio.h"
#include "Menu_Class.h"

//#include "18_09_24__Strukturen_Aufgabe.cpp"



#define TAB	cout << "\t"
#define COUT(x) cout << x << endl

#define WAIT 400
#define _SET_main 16	// Manuelle .cpp Auswahl => aktuelle neue Datei


void _menu(string main_name);	// Menüpunkte generieren
int print_menu();	// Aufwahlmenü generieren
void prog_close();



Menu_Class* _menu_obj[100];	// Menüpunkte


bool toggle_menu = true;	// Auswahlmenü toggeln

void main(void)
{
	int select_main;
	int i = 0;

	// === Prototypen für auszuführende '.cpp' ===
	void _18_09_10__Sortier_Algorithmus();
	_menu("18_09_10__Sortier_Algorithmus");

	void _18_09_21__Strukturen();
	_menu("18_09_21__Strukturen");

	//void _18_09_24__Strukturen_Aufgabe();
	_menu("18_09_24__Strukturen_Aufgabe");


	void _19_02_12__KA_Uebung_Supermarkt();
	_menu("19_02_12__KA_Uebung_Supermarkt");
	
	
	
	do
	{
		COUT(endl << "======= C++ PROGRAMMIERUNG ================== ALEX HUBER === FTED2 =======");
		//COUT(endl << "======= C++ Programmierung =============================================");
		if (toggle_menu)
		{
			select_main = print_menu();
		}
		else select_main = _SET_main;	// Manuelle .cpp Auswahl => aktuelle neue Datei


		// select_main = xx;	// manuelle Auswahl
		switch (select_main)
		{
		case 0:		// Beenden
			break;
		case 1:
			_18_09_10__Sortier_Algorithmus();
			break;
		case 2:
			_18_09_21__Strukturen();
			break;
		case 3:
			//_18_09_24__Strukturen_Aufgabe();
			break;

		case 16:
			
			_19_02_12__KA_Uebung_Supermarkt();
			break;

		default:
			break;
		}
		
	} while (select_main != 0 && toggle_menu);


	// === Menüpunkte wieder löschen
	for (int i = 0; i < Menu_Class::get_main_count(); i++)
	{
		delete _menu_obj[i];
		_menu_obj[i] = nullptr;
	}

	prog_close();
}

// === Menüpunkte bestimmen ===
void _menu(string main_name)
{
	int i = Menu_Class::get_main_count();
	_menu_obj[i] = new Menu_Class;
	_menu_obj[i]->inc_count();
	_menu_obj[i]->set_main_name(main_name);
}

// === Auswahlmenü ausgebne ===
int print_menu()
{
	int i;
	int user_input;
	int count = Menu_Class::get_main_count();
	COUT("========================================================================");
	COUT(endl << "Welche '.cpp' Datei soll ausgefuehrt werden?");
	COUT("________________________________________________________________________" << endl);
	for (i = 0; i != count; i++)
	{
		COUT("   [" << i + 1 << "]  " << _menu_obj[i]->get_main_name());
	}
	COUT(endl << "   [" << i + 1 << "]  Auswahmenue ausschalten!");
	///TAB; COUT("=> Default .cpp ausfuehren: " << _menu_obj[_SET_main - 1 ]->get_main_name()))
	COUT("   [0]  [BEENDEN]");

	cout << endl << "AUSWAHL [  ]\b\b\b";
	cin >> user_input;
	COUT("________________________________________________________________________" << endl);

	if (user_input == (i + 1))	// Wenn Auswahl ausgeschaltet wird
	{
		toggle_menu = false;
		user_input = _SET_main;			// Defpult .cpp wird ausgeführt => _SET_main 
		COUT("[Menue ausgeschaltet!]");
		COUT(" Folgende .cpp wird ausgeführt: " << endl
			<< "   => " << _menu_obj[0]->get_main_name());	//[user_input-1]
	}
	
	//COUT("========================================================================");

	return user_input;
}


void prog_close()
{
	int i;
	cout << "\n PROGRAMM WIRD BEENDET ... PEACE OUT ";
	for (i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(WAIT);
	}

}