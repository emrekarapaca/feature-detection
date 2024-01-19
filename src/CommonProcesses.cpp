#include "CommonProcesses.h"
#include <opencv2/gapi/imgproc.hpp>

CommonProcesses::CommonProcesses(string& PATH)
	:filePath(PATH) {}

CommonProcesses::~CommonProcesses(){}

void CommonProcesses::setFilePath(const string& PATH) {
	filePath.assign(PATH);
}

void CommonProcesses::setRGBdata(const Mat& obj) {
	rgbData = obj.clone();
}

void CommonProcesses::setOutputRGB(const Mat& obj) {
	dstData = obj.clone();
}

Mat CommonProcesses::getRGBdata() const {
	return rgbData;
}

Mat CommonProcesses::getOutputRGB() const {
	return dstData;
}

string CommonProcesses::getFilePath() const {
	return filePath;
}

void CommonProcesses::readRGBfromFile() {
	setRGBdata(imread(getFilePath()));
	setOutputRGB(imread(getFilePath()));
}

void CommonProcesses::viewRGB() {
	imshow("RGB Data", getRGBdata());
	waitKey();
	destroyAllWindows();
}

void CommonProcesses::viewOutputRGB() {
	imshow("RGB Output Data", getOutputRGB());
	waitKey();
	destroyAllWindows();
}

void CommonProcesses::rgb2GS() {
	cvtColor(getRGBdata(), dstData, COLOR_RGB2GRAY);
}

void CommonProcesses::filterNoise(int filterSize) {
	if (getRGBdata().empty()) {
		throw invalid_argument("There is no image data to filter.");
	}
	if (filterSize % 2 == 0 || filterSize < 0)
		throw invalid_argument("Filter size must be positive & odd.");

	GaussianBlur(getRGBdata(), dstData, Size(filterSize, filterSize), 0);
}

void CommonProcesses::rescaleImage(double sw, double sh) {
	if (getRGBdata().empty()) {
		throw invalid_argument("There is no image data to rescale.");
	}
	if (sw <= 0 || sh <= 0)
		throw invalid_argument("Rescale numbers must be >=0 ");
	resize(getRGBdata(), dstData, Size(), sw, sh);
}

void CommonProcesses::writeRGBtoFile(const string& outputPath) {
	if (getRGBdata().empty()) {
		throw invalid_argument("There is no image data to write.");
	}
	if (outputPath.empty())
		throw invalid_argument("There is no filepath to read.");
	imwrite(outputPath, dstData);
}
