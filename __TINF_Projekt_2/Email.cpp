


#include <iostream>
#include <string>
#include <stdio.h>
//#include "Teilnehmer.h"
using namespace std;

#include  "Email.h"

#define TAB	cout << "\t"
#define COUT(x) cout << x << endl

// Klasse Email ===
Email::Email(string txt, Teilnehmer* sender, Teilnehmer* empfaenger)
{
	//strcry(text, txt);	// mit char
	text = txt;
	this->sender = sender;
	this->empfaenger = empfaenger;
}


Email::~Email()
{
	COUT(endl << "-----------------------------------------");
	COUT("Email zerstoert");
}

Teilnehmer* Email::getSender()
{
	return this->sender;
}

inline Teilnehmer* Email::getEmpfaenger()
{
	return this->empfaenger;
}

string Email::getText()
{
	return text;
}


// === Klasse Teilnehmer
Teilnehmer::Teilnehmer(string nam, Internet* provider)
{
	if (nam.length() <= 50)
		name = nam;	// sctcpy(name,nam);
	else { COUT("Name zu lang"); }

	this->provider = provider;


}

void Teilnehmer::senden(Teilnehmer* ziel)
{
	// char text[1000];
	
	string text;
	COUT( name << " sendet EMail an " << ziel->getName());
	COUT(" Emailinhalt eingeben:"); TAB;
	//fflush(stdin);	// tut nicht bei VS 17 !!!!
	// scanf_s("%[^\n]",text); // bis 'ENTER' einlesen
	// cin.ignore(); // TODO was passiert wenn nichts im Puffer ist? => FEHLER => nur notwendig für 'cin <<' !!
	getline(cin, text);	// Text einlesen
	Email* email = new Email(text, this, ziel);	// 'this' Verweis auf sich selbst
	//provider.>
	provider->eMailEingang(email);


}

void Teilnehmer::empfangen(Email* mail)	// kein 'virtuell' hier
{
	COUT(endl << "-----------------------------------------");
	COUT( name << " Sie haben eine neue Email:");
	COUT(" Sender: " << mail->getSender()->getName());
	COUT(" Emailinhalt: " << mail->getText());

	delete mail;
	mail = nullptr;
}

string Teilnehmer::getName()
{
	return  name;
}


// === Klasse Internet ===

void Internet::eMailEingang(Email* mail)
{
	//meinGeheimdienst->empfangen(mail);
	//meinGeheimdienst->

	// Kopie erstellen
	//Email* kopie = new Email("", nullptr, nullptr);
	//*kopie = *mail;	// Inhalt von 'mail' in den Inhalt von 'kopie' kopieren
	if (mail != nullptr)
	{
		if (meinGeheimdienst != nullptr)	// Sicherheit	// Konstruktor notwendig damit Zeiger auf 'nullptr' gesetzt wird
			meinGeheimdienst->empfangen(mail);	// (kopie);
		if(mail->getEmpfaenger() != nullptr)
			mail->getEmpfaenger()->empfangen(mail);
	}
}
void Internet::setGeheimdienst(Xsa* dienst)
{
	meinGeheimdienst = dienst;
}

// === Klasse Xsa ===

Xsa::Xsa(std::string nam, Internet* provider) : Teilnehmer(nam, provider)
{
}


void Xsa::empfangen(Email* mail) // virtuelle Methode
{
	COUT(endl << "-----------------------------------------");
	COUT(this->getName() << ": Wir haben mitgehoert!");
	COUT(" " << mail->getSender()->getName() << " hat an " << mail->getEmpfaenger()->getName() << " geschrieben:");
	COUT(" Emailinhalt: " << mail->getText());
}

