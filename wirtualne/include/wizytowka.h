#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once

class Wizytowka {
	protected:
	
	string imie;
	string nazwisko;
	int wiek;
	string tytul;
	
	
	public:
	Wizytowka(string im = "brak imienia", string naz = "brak nazwiska", int w = 0, string t = "brak tytulu");
	~Wizytowka();
	
	void GetWizytowka();
	
	
	
};
