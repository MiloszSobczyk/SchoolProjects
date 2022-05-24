#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Bron;
class Zbroja;
class Artefakt;

class Postac
{
protected:
	string imie;
	int punktyZycia;
	int zrecznosc;
	int sila;
	int poziom;

	int sila_ataku;
	int poziom_ochrony;
	Bron* bron_w_reku;
	Zbroja* zbroja_na_ciele;
	Artefakt* artefakt;

public:
	Postac(string imie = "", int punktyZycia = 0, int zrecznosc = 0, int sila = 0, int poziom = 0);
	Postac(const Postac& z) = delete; 
	Postac& operator=(const Postac& z) = delete;
	virtual ~Postac();

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika);
	virtual void przyjmij_atak(int obrazenia);

	void odrzuc_bron(); 
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony;  }

	virtual void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Postac&);
};

