#include "random.h"
#include "uniform.h"
#include "gauss.h"
#include "poisson.h"

int main (int argc, char** argv){
	Uniform uni1(-3,3);
	cout << uni1.Exec() << endl;
	
	Uniform uni2(-1,8);
	cout << uni2.Exec() << endl;
	
	Gauss gauss1(140, 5);
	cout << gauss1.Exec() << endl;
	
	Gauss gauss2(110, 50);
	cout << gauss2.Exec() << endl;
	
	Poisson p1(500);
	cout << p1.Exec() << endl;
	
	Poisson p2(56);
	cout << p2.Exec() << endl;
	
	Random* wsk;
	wsk = &uni1;
	cout << wsk -> Exec() << endl;
	
	wsk = &gauss1;
	cout << wsk -> Exec() << endl;
	
	wsk = &p1;
	cout << wsk -> Exec() << endl;
	
	gauss1.ZapiszGauss(argv[1]);
	p2.ZapiszPoisson(argv[1]);
	uni1.ZapiszUniform(argv[1]);
	
	gauss1.WczytajGauss(argv[2]);
	uni1.WczytajUniform(argv[3]);
	p1.WczytajPoisson(argv[4]);
	
	
	return 0;
	
}
