#include <fstream>
#include <iomanip>
#include "slownik.h"
using namespace std;

//------------------------------------------------------
bool slownik::wczytaj_slowka(string nazwa_pliku)
{
	fstream plik;
	plik.open(nazwa_pliku, ios::in);
	if (!plik)
	{
		cout << "Nie mozna otworzyc pliku" << endl;
		return false;
	}
	
	slowko nowy;
	while (!plik.eof())
	{
		plik >> nowy;
		L.push_back(nowy);
	}
	plik.close();
	return true;
}

//------------------------------------------------------
void slownik::sortowanie(fun kryterium)
{
	L.sort(kryterium);
}

//------------------------------------------------------
void slownik::wstaw()
{
	slowko s;
	cin >> s;
	if (jak_posortowany == sortowanie_slownika::BRAK)
	{
		L.push_back(s);
		return;
	}

	list<slowko>::const_iterator cit = L.begin();
	if (jak_posortowany == sortowanie_slownika::POL_ANG)
	{
		for (cit; cit != L.end(); ++cit)
		{
			if (pol_ang(s, *cit))
			{
				break;
			}
		}
	}
	else if (jak_posortowany == sortowanie_slownika::POL_ANG)
	{
		for (cit; cit != L.end(); ++cit)
		{
			if (ang_pol(s, *cit))
			{
				break;
			}
		}
	}
	L.insert(cit, s);


}

//------------------------------------------------------
bool slownik::znajdz_slowko(slowko s) const
{
	for (const slowko& inne : L)
	{
		if (inne == s)
		{
			return true;
		}
	}

	return false;
}

//------------------------------------------------------
void slownik::test() const
{
	int N = L.size();
	int nr = rand() % N;
	auto cit = L.cbegin();
	advance(cit, nr);

	cout << "Wylosowane slowko polskie: " << cit->get_pol() << endl;

	string odpowiedz;
	cout << "Wprowadz angielskie slowko: ";
	cin >> odpowiedz;

	slowko s(cit->get_pol(), odpowiedz);
	if (znajdz_slowko(s))
	{
		cout << "Dobra odpowiedz!" << endl;
	}
	else
	{
		cout << "Poucz sie jeszcze!" << endl;
	}
}

//------------------------------------------------------
bool slownik::zapisz_slowka() const
{
	string nazwa;
	cout << "Podaj nazwe pliku :";
	cin >> nazwa;

	ifstream test(nazwa);
	if (test)
	{
		cout << "Plik juz istnieje. Podaj inna nazwe." << endl;
		test.close();
		return false;
	}
	test.close();
	ofstream plik(nazwa);
	if (!plik)
	{
		cout << "Nie udalo sie utworzyc pliku." << endl;
		return false;
	}

	plik << *this;
	plik.close();

	return true;

}

//------------------------------------------------------
ostream& operator<<(ostream& out, const slownik& S)
{
	int i = 0;

	for (auto cit = S.L.cbegin(); cit != S.L.cend(); ++cit)
	{
		if (&out == &cout)
		{
		out << setw(4) << right << ++i << '.' << * cit;
		}
		else
		{
			out << *cit;
		}
	}

	return out;
}

//------------------------------------------------------
