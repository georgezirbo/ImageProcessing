#include "Convolution.h"

Image Convolution::identity(Image& a)
{
    Image kernel = Image::identity_kernel();
    unsigned int width, height;
    width = a.get_width();
    height = a.get_height();
    Image result(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1) {
                result.row(i)[j] = a.getROI(i - 1, j - 1, 3, 3).kernel_multiplication(kernel);
            }
            else {
                Image current(3, 3);
                for (int k = i - 1; k < i - 1 + 3; k++) {
                    for (int l = j - 1; l < j - 1 + 3; l++) {
                        if (k < 0 || k >= height || l < 0 || l >= width)
                            current.row(k - i + 1)[l - j + 1] = 0;
                        else
                            current.row(k - i + 1)[l - j + 1] = a.row(k)[l];
                    }
                }
                result.row(i)[j] = current.kernel_multiplication(kernel);
            }

        }
    }
    return result;
}
Image Convolution::mean_blur(Image& a)
{
    Image kernel = Image::mean_blur_kernel();
    unsigned int width, height;
    width = a.get_width();
    height = a.get_height();
    Image result(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1) {
                result.row(i)[j] = a.getROI(i - 1, j - 1, 3, 3).kernel_multiplication(kernel) / 9;
            }
            else {
                Image current(3, 3);
                for (int k = i - 1; k < i - 1 + 3; k++) {
                    for (int l = j - 1; l < j - 1 + 3; l++) {
                        if (k < 0 || k >= height || l < 0 || l >= width)
                            current.row(k - i + 1)[l - j + 1] = 0;
                        else
                            current.row(k - i + 1)[l - j + 1] = a.row(k)[l];
                    }
                }
                result.row(i)[j] = current.kernel_multiplication(kernel) / 9;
            }

        }
    }
    return result;
}

Image Convolution::gaussian_blur(Image& a)
{
    Image kernel = Image::gaussian_blur_kernel();
    unsigned int width, height;
    width = a.get_width();
    height = a.get_height();
    Image result(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1) {
                result.row(i)[j] = a.getROI(i - 1, j - 1, 3, 3).kernel_multiplication(kernel) / 16;
            }
            else {
                Image current(3, 3);
                for (int k = i - 1; k < i - 1 + 3; k++) {
                    for (int l = j - 1; l < j - 1 + 3; l++) {
                        if (k < 0 || k >= height || l < 0 || l >= width)
                            current.row(k - i + 1)[l - j + 1] = 0;
                        else
                            current.row(k - i + 1)[l - j + 1] = a.row(k)[l];
                    }
                }
                result.row(i)[j] = current.kernel_multiplication(kernel) / 16;
            }

        }
    }
    return result;
}

Image Convolution::horizontal(Image& a)
{
    int array[3][3] = { {1,2,1} ,{0,0,0}, {-1,-2,-1} };
    unsigned int width, height;
    width = a.get_width();
    height = a.get_height();
    Image result(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1) 
                result.row(i)[j] = a.getROI(i - 1, j - 1, 3, 3).array_multiplication(array);
            else {
                Image current(3, 3);
                for (int k = i - 1; k < i - 1 + 3; k++) {
                    for (int l = j - 1; l < j - 1 + 3; l++) {
                        if (k < 0 || k >= height || l < 0 || l >= width)
                            current.row(k - i + 1)[l - j + 1] = 0;
                        else
                            current.row(k - i + 1)[l - j + 1] = a.row(k)[l];
                    }
                }
                result.row(i)[j] = current.array_multiplication(array);
            }
            if (result.row(i)[j] > 255)
                result.row(i)[j] = 256;
        }
    }
    return result;
}

Image Convolution::vertical(Image& a)
{
    int array[3][3] = { {-1,0,1} ,{-2,0,2}, {-1,0,1} };
    unsigned int width, height;
    width = a.get_width();
    height = a.get_height();
    Image result(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
                result.row(i)[j] = a.getROI(i - 1, j - 1, 3, 3).array_multiplication(array);
            else {
                Image current(3, 3);
                for (int k = i - 1; k < i - 1 + 3; k++) {
                    for (int l = j - 1; l < j - 1 + 3; l++) {
                        if (k < 0 || k >= height || l < 0 || l >= width)
                            current.row(k - i + 1)[l - j + 1] = 0;
                        else
                            current.row(k - i + 1)[l - j + 1] = a.row(k)[l];
                    }
                }
                result.row(i)[j] = current.array_multiplication(array);
            }
            if (result.row(i)[j] > 255)
                result.row(i)[j] = 256;
        }
    }
    return result;
}

