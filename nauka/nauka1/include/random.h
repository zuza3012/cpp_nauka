#include <iostream>
#include <stdlib.h> //do rand()'a i srand()'a
#include <time.h>
#include <cmath>
#include <fstream>
#define pi 3.1415
#pragma once

using namespace std;

class Random {
	protected:
	
	public:
	Random();
	virtual ~Random();
	
	virtual double Exec() = 0;
	

};
