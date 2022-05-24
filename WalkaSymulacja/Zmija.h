#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Zmija
{	
protected:
	int punkty_zycia = 8;
	int sila_ataku = 3;
	int poziom_ochrony = 3;

public:
	virtual ~Zmija() {};
	bool czyZyje() const { return punkty_zycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Zmija&);
};

class Zmija_Zwyczajna : public Zmija
{
protected:
	virtual int ugryzienie() const;
public:
	virtual ~Zmija_Zwyczajna() {};

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const;

	virtual const char* nazwa() const;
	virtual void info(ostream&) const;
};

class Zmija_Jadowita : public Zmija_Zwyczajna
{
	static int ile_zmij;
	const int numer_zmiji;
protected:
	virtual int ugryzienie() const;
	int zatrucie() const;
public:
	Zmija_Jadowita();
	virtual ~Zmija_Jadowita() {};

	virtual int wykonaj_atak(int poziom_obrony_przeciwnika) const;

	virtual const char* nazwa() const;
};