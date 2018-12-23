#include "robotnik.h"

Robotnik :: Robotnik(string im, string naz, int w, string t, int st, double sta, double godz):Pracownik(im, naz, w, t, st), stawka(sta), iloscGodzin(godz){}

Robotnik ::	~Robotnik(){}

void Robotnik :: SetGodziny(double godziny){
	iloscGodzin = godziny;
}


double Robotnik :: GetPensja() {
	return stawka*iloscGodzin;
}

void Robotnik :: GetInfo(){
	cout << "Przedstawiamy robotnika: " << endl;
	GetWizytowka();
	cout << "Staz: " << staz << endl;
	cout << "Stawka: " << stawka << endl;
	cout << "Pensja: " << GetPensja() << endl;
	cout << "Przepracowane godziny: " << iloscGodzin << endl;
}
//app- dopisanie do pliku
void Robotnik :: Zapisz(char* a){
	ofstream plik;
	plik.open(a, std::ios::app);
	//domyslnie plik.good sa true
	if( plik.good() == true){
		plik << "Przedstawiamy robotnika: " << endl;
		//GetWizytowka();
		plik << tytul << " " << imie << " " << nazwisko << endl;
		plik << "Wiek: " << wiek << endl;
		plik << "Staz: " << staz << endl;
		plik << "Stawka: " << stawka << endl;
		plik << "Pensja: " << GetPensja() << endl;
		plik << "Przepracowane godziny: " << iloscGodzin << endl;
		
		plik << endl;
		plik.close();
	}else{
		cerr << "Nie moge zapisac do pliku!!!" << endl;
		exit (1);
	}
	
	
}


void Robotnik :: Wczytaj (char* a){
	fstream plik;
	plik.open(a, ios::in);
	
	string im, naz, t;
	int w, st;
	double sta, godz;
	
	if(plik.good() == true){
        while(!plik.eof()){
            plik >> t >> im >> naz;
            plik >> w >> st;
            plik >> sta;
            plik >> godz;
			
			tytul = t;
			imie = im;
			nazwisko = naz;
			wiek = w;
			staz = st;
			stawka = sta;
			iloscGodzin = godz;
        }
    }else{
		cerr << "Nie moge otworzyc pliku!!!" << endl;
		exit (1);
	}
	 plik.close();

}


