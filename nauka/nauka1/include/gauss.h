#include "random.h"
#pragma once

class Gauss: public Random {
	protected:
	double fMean;
	double fSigma;
	
	public:
	Gauss(double srednia = 0, double odchylenie = 0);
	~Gauss();
	
	void SetfMean(double srednia);
	void SetfSigma(double odchylenie);
	
	double GetfMean();
	double GetfSigma();
	
	double Exec();
	
	void ZapiszGauss(char* a);
	void WczytajGauss(char* a);
	
};
