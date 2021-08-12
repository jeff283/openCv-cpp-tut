#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
/////////////// Images	////////////////////// 
int main() {
 /*   string path = "Resources/test.png"; 
    Mat img = imread(path);*/

    CascadeClassifier faceCasc;
    faceCasc.load("Resources/haarcascade_frontalface_default.xml");
    VideoCapture cap(0);


	Mat img;

	while (true)
	{
		cap.read(img);

        if (faceCasc.empty()) { cout << "XML file not loaded" << endl; }//check if empty

        vector<Rect> faces;
        faceCasc.detectMultiScale(img, faces, 1.1, 10);

        for (int i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);

        }

		imshow("webcam", img);
		waitKey(20);
	}


    //imshow("Image", img); 
    //waitKey(0);

    return 0;
}