#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

int main (int argc, char** argv){
	
	string zdjecieNazwa ("./las.jpg");
	
	zdjecieNazwa = argv[1];
	Mat zdjecie;
	zdjecie = imread (zdjecieNazwa, 1); //1-color
	
	if( argc != 2 ||!zdjecie.data ){
		cerr << "Nie moge otworzyc pliku " << endl;
		return 1;
	}
	
	Mat przerobione_zdjecie;
	//CV_BGR2GRAY
	 cvtColor(zdjecie, przerobione_zdjecie, CV_BGR2Luv);//#include <opencv2/opencv.hpp>
	imwrite ("./zdj_przerobione.jpg", przerobione_zdjecie);
	
	Mat zdj_pomn;

	resize (zdjecie, zdj_pomn, Size(276*0.75,182*0.75), 0, 0, CV_INTER_LINEAR);//Size (width, height) lub Size (liczba_pixeli_kolumny*procent,liczba_pixeli_wiersze*procent)
	
	//namedWindow (zdjecieNazwa, WINDOW_AUTOSIZE); //otwiera okno, jak odkomento/wane to wyswietli 6 okien, 3-zdjecia, 3 puste okna
	//namedWindow ("szare_zdjecie", WINDOW_AUTOSIZE);
	//namedWindow("zdj0_75.jpg", WINDOW_AUTOSIZE);
	/*
	 * The fuction namedWindow just makes sure that if you wish to do something with that same window afterwards (eg move, resize, close that window), you can do it by referencing it with the same name.
		So if you just want to show it; you don't need to use namedWindow().
	 * 
	 */
	
	
	imshow (zdjecieNazwa, zdjecie);
	imshow("przerobka", przerobione_zdjecie);
	imshow ("oryginal pomniejszony ", zdj_pomn);
	
	
	waitKey(0);
	
	
	
	return 0;
}
