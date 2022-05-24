#include <iostream> 
using namespace std;
#include "Postac.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"

// klasa Postac

Postac::Postac(string imie, int punktyZycia, int zrecznosc, int sila, int poziom) : imie(imie), punktyZycia(punktyZycia), zrecznosc(zrecznosc), sila(sila), poziom(poziom)

{
	sila_ataku = sila;
	poziom_ochrony = zrecznosc;
	bron_w_reku = nullptr;
	zbroja_na_ciele = nullptr;
	artefakt = nullptr;
}

void Postac::odrzuc_bron() { if (bron_w_reku) delete bron_w_reku; bron_w_reku = nullptr; }

Postac::~Postac()
{
	if (bron_w_reku) delete bron_w_reku;
	if (zbroja_na_ciele) delete zbroja_na_ciele;
	if (artefakt) delete artefakt;
}

int Postac::wykonaj_atak(int poziom_ochrony_przeciwnika)
{
	if (sila_ataku > poziom_ochrony_przeciwnika)
	{
		if (bron_w_reku)
			return bron_w_reku->zadaj_obrazenia();
	}
	return 0;
}

void Postac::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

void Postac::info(ostream& out) const
{
	out << imie << " - calkowita sila ataku: " << sila_ataku << " calkowity poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia << endl;
	out << "Bron: " << endl;
	if (bron_w_reku)
		out << *bron_w_reku;
	else
		out << "Brak broni w rece" << endl;
	out << "Zbroja: " << endl;
	if (zbroja_na_ciele)
		out << *zbroja_na_ciele;
	else
		out << "Brak zbroi na ciele" << endl;
	out << "Artefakt: " << endl;
	if (artefakt)
		out << *artefakt;
	else
		out << "Brak artefaktow" << endl;
}

ostream& operator<<(ostream& out, const Postac& p)
{
	p.info(out);
	out << endl;
	return out;
}
