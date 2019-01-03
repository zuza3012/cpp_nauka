#include "okrag.h"

Okrag :: Okrag():Figura(), r(0){}

Okrag :: Okrag(Punkt *pp, int n, double rr):Figura(pp, n), r(rr){}

Okrag :: Okrag(const Okrag &o):Figura(o){
	r = o.r;
}
Okrag :: ~Okrag(){}

double Okrag :: Pole(){
	return PI*r*r;
}
double Okrag :: Obwod(){
	return 2*PI*r;
}
void Okrag :: Wypisz(){
	cout << "OKRAG" << endl;
	cout << "Liczba punktow: " << N << endl;
	cout << "Kolejne punkty: " << endl;
	WypiszinfoPunkty();
	cout << "Promien: " << r << endl;;
	cout << "Pole: " << Pole() << endl;
	cout << "Obwod: " << Obwod() << endl;
	cout<< "Liczba figur w bazie: " << GetfLicznik() << endl << endl;
	cout << endl;

}
