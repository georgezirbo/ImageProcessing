#pragma once
#include <string>
#include "..\Size\Size.h"
#include "..\Point\Point.h"
#include "..\Rectangle\Rectangle.h"
using std::string;

class Image 
{
public:
	Image();
	Image(unsigned int w, unsigned int h);
	Image(const Image& other);

	~Image();

	bool load(string imagePath);
	bool save(string imagePath);

	Image& operator = (const Image& other);
	Image& operator + (const Image& other);
	Image& operator + (int);
	Image& operator - (const Image& other);
	Image& operator - (int);
	Image& operator * (const Image& other);
	Image& operator * (float);
	Image& operator ^ (float);

	Image getROI(Rectangle roiRect);
	Image getROI(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	bool isEmpty() const;

	Size size() const { return Size(width, height); }

	unsigned int get_width() const { return width; }
	unsigned int get_height() const { return height; }

	unsigned int& at(unsigned int x, unsigned int y) { return data[x][y]; }
	unsigned int& at(Point pt) { return data[pt.get_x()][pt.get_y()]; };

	unsigned int* row(int y);

	void release();

	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);

	static Image identity_kernel();
	static Image mean_blur_kernel();
	static Image gaussian_blur_kernel();
	static int* horizontal();
	static int* vertical();
	
	unsigned int kernel_multiplication(const Image& other);
	int array_multiplication(int array[3][3]);

	
private:
	unsigned int** data;
	unsigned int width;
	unsigned int height;
};