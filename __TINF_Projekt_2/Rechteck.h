///*======================================================================================================
//TINF
//
//NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018
//
//KLASSE:	Recheck
//		Berechnet H�he, L�nge, Umfang und Fl�che von einem Rechteck
//		Radius, Umfang und Fl�che k�nnen einzelnd ge�ndert werden, der Rest wird automatisch berechnet
//
//		U = 2*h + 2*l
//		A = h * l
//======================================================================================================*/
//
//#pragma once	/*	Pr�prozessor Anweisung: 
//					dadurch werden Dateien nur einmal eingef�gt, 
//					falls doppelte includes vorhanden sind, nicht genormt*/
//
///* // falls Compiler '#pragma once' nicht kennt, werden doppelte Include-Dateien wie folgt rausgefiltert
///*
//#ifndef CLASSDATUM
//#define CLASSDATUM
//#endif // !CLASSDATUM
//*/
//
//// === KLASSE ===
///*
//- Attribute und Methoden sind in einer 'Klasse' gekapselt
//- Attribute sind f�r die Methoden zug�nglich (wie fr�her globale Variable)
//- �bergabe und R�ckgabe sind nicht mehr zwingend notwendig*/
//
//class Rechteck
//{
//// --- ATTRIBUTE ---	Attribute => 'private'
//						
//private:			/*	Vorteil der Kapselung: Zugriff auf 'private'-Attribute nur �ber 
//						Methoden der Klassse (zB. 'set'- bzw. 'get'-Methoden) m�glich, 
//						�berpr�fung auf sinnvolle Werte, freie Programmierung innehalt der Klasse*/
//	double laenge, hoehe, umfang, flaeche;
//
//// --- METHODEN ---		==> Nur Prototypen in der Headerdatei
//private:
//	double calUmfang(double h, double l);
//	double calFlaeche(double h, double l);
//
//
//public:
//	bool setSeiten(double h, double l);
//	bool setLaenge(double l);
//	bool setUmfang(double u);
//	bool setFlaeche(double f);
//
//	double getHoehe();
//	double getLaenge();
//	double getUmfang();
//	double getFlaeche();
//};
//
///*
////#endif	// */
