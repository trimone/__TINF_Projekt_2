///*======================================================================================================
//TINF
//
//NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018
//
//KLASSE:	Recheck
//		Berechnet Höhe, Länge, Umfang und Fläche von einem Rechteck
//		Radius, Umfang und Fläche können einzelnd geändert werden, der Rest wird automatisch berechnet
//
//		U = 2*h + 2*l
//		A = h * l
//======================================================================================================*/
//
//#pragma once	/*	Präprozessor Anweisung: 
//					dadurch werden Dateien nur einmal eingefügt, 
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
//- Attribute sind für die Methoden zugänglich (wie früher globale Variable)
//- Übergabe und Rückgabe sind nicht mehr zwingend notwendig*/
//
//class Rechteck
//{
//// --- ATTRIBUTE ---	Attribute => 'private'
//						
//private:			/*	Vorteil der Kapselung: Zugriff auf 'private'-Attribute nur über 
//						Methoden der Klassse (zB. 'set'- bzw. 'get'-Methoden) möglich, 
//						Überprüfung auf sinnvolle Werte, freie Programmierung innehalt der Klasse*/
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
