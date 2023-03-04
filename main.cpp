//for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <iomanip>
#include "tests\Tests.h"
#include "domain\Image\Image.h"
#include "domain\ImageProcessing\ImageProcessing.h"
#include "domain\ImageProcessing\BrightnessContrast\Brightness_Contrast.h"
#include "domain\ImageProcessing\GammaCorrection\Gamma.h"
#include "domain\ImageProcessing\Convolution\Convolution.h"
#include "utils\Draw.h"
#include "ui\Console.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Console::start();
    _CrtDumpMemoryLeaks();
    return 0;
}
