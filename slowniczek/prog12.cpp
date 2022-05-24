#pragma once
#include <iostream>
using namespace std;
#include <list>
#include <string>
#include <ctime>
#include "kryteria.h"
#include "slowko.h"
#include "slownik.h"
//------------------------------------------------------
  
int main()
{
	
	cout<<"---------------- TEST klasy slowko -----------------"<<endl;
	slowko s1;
	slowko s2("kot","cat"), s3("pies","dog");
	
	cout<<s2<<s3;
	
	cout<<s2.get_pol()<<endl;

	if (s2==s3)
		cout<<"takie same"<<endl;
	else
		cout<<"NIE takie same"<<endl;
	
	if (pol_ang(s2,s3)) 	cout<<"pol_ang: s2 jest pierwsze"<<endl;
	if (ang_pol(s2,s3)) 	cout<<"ang_pol: s2 jest pierwsze"<<endl;
	
	cout<<"Podaj slowko"<<endl;
	cin>>s1;

	if (s2==s1)
		cout<<"takie same"<<endl;
	else
		cout<<"NIE takie same"<<endl;
	
	//----------------------------------------------------------------------

	

	srand((unsigned)time(0));

	slownik		S;
	
		
	if (!S.wczytaj_slowka("slowka_dnia.txt")) 
	{
		cout<<"Brak pliku"<<endl;
		return 0;
	}
	
	int	K;
	do  {
				cout<<S;	//wypisanie slownika

                cout<<"\nMENU:"<<endl;
                cout<<"1 - SORTOWANIE listy wg pola POL"<<endl;
                cout<<"2 - SORTOWANIE listy wg pola ANG"<<endl;
                cout<<"3 - DOPISZ slowko"<<endl;
				cout<<"4 - TEST"<<endl;
				cout<<"5 - ZAPISZ slownik"<<endl;
                cout<<"0 - KONIEC"<<endl;
                cout<<"*** Podaj numer opcji:  ";
                
				cin>>K;
                switch (K)
                {
					case 1:	//SORTOWANIE slownika wg pola POL
						S.jak_posortowany=slownik::POL_ANG;
						S.sortowanie(pol_ang);
						break;
			
                    case 2:	//SORTOWANIE slownika wg pola ANG
						S.jak_posortowany=slownik::ANG_POL;
						S.sortowanie(ang_pol);
						break;
        
                    case 3:	//DOPISZ slowko
						S.wstaw();
						break;
					
					case 4: //TEST
						S.test();
						break;
					
					case 5: //ZAPIS
						if (!S.zapisz_slowka()) cout<<"Brak zapisu"<<endl;
						break;
                }//switch
	} while (K != 0);




}	

