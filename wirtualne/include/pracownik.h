#include "wizytowka.h"

#pragma once 

class Pracownik: public Wizytowka {
	protected:
	
	//Wizytowka wiz;
	int staz;
	double pensja;
	
	public:
	Pracownik(string im, string naz, int w, string t, int st);
	virtual ~Pracownik();
	
	virtual void GetInfo() = 0;
	virtual double GetPensja() = 0;
	//virtual void CzystaFunkcja() = 0;
	
};
