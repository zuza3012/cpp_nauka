#include "punkt.h"

Punkt :: Punkt (double xx, double yy){
	x = xx;
	y = yy;
}
Punkt :: ~Punkt(){}

double Punkt :: Getx(){
	return x;
}
double Punkt :: Gety(){
	return y;
}
void Punkt :: Setx(double xx){
	x = xx;
}
void Punkt :: Sety(double yy){
	y = yy;
}
