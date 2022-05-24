#include <iostream>
#include <math.h>
#include "sygnal.h"
#include "uklad_wspolrzednych.h"


int main()
{

	std::cout << "===================== ETAP 1 =====================" << std::endl;

	// Konstruktor bezargumentowy
	sygnal_cyfrowy sygnal_1;
	// Konstruktor z sygna³em zerowym
	sygnal_cyfrowy* sygnal_2 = new sygnal_cyfrowy(10);
	// Konstruktor z sygna³em prostokatnym
	int s3[20] = { 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5 };
	sygnal_cyfrowy sygnal_3(20, s3);
	// Konstruktor z sygna³em trójk¹tnym
	int s4[50] = { 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10,
				  -8, -6, -4, -2, 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4 };
	sygnal_cyfrowy sygnal_4(30, s4);
	// Konstruktor z sygna³em sta³ym
	int s5[25] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	sygnal_cyfrowy sygnal_5(20, s5);

	std::cout << "Pusty sygnal - nic sie nie wyswietla" << std::endl;
	std::cout << sygnal_1 << std::endl;
	std::cout << "Sygnal zerowy - same zera" << std::endl;
	std::cout << *sygnal_2 << std::endl;
	std::cout << "Sygnal prostokatny" << std::endl;
	std::cout << sygnal_3 << std::endl;
	std::cout << "Sygnal trojkatny" << std::endl;
	std::cout << sygnal_4 << std::endl;

	std::cout << "Suma sygnalow sta³ego i trojkatnego" << std::endl;
	std::cout << (sygnal_5 += sygnal_4) << std::endl;

	std::cout << "Kolejne sygnaly powinny byc rozne (pierwsza liczba)" << std::endl;
	sygnal_cyfrowy sygnal_6;
	sygnal_6 = sygnal_5;
	sygnal_6.set_pierwsza_wartosc(100);
	std::cout << " I: " << std::endl << sygnal_5 << std::endl;
	std::cout << "II: " << std::endl << sygnal_6 << std::endl;

	int* p = sygnal_2->get_probki();
	delete sygnal_2;
	if (p[0] != 0) std::cout << "Etap 1 - OK" << std::endl;
	else std::cout << "Czegos jeszcze brakuje..." << std::endl;

	std::cout << std::endl;
	std::cout << "===================== ETAP 2 =====================" << std::endl;

	uklad_wspolrzednych uklad_1;
	uklad_wspolrzednych uklad_2 (&sygnal_3);
	
	std::cout << "Pusty wykres - nic sie nie rysuje" << std::endl;
	std::cout << uklad_1 << std::endl;
	std::cout << "Wykres sygnalu prostokatnego" << std::endl;
	std::cout << uklad_2 << std::endl;
	std::cout << "Wykres dwoch sygnalow" << std::endl;
	uklad_2.add(&sygnal_4);
	std::cout << uklad_2 << std::endl;
	std::cout << "Wykres trzech sygnalow" << std::endl;
	sygnal_cyfrowy sygnal_p(25, s5);
	uklad_2.add(&sygnal_p);
	std::cout << uklad_2 << std::endl;
	
	return 0;
}