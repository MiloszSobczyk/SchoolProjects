#include <iostream> 
using namespace std;
#include "Bron.h"

// klasa Bron

Bron::Bron(string nazwa, string opis, int obrazenia) : Przedmiot(nazwa, opis), obrazenia(obrazenia) {}

int Bron::zadaj_obrazenia() const
{
	return obrazenia;
}

void Bron::info(ostream& out) const
{
	Przedmiot::info(out);
	out << "Obrazenia: " << obrazenia;
}

