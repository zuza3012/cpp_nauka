#include "poisson.h"

Poisson :: Poisson (double flambda ): Random(), fLambda(flambda){}
Poisson :: ~Poisson(){}
	
void Poisson :: SetfLambda(double lambda){
	fLambda = lambda;
}
double Poisson :: GetfLambda(){
	return fLambda;
}
	
double Poisson :: Exec(){
	double e = exp(-1*fLambda);
	double liczba = 1;
	bool koniec = false;
	int n = 0;
	while(!koniec && n < 100){
		
		liczba*= (double) rand()/RAND_MAX;//dowolna liczba z rozkladu jednorodnego z przedzialu 0-1
		if(liczba < e)
			koniec = true;
		n++;
	}
		return n;
}
void Poisson :: ZapiszPoisson(char* a){
	ofstream plik;
	plik.open(a, std::ios::app);//z dopisywaniem do pliku
	if(plik.good() == true){
		plik << "Kilka liczb z rozkladu Poissona" << endl;
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


void Poisson :: WczytajPoisson(char* a){
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
