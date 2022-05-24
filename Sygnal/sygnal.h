#pragma once

class uklad_wspolrzednych;

class sygnal_cyfrowy
{
private:
	int* wartosc_probek;
	int liczba_danych;

public:
	sygnal_cyfrowy(int ilosc = 0, int* tab = nullptr);
	~sygnal_cyfrowy();

	int* get_probki() const { return wartosc_probek; }
	int get_ilosc() const { return liczba_danych; }
	void set_pierwsza_wartosc(int x) { wartosc_probek[0] = x; }
	sygnal_cyfrowy& operator+=(const sygnal_cyfrowy& s);
	sygnal_cyfrowy& operator=(const sygnal_cyfrowy& s);
	friend std::ostream& operator<<(std::ostream& out, const sygnal_cyfrowy& s);
	

	friend class uklad_wspolrzednych;
};
