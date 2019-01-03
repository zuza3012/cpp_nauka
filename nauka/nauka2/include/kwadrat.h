#include "figura.h"
#pragma once
class Kwadrat: public Figura {
	protected:
	double a;
	
	public:
	Kwadrat();
	Kwadrat(Punkt *p, int n, double aa);
	Kwadrat(const Kwadrat &k);
	~Kwadrat();
	
	double Pole();
	double Obwod();
	void Wypisz();
	
};
