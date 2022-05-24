#include <iostream> 
using namespace std;
#include "Rycerz.h"
#include "Przedmiot.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"
#include "Zdolnosc.h"

// klasa Rycerz


Rycerz::Rycerz(string imie, int punktyZycia, int zrecznosc, int sila, int poziom) : Postac(imie, punktyZycia, zrecznosc, sila, poziom)
{
	zdolnosci = new (nothrow) Zdolnosc*[liczba_zdolnosci];
	zdolnosci[0] = new Zdolnosc_Specjalna("Perfekcyjne ostrzenie broni", "dodatkowe 2 obrazenia", 2);
	zdolnosci[1] = new Zdolnosc_Uzdrawiajaca("Opatrywanie ran", "leczy 4 obrazenia", 4);

	for (int i = 0; i < wielkosc_ekwipunku; i++)
		ekwipunek[i] = nullptr;
	ekwipunek[0] = new Bron("Miecz", "doskonaly miecz", 5);
	ekwipunek[1] = new Przedmiot("Butelka", "butelka z woda pitna");
	ekwipunek[2] = new Bron("Sztylet", "sztylet krotki", 1);
	ekwipunek[3] = new Zbroja("Kolczuga", "klasyczna kolczuga", 3);
}

Rycerz::~Rycerz()
{
	for (int i = 0; i < liczba_zdolnosci; ++i)
	{
		delete(zdolnosci[i]);
	}
	delete[] (zdolnosci);
	for (int i = 0; i < wielkosc_ekwipunku; ++i)
	{
		delete(ekwipunek[i]);
	}
}

void Rycerz::info(ostream& out) const
{
	Postac::info(out);
	cout << "Modyfikator obrazen: " << modyfikator_obrazen << endl;
	cout << "Zdolnosci: " << endl;
	for (int i = 0; i < liczba_zdolnosci; i++)
		out << *zdolnosci[i];
	cout << "Ekwipunek: " << endl;
	for (int i = 0; i < wielkosc_ekwipunku; i++)
	{
		if (ekwipunek[i])
			out << i + 1 << ". " << *ekwipunek[i];
		else
			out << i + 1 << ". " << "pusto" << endl;
	}
}


void Rycerz::przygotowanie()
{
	for (int i = 0; i < wielkosc_ekwipunku; ++i)
	{
		Bron* pb = dynamic_cast<Bron*>(ekwipunek[i]);
		if (pb)
		{
			bron_w_reku = pb;
			ekwipunek[i] = nullptr;
			break;
		}
	}

	for (int i = 0; i < wielkosc_ekwipunku; ++i)
	{
		Zbroja* pz = dynamic_cast<Zbroja*>(ekwipunek[i]);
		if (pz)
		{
			zbroja_na_ciele = pz;
			poziom_ochrony += zbroja_na_ciele->wykorzystaj_ochrone();
			ekwipunek[i] = nullptr;
			break;
		}
	}

	for (int i = 0; i < wielkosc_ekwipunku; ++i)
	{
		Artefakt* pa = dynamic_cast<Artefakt*>(ekwipunek[i]);
		if (pa)
		{
			artefakt = pa;
			if (artefakt->jaki_typ_artefaktu() == Artefakt::typ_artefaktu::MODYFIKUJACY_ATAK)
			{
				sila_ataku += artefakt->wykorzystaj_artefakt();
			}
			else
			{
				poziom_ochrony += artefakt->wykorzystaj_artefakt();
			}
			ekwipunek[i] = nullptr;
			break;
		}
	}
	for (int i = 0; i < liczba_zdolnosci; ++i)
	{
		zdolnosci[i]->dostepnosc = true;
	}
}

int Rycerz::czy_dostepna_specjalna() const
{
	for (int i = 0; i < liczba_zdolnosci; ++i)
	{
		Zdolnosc_Specjalna* pz = dynamic_cast<Zdolnosc_Specjalna*>(zdolnosci[i]);
		if (pz && zdolnosci[i]->dostepnosc)
		{
			return i;
		}
	}
	return -1;
}

int Rycerz::czy_dostepna_uzdrawiajaca() const
{
	for (int i = 0; i < liczba_zdolnosci; ++i)
	{
		Zdolnosc_Uzdrawiajaca* pz = dynamic_cast<Zdolnosc_Uzdrawiajaca*>(zdolnosci[i]);
		if (pz && zdolnosci[i]->dostepnosc)
		{
			return i;
		}
	}
	return -1;
}

int Rycerz::wykonaj_atak(int poziom_ochrony_przeciwnika)
{
	if (punktyZycia < 10 && czy_dostepna_uzdrawiajaca() != -1)
	{
		punktyZycia += zdolnosci[czy_dostepna_uzdrawiajaca()]->wykorzystaj_zdolnosc();
		return 0;
	}
	if (sila > poziom_ochrony_przeciwnika)
	{
		if (czy_dostepna_specjalna() != -1)
		{
			return Postac::wykonaj_atak(poziom_ochrony_przeciwnika) + zdolnosci[czy_dostepna_specjalna()]->wykorzystaj_zdolnosc();
		}
		return Postac::wykonaj_atak(poziom_ochrony_przeciwnika);
	}
}