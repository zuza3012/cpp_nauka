#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

int main (int argc, char** argv){
	
	if( argc!= 2){
		cerr << "Podano zla liczbe argumentow!!!(podaj 2)" << endl;
		return 1;
	}
	
	String zdjecie = argv[1];
	Mat image;
	
	//image = imread (zdjecie ,IMREAD_REDUCED_GRAYSCALE_2 );//If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
	image = imread (zdjecie ,IMREAD_ANYCOLOR )
	if( image.empty()){
		cerr << "Nie emoge otworzyc pliku!!!" << endl;
		return 1;
	}
	
	namedWindow ("Display window", WINDOW_AUTOSIZE ); // tworzymy okno
	imshow ("Display window", image);
	
	waitKey(0);

	
	
	return 0;
}
