#pragma once
#include "slowko.h"


bool pol_ang(const slowko& s1, const slowko& s2)
{
	if (s1.pol == s2.pol)
	{
		return (s1.ang < s2.ang);
	}
	return s1.pol < s2.pol;
}

bool ang_pol(const slowko& s1, const slowko& s2)
{
	if (s1.ang == s2.ang)
	{
		return (s1.pol < s2.pol);
	}
	return s1.ang < s2.ang;
}
