#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv; 
using namespace std;	
///////////////// Images	////////////////////// 
//int main() {
//    string path = "Resources/test.png"; 
//    Mat img = imread(path); 
//    imshow("Image", img); 
//    waitKey(0);
//
//    return 0;
//}


///webcam
//void main() {
// 
//	VideoCapture cap(0);
//
//	Mat img;
//
//	while (true)
//	{
//		cap.read(img);
//		imshow("webcam", img);
//		waitKey(1);
//	}
//}


////Video Capture
void main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);

	Mat img;

	while (true)
	{
		cap.read(img);
		imshow("video", img);
		waitKey(20);
	}
}