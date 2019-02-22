/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM: 1:10:18

PROJEKT:

		Ein Programm zur Speicherung und Verwaltung von Teilnehmern eines Marathonslaufes soll erstellt
		werden. Die Aufgabe ist die Entwicklung einer geeignetn Struktur, einner Funktion zum Einlesen
		eines Datensatzes, einer Funktion zum Ausgeben eines Datensatzes, einer Funktion zum Berechenen
		Berechnen der Laufzeit und einer geeigneten Testumgebung.
		Die Testumgebung soll menügesteuert sein

======================================================================================================*/

#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES		// Reihenfolge des #define und #include wichtig, 
#include <math.h>				//sonst ist M_PI als "nichtdeklarierter Bezeichner" ausgewiesen!
#include <string.h>				// für String Funktionen
#include <ctype.h>
#include <windows.h>			// Sleep


#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define ANZ 100

// === Strukturen anlegen (global) ===
struct Datum		// neuen Datentyp anlegen, noch keine Variable
{
	int tag;		// Ausbau des Datentyps
	int monat;
	int jahr;
};				// ';' sehr wichtig !!!
typedef struct Datum Datum;	// Vorhandener Datentyp wird ersetzt // ABKÜRZUNG !!
							// Man muss nicht immer 'struct Datum' schreiben, 'Datum' reicht

struct Zeit
{
	int stunde = 0;
	int minute = 0;
	int sekunde = 0;
}; typedef struct Zeit Zeit;

struct Teilnehmer
{
	char vorname[50];
	char nachname[50];
	Zeit startZ;
	Zeit ankunftZ;

}; typedef struct Teilnehmer Teilnehmer;

// === PROTOTYPEN ===
void ausgeben(Datum dat);
void ausgeben_zg(Datum* dat);
Datum eingeben(void);
void eingeben_zg(Datum* dat);
void teil_einlesen(Teilnehmer* per, Zeit* start, Zeit* ende );
void teil_ausgeben(Teilnehmer* per, Zeit* start, Zeit* ende);
void laufzeit(Zeit* start, Zeit* ende);
void zeitausgeben(Zeit* time);



//int per_suchen(char nachname[], int anzahl, Person per_vek[]);
int menu(int i);


// === HAUPTPROGRAMM ===
void _18_10_01_Marothon::main(void)
{
	// --- Lokale Variablen ---
	int eingabe;
	double zeit;
	Zeit time, start, ende;

	Teilnehmer laeufer;

	// --- Programm Einleitung ---
	printf("\n======================================================================\n");
	printf("\n\t Teilnehmer für einen Marathon eingeben und Laufzeitberechnen");
	printf("\n======================================================================\n");
	do
	{
		eingabe = menu(1);

		switch (eingabe)
		{
		case 1:
			teil_einlesen(&laeufer, &start, &ende);
			break;
		case 2:
			teil_ausgeben(&laeufer, &start, &ende);
			break;
		case 3:
			laufzeit(&start, &ende);
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


	} while (eingabe != 4);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===
//
//int per_suchen(char nachname[], int anzahl, Person per_vek[])
//{
//	int i = 0, gefunden = 0, nr;
//
//	while (i <anzahl && gefunden == 0)
//	{
//		if (0 == strcmp(nachname, per_vek[i].nachname))	// Vergleicht
//		{
//			gefunden = 1;
//		}
//		else
//			i++;
//	}
//	if (i < anzahl)	// wirklich gefunden
//		nr = i;
//	else
//		nr = -1;
//	return nr;
//}

int menu(int i)
{
	int eingabe = 0;
	printf("\n\n [1] Teilnehmer eingeben");
	printf("\n [2] Teilnehmer anzeigen");
	printf("\n [3] Laufzeit berechnen und ausgeben");
	
	printf("\n [4] ENDE");
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

void teil_einlesen(Teilnehmer* per, Zeit* start, Zeit* ende)
{
	int ok = 0;
	int start_tmp, ende_tmp;
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

	// !!!!!!!!!!!!!!!1
	//zeitEigeben(&teilnehmer->start);
//	!!!!!!!!!!!

	printf("\n Startzeit eingeben(hh:mm:ss):\n");
	scanf("%i:%i:%i", &start->stunde, &start->minute, &start->sekunde );
	do{
		printf("\n Ankunfszeit eingeben(hh:mm:ss):\n");
		scanf("%i:%i:%i", &ende->stunde, &ende->minute, &ende->sekunde);
	
		start_tmp = (start->stunde * 3600) + (start->minute * 60) + start->sekunde;
		ende_tmp = (ende->stunde * 3600) + (ende->minute * 60) + ende->sekunde;

		if((ende_tmp - start_tmp)> 3600)
		{ 
			ok = 1;
		}
		else 
		{ 
			printf("\n Marothon sollte laenger als eine Stunde dauern!! ");
			_getch();
		}
	} while (!ok);
}

void teil_ausgeben(Teilnehmer* per, Zeit* start, Zeit* ende)
{
	//printf("%s %s", per->vorname, per->nachname);
	printf("\n Vorname: %s", per->vorname);
	printf("\n Nachname: %s", per->nachname);
	printf("\n Startzeit: %i:%.2i:%.2i", start->stunde, start->minute, start->stunde);
	printf("\n Ankunftszeit: %i:%.2i:%.2i", ende->stunde, ende->minute, ende->stunde);
	
}

/*
int  laufzeit(Zeit* start, Zeit* ende, int ausgabe)
{

	int i, sek, min, std;
	double zeit;
	///*	start = clock();	// Takt einlesen
	//....			// Funktion
	//....
	//ende = clock();		// Takt einlesen 

	
	srand(time_t(NULL));	// Zufallsgenerator initialisieren, 
							// damit Zahlen bei jedem Durchlauf anders sind
	do{
	sek = rand();
	//zeit = zeit / 1000;
	//zeit = (double)(zeit) / CLK_TCK;
	} while (!(sek > 0 && sek < 59));

	do {
		min = rand();
		//zeit = zeit / 1000;
		//zeit = (double)(zeit) / CLK_TCK;
	} while (!(min > 0 && min < 60));

	do {
		std = rand();
		//zeit = zeit / 1000;
		//zeit = (double)(zeit) / CLK_TCK;
	} while (!(std > 1 && std < 12));

	time->stunde = std;
	time->minute = min;
	time->sekunde = sek;
	zeit = (std * 3600) + (min * 60) + sek;

	//ende = clock();
	//zeit = (double)(zeit) / CLK_TCK;	// Zeitberechnen in sek
	return zeit;
}
*/

void laufzeit(Zeit* start, Zeit* ende)
{
	int start_tmp, ende_tmp, sekunden;
	int hh, mm, ss;


	start_tmp = (start->stunde * 3600) + (start->minute * 60) + start->sekunde;
	ende_tmp = (ende->stunde * 3600) + (ende->minute * 60) + ende->sekunde;

	sekunden = ende_tmp - start_tmp;
	hh = sekunden / 3600;
	mm = (sekunden - (sekunden / 3600) * 3600) / 60;
	// mm = (sekunden / 60) % 60;	// alternativ
	ss = sekunden % 60;

	printf("\n Laufzeit is Sekunden: %i", sekunden);
	printf("\n Laufzeit: %i:%.2i:%.2d", hh, mm, ss );
}
