#include "pracownik.h"
#pragma once 

class Robotnik: public Pracownik {
	protected:
	double stawka;
	double iloscGodzin;
	
	public:
	Robotnik(string im = "brak imienia", string naz = "brak nazwiska", int w = 0, string t = "brak tytulu", int st = 0, double sta = 0, double godz = 0);
	~Robotnik();
	
	void SetGodziny(double godziny);
	double GetPensja(); 
	void GetInfo();
	void Zapisz(char* a);
	
};
