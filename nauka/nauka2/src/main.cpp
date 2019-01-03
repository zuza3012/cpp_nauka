#include "figura.h"
#include "okrag.h"
#include "kwadrat.h"
#include "trojkat.h"
#include "punkt.h"
int main (int argc, char** argv){
	
	//Figura f1;
	//f1.Wypisz();
	//cout << endl;
	
	
	Punkt p1(0,-1);
	Punkt p2(45, 7);
	Punkt p3(34, -9);
	Punkt *tab;
	tab = new Punkt [3];
	tab[0] = p1;
	tab[1] = p2;
	tab[2] = p3;
	
	//Figura f2(tab, 3);
	//f2.Wypisz();
	
	//Figura f3(f2);
	//f3.Wypisz();
	
	Kwadrat k1;
	k1.Wypisz();
	Punkt pp1(2, 2);
	Punkt pp2(2, -2);
	Punkt pp3(-2, 2);
	Punkt pp4(2, -2);
	
	Punkt *tab2;
	tab2 = new Punkt [4];
	tab2[0] = pp1;
	tab2[1] = pp2;
	tab2[2] = pp3;
	tab2[3] = pp4;
	
	Kwadrat k2(tab2, 4, 4);
	k2.Wypisz();
	
	Kwadrat k3(k2);
	k3.Wypisz();
	
	Kwadrat *wsk;
	wsk = &k3;
	wsk -> Wypisz();
	
	Trojkat t1;
	Trojkat t2(tab, 3, 3, 4.7);
	Trojkat t3(t2);
	
	t1.Wypisz();
	t2.Wypisz();
	t3.Wypisz();
	
	Okrag o1;
	o1.Wypisz();
	
	Punkt *tab3;
	tab3 = new Punkt [1];
	tab3[0] = pp2;
	
	Okrag o2(tab3, 1, 5);
	o2.Wypisz();
	
	Okrag o3(o2);
	o3.Wypisz();
	
	//zastosowanie virtuala
	Figura *wskF;
	wskF = &o3;
	wskF -> Wypisz();
	
	DajDane(k2);
	
	delete [] tab;
	delete [] tab2;
	delete [] tab3;
	return 0;

}
