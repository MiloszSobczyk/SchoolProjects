#include <iostream>
#include "wielomian.h"

wielomian::wielomian() { };

wielomian::wielomian(int n, double* a)
{
	if (n > 11)
	{
		n = 11;
	}
	this->n = n;
	for (int i = 0; i < n + 1; i++)
	{
		this->tab[i] = a[i];
	}
}

double wielomian::operator()(double x) const
{	
	double wynik = this->tab[this->n];
	for (int i = this->n; i > 0; i--)
	{
		wynik *= x;
		wynik += this->tab[i - 1];
	}
	return wynik;
}

wielomian& wielomian::operator++()
{
	double tab[N];
	for (int i = 0; i < this->n + 1; i++)
	{
		tab[i] = 1;
	}
	*this = *this + wielomian(this->n, tab);
	return *this;
}

wielomian& wielomian::operator--()
{
	double tab[N];
	for (int i = 0; i < this->n + 1; i++)
	{
		tab[i] = -1;
	}
	*this = *this + wielomian(this->n, tab);
	return *this;
}

wielomian operator+(const wielomian& w, const wielomian& v)
{
	if (w.n == 0 && v.n == 0)
	{
		return wielomian(0);
	}
	double tab[N];
	int n;
	if (w.n >= v.n)
	{
		n = w.n;
		for (int i = 0; i < v.n + 1; i++)
		{
			tab[i] = w.tab[i] + v.tab[i];
		}
		for (int i = v.n + 1; i < w.n + 1; i++)
		{
			tab[i] = w.tab[i];
		}
	}
	else
	{	
		n = v.n;
		for (int i = 0; i < w.n + 1; i++)
		{
			tab[i] = w.tab[i] + v.tab[i];
		}
		for (int i = w.n + 1; i < v.n + 1; i++)
		{
			tab[i] = v.tab[i];
		}
	}
	while (tab[n] == 0)
	{
		n--;
	}
	return wielomian(n, tab);
}

wielomian operator*(int skalar, const wielomian& w)
{
	double tab[N];
	if (skalar == 0)
	{
		tab[0] = 0;
		return wielomian(0, tab);
	}
	for (int i = 0; i < w.n + 1; i++)
	{
		tab[i] = skalar * (w.tab[i]);
	}
	return wielomian(w.n, tab);
}

wielomian operator-(const wielomian& w, const wielomian& v)
{
	return (w + ((-1) * v));
}


std::ostream& operator<<(std::ostream& out, wielomian& w)
{
	out << "Stopien wielomianu: " << w.n << std::endl << "Wspolczynniki wielomianu: ";
	out << "[";
	for (int i = 0; i < w.n + 1; i++)
	{
		out << " " << w.tab[i];
	}
	out << " ]" << std::endl;
	return out;
}