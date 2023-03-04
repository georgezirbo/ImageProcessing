#pragma once
#include "..\ImageProcessing.h"
#include "..\..\Image\Image.h"

class Convolution: public ImageProcessing
{
public:
	static Image identity(Image&);
	static Image mean_blur(Image&);
	static Image gaussian_blur(Image&);
	static Image horizontal(Image&);
	static Image vertical(Image&);

private:
	Image kernel;
};

