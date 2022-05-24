#pragma once
#include <iostream> 
#include "sygnal.h"

class uklad_wspolrzednych
{
private:
	sygnal_cyfrowy** sygnaly;	//dynamiczna tablica wskaŸników do sygna³ów
	int liczba_sygnalow;
	int min;
	int max;
public:
	char** wykres;
	int wiersze;
	int kolumny;
	uklad_wspolrzednych(sygnal_cyfrowy* sygnal = nullptr);
	~uklad_wspolrzednych();

	void add(sygnal_cyfrowy* sygnal);

	friend std::ostream& operator<<(std::ostream&, const uklad_wspolrzednych&);

private:
	//void delete_wykres();// metoda pomocnicza
};