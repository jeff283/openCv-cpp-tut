#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	//cout << img.size() << endl;

	Mat imgResize, imgCrop;

	//resize(img, imgResize, Size(480, 360));
	resize(img, imgResize,Size(), 0.5, 0.5);
	
	Rect roi(200, 70, 350, 300); // x, y ,w ,h
	imgCrop = img(roi);


	imshow("Original Image", img);
	//imshow("Resized Image", imgResize);
	imshow("Cropped Image", imgCrop);



	waitKey(0);
	return 0;
}