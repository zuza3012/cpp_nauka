#include "wizytowka.h"

Wizytowka :: Wizytowka(string im, string naz, int w, string t){
	imie = im;
	nazwisko = naz;
	wiek = w;
	tytul = t;
}
Wizytowka :: ~Wizytowka(){}
	
void Wizytowka :: GetWizytowka(){
	//cout << "WIZYTOWKA" << endl;
	cout << tytul << " " << imie << " " << nazwisko << endl;
	cout << "Wiek: " << wiek << endl;

	}
