#include <iostream>
#include <cmath>
#pragma once 
using namespace std;

class Punkt {
	friend class Figura;
	private:
	
	double x;
	double y;
	
	public:
	Punkt(double xx = 0, double yy = 0);
	~Punkt();
	
	double Getx();
	double Gety();
	void Setx(double xx);
	void Sety(double yy);
	
	
};
