#include <iostream>
#include <opencv2/opencv.hpp>
#include "CommonProcesses.h"
#include "LineDetection.h"
#include "CornerDetection.h"
using namespace std;

int main()
{
	string path = "C:/Users/eeekr/Desktop/FindFeature/FindFeature/image.jpg";
	LineDetection obj(path);
	obj.readRGBfromFile();
	obj.detectLines();
	obj.visualizeFeatures();
	
}
