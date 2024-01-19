#pragma once
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class CommonProcesses
{
private:
	Mat rgbData;
	Mat dstData; 
	string filePath;
public:
	CommonProcesses(string&);
	~CommonProcesses();

	void setRGBdata(const Mat&);
	void setOutputRGB(const Mat&);
	void setFilePath(const string&);

	Mat getRGBdata() const;
	Mat getOutputRGB() const;
	string getFilePath() const;
	void readRGBfromFile();

	void viewRGB();
	void viewOutputRGB();
	void rgb2GS();
	void filterNoise(int);
	void rescaleImage(double, double);
	void writeRGBtoFile(const string& outputPath);



};

