

#include <iostream>
#include <string>
using namespace std;
#include "Fahrzeugentwicklung.h"

#define COUT(x) cout << x << endl

// =============================================================================
Motor_Pr::Motor_Pr(double kW)
{
	gewicht = 0;
	leistung = kW;
}

void Motor_Pr::setGewicht(double gew)
{
	if (gew > 0)
		gewicht = gew;
	else cout << "Gewicht nicht gesetzt!" << endl;
}

double Motor_Pr::getGewicht()
{
	return gewicht;
}

double Motor_Pr::getLeistung()
{
	return leistung;
}

ElektroMotor::ElektroMotor(double kW) : Motor_Pr(kW)
{
	setGewicht(getLeistung() / 1.5);
}

VerbrennungsMotor::VerbrennungsMotor(double kW) : Motor_Pr(kW)
{
	setGewicht(getLeistung() / 2.0);
}
// =============================================================================
Energiespeicher::Energiespeicher()
{
	energie = 0;
	gewicht = 0;
	art = -1;
}

int Energiespeicher::getArt()
{
	return art;
}

double Energiespeicher::getEnergie()
{
	return energie;
}

double Energiespeicher::getGewicht()
{
	return gewicht;
}

Batterie::Batterie(double kWh)
{
	art = 1;	// = Batterie
	energie = kWh;
	gewicht = energie / (0.13);	// Gewicht berechnen [kg]
}

Tank::Tank(double ltr)
{
	art = 0;	// = Tank
	energie = ltr * 10.75;	// [kWh]
	gewicht = ltr * 0.8;	// [kg]
}
// =============================================================================
Auto_Pr::Auto_Pr(double karossGew)
{
	if (karossGew > 0)
		karosserieGewicht = karossGew;
	anzahlAntriebe = 0;
	for (auto &mot : mot)	// jedes Element in Array durch gehen
		mot = nullptr;
	for (auto &eng : energie)
		eng = nullptr;
	konstruktion();
}

Auto_Pr::~Auto_Pr()
{
}

void Auto_Pr::analyse()
{
}

void Auto_Pr::konstruktion()
{
	int eingabe;
	COUT("==== Fahrzeug kostruieren ====");
	COUT("--- Motor auswaehlen ---");
	COUT("  [1] Verbreunnungsmotor");
	COUT("  [2] Elektormotor");
	COUT("  [3] Hybrid (Verbrennungs- & Elektromotor");
	cin >> eingabe;

	if (eingabe == 3)
	{
		motorErzeugen(1);
		motorErzeugen(2);
		energiespeicherErzeugen(1);
		energiespeicherErzeugen(2);
		anzahlAntriebe = 2;
	}
	else
	{
		motorErzeugen(eingabe);
		energiespeicherErzeugen(eingabe);
		anzahlAntriebe = 1;
	}
}

Motor_Pr* Auto_Pr::motorErzeugen(int art)
{
	double kW;
	COUT("Leistung fuer Verbrennungsmotor angeben: ");
	cin >> kW;
	if (mot == nullptr)
	{
		if (art == 1)
			mot[0] = new VerbrennungsMotor(kW);
		else if (art == 2)
			mot[0] = new ElektroMotor(kW);
	}
	else
	{
		if (art == 1)
			mot[1] = new VerbrennungsMotor(kW);
		else if (art == 2)
			mot[1] = new ElektroMotor(kW);
	}
}

Energiespeicher* Auto_Pr::energiespeicherErzeugen(int art)
{
}
