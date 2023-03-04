#include "Tests.h"
#include "..\domain\Point\Point.h"
#include "..\domain\Size\Size.h"
#include <cassert>

 void Tests::run_tests()
{
	cout << "Point - run tests" << endl;
	run_tests_point();
	cout << "Point - successfully tested" << endl;
	cout << "- - - - - - - - - - - - - - - - -" << endl;
	cout << "Size - run tests" << endl;
	run_tests_size();
	cout << "Size - successfully tested" << endl;
}

 void Tests::run_tests_point()
{
	Point a(2, 6);
	assert(a.get_x() == 2);
	assert(a.get_y() == 6);
}

void Tests::run_tests_size()
 {
	Size a(200, 800);
	assert(a.get_width() == 200);
	assert(a.get_height() == 800);
 }
