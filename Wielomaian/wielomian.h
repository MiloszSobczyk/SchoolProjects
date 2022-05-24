#pragma once

const int N = 11;

class wielomian
{
	int n; //obecny stopien wielomianu + 1
	double tab[N]; //tablica wspolczynnikow
public:
	wielomian();
	wielomian(int n, double* a = nullptr);
	double operator()(double x) const;
	wielomian& operator++();
	wielomian& operator--();
	
	friend wielomian operator+(const wielomian& w, const wielomian& v);
	friend wielomian operator-(const wielomian& w, const wielomian& v);
	friend wielomian operator*(int skalar, const wielomian& w);

	friend std::ostream& operator<<(std::ostream& out, wielomian& w);
	friend std::istream& operator>>(std::istream& in, wielomian& w);
};