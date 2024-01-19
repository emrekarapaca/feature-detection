#pragma once
#include "Detection.h"
class CornerDetection : public Detection
{
public:
	CornerDetection(string&, int = 2, int = 3, double = 0.04, int=200);
	~CornerDetection();

	void setBlockSize(int);
	void setApertureSize(int);
	void setK(double);
	void setThresh(int);

	int getBlockSize() const;
	int getApertureSize() const;
	double getK() const;
	int getThresh() const;

	void detectCorners();
	void writeFeaturesToFile(const string& outputPath) const override;
	void visualizeFeatures() const override;
	
private:
	Mat dst;
	int blockSize;
	int apertureSize;
	double k;
	int thresh;
};

