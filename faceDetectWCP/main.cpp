#include "FaceDetection.h"
#include <iostream>
#include <fstream>
#include <string>

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace std;

int main()
{  
	CFaceDetection FaceDetection;
	ifstream infilename;
	infilename.open("E:\\Data_Set\\FDDBÊý¾Ý¿â\\2002\\07\\19\\big\\Path_Images.txt");
	CvRect faceRects[50];
	double faceWeights[50];
	string fileName;
	cv::Mat sorImgs, grayImgs;
	while(getline( infilename, fileName ))
	{
		cout<<sizeof( fileName )<<endl;

		sorImgs = cv::imread(fileName);
		if (sorImgs.empty())
		{
			break;
		}
		if (sorImgs.channels() == 3)
			cv::cvtColor( sorImgs, grayImgs, cv::COLOR_BGR2GRAY);
		else
		{
			grayImgs = sorImgs.clone();
		}

		int nface = FaceDetection.GetFaceRects(grayImgs,faceRects,faceWeights);

		//std::vector<cv::Rect> rects = std::vector<cv::Rect>(nface);
	
		for (int i = 0 ; i<nface; ++i)
		{
			rectangle(sorImgs, cvPoint( faceRects[i].x,faceRects[i].y ),
				cvPoint(faceRects[i].x+faceRects[i].width,faceRects[i].y+faceRects[i].height),cv::Scalar(0,0,255), 1, 8, 0);		
		
		}
		cv::imshow("pictures",sorImgs);
		
		}
	cout<<"END"<<endl;
	return 0;
}