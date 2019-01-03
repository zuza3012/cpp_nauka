#include "figura.h"
#pragma once 
#define PI 3.1415

class Okrag:public Figura {
	protected:
	double r;
	
	public:
	Okrag();
	Okrag(Punkt *pp, int n, double rr);
	Okrag(const Okrag &o);
	~Okrag();
	
	double Pole();
	double Obwod();
	void Wypisz();
	
};
