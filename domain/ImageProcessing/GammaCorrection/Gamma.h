#pragma once
#include "..\ImageProcessing.h"
#include "..\..\Image\Image.h"
class Gamma : public ImageProcessing
{
public:
	static Image correction(Image& a, float G);
private:
	float G;
};

