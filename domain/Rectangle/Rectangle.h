#pragma once
#include "..\Point\Point.h"
class Rectangle
{
public:
	Rectangle(Point _ul, Point _dr)
		: ul{ _ul }, dr{ _dr }{
	}
	Point get_ul() { return ul; }
	Point get_dr() { return dr; }
private:
	Point ul;
	Point dr;
};

