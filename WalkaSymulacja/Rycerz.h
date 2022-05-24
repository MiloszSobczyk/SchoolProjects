#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Postac.h"

class Zdolnosc;
class Przedmiot;

class Rycerz : public Postac
{
protected:
	int modyfikator_obrazen = 0;

	int liczba_zdolnosci = 2;
	Zdolnosc** zdolnosci;
	static const int wielkosc_ekwipunku = 4;
	Przedmiot* ekwipunek[wielkosc_ekwipunku];

public:
	Rycerz(string imie, int punktyZycia, int zrecznosc, int sila, int poziom);
	Rycerz(const Rycerz& z) = delete;
	Rycerz& operator= (const Rycerz& z) = delete;
	virtual ~Rycerz();

	int czy_dostepna_specjalna() const;
	int czy_dostepna_uzdrawiajaca() const;

	void przygotowanie();
	int wykonaj_atak(int poziom_ochrony_przeciwnika) override;

	virtual void info(ostream&) const override;
};

