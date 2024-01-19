#pragma once
#include "CommonProcesses.h"
class Detection : public CommonProcesses
{
public:
	Detection(string&);
	~Detection();

	virtual void writeFeaturesToFile(const string&) const = 0;
	virtual void visualizeFeatures() const = 0;
};

