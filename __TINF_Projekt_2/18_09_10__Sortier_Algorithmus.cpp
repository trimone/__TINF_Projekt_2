/*======================================================================================================
TINF

NAME: ALEX HUBER	KLASSE: FTED2	DATUM: 10.09.18

PROJEKT:	Sortier Algorithmus
			
	Bubblesort
	---->	Für nr = 0 bis nr = Anzahl - 2		
	|		  wenn Element[nr+1] < Element [nr]
	|			dann TAUSCHEN
	|---<	  solange getauscht wurde


	n² Sort
		|--> Für nr = 0 bis nr = Anzahl - 2
		|	|--> Für i = nr+1 bis i = Anzahl -1	// !!!
		|	|	   wenn Element[i] < Element [nr]
		|	|----<  dann TAUSCHEN
		|--------<

		// --- Funktionslaufzeit bestimmen ---
		start = clock();	// Aktuellen Clock der CPU wird in die Variable geladen,
		// bevor die Funktion durchlafen ist

		primHuber(ANZ, primzahlen);	// Funktion starten

		ende = clock();		// Aktuellen Clock der CPU wird in die Variable geladen,
		// nachdem die Funktion durchlafen ist

		zeit = (double)((double)ende - start) / CLK_TCK;	// 'casten' notwendig um Kommazahle zu erhalten


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


#include "my_biblio.h"			// Eigene Bibliothek

// === MAKROS ===
#define xHoch2(x) (x)*(x) // BESSERES Makros !!!
#define WAIT 800
#define ANZ 100000

// === PROTOTYPEN ===
int menue();
void vektor_zufall(double vektor[]);
void print_vek(double vek[]);
int sort_bubble(double vek[]);
int sort_n2(double vek[]);
int sort_n2_fast(double vek[]);

double laufzeit(int start, int ende);

void prog_end();
void dot_dot();

int vergleiche(const void* e1, const void* e2);


// === HAUPTPROGRAMM ===

void main(void)
{
	// --- Lokale Variablen ---
	 
	int eingabe, sort=0;
	double vektor[ANZ];	

	int start, ende;
	double zeit;
		
	vek_init_double(vektor, ANZ);	// Vertor mit Nullen fühlen

	// --- Programm Einleitung ---
	printf("\n======================================================================\n");
	printf("\n Programm zur Sortierung von Zahlen in einem Vektor");
	printf("\n======================================================================\n");
	
	do
	{		
		eingabe = menue();

		switch (eingabe)
		{
			case 1:	vektor_zufall(vektor);
				break;
			case 2:					
				sort_bubble(vektor);
				break;
			case 3:	
				//sort_n2(vektor);
				sort_n2_fast(vektor);
				break;
			case 4: 
				start = clock();

				// --- Quick Sort --- Aufteilung in kleine Gruppen
				qsort(vektor, ANZ, sizeof(double), vergleiche);		// == qsort(vektor, ANZ, 8, vergleiche);
				
				ende = clock();
				zeit = laufzeit(start, ende); 
				printf("Zahlenreihe wurde sortiert\n");
				printf("Laufzeit: %lg sek", zeit);
				break;
			case 5: print_vek(vektor);
				break;
			case 6:	prog_end();
				break;
			default: 
				printf("\n Falsche Eingabe \n");
				break;
		}

	} while (eingabe != 6);	// Solange die 5 nicht gedrückt wird, wiederholt sich die 'do while'-Schleife
}

// === FUNKTIONEN ===

// === Menü ===
int menue()
{
	
	int eingabe = 0;
	
	_getch();
	
	printf("\n === Menue Steuerung ===");
	printf("\n [1] Vektor mit Zufallszahlen fuehlen");
	printf("\n [2] Sortieren Bubble");
	printf("\n [3] Sortieren n^2");
	printf("\n [4] Sortieren qsort");
	printf("\n [5] Vektor ausgeben");
	printf("\n\n [6] BEENDEN");
	printf("\n\n Menue Eingabe: [ ]\b\b");

	scanf_s("%i", &eingabe);
	return eingabe;
}

// === Vektor mit zufalligen Zahlen fühlen ===
void vektor_zufall(double vektor[])	// mit Zufallszahlen fühlen
{
	int i;
	srand(time_t(NULL));	// Zufallsgenerator initialisieren, 
							// damit Zahlen bei jedem Durchlauf anders sind

	for (i = 0; i < ANZ; i++)
	{
		vektor[i] = rand();
		vektor[i] = vektor[i] / 1000;
	}

	//dot_dot();
	printf(" Vektor wurde gefuehlt\n");
}

// === Vektor ausgeben ===
void print_vek(double vek[])
{
	int i;
	printf("\n Vektor:\n");
	for (i = 0; i < ANZ; i++)
	{
		printf(" %lg ;", vek[i]);
	}
	printf("\b \n");	// letztes ';' löschen/überschreiben --> \back[SPACE]
	//_getch();
}

// === Bubble Sortierung ===
int sort_bubble(double vek[])
{
	int zahl, flag, sort=0;
	int start, ende;	// Laufzeitbestimmung
	double temp, zeit;

	printf("\n Bubblesort: Zahlenreihe wird sortiert ...\n");
	start = clock();
	
	do{
		flag = 0;		// es wurde nichts getauscht
		for (zahl = 0; zahl < (ANZ - 1); zahl++)
		{
			if (vek[zahl+1] < vek[zahl])	// zwei Zahle vergleichen
			{
				temp = vek[zahl+1];			// tauschen
				vek[zahl+1] = vek[zahl];
				vek[zahl] = temp;
				flag = 1;					// es wurde getauscht
			}
		}
	} while (flag);		// solange getauscht wurde, wiederholen
	
	ende = clock();
	zeit = laufzeit(start, ende); 

	//dot_dot();
	printf("Zahlenreihe wurde sortiert\n");	
	printf("Laufzeit: %lg sek", zeit);
	
	return sort = 1;
}

// === n² Sortierung ===
int sort_n2(double vek[])
{
	int i, zahl, sort=0;
	int start, ende;	// Laufzeitbestimmung

	double temp, zeit;

	printf("\n n^2 Sort: Zahlenreihe wird sortiert ...\n");

	start = clock();

	for (zahl = 0; zahl < ANZ - 1; zahl++)
	{
		for (i = zahl + 1; i < ANZ ; i++)
		{
			if (vek[i] < vek[zahl])
			{
				temp = vek[i];
				vek[i] = vek[zahl];
				vek[zahl] = temp;
			}
		}
	}

	ende = clock();
	zeit = laufzeit(start, ende);
	//dot_dot();
	printf(" Zahlenreihe wurde sortiert\n");
	printf("Laufzeit: %lg sek", zeit);

	return sort = 2;

}


// === n² Sortierung schneller ===
int sort_n2_fast(double vek[])
{
	int i, j, zahl, sort = 0;
	int start, ende;	// Laufzeitbestimmung

	double temp, zeit;
	double min;
	int minNR;

	printf("\n n^2 Sort: Zahlenreihe wird sortiert ...\n");

	start = clock();

	for (zahl = 0; zahl < ANZ - 1; zahl++)
	{
		for (j = zahl + 1; j < ANZ; j++)
		{
			if (vek[j] < vek[zahl])
			{
				minNR = j;
				min = vek[j];
			}
		}
		temp = vek[zahl];
		vek[zahl] = vek[minNR];
		vek[minNR] = temp;
	}

	ende = clock();
	zeit = laufzeit(start, ende);
	//dot_dot();
	printf(" Zahlenreihe wurde sortiert\n");
	printf("Laufzeit: %lg sek", zeit);

	return sort = 2;

}

// === Laufzeit für eine Funktion bestimmen ===
double laufzeit(int start, int ende)
{
	double zeit;
	/*	start = clock();	// Takt einlesen
			....			// Funktion
			....
		ende = clock();		// Takt einlesen */

	zeit = (double)(ende - start) / CLK_TCK;	// Zeitberechnen in sek
	return zeit;
}

void prog_end()
{
	int i;

	printf("\n PROGRAMM WIRD BEENDET ");
	//_getch();
	for (i = 0; i < 4; i++)
	{
		printf(".");
		Sleep(WAIT);		
	}
	
}

void dot_dot()
{
	int i;
	printf("\n ");

	for (i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}
}

// --- für 'qsort()' ---
int vergleiche(const void * e1, const void * e2)
{
	double el1, el2;
	int erg = 0;

	el1 = *(double*)e1; // void Zeiger casten (double*)
						// '*' Inhalt rausholen
	el2 = *(double*)e2;

	if (el1 < el2)
		erg = -1;
	if (el1 < el2)
		erg = 1;
	if (el1 == el2)
		erg = 0;

	return erg;
}
