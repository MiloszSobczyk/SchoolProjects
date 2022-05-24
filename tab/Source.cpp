#include <iostream>
#include "tabD.h"

char tab[] = "1234567";
const char* s = "54321";

int main()
{
	tabD b(14, tab), c(5, 'c'), d('d');
	tabD e = c;
	e[2] = '5';
	e + c;
	e += "6666";
	std::cout << b << c << d << e;
}