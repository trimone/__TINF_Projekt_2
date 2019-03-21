// ===== my_biblio.cpp =====

/*= ==========================================================================================
TINF
NAME : ALEX HUBER	KLASSE : FTE1	DATUM :	03.03.2018

		EIGENE BIBLIOTHEK .cpp-DATEI

		In der .cpp-Datei werden die eigentlichen Funktionen aufgelistet,
		die in 'main' aufgerufen werden

=========================================================================================== */

#include <stdio.h>		// weil 'prinf' verwendet wird
#include <conio.h>

#include "my_biblio.h"		// Um Funktions-Prototypen einzufügen

// === FUNKTIONEN ===

// --- Abfrage, ob das Programm beendet werden soll ---
int main_beenden()
{
	int end;

	printf("\n\n\n******************************************");
	printf("\n Soll das Sub Programm beenden werden?\n   [1] BEENDEN\n   [2] Nicht beenden\n   ");	// Buchstaben dürfen nicht gedrückt werden!
	fflush(stdin);
	scanf_s("%i", &end);

	return end;
}

// === double Vektor mit Nullen fühlen ===
void vek_init_double(double vek[], int anzahl)		//
{
	int i;
	for (i = 0; i < anzahl; i++)
	{
		vek[i] = 0.0;
	}
}

// === int Vektor mit Nullen fühlen ===
void vek_init_int(int vek[], int anzahl)
{
	int i;
	for (i = 0; i < anzahl; i++)
	{
		vek[i] = 0;
	}
}