#include <iostream> 
using namespace std;
#include "Zdolnosc.h"

// klasa Zdolnosc

Zdolnosc::Zdolnosc(string nazwa, string opis) : nazwa(nazwa), opis(opis) {}

void Zdolnosc::info(ostream& out) const
{
	out << nazwa << " (" << opis << ", dostepnosc " << dostepnosc << " ) ";
}

ostream& operator<<(ostream& out, const Zdolnosc& p)
{
	p.info(out);
	out << endl;
	return out;
}

// klasa Zdolnosc_Specjalna

Zdolnosc_Specjalna::Zdolnosc_Specjalna(string nazwa, string opis, int modyfikator) : Zdolnosc::Zdolnosc(nazwa, opis), modyfikator(modyfikator) 
{
	dostepnosc = true;
}

int Zdolnosc_Specjalna::wykorzystaj_zdolnosc()
{	
	if (dostepnosc == true)
	{
		dostepnosc = false;
		return modyfikator;
	}
	return 0;
}

void Zdolnosc_Specjalna::info(ostream& out) const
{
	Zdolnosc::info(out);
	out << " Modyfikator obrazen: " << modyfikator;
}

// klasa Zdolnosc_Uzdrawiajaca

Zdolnosc_Uzdrawiajaca::Zdolnosc_Uzdrawiajaca(string nazwa, string opis, int uleczone_punkty_zycia) : Zdolnosc::Zdolnosc(nazwa, opis),uleczone_punkty_zycia(uleczone_punkty_zycia)
{
	dostepnosc = true;
};

int Zdolnosc_Uzdrawiajaca::wykorzystaj_zdolnosc()
{
	if (dostepnosc == true)
	{
		dostepnosc = false;
		return uleczone_punkty_zycia;
	}
	return 0;
}

void Zdolnosc_Uzdrawiajaca::info(ostream& out) const
{
	Zdolnosc::info(out);
	out << " Punkty zycia do uleczenia: " << uleczone_punkty_zycia;
}