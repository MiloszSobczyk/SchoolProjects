#pragma once
#include <list>
#include "slowko.h"


using std::list;
using fun=bool (*)(const slowko&, const slowko&);

class slownik
{
	list<slowko> L;

public:
	enum sortowanie_slownika { BRAK, POL_ANG, ANG_POL } jak_posortowany=BRAK;

public:
	bool wczytaj_slowka(string nazwa_pliku);

	void sortowanie(fun kryterium);

	void wstaw();

	bool znajdz_slowko(slowko s) const;
	void test() const;

	bool zapisz_slowka() const;
	
	friend ostream& operator<<(ostream& out, const slownik& S);

};

