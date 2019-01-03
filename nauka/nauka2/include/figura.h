#include "punkt.h"
#pragma once


class Figura {
	protected:
	
	Punkt *punkty;
	int N;//liczba punktów
	static int fLicznik; // liczy ile mamy figur
	
	public:
	Figura();
	Figura(Punkt *p, int n);
	Figura(const Figura &f);
	virtual ~Figura();
	//Jeżeli klasa pochodna nie przesłoni wszystkich metod czysto wirtualnych, również jest klasą abstrakcyjną. Nie można utworzyć obiektów klasy abstrakcyjnej.
	static int GetfLicznik();
	virtual void Wypisz() = 0;
	void WypiszinfoPunkty();
	virtual double Pole() = 0;
	virtual double Obwod() = 0;
	
	friend void DajDane(Figura &f);
};
void DajDane(Figura &f);
