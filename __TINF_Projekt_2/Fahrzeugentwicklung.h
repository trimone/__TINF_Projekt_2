///*======================================================================================================
//
//NAME: ALEX HUBER	KLASSE: FTED2	DATUM:	22.10.2018
//
//KLASSE:	Recheck
//
//======================================================================================================*/
//
//#pragma once	/*	Präprozessor Anweisung: 
//dadurch werden Dateien nur einmal eingefügt,
//falls doppelte includes vorhanden sind, nicht genormt*/

// =============================================================================
class Motor_Pr
{
private:
	double leistung;	// größer 0 !!
	double gewicht;
public:
	Motor_Pr(double kW);
	void setGewicht(double gew);
	double getGewicht(void);
	double getLeistung(void);
};

class ElektroMotor : public Motor_Pr
{
	ElektroMotor(double kW);
};

class VerbrennungsMotor : public Motor_Pr
{
	VerbrennungsMotor(double kW);
};
// =============================================================================
class Energiespeicher
{
protected:
	int art;
	double energie;
	double gewicht;
public:
	Energiespeicher(void);
	int getArt(void);
	double getEnergie(void);
	double getGewicht(void);
};

class Batterie : public Energiespeicher
{
public:
	Batterie(double kWh);
};
class  Tank : public Energiespeicher
{
public:
	Tank(double ltr);
};
// =============================================================================
class Auto_Pr
{
private: 
	Motor_Pr* mot[2];
	Energiespeicher* energie[2];
	double karosserieGewicht;	// >0
	int anzahlAntriebe;
public:
	Auto_Pr(double karossGew);
	~Auto_Pr();
	void analyse(void);
protected:
	void konstruktion(void);
	Motor_Pr* motorErzeugen(int art);
	Energiespeicher* energiespeicherErzeugen(int art);
};

