#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
using namespace std;
using namespace cv;



/*void main() {


	string path = "zaydan.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}*/

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img; 
	facedetect.load("haarcascade_frontalface_default.xml"); //loading cascade classifier for facedetect
	vector<Rect> faces;

	facedetect.detectMultiScale(img, faces, 1.1, 4); 

	cout << faces.size() << endl;

	while (true) {
		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img, faces, 1.1, 4);

		for(int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
			rectangle(img, Point(0,0), Point(250,70), Scalar(255, 0, 255), FILLED);
			putText(img, to_string(faces.size())+"Face Found", Point(10, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 1);
		}

		imshow("Frame", img);
		waitKey(1);
	}
}