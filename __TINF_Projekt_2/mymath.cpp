// In der .ccp werden die eigentlichen Funktionen reingeschrieben, 
// die im Hauptprogramm 'main' aufgerufen werden

#include <stdio.h>		// weil 'prinf' verwendet wird
#include <conio.h>

#include "mymath.h"		// Um Prototypen einzufügen

// Funktionen
// Fakultät
double fak(int n)
{
	int i;
	double erg=1;
	for( i = 1 ; i <= n ; i++ ) // i kann auch mit 2 anfangen / Fakultät von 0 oder 1  = 1
	{
		erg= erg * i;
	}
	return (erg);
}

// Binominalkoeffizient	
double binKoe(int n, int k)
{
	double erg;
	
	erg = fak(n) / (fak(k)* fak(n-k)); // In die () von Funktionen können auch Berechnungen reingeschrieben werden

	return (erg);
}

// LOTTO
void lotto(int n, int k)
{
	int r;
	double erg;

	for( r=1 ; r<=k ; r++ )
	{
		erg= binKoe(n,k) / (binKoe(k,r)*binKoe(n-k,k-r));
		printf("\n Die Chance %i Richtige zu haben 1 zu %lg", r, erg);
		// Ausgabe im 'main' wäre besser
	}

}
