#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Przedmiot
{
protected:
	string nazwa;
	string opis;
public:
	Przedmiot(string nazwa, string opis);
	virtual ~Przedmiot() {};
	virtual void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Przedmiot&);
};

