#pragma once
#include <iostream>
#include "tabD.h"

tabD::tabD() : n{ 0 }, a{ nullptr } {};

tabD::tabD(int n, char ch)
{	
	if (n <= 0)
	{
		this->n = 0;
		this->a = nullptr;
		return;
	}
	this->n = n;
	this->a = new (std::nothrow) char[n];
	if (a == nullptr)
	{
		std::cout << "Array initialization failed" << std::endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		(this->a)[i] = ch;
	}
}

tabD::tabD(int n, const char* tab)
{	
	if (n <= 0)
	{
		this->n = 0;
		this->a = nullptr;
		return;
	}
	if (n > strlen(tab))
	{
		n = strlen(tab);
	}
	this->n = n;
	this->a = new (std::nothrow) char[n];
	if (this->a == nullptr)
	{
		std::cout << "Array initialization failed" << std::endl;
	}
	std::copy(tab, tab + n, a);
}

tabD::tabD(char ch)
{
	this->n = 1;
	this->a = new (std::nothrow) char[1];
	if (this->a == nullptr)
	{
		std::cout << "Array initialization failed" << std::endl;
		return;
	}
	this->a[0] = ch;
}

tabD::tabD(const tabD& A)
{
	this->n = A.n;
	this->a = new (std::nothrow) char[this->n];
	if (a == nullptr)
	{
		std::cout << "Array initialization failed" << std::endl;
		return;
	}
	for (int i = 0; i < this->n; i++)
	{
		this->a[i] = A.a[i];
	}
}
char& tabD::operator[](int i)
{
	if (i >= this->n)
	{
		i = 0;
	}
	return (this->a)[i];
}

int tabD::size()
{
	return 1 * n; //sizeof(char) * number of elements
}

void tabD::operator+(tabD& A)
{
	char* tab = new (std::nothrow) char[this->n + A.n];
	if (tab == nullptr)
	{
		return;
	}
	for (int i = 0; i < this->n; i++)
	{
		tab[i] = this->a[i];
	}
	for (int i = 0; i < A.n; i++)
	{
		tab[this->n + i] = A[i];
	}
	this->n += A.n;
	delete[](this->a);
	this->a = tab;
}

void tabD::operator+=(const char* elements)
{
	tabD temp(strlen(elements), elements);
	this->operator+(temp);
}
std::ostream& operator<<(std::ostream& out, const tabD A)
{
	out << "Array size: " << A.n << std::endl;
	for (int i = 0; i < A.n; i++)
	{
		out << A.a[i];
	}
	out << std::endl;
	return out;
}

//std::istream& operator>>(std::istream& in, tabD A)
//{
//	;
//}