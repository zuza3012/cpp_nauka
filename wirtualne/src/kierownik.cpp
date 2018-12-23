#include "kierownik.h"

Kierownik :: Kierownik (string im, string naz, int w, string t, int st, double pp, double prem):Pracownik(im, naz, w, t, st), pPodstawowa(pp), premia(prem){}
Kierownik :: ~Kierownik(){}


double Kierownik :: GetPremia(){
	return staz*100;
}

double Kierownik :: GetPensja(){
	return pPodstawowa+premia;
}

void Kierownik :: GetInfo(){
	cout << "Przedstawiamy kierownika: " << endl;
	GetWizytowka();
	cout << "Staz: " << staz << endl;
	cout << "Premia: " << premia << endl;
	cout << "Pensja podstawowa: " << pPodstawowa << endl;
	cout << "Pensja: " << GetPensja() << endl;
}

//app - dopisanie do pliku
void Kierownik :: Zapisz(char* a){
	ofstream plik;
	plik.open(a, std::ios::app);
	//domyslnie plik.good sa true
	if( plik.good() == true){
		plik << "Przedstawiamy kierownika: " << endl;
	//GetWizytowka();
		plik << tytul << " " << imie << " " << nazwisko << endl;
		plik << "Wiek: " << wiek << endl;
		plik << "Staz: " << staz << endl;
		plik << "Premia: " << premia << endl;
		plik << "Pensja podstawowa: " << pPodstawowa << endl;
		plik << "Pensja: " << GetPensja() << endl;
	
		plik << endl;
		plik.close();

	}else{
		cerr << "Nie moge zapisac do pliku!!!" << endl;
		exit (1);
	}
	
}


void Kierownik :: Wczytaj (char* a){
	fstream plik;
	plik.open(a, ios::in);
	
	string im, naz, t;
	int w, st;
	double prem, pp;
	
	if(plik.good() == true){
        while(!plik.eof()){
            plik >> t >> im >> naz;
            plik >> w >> st;
            plik >> prem;
            plik >> pp;
			
			tytul = t;
			imie = im;
			nazwisko = naz;
			wiek = w;
			staz = st;
			premia = prem;
			pPodstawowa = pp;
        }
    }else{
		cerr << "Nie moge otworzyc pliku!!!" << endl;
		exit (1);
	}
	 plik.close();

}

