#pragma once
#include "..\ImageProcessing.h"

class Brightness_Contrast : public ImageProcessing
{
public:
	static Image adjust(Image& src, float A, float B);
private:
	float A;
	float B;
};

