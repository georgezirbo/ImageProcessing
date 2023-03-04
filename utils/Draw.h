#pragma once
#include "..\domain\Image\Image.h"

class Draw
{
public:
	static Image drawCircle(Image& img, Point center, unsigned int radius, unsigned int color);
	static Image drawLine(Image& img, Point p1, Point p2, unsigned int color);
	static Image drawRectangle(Image& img, Rectangle r, unsigned int color);
	static Image drawRectangle(Image& img, Point tl, Point br, unsigned int color);
};

