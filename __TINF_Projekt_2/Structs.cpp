


#include <stdio.h>
#include <conio.h>
#include "Structs.h"



void ausgeben(Datum dat)
{
	printf("\n %i.%i.%i\n", dat.tag, dat.monat, dat.jahr);
}

void ausgeben_zg(Datum* dat)
{
	printf(" %i.%i.%i\n", dat->tag, dat->monat, dat->jahr);
}

Datum eingeben(void)
{
	Datum dat;
	printf("\n Datum eingeben (DD.MM.JJJJ):");
	scanf_s("%d.%d.%d", &dat.tag, &dat.monat, &dat.jahr);	// DD.MM.JJJJ wird vorgegeben
															// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal


	return dat;
}


// mit Zeiger
void eingeben_zg(Datum* dat)
{
	printf("\n Datum eingeben (DD.MM.JJJJ):");
	scanf_s("%d.%d.%d", &dat->tag, &dat->monat, &dat->jahr);	// DD.MM.JJJJ wird vorgegeben
					// '.' Punkt muss zwischen Zahlen eingegeben werden	// '%d' Dezimal

	//return (dat);
}

