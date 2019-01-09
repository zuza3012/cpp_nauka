#include "macierz.h"

Macierz :: Macierz(int nn, int mm){
	n = nn;
	m = mm;
	
	tab = new double* [n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tab[j] = new double [m];
			tab[i][j] = 0;
		}
	}
}
Macierz :: Macierz(const Macierz &M){
	n = M.n;
	n = M.m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tab[j] = new double [m];
			tab[i][j] = M.tab[i][j];
		}
	}
}
Macierz :: ~Macierz(){
	for(int i = 0; i < n; i++)
		delete [] tab[i];
	delete [] tab;
}

void Macierz :: Wypisz(){
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Macierz :: Wpisz(int x, int y, double val){
	tab[x][y] = val;
}

void Macierz :: Losuj(){
	srand(time(NULL));//albo w mainie na poczatku
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++)
			 tab[i][j] = rand() % 10;
	}	
}
void Macierz :: Zapisz(char* a, string nazwa){
	ofstream plik;
	plik.open(a, std::ios::app);
	if(plik.good() == true){
		plik << nazwa << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0 ; j < m; j++)
			plik << tab[i][j] << " " ;
		plik << endl;
		plik.close();
		}
		cout << "Zapisano do pliku " << a << endl << endl;
	}else{
		cerr << "Nie moge zapisac do pliku " << a << endl;
		exit(1);
	}
}
void Macierz :: Wczytaj(char* a, int N, int M){
	ifstream plik;
	double b;
	if(N > n || M > m){
		cerr << "Uzytkowniku! Nie ładnie przekraczac rozmiaru tablicy!" << endl;
		cerr << "Badz rozwazny, bo krzywdy narobisz !!!" << endl;
		exit(1);
	}else if(N < n || M < m){
		cerr << "Podajac takie argumenty czesc tablicy jest pusta." << endl;
		cerr << "Zachowaj rozwage !!!" << endl;
		exit(1);
	}
	plik.open(a);
	if(plik.good() == true){
		for(int i = 0; i < N; i++){
			for(int j = 0 ; j < M; j++){
				plik >> b;
				tab[i][j] = b;
			}
		}
	plik.close();
	cout << "Wczytano z pliku " << a << endl;
	}else{
		cerr << "Nie moge wczytac z pliku " << a << endl << endl;
		exit(1);
	}
}
double& Macierz :: operator()(int x, int y){
	return tab[x][y];
}
Macierz Macierz :: operator+(Macierz m2){
	Macierz m3;
	if(m2.n != n  || m2.m != m){
		cerr << "Nie moge dodac macierzy, zwracam Ci to co mam po lewej stronie." << endl;
		return *this;
	}
		for(int i = 0; i < n; i++){
			for(int j = 0 ; j < m; j++)
				m3.tab[i][j] = tab[i][j] + m2.tab[i][j];	
		}
	
	return m3;
	
}
