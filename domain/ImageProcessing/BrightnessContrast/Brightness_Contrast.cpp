#include "Brightness_Contrast.h"

Image Brightness_Contrast::adjust(Image& src, float A, float B)
{
    src * A + B;
    return src;
}
