/*
 *	Prüfung Sommer 2014
 *
 */

#pragma once
#include <string>
//#include "Xsa.h"
 //#include "Email.h"



class Teilnehmer;
class Email
{
private:
	Teilnehmer* sender;
	Teilnehmer* empfaenger;
	string text;
public:
	Email(string txt, Teilnehmer* sender, Teilnehmer* empfaenger);
	~Email();
	Teilnehmer* getSender(void);
	Teilnehmer* getEmpfaenger(void);
	string getText(void);

};

class Internet;
class Teilnehmer
{
private:
	string name;
	Internet* provider;
public:
	Teilnehmer(string nam, Internet* provider);
	//virtual ~Teilnehmer();
	void senden(Teilnehmer* ziel);
	virtual void empfangen(Email* mail);
	string getName(void);
};

class Xsa;
class Internet
{
private:
	Xsa* meinGeheimdienst;
public:
	//Internet(string txt, Teilnehmer* sender, Teilnehmer* empfaenger);
	//~Internet();
	void eMailEingang(Email* mail);
	void setGeheimdienst(Xsa* dienst);
};


class Xsa : public Teilnehmer	// 'public' nicht vergessen
{
public:
	Xsa(std::string nam, Internet* provider); //  : nam, provider;
	//virtual ~Xsa();
	void empfangen(Email* mail) override;
};
