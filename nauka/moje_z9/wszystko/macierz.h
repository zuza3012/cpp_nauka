#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#pragma once

using namespace std;

class Macierz{
	int n;//pion
	int m;//poziom
	double** tab;
	
	public:
	Macierz(int nn = 3, int mm = 3);
	Macierz(const Macierz &M);
	~Macierz();
	
	void Wypisz();
	void Wpisz(int x, int y, double val);
	void Losuj();
	void Zapisz(char* a, string nazwa);
	void Wczytaj(char* a, int N, int M);
	double& operator()(int x, int y);// double bo w tablicy sa double!
	Macierz operator+(Macierz m2);
	
};
