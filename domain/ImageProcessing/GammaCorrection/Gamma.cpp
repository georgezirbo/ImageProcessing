#include "Gamma.h"

Image Gamma::correction(Image& a, float G)
{
	Image result;
	result = a ^ G;
	return result;
}
