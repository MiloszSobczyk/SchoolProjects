#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Przedmiot.h"

class Zbroja : public Przedmiot
{
protected:
	int dodatkowa_ochrona;
public:
	Zbroja(string nazwa, string opis, int dodatkowa_ochrona);
	virtual int wykorzystaj_ochrone() const;
	void info(ostream&) const override;
};



