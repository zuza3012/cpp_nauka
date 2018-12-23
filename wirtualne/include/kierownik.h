#include "pracownik.h"
#pragma once

class Kierownik: public Pracownik{
	protected:
	double pPodstawowa;
	double premia;
	
	public:
	Kierownik(string im = "brak imienia", string naz = "brak nazwiska", int w = 0, string t = "brak tytulu", int st = 0, double pp = 0, double prem = 0);
	~Kierownik();
	
	double GetPremia();
	double GetPensja();
	void GetInfo();
	void Zapisz(char* a);
	void Wczytaj(char* a);
	
};
