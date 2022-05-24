#include <iostream> 
#include "Zmija.h"
#include "Zdolnosc.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"
#include "Rycerz.h"
using namespace std;

void spotkanie(Zmija_Jadowita* zmija, Rycerz* mag);

int main()
{
	cout << endl << "-------------  ETAP 1 (2,5 pkt) --------------" << endl;
	
	{
	Zmija_Zwyczajna zmija;
	Zmija_Jadowita zmija_jadowita1, zmija_jadowita2;

	cout << zmija << zmija_jadowita1 << endl;

	cout << "Atakuje " << zmija << "- trafia i zadaje " << zmija.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << zmija << "- nie trafia i zadaje " << zmija.wykonaj_atak(8) << " obrazen" << endl;
	cout << "Broni sie " << zmija << "- trafiona za 20 obrazen!" << endl;
	zmija.przyjmij_atak(20);
	if (!zmija.czyZyje()) cout << zmija << "- zabita!!! Huraaaa!!!" << endl << endl;

	cout << "Atakuje " << zmija_jadowita1 << "- trafia i zadaje " << zmija_jadowita1.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << zmija_jadowita1 << "- nie trafia i zadaje " << zmija_jadowita1.wykonaj_atak(8) << " obrazen" << endl;
	cout << "A teraz druga zmija jadowita wkracza do walki (bedzie uzywala zatrucia)" << endl;
	cout << "Atakuje " << zmija_jadowita2 << "- (zawsze trafia) - trafia i zadaje " << zmija_jadowita2.wykonaj_atak(100) << " obrazen" << endl;
	cout << "Broni sie " << zmija_jadowita2 << "- trafiona za 20 obrazen!" << endl;
	zmija_jadowita2.przyjmij_atak(20);
	if (!zmija_jadowita2.czyZyje()) cout << zmija_jadowita2 << "- zabita!!! Huraaaa!!!" << endl << endl;
	}
	
	cout << endl << "-------------  ETAP 2 (2 pkt) --------------" << endl;
	
	Zdolnosc_Specjalna zs("Perfekcyjne ostrzenie broni", "dodatkowe 2 obrazenia", 2);
	Zdolnosc_Uzdrawiajaca zu("Opatrywanie ran", "leczy 4 obrazenia", 4);

	cout << zs << "Dodatkowe obrazenia zadane ostra bronia: " << zs.wykorzystaj_zdolnosc() << endl;
	cout << zu << "Uleczone punkty zycia: " << zu.wykorzystaj_zdolnosc() << endl;
	
	cout << endl << "-------------  ETAP 3  (2 pkt) --------------" << endl;
	
	Bron* miecz = new Bron("Miecz", "piekny miecz", 5);

	cout << *miecz;
	cout << "Atak mieczem - zadano " << miecz->zadaj_obrazenia() << " obrazenia" << endl;
	
	Zbroja* kolczuga = new Zbroja("Kolczuga", "klasyczna kolczuga", 3);

	cout << *kolczuga;
	cout << "Noszenie kolczugi poprawia obrone o " << kolczuga->wykorzystaj_ochrone() << " punkty" << endl;
	
	Artefakt* amulet = new Artefakt("Amulet zielonego kamienia", "amulet zwiekszajacy poziom ochrony", Artefakt::typ_artefaktu::MODYFIKUJACY_OCHRONE, 3);

	cout << *amulet;
	cout << "Amulet na szyi poprawia poziom ochrony o " << amulet->wykorzystaj_artefakt() << " punkty" << endl;

	delete miecz;
	delete kolczuga;
	delete amulet;
	
	cout << endl << "-------------  ETAP 4  (1,5 pkt) --------------" << endl;
	
	Rycerz Mathghamhain("Mathghamhain", 30, 5, 8, 3);
	cout << Mathghamhain << endl;

	cout << "Mathghamhain przygotowuje sie ...  zaklada zbroje, bierze bron, ostrzy ..." << endl << endl;
	Mathghamhain.przygotowanie();
	cout << Mathghamhain << endl;
	
	cout << endl << "-------------  ETAP 5  (2 pkt) --------------" << endl;
	
	cout << "Mathghamhain - trafia i zadaje " << Mathghamhain.wykonaj_atak(1) << " obrazen (atak mieczem)" << endl;
	cout << Mathghamhain << endl;
	cout << "Broni sie Mathghamhain - trafiony za 25 obrazen!" << endl;
	Mathghamhain.przyjmij_atak(25);
	cout << Mathghamhain << endl;
	cout << "Atakuje Mathghamhain - teraz sie leczy (<10 PZ) umiejetnoscia (Opatrywanie ran; ; po uzyciu bedzie ona niedostepne) wiec zadaje " << Mathghamhain.wykonaj_atak(1) << " obrazen" << endl;
	cout << Mathghamhain << endl;
	cout << "Broni sie Mathghamhain - trafiony za 5 obrazen!" << endl;
	Mathghamhain.przyjmij_atak(5);
	cout << Mathghamhain << endl;
	cout << "Atakuje Mathghamhain - (< 10 pkt zycia ale umiejetnosc niedostepna wiec ponownie atak mieczem) jednak nie trafia i zadaje " << Mathghamhain.wykonaj_atak(20) << " obrazen " << endl;
	cout << Mathghamhain << endl;
	

	
	cout << endl << "-------------  Symulacja --------------" << endl;
	
	Rycerz Summerled("Summerled", 28, 5, 8, 3);
	Zmija_Jadowita potwor1, potwor2;

	Summerled.przygotowanie();
	spotkanie(&potwor2, &Summerled);
	
	return 0;
}


void spotkanie(Zmija_Jadowita* zmija, Rycerz* rycerz)
{
	int i = 1;
	cout << "Witaj ! Musisz ocalic swiat przed atakiem Zmij" << endl;
	while (zmija->czyZyje() && rycerz->czyZyje())
	{
		cout << " ********** RUNDA " << i++ << " **********" << endl;
		cout << *rycerz << endl << *zmija << endl;
		// atakuje rycerz
		zmija->przyjmij_atak(rycerz->wykonaj_atak(zmija->jaki_poziom_ochrony()));
		if (zmija->czyZyje()) // atakuje zmija
			rycerz->przyjmij_atak(zmija->wykonaj_atak(rycerz->jaki_poziom_ochrony()));
	}
	cout << " ********** KONIEC WALKI **********" << endl;
	cout << *rycerz << endl << *zmija << endl;
	if (zmija->czyZyje())
		cout << "Polegles na polu chwaly" << endl;
	else
		cout << "Zwyciezyles !!! Swiat uratowany !! Dobrze, ze poszedles na nuki :)" << endl << endl;
}
