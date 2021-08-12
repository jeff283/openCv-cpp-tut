#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv;
using namespace std;
/////////////// Color Detection	////////////////////// 


int main() {
    string path = "Resources/lambo.png"; 
    Mat img = imread(path);

    Mat imgHSV, mask;
    //int hmin = 0, smin = 110, vmin = 153;
    //int hmax = 19, smax = 240, vmax = 255;

    //Values for getting a  mask
    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    //creating track bars
    namedWindow("Trackbars", (640, 400));
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Value Min", "Trackbars", &vmin, 255);
    createTrackbar("Value Max", "Trackbars", &vmax, 255);


    while (true)
    {
        //lower and upper limit of the selected color...this is due to variation in lighting
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        
        //Getting the mask
        inRange(imgHSV, lower, upper, mask);

        //imshow("Original Image", img);
        imshow("HSV Image", imgHSV);
        imshow("Mask Image", mask);

        waitKey(1);
    }

    destroyAllWindows();
    return 0;
}
