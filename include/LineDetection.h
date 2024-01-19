#pragma once
#include "Detection.h"
class LineDetection : public Detection
{
public:
	LineDetection(string&, int=0, int=100, int=3, int=3);
	~LineDetection();

	void setLowTh(int);
	void setMaxTh(int);
	void setRatio(int);
	void setKernelSize(int);

	int getLowTh() const;
	int getMaxTh() const;
	int getRatio() const;
	int getKernelSize() const;

	void detectLines();

	void writeFeaturesToFile(const string& outputPath) const override;
	void visualizeFeatures() const override;


private:
	Mat dst;
	int lowTh;
	int maxTh;
	int ratio;
	int kernel_size;

};

