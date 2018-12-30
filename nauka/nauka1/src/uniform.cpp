#include "uniform.h"

Uniform :: Uniform(): Random(){
	fMin = 0;
	fMax = 1;
	
}

Uniform :: Uniform(double min, double max):Random(), fMin(min), fMax(max){}

Uniform :: ~Uniform(){}
	

void Uniform :: SetfMin(double min){
	fMin = min;
}
void Uniform :: SetfMax(double max){
	fMax = max;
}
	
double Uniform :: GetfMin(){
	return fMin;
}
double Uniform :: GetfMax(){
	return fMax;
}

double Uniform :: Exec(){
	fMin + (fMax - fMin) * rand()/RAND_MAX;
}

void Uniform :: ZapiszUniform(char* a){
	ofstream plik;
	plik.open(a, std::ios::app);//z dopisywaniem do pliku
	if(plik.good() == true){
		plik << "Kilka liczb z rozkladu jednorodnego" << endl;
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


void Uniform :: WczytajUniform(char* a){
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

