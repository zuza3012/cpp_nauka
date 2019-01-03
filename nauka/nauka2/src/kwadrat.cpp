#include "kwadrat.h" 
Kwadrat :: Kwadrat():Figura(), a(0){}

Kwadrat :: Kwadrat(Punkt *pp, int n, double aa): Figura(pp, n), a(aa) {}

Kwadrat :: Kwadrat(const Kwadrat &k):Figura(k){
	a = k.a;
}
Kwadrat :: ~Kwadrat(){}


double Kwadrat :: Pole(){
	return a*a;
}
double Kwadrat :: Obwod(){
	return 4*a;
}
void Kwadrat :: Wypisz(){
	cout << "KWADRAT" << endl;
	cout << "Liczba punktow: " << N << endl;
	cout << "Kolejne punkty: " << endl;
	WypiszinfoPunkty();
	cout << "Dlugosc boku:" << a << endl;
	cout << "Pole: " << Pole() << endl;
	cout << "Obwod: " << Obwod() << endl;
	cout<< "Liczba figur w bazie: " << GetfLicznik() << endl << endl;
	cout << endl;
}
