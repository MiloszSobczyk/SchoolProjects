#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Przedmiot.h"

class Artefakt : public Przedmiot
{
public:
	enum class typ_artefaktu { MODYFIKUJACY_ATAK, MODYFIKUJACY_OCHRONE };
protected:
	int modyfikator;
	typ_artefaktu typ;
public:
	Artefakt(string nazwa, string opis, typ_artefaktu typ, int modyfikator);
	typ_artefaktu jaki_typ_artefaktu() const { return typ; }
	virtual int wykorzystaj_artefakt() const;
	void info(ostream&) const override;
}; 
