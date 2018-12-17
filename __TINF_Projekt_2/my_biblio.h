
// ===== my_biblio.h =====

/*= ==========================================================================================
TINF
NAME : ALEX HUBER	KLASSE : FTE1	DATUM :	03.03.2018

		EIGENE BIBLIOTHEK HEADER-DATEI

		In der Headerdatei werden die Funktionsprototypen aufgelistet
		Bei Prototypen-Deklaration ist immer Strichpunkt ";" notwendig !!
=========================================================================================== */

// === PROTOTYPEN ===

// --- Abfrage, ob das Programm beendet werden soll ---
int main_beenden(); // Programm beenden??
		/*	Einbindung durch eine 'do while' Schleife.
			Liefert eine '1' wenn das Programm beendet werden soll
				
				do {
					...
					...	
					...
				} while (main_beenden() != 1);	// Solange die 1 nicht gedrückt wird, wiederholt sich die 'do'-Schleife
		*/
void vek_init_double( double vek[], int anzahl);	// Vektor mit Nullen fühlen
void vek_init_int(int vek[], int anzahl);