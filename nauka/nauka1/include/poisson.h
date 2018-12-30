#include "random.h"
#pragma once

class Poisson: public Random {
	protected:
	double fLambda;
	
	public:
	Poisson(double flambda = 0);
	~Poisson();
	
	void SetfLambda(double lambda);
	double GetfLambda();
	
	double Exec();
	
	void ZapiszPoisson(char* a);
	
	void WczytajPoisson(char* a);
};
