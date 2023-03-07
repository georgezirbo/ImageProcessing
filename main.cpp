//for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "ui\Console.h"

int main()
{
    Console::start();
    _CrtDumpMemoryLeaks();
    return 0;
}
