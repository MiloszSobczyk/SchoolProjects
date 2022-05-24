#pragma once

class tabD
{
	int n; //liczba elementow tablicy
	char* a; //wskaznik dymanicznej tablicy ciagu znakow
public:
	tabD();
	explicit tabD(int n, char ch = '0');
	tabD(int n, const char* tab);
	tabD(char ch);
	tabD(const tabD& A);
	char& operator[](int i);
	int size();

	void operator+(tabD& A);
	void operator+=(const char* elements);
	friend std::ostream& operator<<(std::ostream& out, const tabD A);
	friend std::istream& operator>>(std::istream& in, tabD A);

};