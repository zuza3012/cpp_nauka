#include "gauss.h"

Gauss :: Gauss (double srednia, double odchylenie):Random(), fMean(srednia), fSigma(odchylenie){}
Gauss ::~Gauss(){}
	
void Gauss :: SetfMean(double srednia){
	fMean = srednia;
}
void Gauss :: SetfSigma(double odchylenie){
	fSigma = odchylenie;
}	
	
double Gauss :: GetfMean(){
	return fMean;
}
double Gauss :: GetfSigma(){
	return fSigma;
}
	
double Gauss :: Exec(){
	double x;
	double U = (double)rand()/RAND_MAX;// jak nie damy double to dostniemy 0 lub 1 bo dzielimy inta przez wiekszego lub rownego inta
	double V = (double)rand()/RAND_MAX;// otrzmmamy wedy jakiegos doubla z przedzialu 0-1
	
	x = fMean + fSigma*sqrt(-2*log(U))*cos(2*pi*V);
	return x;
}

void Gauss :: ZapiszGauss(char* a){
	ofstream plik;
	plik.open(a, std::ios::app);//z dopisywaniem do pliku
	if(plik.good() == true){
		plik << "Kilka liczb z rozkladu Gaussa" << endl;
		for(int i = 0; i < 30; i++){
			plik << Exec() << endl;
		}
		plik << endl;
		plik.close();
	}else{
		cerr << "Nie moge zapisac do pliku !!!" << endl;
		exit(1);
	}
}

void Gauss :: WczytajGauss(char* a){
	ifstream plik;
	double b;
	plik.open(a);
	
	if(plik.good() == true){
		while(!plik.eof()){
		plik >> b;
		cout << b << endl;
		}
		plik.close();
	}else{
		cerr << "Nie moge wczytac z pliku !!!" << endl;
		exit(1);
	}
	
}
