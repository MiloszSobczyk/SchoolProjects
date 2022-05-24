#include <iostream> 
#include "sygnal.h"

sygnal_cyfrowy::sygnal_cyfrowy(int ilosc, int* tab) : liczba_danych{ilosc}, wartosc_probek{nullptr}
{
	if (ilosc > 0)
	{
		this->wartosc_probek = new int[ilosc];
	}
	
	if (tab == nullptr)
	{
		for (int i = 0; i < ilosc; i++)
		{
			this->wartosc_probek[i] = 0;
		}
		return;
	}

	for (int i = 0; i < ilosc; i++)
	{
		this->wartosc_probek[i] = tab[i];
	}
}

sygnal_cyfrowy::~sygnal_cyfrowy()
{
	delete[] this->wartosc_probek;
}

std::ostream& operator<<(std::ostream& out, const sygnal_cyfrowy& s)
{
	out << '{';
	for (int i = 0; i < s.liczba_danych; i++)
	{
		out << ' ' << s.wartosc_probek[i];
	}
	out << " }";
	return out;
}

sygnal_cyfrowy& sygnal_cyfrowy::operator+=(const sygnal_cyfrowy& s)
{
	if (this->liczba_danych >= s.liczba_danych)
	{
		for (int i = 0; i < s.liczba_danych; i++)
		{
			this->wartosc_probek[i] += s.wartosc_probek[i];
		}
		return *this;
	}
	if (this->liczba_danych < s.liczba_danych)
	{
		int* tab = new int[s.liczba_danych];
		for (int i = 0; i < s.liczba_danych; i++)
		{
			tab[i] = s.wartosc_probek[i];
		}
		for (int i = 0; i < this->liczba_danych; i++)
		{
			tab[i] += this->wartosc_probek[i];
		}
		delete[] this->wartosc_probek;
		this->wartosc_probek = tab;
		return *this;

	}
}

sygnal_cyfrowy& sygnal_cyfrowy::operator=(const sygnal_cyfrowy& s)
{
	if (this == &s)
	{
		return *this;
	}
	this->liczba_danych = s.liczba_danych;
	delete[] this->wartosc_probek;
	this->wartosc_probek = new int[this->liczba_danych];
	for (int i = 0; i < this->liczba_danych; i++)
	{
		this->wartosc_probek[i] = s.wartosc_probek[i];
	}
	return *this;
}












