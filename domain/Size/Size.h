#pragma once
#include <string>

class Size
{
public:
	Size(unsigned int _w, unsigned int _h)
		:w{ _w }, h{ _h } {
	}
	unsigned int get_width() const { return w; }
	unsigned int get_height() const { return h; }
	std::string to_string() const;
	friend std::ostream& operator << (std::ostream& stream, Size a);

private:
	unsigned int w;
	unsigned int h;
};

