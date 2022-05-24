#pragma once
#include <iostream>
#include <string>


using std::string;
using std::ostream;
using std::istream;


class slowko
{
	string ang;	
	string pol;	
public:
	slowko(string pol="", string ang="");
	    	
	string get_pol() const {return pol;}

	friend bool pol_ang(const slowko& s1, const slowko& s2);	
	friend bool ang_pol(const slowko& s1, const slowko& s2);

	friend bool operator==(const slowko& s1, const slowko& s2);

	friend ostream& operator<<(ostream& out, const slowko& s);
	friend istream& operator>>(istream& in, slowko& s);

};