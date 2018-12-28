#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace cv;

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta1;
				
Mat src1, src2, dst;
				
			
				
static void on_trackbar (int , void* ){
	alpha = (double) alpha_slider/alpha_slider_max;
	beta1 = (1.0 - alpha);
	addWeighted (src1, alpha, src2, beta1, 0.0, dst);
	imshow("Linear Blend", dst);
}
					
int main (int argc, char** argv){
	
	if (argc == 1) {
		cerr << "Nieprawidlowa ilosc argumentow "  << endl;
		return 1;
	}
	bool koniec = false;
	
	
	while (!koniec){
		int a;
		cout << "Co chcesz zrobic? " << endl;
		cout << "1 - wyświetlenie zdjec w oryginale" << endl;
		cout << "2 - zmiana koloru zdjec na szare" << endl;
		cout << "3 - zmiana rozmiaru" << endl;
		cout << "4 - przyblizanie i oddalanie zdjecia pierwszego" << endl;
		cout << "5 - Histogram Equalization (zmiana intensywnosci zdjecia)" << endl;
		cout << "6 - Trackbar" << endl;
		cout << "0 - wyjscie z opcji " << endl;
	
		cin >> a;
		
		switch(a)
		{
		
			case 1:
			{	
				for (int i = 1; i < argc; i++){
					Mat zdjecie;
					string nazwaZdjecia = argv[i];
					zdjecie = imread (nazwaZdjecia, 1);
					namedWindow (nazwaZdjecia, WINDOW_AUTOSIZE);
					imshow (nazwaZdjecia, zdjecie);
					waitKey(0);
					destroyWindow(nazwaZdjecia);
					
					}
				break;
			}	
			case 2:
			{	int licznik = 0;
				
				for(int i = 1; i< argc; i++){
					Mat zdjecie;
					string nazwaZdjecia = argv[i];
					zdjecie = imread (nazwaZdjecia, 1);
					
					Mat szare;
					cvtColor(zdjecie, szare, CV_RGB2GRAY );
					cout << "Czy zapisac zdjecie nr " << i << " osobno?" << endl;
					string odp;
					cin >> odp;
					
					if (odp == "tak"){
						string zapiszZdjecie = "./zdj_" + to_string(++licznik) + ".jpg";
						imwrite (zapiszZdjecie, szare);
						cout << "Zmieniono na skale szarosci dla obrazu nr " << i << endl << endl;
					}else if (odp == "nie"){
						cout << "Zmieniono zdjecie nr " << i << "w oryginalne" << endl;
						imwrite (nazwaZdjecia, szare);
						cout << "Zmieniono na skale szarosci dla obrazu nr " << i << endl << endl;
					}else{
						cout << "Uzytkowniku, zdecyduj sie !!! " << endl;
						break;
					}
	
				}
				break;
			}
			case 3:
			{
			int licznik = 0;
			cout << "Podaj doclowy rozmiar zdjecia (szer x dl)" << endl << endl;
			int a, b;
			cin >> a >> b;
			
				for (int i = 1; i < argc; i++){
				Mat zdjecie;
				string zapiszZdjecie = "./zdj_" + to_string(++licznik) + ".jpg";
				string nazwaZdjecia = argv[i];
				
				zdjecie = imread( nazwaZdjecia, 1);
				Mat zdj_pomn;
				resize (zdjecie, zdj_pomn, Size(a,b), 0, 0, CV_INTER_LINEAR);
		 
				imwrite (zapiszZdjecie, zdj_pomn);
				cout << "Zmiana rozdzielczosci obrazu nr" << i << endl;
				}
			}
			case 4:
			{
				Mat src, dst, tmp;
				string nazwaOkna = "Piramida Demo";
				
				cout << "zoom In-Out Demo" << endl;
				cout << "u - zoom in" << endl;
				cout << "d - zoom out" << endl;
				cout << "esc lub enter - wyjscie" << endl;
				
				src = imread (argv[1], 1);
				if (src.empty()){
					cout << "Brak zdjecia w bazie !!!" << endl;
					return 1;
				}
				
				tmp = src;
				dst = tmp;
				
				imshow( nazwaOkna, dst);
				for(;;){//nieskonczona petla
					char znak = (char)waitKey(0);
					if(znak == 27 ) //13-enter, 27-esc
						break;
						//if ( znak == 13)
						//	break;
					if(znak == 'u'){
						pyrUp(tmp, dst, Size (tmp.cols*2, tmp.rows*2));
						cout << "Powiekszono" << endl;
					}
					if(znak == 'd'){
						pyrDown(tmp, dst, Size(tmp.cols/2, tmp.rows/2));
						cout << "Pomniejszono" << endl;
					}
				imshow(nazwaOkna, dst);
				tmp = dst;
				}
				
				break;			
			} 
			case 5:
			{
				Mat src, dst;
				for(int i=1; i< argc; i++){
					string nazwaOkna = argv[i];
					string nazwaOkna2 = "Okno wyostreznie";
					
					src = imread (nazwaOkna, 1);
					if (src.empty()){
						cerr << "Blad !!!" << endl;
						return 1;
					}
					cvtColor(src, src, CV_RGB2GRAY);
					equalizeHist(src, dst);
					
					namedWindow(nazwaOkna, WINDOW_AUTOSIZE);
					namedWindow(nazwaOkna2, WINDOW_AUTOSIZE);
					
					imshow(nazwaOkna, src);
					imshow(nazwaOkna2, dst);
					
					waitKey(0);
				}
				
			}
			case 6:
			{	/*
				const int alpha_slider_max = 100;
				int alpha_slider;
				double alpha;
				double beta;
				
				Mat src1, src2, dst;
				
				//funkcja ponizej
				
				static void on_trackbar (int , void* ){
					alpha = (double) alpha_slider/alpha_slider_max;
					beta = (1.0 - alpha);
					addWeighted (src1, alpha, src2, beta, 0.0, dst);
					imshow("Linear Blend", dst);
				}
				*/
				
					/*		
					//https://docs.opencv.org/3.2.0/da/d6a/tutorial_trackbar.html
					src1 = imread (argv[1], 1);
					src2 = imread (argv[2], 1);
					
					if(src1.empty()){
						cerr << "Blad w czytaniu zdjecia" << endl;
						return 1;
					}
					
					if(src2.empty()){
						cerr << "Blad w czytaniu zdjecia" << endl;
						return 1;
					}
					
					
					alpha_slider = 0;
					namedWindow ("Linear Blend", WINDOW_AUTOSIZE);
					
					char TrackbarName[50];
					sprintf(TrackbarName, "Alpha x %d", alpha_slider_max);//Write formatted data to string
					
					createTrackbar(TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);
					on_trackbar(alpha_slider, 0);
					
					waitKey(0);
					
				*/

				
			}
			case 0:
			{
				koniec = true;
				break;
			}
			default://cos innego niz liczba
			{
				cout << "Nieprawidlowo podano wartosc " << endl;
				break;
			}
				
		}
	
	}
	
	
	//system("pause");
	
	
	
	return 0;
}
