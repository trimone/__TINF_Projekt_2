#pragma once

#include <windows.h>			// Sleep()
#include <string>				// für string als Datentyp
using namespace std;			// damit string als Datentyp erkannt wird
#include <iostream>				// für 'cin' & 'cout'
#include <vector>
#include <ObjectArray.h>
//#include "19_02_12__KA_Uebung_Supermarkt.cpp"

// === alle Prototpen für main() ===
#include "my_biblio.h"
#include "__all_mains.h"	// Prototypen für jeweilige .cpp 
#include "Menu_Class.h"

//#include "18_09_24__Strukturen_Aufgabe.cpp"
//#include "19_02_12__"



#define TAB	cout << "\t"
#define COUT(x) cout << x << endl

#define WAIT 400
#define _SET_main 16	// Manuelle .cpp Auswahl => aktuelle neue Datei


void _menu(string main_name);	// Menüpunkte generieren
int print_menu();	// Aufwahlmenü generieren
int print_menu(_main_struct* all_sub_mains[]);
void prog_close();


//#include "19_02_12__KA_Uebung_Supermarkt.cpp"

const int anz = 50;
//_19_02_12_Supermarkt ka;

Menu_Class* _menu_obj[100];	// Menüpunkte




bool toggle_menu = true;	// Auswahlmenü toggeln

void main(void)
{
	// === VARIABLEN / INSTANZEN ===

	int i_main;
	int select_main;
	
	_main_struct* all_sub_mains[anz];

	// Zeiger auf NULL setzen
	for (_main_struct* &alle : all_sub_mains)	// '&' => den Zeiger nicht den Inhalt verwenden
		alle = nullptr;
	
	// Schnittstellen zur 'sub mains' herstellen 
	// nur Methoden von '_main_struct' können aufgerufen werden
	//all_sub_mains[i_main] = new <MAINNAME>; i_main++;	// Zähler erhöhen
	
	i_main = 0;
	all_sub_mains[i_main] = new _18_10_01_Marothon; i_main++;
	all_sub_mains[i_main] = new _19_02_08_Rahmen; i_main++;
	all_sub_mains[i_main] = new _19_02_12_Supermarkt; i_main++;
	
	
	

	//// === Prototypen für auszuführende '.cpp' ===
	//void _18_09_10__Sortier_Algorithmus();
	//_menu("18_09_10__Sortier_Algorithmus");

	//void _18_09_21__Strukturen();
	//_menu("18_09_21__Strukturen");

	////void _18_09_24__Strukturen_Aufgabe();
	//_menu("18_09_24__Strukturen_Aufgabe");

	////void _19_02_12__KA_Uebung_Supermarkt();
	//_menu("19_02_12__KA_Uebung_Supermarkt");
	
	
	
	do
	{
		COUT(endl << "======= C++ PROGRAMMIERUNG ================== ALEX HUBER === FTED2 =======");
		//COUT(endl << "======= C++ Programmierung =============================================");
		if (toggle_menu)
		{
			
			select_main = print_menu(all_sub_mains);
		}
		else select_main = _SET_main;	// Manuelle .cpp Auswahl => aktuelle neue Datei

		/// !!!!!!!!!
		all_sub_mains[select_main]->main();

		//// select_main = xx;	// manuelle Auswahl
		//switch (select_main)
		//{
		//case 0:		// Beenden
		//	break;
		//case 1:
		//	_18_09_10__Sortier_Algorithmus();
		//	break;
		//case 2:
		//	_18_09_21__Strukturen();
		//	break;
		//case 3:
		//	//_18_09_24__Strukturen_Aufgabe();
		//	break;

		//case 16:
		//	//alle[1]->main();
		//	//ka.main();
		//	//_19_02_12__KA_Uebung_Supermarkt();
		//	break;

		//default:
		//	break;
		//}
		
	} while (select_main != 0 && toggle_menu);

	for (auto &_main_end : all_sub_mains)
	{
		if (_main_end == nullptr)
			break;
		delete _main_end;
		_main_end = nullptr;

	}
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

// === Auswahlmenü ausgebnen ===
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

	return user_input - 1;
}

// === Auswahlmenü ausgebnen ===
int print_menu(_main_struct* all_sub_mains[])
{
	int i, user_input;

	COUT("========================================================================");
	COUT(endl << "Welche '.cpp' Datei soll ausgefuehrt werden?");
	COUT("________________________________________________________________________" << endl);
	
	for (i = 0; all_sub_mains[i] != nullptr; i++)
	{
		COUT("   [" << i + 1 << "]  " << all_sub_mains[i]->get_main_name());
	}
	/*for (_main_struct* sub_main : all_sub_mains)
	{
		if (sub_main == nullptr)
			break;
		COUT("   [" << i + 1 << "]  " << sub_main->get_main_name());
	}*/
	
	COUT(endl << "   [" << i + 1 << "]  Auswahlmenue ausschalten!");
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
			<< "   => " << all_sub_mains[0]->get_main_name());	//[user_input-1]
	}

	//COUT("========================================================================");

	return user_input - 1;
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