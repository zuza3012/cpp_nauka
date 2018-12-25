#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main (int argc, char** argv){
	
	if(argc < 1){
		cerr << "Podaj prawidolowa ilosc argumentow !!! " << endl;
		return 1;
	}
	
	cout << "Podaj rozdzielczosc docelowa zdjecia (width x height) " << endl;
	int a;
	int b;
	
	cin >> a >> b;
	int licznik = 0;
	
	for (int i = 1; i < argc; i++){
		
		String zapiszZdjecie = "./zdj_" + to_string(++licznik) + ".jpg";
		
		string nazwaZdjecia = argv[i];//jak for od 0ra to tutaj argv[i+1], zeby brac obraz, nie program caly, SYPIE SIE
		Mat zdjecie;
		zdjecie = imread( nazwaZdjecia, 1);
		
		Mat zdj_pomn;
	

		resize (zdjecie, zdj_pomn, Size(a,b), 0, 0, CV_INTER_LINEAR);//Szie(width, height)// cos tu moze jest zle?
		 
		 
		//vector <Mat> wyj;
		//wyj[i] = zdj_pomn.clone();
		imwrite (zapiszZdjecie, zdj_pomn);//wyj[i]);
		cout << "Pomniejszono obraz nr" << i << endl;
	}
	
	return 0;
	
}
