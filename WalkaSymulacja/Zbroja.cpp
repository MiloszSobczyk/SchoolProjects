#include <iostream> 
#include <string>
using namespace std;
#include "Zbroja.h"

// uzupelnij

Zbroja::Zbroja(string nazwa, string opis, int dodatkowa_ochrona) : Przedmiot::Przedmiot(nazwa, opis), dodatkowa_ochrona(dodatkowa_ochrona) { }

int Zbroja::wykorzystaj_ochrone() const
{
	return dodatkowa_ochrona;
}

void Zbroja::info(ostream& out) const
{
	Przedmiot::info(out);
	out << " Ochrona: " << dodatkowa_ochrona;
}




