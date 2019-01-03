#include "figura.h"
int Figura :: fLicznik = 0;

Figura :: Figura(){
	N = 1;;
	punkty = new Punkt [N];

	
	for (int i =0; i < N; i++){
		punkty[i].x = 0;
		punkty[i].y = 0;
	}

	fLicznik++;
	
}
Figura :: Figura (Punkt *p, int n){
	N = n;
	punkty = new Punkt [N];
	for (int i = 0; i < N; i++)
		punkty[i] = p[i];
	fLicznik++;
}

Figura :: Figura(const Figura &f){
	N = f.N;
	punkty = new Punkt [N];
	for (int i = 0; i < N; i++){
		punkty[i].x = f.punkty[i].x;
		punkty[i].y = f.punkty[i].y;
	}
	fLicznik++;
	
}
Figura :: ~Figura(){
	delete [] punkty;
	fLicznik--;
}

int Figura :: GetfLicznik(){
	return fLicznik;
}
/*
void Figura :: Wypisz(){
	cout << "Dane Figury: " << endl;
	cout << "Liczba punktow: " << N << endl;
	cout << "Kolejne punkty: " << endl;
		for (int i =0; i < N; i++){
			 cout << i+1 << "." << endl;
			 cout << "(" << punkty[i].x << "," << punkty[i].y << ")" << endl;
		}
		
		cout<< "Liczba figur w bazie: " << GetfLicznik() << endl << endl;
		cout << endl;
		
		
}
*/

void Figura :: WypiszinfoPunkty(){
		for (int i =0; i < N; i++){
			 cout << i+1 << "." ;
			 cout << "(" << punkty[i].x << "," << punkty[i].y << ")" << endl;
		}
}
