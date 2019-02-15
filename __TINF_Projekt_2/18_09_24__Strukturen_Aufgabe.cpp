#pragma once
/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTE1	DATUM:

PROJEKT:

======================================================================================================*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 
#include <math.h>				//sonst ist M_PI als "nichtdeklarierter Bezeichner" ausgewiesen!
#include <string.h>				// für String Funktionen
#include <ctype.h>
#include <windows.h>			// Sleep

#include "Structs.h"
#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 100

// === Strukturen anlegen (global) ===
//struct Datum		// neuen Datentyp anlegen, noch keine Variable
//{
//	int tag;		// Ausbau des Datentyps
//	int monat;
//	int jahr;
//};				// ';' sehr wichtig !!!
//typedef struct Datum Datum;	// Vorhandener Datentyp wird ersetzt // ABKÜRZUNG !!
//							// Man muss nicht immer 'struct Datum' schreiben, 'Datum' reicht
//
struct Person
{
	char vorname[50];
	char nachname[50];
	Datum gebTag;
}; typedef struct Person Person;
//
//// === PROTOTYPEN ===
//void ausgeben(Datum dat);
//void ausgeben_zg(Datum* dat);
//Datum eingeben(void);
//void eingeben_zg(Datum* dat);
void per_einlesen(Person* per);
void per_ausgeben(Person* per);

int per_suchen(char nachname[], int anzahl, Person per_vek[]);
int menus();


// === HAUPTPROGRAMM ===
void _18_09_24__Strukturen_Aufgabe(void)
{
	// --- Lokale Variablen ---
	int eingabe, i, nr;
	int nummer = 0;
	char nachname[50];
	// --- Ausführlich ----
	struct Datum gebTag;	// neue Variable von Typ 'Datum'

							// Inhalt bestimmen
	gebTag.tag = 23;
	gebTag.monat = 03;
	gebTag.jahr = 1991;

	// --- Abgekürtzt ---
	Datum heute = { 21, 9, 2018 };

	// Zeiger		// Zeigerübergabe spart Platz und Zeit
	Datum* d_zg;
	d_zg = &heute;	// 'dat_zg' zeigt auf 'heute'

	//heute.tag = 21;
	//(*d_zg).tag = 21;
	d_zg->tag = 21;		// bessere Schreibweise

	Person person;
	Person* per_zg = &person;

	Person alex{ "Alex","Huber", 23,03,1891 };	// eine bestimmte Person anlegen

	Person per_vek[ANZ];


	// --- Programm Einleitung ---
	printf("\n======================================================================\n");
	printf("\n ");
	printf("\n======================================================================\n");
	do
	{
		eingabe = menus();

		switch (eingabe)
		{
		case 1:
			per_einlesen(&per_vek[nummer]);
			nummer++;
			break;
		case 2:
			for (i=0; i< nummer;i++)
			{
			per_ausgeben(&per_vek[i]);
			
			}
			break;
		case 3:
			printf("\n Nachname: ");
			scanf("%s", &nachname);
			nr = per_suchen(nachname, ANZ, per_vek);
			if (nr >= 0)
			{
				per_ausgeben(&per_vek[nr]);
			}
			else
				printf("\n Person %s nicht gefunden", nachname);
			break;
		case 4:
			break;
		default:
			break;

		}

		//ausgeben(heute);

		//heute = eingeben();
		//eingeben_zg(&heute); // Zeiger // '&heute' Adresse von heute

							 //ausgeben(heute);
		//ausgeben_zg(&heute);
		

	} while (eingabe != 5);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

int per_suchen(char nachname[], int anzahl, Person per_vek[])
{
	int i = 0, gefunden = 0, nr;

	while(i <anzahl && gefunden == 0)
	{
		if (0 == strcmp(nachname, per_vek[i].nachname))	// Vergleicht
		{
			gefunden = 1;
		}
		else
			i++;
	}
	if (i < anzahl)	// wirklich gefunden
		nr = i;
	else
		nr = -1;
	return nr;
}

int menus()
{
	int eingabe=0;
	printf("\n [1] Person eingeben");
	printf("\n [2] Person anzeigen");
	printf("\n [3] Person suchen");
	printf("\n [4] Person loeschen");
	printf("\n [5] ENDE");
	printf("\n\n EINGABE [ ]\b\b");
	scanf_s("%i", &eingabe);
	
	return eingabe;
}
//
//void ausgeben(Datum dat)
//{
//	printf("\n %i.%i.%i\n", dat.tag, dat.monat, dat.jahr);
//}
//
//void ausgeben_zg(Datum* dat)
//{
//	printf(" %i.%i.%i\n", dat->tag, dat->monat, dat->jahr);
//}
//
//Datum eingeben(void)
//{
//	Datum dat;
//	printf("\n Datum eingeben (DD.MM.JJJJ):");
//	scanf_s("%d.%d.%d", &dat.tag, &dat.monat, &dat.jahr);	// DD.MM.JJJJ wird vorgegeben
//															// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal
//
//
//	return dat;
//}
//
//// mit Zeiger
//void eingeben_zg(Datum* dat)
//{
//	printf("\n Datum eingeben (DD.MM.JJJJ):");
//	scanf_s("%d.%d.%d", &dat->tag, &dat->monat, &dat->jahr);	// DD.MM.JJJJ wird vorgegeben
//																// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal
//
//																//return (dat);
//}

void per_einlesen(Person * per)
{
	//while (_getch() != '\r');
	//char c = _getch();
	//fflush(stdin); fflush(stdin);
	printf("\n Vornamen eingebnen: ");
	scanf("%s", per->vorname);  // nicht 'scanf_s' benutzen 
								//--> [DEBUGGEN]> [EIGENSCHAFTEN]>[C/C++]>[ALLGEMEIN]>[SDL Prüfung]>[NEIN]
	//gets_s(per->vorname);
	//scanf_s("%s", &vor);
	printf("\n Nachnamen eingebnen: ");
	scanf("%s", per->nachname);
	//gets_s(per->nachname);
	
	//*per->vorname = vor;
	eingeben_zg(&per->gebTag);
}

void per_ausgeben(Person * per)
{
	//printf("%s %s", per->vorname, per->nachname);
	printf("\n Vorname: %s", per->vorname);
	printf("\n Nachname: %s", per->nachname);
	printf("\n Geburtstag: ");
	ausgeben_zg(&per->gebTag);	// '&' Zeiger auf die Variable
}

