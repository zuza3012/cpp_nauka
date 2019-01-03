#include "trojkat.h"
Trojkat :: Trojkat():Figura(), a(0), h(0){}

Trojkat :: Trojkat(Punkt *pp, int n, double aa, double hh):Figura(pp, n), a(aa), h(hh){}

Trojkat :: Trojkat(const Trojkat &t):Figura(t){
	a = t.a;
	h = t.h;
}
Trojkat :: ~Trojkat(){}

double Trojkat :: Pole(){
	return a*h*0.5;
}
double Trojkat :: Obwod(){
	double aa = 0;
	double bb = 0;
	double cc = 0;
	aa = sqrt((punkty[0].Getx()-punkty[1].Getx())*(punkty[0].Getx()-punkty[1].Getx())+(punkty[0].Gety()-punkty[1].Gety())*(punkty[0].Gety()-punkty[1].Gety()));
	bb = sqrt((punkty[1].Getx()-punkty[2].Getx())*(punkty[1].Getx()-punkty[2].Getx())+(punkty[1].Gety()-punkty[2].Gety())*(punkty[1].Gety()-punkty[2].Gety()));
	cc = sqrt((punkty[2].Getx()-punkty[0].Getx())*(punkty[2].Getx()-punkty[0].Getx())+(punkty[2].Gety()-punkty[0].Gety())*(punkty[2].Gety()-punkty[0].Gety())); 
	return aa+bb+cc;;
	
}
void Trojkat :: Wypisz(){
	cout << "TROJKAT" << endl;
	cout << "Liczba punktow: " << N << endl;
	cout << "Kolejne punkty: " << endl;
	WypiszinfoPunkty();
	cout << "Dlugosc boku:" << a << endl;
	cout << "Wysokosc: " << h << endl;
	cout << "Pole: " << Pole() << endl;
	cout << "Obwod: " << Obwod() << endl;
	cout<< "Liczba figur w bazie: " << GetfLicznik() << endl << endl;
	cout << endl;
}
