#pragma once



class Rechteck
{
private:
	double laenge;
	double breite;
protected:
	double flaeche;
	double umfang;

public:
	Rechteck();
	Rechteck(double l, double b);
	~Rechteck();

	void setAbmessungen(double l, double b);
	double getFlaeche();
	double getUmfang();
};

class Quader : public Rechteck
{
protected:
	double hoehe;

public:
	Quader();
	Quader(double l, double b, double h);
	~Quader();

	void setHoehe(double h);
	double getVolumen();

};



class Rahmen
{
private:
	Rechteck innen;
	Rechteck aussen;
public:
	Rahmen(double li, double bi, double la, double ba);
	~Rahmen();

	double getFlaeche();

};
