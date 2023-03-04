#pragma once
#include <iostream>
#include "..\domain\Image\Image.h"
#include "..\domain\Size\Size.h"
#include "..\domain\Point\Point.h"
#include "..\domain\Rectangle\Rectangle.h"
using std::cin;
using std::cout;
using std::endl;

class Tests
{
public:
	static void run_tests();
private:
	static void run_tests_point();
	static void run_tests_size();
};

