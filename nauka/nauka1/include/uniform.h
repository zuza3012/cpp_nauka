#include "random.h"
#pragma once

class Uniform: public Random {
	protected:
	double fMin;
	double fMax;
	
	public:
	Uniform();
	Uniform(double min, double max);
	~Uniform();
	
	void SetfMin(double min);
	void SetfMax(double max);
	
	double GetfMin();
	double GetfMax();
	
	double Exec();
	
	void ZapiszUniform(char* a);
	
	void WczytajUniform(char* a);
	

	
};
