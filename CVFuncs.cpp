#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv;
using namespace std;


void main() {
	string path = "Resources/test.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray,imgBlur, Size(3,3), 5, 0);
	Canny(imgBlur, imgCanny, 50, 150);
	dilate(imgCanny, imgDil, kernel);

	erode(imgDil, imgErode, kernel);


	//imshow("Original Image", img);
	//imshow("Gray Image", imgGray);
	//imshow("Blurred Image", imgBlur);
	imshow("Edgy Image", imgCanny);
	imshow("Dilated Image", imgDil);
	imshow("Eroded Image", imgErode);



	waitKey(0);



}