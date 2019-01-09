#include "macierz.h"

int main (int argc, char** argv){
	srand(time(NULL));
	
	Macierz m1;
	m1.Wypisz();
	m1.Wpisz(0,1,9);
	m1.Wypisz();
	
	Macierz m2;
	m2.Losuj();
	m2.Wypisz();
	
	m2.Zapisz(argv[1], "Macierz A");
	Macierz m3;
	m3.Wczytaj(argv[2],3,3);
	m3.Wypisz();
	
	cout << m3(1,2) << endl;
	Macierz p1;
	p1.Losuj();
	cout << "Macierz p1" << endl;
	p1.Wypisz();
	
	Macierz p2;
	p2.Losuj();
	cout << "Macierz p2" << endl;
	p2.Wypisz();
	
	cout << "p1+p2" << endl;
	(p1+p2).Wypisz();
	
	cout <<"Mnozenie macierzy" << endl;
	Macierz r1(2,2);
	r1.Losuj();
	cout << "Macierz r1" << endl;
	r1.Wypisz();
	
	Macierz r2(2,2);
	r2.Losuj();
	cout << "Macierz r2" << endl;
	r2.Wypisz();
	
	//cout << "Mnozenie r1*r2= " << endl;
	//(r1*r2).Wypisz();
	
	return 0;
}
