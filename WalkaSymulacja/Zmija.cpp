#include <iostream> 
using namespace std;
#include "Zmija.h"

int Zmija_Jadowita::ile_zmij = 0;

// Klasa Zmija

void Zmija::przyjmij_atak(int obrazenia)
{
	punkty_zycia -= obrazenia;
}

ostream& operator<<(ostream& out, const Zmija& p)
{
	p.info(out);
	return out;
}

// Klasa Zmija_Zwyczjna

int Zmija_Zwyczajna::ugryzienie() const
{
	return 3;
}

int Zmija_Zwyczajna::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if (sila_ataku > poziom_ochrony_przeciwnika)
	{
		return ugryzienie();
	}
	return 0;
}

const char* Zmija_Zwyczajna::nazwa() const
{
	return "Zmija Zwyczajna";
}

void Zmija_Zwyczajna::info(ostream& out) const
{
	out << nazwa() << " - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punkty_zycia << endl;
}

// Klasa Zmija_Jadowita

Zmija_Jadowita::Zmija_Jadowita() : numer_zmiji(++ile_zmij)
{
	punkty_zycia *= 2;
	sila_ataku *= 2;
	poziom_ochrony *= 2;
}

int Zmija_Jadowita::ugryzienie() const
{
	return 5;
}

int Zmija_Jadowita::zatrucie() const
{
	return ugryzienie() * 2;
}

int Zmija_Jadowita::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if (numer_zmiji % 2 == 0)
	{
		return zatrucie();
	}
	Zmija_Zwyczajna::wykonaj_atak(poziom_ochrony_przeciwnika);
}

const char* Zmija_Jadowita::nazwa() const
{
	return "Zmija Jadowita";
}