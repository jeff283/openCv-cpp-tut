#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv;
using namespace std;

//Warping an Image

float w= 250, h =350;
Mat matrix, imgWrap;

int main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	//resize(img, img , Size(), 0.5, 0.5);

	Point2f src[4] = { {529, 142}, {771, 190}, {405, 395},{647, 457} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);

	warpPerspective(img, imgWrap, matrix, Point(w, h));
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}
	imshow("Image", img);
	imshow("Image Wrap", imgWrap);

	waitKey(0);
	return 0;
}