#include <iostream>
#include "wielomian.h"


int main()
{	
	double a[3] = { 1, 2, 1 };
	double b[4] = { 4, 0, -2, -1 };
	wielomian w(2, a);
	std::cout << w(15);

	


}