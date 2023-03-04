#define CRT_SECURE_NO_WARNINGS
#include "Image.h"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <math.h>

Image::Image()
	:width{ 10 }, height{ 10 }
{
	data = new unsigned int* [height];
	for (unsigned int i = 0; i < height; i++) {
		data[i] = new unsigned int[width];
		memset(data[i], 0, width * sizeof(unsigned int));
	}
}

Image::Image(unsigned int w, unsigned int h)
	:width{w}, height{h}
{
	data = new unsigned int* [height];
	for (unsigned int i = 0; i < height; i++) {
		data[i] = new unsigned int[width];
		memset(data[i], 0, width * sizeof(unsigned int));
	}
}

Image::Image(const Image& other)
	:width{other.width}, height{other.height}
{
	data = new unsigned int* [other.height];
	for (unsigned int i = 0; i < other.height; i++) {
		data[i] = new unsigned int[other.width];
		for (unsigned int j = 0; j < other.width; j++)
			data[i][j] = other.data[i][j];
	}
}

Image::~Image()
{
	this->release();
}

bool Image::load(string imagePath)
{
	std::ifstream fin;
	char junk[5];
	unsigned int temp;
	unsigned int i = 0, j = 0;
	fin.open(imagePath);
	if (!fin.good())
		return false;
	fin >> junk >> i>>j>>junk;
	Image a(i, j);
	*this = a;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			fin >> temp;
			data[i][j] = temp;
		}
	}
	fin.close();
	if ((i == height - 1) || (j = width - 1))
		return true;
	return false;
}

bool Image::save(string imagePath)
{
	std::ofstream fout;
	fout.open(imagePath);
	if (!fout.good())
		return false;
	fout << "P2\n" << width << " " << height << "\n" <<255<<"\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			fout << std::setw(3) << data[i][j] << " ";
		fout << "\n";
	}
	fout.close();
	return true;
}

Image& Image::operator=(const Image& other)
	
{
	for (int i = 0; i < height; i++) {
		delete[] data[i];
	}
	delete[] data;
	width = other.width; 
	height = other.height;
	data = new unsigned int* [other.height];
	for (unsigned int i = 0; i < other.height; i++) {
		data[i] = new unsigned int[other.width];
		for (unsigned int j = 0; j < other.width; j++)
			data[i][j] = other.data[i][j];
	}
	return *this;
}

Image& Image::operator+(const Image& other)
{
	if (width != other.width || height != other.height) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				data[i][j] += other.data[i][j];
		}
	}

	return *this;
}

Image& Image::operator+(int n)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[i][j] = (data[i][j] + n);
			if (data[i][j] > 255) {
				if (n < 0)
					data[i][j] = 256;
				else
					data[i][j] = 255;
			}
		}
	}
	return *this;
}

Image& Image::operator-(const Image& other)
{
	if (width != other.width || height != other.height) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				data[i][j] = (data[i][j] - other.data[i][j]);
		}
	}
	return *this; 
}

Image& Image::operator-(int n)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[i][j] = (data[i][j] - n);
			if (data[i][j] > 255) {
				if (n < 0)
					data[i][j] = 256;
				else
					data[i][j] = 255;
			}
		}
	}
	return *this;
}

Image& Image::operator*(const Image& other)
{
	if (width != other.width || height != other.height) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				data[i][j] *= other.data[i][j];
				if (data[i][j] > 255)
					data[i][j] = 255;
			}
		}
	}
	return *this;
}

Image& Image::operator*(float n)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[i][j] *= n;
			if (data[i][j] > 255) {
				if (n < 0)
					data[i][j] = 256;
				else
					data[i][j] = 255;
			}
		}
	}
	return *this;
}

Image& Image::operator^(float n)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[i][j] = pow(data[i][j], n);
			if (data[i][j] > 255) {
				if (n < 0)
					data[i][j] = 256;
				else
					data[i][j] = 255;
			}
		}
	}
	return *this;
}

Image Image::getROI(Rectangle roiRect)
{
	int w, h, x, y;
	Point b = roiRect.get_ul();
	w = roiRect.get_dr().get_y() - roiRect.get_ul().get_y() + 1;
	h = roiRect.get_dr().get_x() - roiRect.get_ul().get_x() + 1;
	if (!(w <= width) || !(h <= height) || w < 0 || h < 0) {
		return *this;
	}
	x = b.get_x();
	y = b.get_y();
	Image a(w, h);
	for (int i = x; i < x + h; i++) {
		for (int j = y; j < y + w; j++)
			a.data[i - x][j - y] = data[i][j];
	}
	return a;
}

Image Image::getROI(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	if (!(w <= width) || !(h <= height) || w < 0 || h < 0) {
		return *this;
	}
	Image a(w, h);
	for (int i = x; i < x + h; i++) {
		for (int j = y; j < y + w; j++)
			a.data[i - x][j - y] = data[i][j] % 256;
	}
	return a;
}

bool Image::isEmpty() const
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (data[i][j] != 0)
				return false;
		}
	}
	return true;
}

unsigned int* Image::row(int y)
{
	return data[y];
}

void Image::release()
{
	for (int i = 0; i < height; i++) {
		delete[] data[i];
	}
	delete[] data;
}

std::string Image::to_string() const
{
	std::ostringstream s;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			s << std::setw(3) << data[i][j] << " ";
		s << std::endl;
	}
	return s.str();
}

Image Image::zeros(unsigned int _width, unsigned int _height)
{
	Image a(_width, _height);
	return a;
}

Image Image::ones(unsigned int _width, unsigned int _height)
{
	Image a(_width, _height);
	a + 1;
	return a;
}

Image Image::identity_kernel()
{
	Image a(3, 3);
	a.data[1][1] = 1;
	return a;
}

Image Image::mean_blur_kernel()
{
	Image a = Image::ones(3, 3);
	return a;
}

Image Image::gaussian_blur_kernel()
{
	Image a = Image::ones(3, 3);
	a.data[0][1] = 2;
	a.data[1][0] = 2;
	a.data[2][1] = 2;
	a.data[1][2] = 2;
	a.data[1][1] = 4;
	return a;
}

unsigned int Image::kernel_multiplication(const Image& other)
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += data[i][j] * other.data[i][j];
		}
	}
	return sum;
}

int Image::array_multiplication(int array[3][3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += data[i][j] * array[i][j];
		}
	}
	return sum;
}

std::ostream& operator<<(std::ostream& os, const Image& dt)
{
	os << dt.to_string();
	return os;
}
