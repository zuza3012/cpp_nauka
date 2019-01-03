#include "figura.h"
#pragma once 

class Trojkat: public Figura{
	protected:
	double a;
	double h;
	
	public:
	Trojkat();
	Trojkat(Punkt *pp, int n, double aa, double hh);
	Trojkat(const Trojkat &t);
	~Trojkat();
	
	double Pole();
	double Obwod();
	void Wypisz();
	
};
