#include "CornerDetection.h"


CornerDetection::CornerDetection(string& PATH, int BS, int AS, double K, int TH)
	:Detection(PATH),
	blockSize(BS),
	apertureSize(AS),
	k(K),
	thresh(TH)
{}

CornerDetection::~CornerDetection(){}

void CornerDetection::setBlockSize(int BS) {
	blockSize = BS;
}

void CornerDetection::setApertureSize(int AS) {
	apertureSize = AS;
}

void CornerDetection::setK(double K) {
	k = K;
}

void CornerDetection::setThresh(int TH) {
	thresh = TH;
}

int CornerDetection::getBlockSize() const {
	return blockSize;
}

int CornerDetection::getApertureSize() const {
	return apertureSize;
}

double CornerDetection::getK() const {
	return k;
}

int CornerDetection::getThresh() const {
	return thresh;
}

void CornerDetection::detectCorners() {
	rgb2GS();
	cornerHarris(getOutputRGB(), dst, getBlockSize(), getApertureSize(), getK());
	Mat dst_norm, dst_norm_scaled;
	normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(dst_norm, dst_norm_scaled);
	for (int i = 0; i < dst_norm.rows; i++)
	{
		for (int j = 0; j < dst_norm.cols; j++)
		{
			if ((int)dst_norm.at<float>(i, j) > getThresh()) 
			{
				circle(dst_norm_scaled, Point(j, i), 5, Scalar(0), 2, 8, 0);
			}
		}
	}
	dst_norm_scaled.copyTo(dst, getOutputRGB());
}

void CornerDetection::visualizeFeatures() const {
	if (!dst.empty()) {
		imshow("Corner Features", dst);
		waitKey(0);
		destroyAllWindows();
	}
	else
	{
		throw runtime_error("There is no detected features");
	}
}

void CornerDetection::writeFeaturesToFile(const string& outputPath) const {
	if (dst.empty()) {
		throw invalid_argument("There is no image data to write.");
	}
	if (outputPath.empty())
		throw invalid_argument("There is no filepath to read.");
	imwrite(outputPath, dst);
}

