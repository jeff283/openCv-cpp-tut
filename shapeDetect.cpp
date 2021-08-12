#include <opencv2/imgcodecs.hpp > 
#include <opencv2/highgui.hpp > 
#include <opencv2/imgproc.hpp > 
#include <iostream>

using namespace cv;
using namespace std;
/////////////// Shape detection	////////////////////// 
Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img) {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> bndRect(contours.size());
    string objType;

    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);

        if (area > 1000)
        {
            float peri = arcLength(contours[i], true);

            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);


            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

            bndRect[i] = boundingRect(conPoly[i]);
            rectangle(img, bndRect[i].tl(), bndRect[i].br(), Scalar(0, 255, 0), 3);

            int objCorn = (int)conPoly[i].size();



            if (objCorn == 3) {
                objType = "Tri";
            }
            else if(objCorn == 4){
                float aspRatio = (float)bndRect[i].width / (float)bndRect[i].height;

                if (aspRatio >= 0.95  && aspRatio <= 1.05) {
                    objType = "Square";
                }
                else {
                    objType = "Rect";
                }
            }
            else {
                objType = "Circle";
            }
            putText(img, objType, { bndRect[i].x, bndRect[i].y -5}, FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 69, 255), 2);


        }
    }
}

int main() {
    string path = "Resources/shapes.png";
    Mat img = imread(path);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    cvtColor(img, imgGray, COLOR_BGR2GRAY);//to Gray scale
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); //Blurring
    Canny(imgBlur, imgCanny, 25, 75); //Edge detection
    dilate(imgCanny, imgDil, kernel); //Dilating -> Output img

    getContours(imgDil, img);

    imshow("Image", img);
    //imshow("Image", imgDil);

    waitKey(0);

    return 0;
}
