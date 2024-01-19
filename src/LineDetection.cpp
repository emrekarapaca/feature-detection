#include "LineDetection.h"


LineDetection::LineDetection(string& PATH, int LT, int MT, int RT, int KS)
	:Detection(PATH)
{
	setLowTh(LT);
	setMaxTh(MT);
	setRatio(RT);
	setKernelSize(KS);
}

LineDetection::~LineDetection(){}

void LineDetection::setLowTh(int LT) {
	lowTh = LT;
}

void LineDetection::setMaxTh(int MT) {
	maxTh = MT;
}

void LineDetection::setRatio(int RT) {
	ratio = RT;
}

void LineDetection::setKernelSize(int KS) {
	kernel_size = KS;
}

int LineDetection::getLowTh() const {
	return lowTh;
}

int LineDetection::getMaxTh() const {
	return maxTh;
}

int LineDetection::getRatio() const {
	return ratio;
}

int LineDetection::getKernelSize() const {
	return kernel_size;
}

void LineDetection::detectLines() {
	rgb2GS();
	filterNoise(getKernelSize());
	Canny(getOutputRGB(), dst, getLowTh(), getMaxTh(), getRatio(), getKernelSize());
}

void LineDetection::visualizeFeatures() const {
	if (!dst.empty()) {
		imshow("Line Features", dst);
		waitKey(0);
		destroyAllWindows();
	}
	else
	{
		throw runtime_error("There is no detected features");
	}
}

void LineDetection::writeFeaturesToFile(const string& outputPath) const {
	if (dst.empty()) {
		throw invalid_argument("There is no image data to write.");
	}
	if (outputPath.empty())
		throw invalid_argument("There is no filepath to read.");
	imwrite(outputPath, dst);
}