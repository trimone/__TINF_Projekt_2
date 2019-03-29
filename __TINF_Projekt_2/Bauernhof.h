#pragma once
class Tier	// Schnittstellenklasse 
{
protected:
	double gewicht;

public:
	Tier();
	void virtual fressen(double kg) = 0;	// rein virtuelle Klasse
	double virtual produzieren(void) = 0;
};

class Kuh : public Tier
{
public:
	void fressen(double kg);
	double produzieren() override;
};

class Schwein : public Tier
{
public:
	void fressen(double kg) override;
	double produzieren() override;	
};

class Bauernhof
{
private:
	Tier* nutzTiere[200];	// Schnittstellenklasse
	int anzahlTier;
	double nutzen;
public:
	Bauernhof();
	~Bauernhof();

	void neuesTier(int art);
	void tiere_fuettern(void);
	void produzieren(void);
};

class Mensch	// Leere Klasse
{};

class Bauer : public Mensch
{
private:
	Bauernhof* meinHof;
public:
	void hof_bekommen(Bauernhof* hof);
	void hof_bewirtschaften(void);
	void neuesTier(int art);
};

