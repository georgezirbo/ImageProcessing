#pragma once
class Point
{
public:
	Point(unsigned int _x, unsigned int _y)
		:x{ _x }, y{ _y }{
	}
	unsigned int get_x() const { return x; }
	unsigned int get_y() const { return y; }

private:
	unsigned int x;
	unsigned int y;
};

