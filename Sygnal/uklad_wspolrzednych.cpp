#include <iostream> 
#include "sygnal.h"
#include "uklad_wspolrzednych.h"

uklad_wspolrzednych::~uklad_wspolrzednych()
{
	delete[] this->sygnaly;
	delete[] this->wykres;
}

uklad_wspolrzednych::uklad_wspolrzednych(sygnal_cyfrowy* sygnal) : liczba_sygnalow{ 1 }, wiersze{ 0 }, kolumny{ 0 }, max { 0 }, min { 0 }
{
	if (sygnal == nullptr) return;
	this->kolumny = sygnal->get_ilosc();
	for (int i = 0; i < this->kolumny; i++)
	{
		if (sygnal->get_probki()[i] > this->max)
		{
			this->max = sygnal->get_probki()[i];
		}
		else if (sygnal->get_probki()[i] < this->min)
		{
			this->min = sygnal->get_probki()[i];
		}
	}

	this->wiersze = this->max - this->min + 1;
	this->wykres = new char* [this->wiersze];

	for (int i = 0; i < this->wiersze; i++)
	{
		this->wykres[i] = new char[this->kolumny];
	}
	for (int i = 0; i < this->wiersze; i++)
	{
		for (int j = 0; j < this->kolumny; j++)
		{
			this->wykres[i][j] = ' ';
		}
	}
	for (int i = 0; i < this->kolumny; i++)
	{
		this->wykres[this->max - sygnal->get_probki()[i]][i] = '*';
	}
}

void uklad_wspolrzednych::add(sygnal_cyfrowy* sygnal)
{
	if (sygnal == nullptr) return;

	int max_old = this->max;
	int min_old = this->min;
	int kolumny_old = this->kolumny;
	int wiersze_old = this->wiersze;

	for (int i = 0; i < sygnal->liczba_danych; i++)
	{
		if (sygnal->get_probki()[i] > this->max)
		{
			this->max = sygnal->get_probki()[i];
		}
		else if (sygnal->get_probki()[i] < this->min)
		{
			this->min = sygnal->get_probki()[i];
		}
	}
	if (sygnal->liczba_danych > this->kolumny)
	{
		this->kolumny = sygnal->liczba_danych;
	}

	if (this->max == max_old && this->min == min_old && this->kolumny == kolumny_old)
	{
		for (int i = 0; i < sygnal->get_ilosc(); i++)
		{
			this->wykres[this->max - sygnal->get_probki()[i]][i] = '*';
		}
		return;
	}
	
	if (sygnal->get_ilosc() > this->kolumny) this->kolumny = sygnal->get_ilosc();
	this->wiersze = this->max - this->min + 1;

	int** wykres_pom = new int* [this->wiersze];
	for (int i = 0; i < this->wiersze; i++)
	{
		wykres_pom[i] = new int[this->kolumny];
	}
	
	for (int i = 0; i < this->wiersze; i++)
	{
		for (int j = 0; j < this->kolumny; j++)
		{
			wykres_pom[i][j] = ' ';
		}
	}

	for (int i = 0; i < kolumny_old; i++)
	{
		for (int j = 0; j < wiersze_old; j++)
		{
			wykres_pom[j + this->max - max_old][i] = wykres[j][i];
		}
	}

	for (int i = 0; i < this->kolumny; i++)
	{
		wykres_pom[this->max - sygnal->get_probki()[i]][i] = '*';
	}
	
	for (int i = 0; i < wiersze_old; i++)
	{
		delete[] this->wykres[i];
	}
	
	this->wykres = new char* [this->wiersze];
	for (int i = 0; i < this->wiersze; i++)
	{
		this->wykres[i] = new char[this->kolumny];
	}

	for (int i = 0; i < this->wiersze; i++)
	{
		for (int j = 0; j < this->kolumny; j++)
		{
			this->wykres[i][j] = wykres_pom[i][j];
		}
		delete[] wykres_pom[i];
	}
}


std::ostream& operator<<(std::ostream& out, const uklad_wspolrzednych& u)
{
	for (int i = 0; i < u.kolumny; i++)
	{
		out << '-';
	}
	out << std::endl;
	for (int i = 0; i < u.wiersze; i++)
	{
		for (int j = 0; j < u.kolumny; j++)
		{
			out << u.wykres[i][j];
		}
		out << std::endl;
	}
	for (int i = 0; i < u.kolumny; i++)
	{
		out << '-';
	}
	return out;
}