#include "Draw.h"
#include <math.h>

Image Draw::drawCircle(Image& img, Point center, unsigned int radius, unsigned int color)
{
    Image result = img;
    float distance;
    int x, y;
    x = center.get_x();
    y = center.get_y();
    for (int i = 0; i < img.get_height(); i++) {
        for (int j = 0; j < img.get_width(); j++) {
            distance = sqrt(pow(x - i, 2) + pow(y - j, 2));
            if (fabs(distance) - radius <= 0.0005 )
                result.row(i)[j] = color;
        }
    }
    
    return result;
}

Image Draw::drawLine(Image& img, Point p1, Point p2, unsigned int color)
{
    Image result = img;
    int x1, y1, x2, y2, x, y, dx, dy, t;
    x1 = p1.get_x();
    y1 = p1.get_y();
    x2 = p2.get_x();
    y2 = p2.get_y();
    float M, p;

    if ((x2 - x1) == 0)
        M = (y2 - y1);
    else
        M = (y2 - y1) / (x2 - x1);

    if (fabs(M) < 1)
    {
        if (x1 > x2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }
        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);
        p = 2 * dy - dx;
        x = x1;
        y = y1;
            
        while (x <= x2)
        {
            result.row(x)[y] = color;
            x = x + 1;
            if (p >= 0){
                if (M < 1)
                    y = y + 1;
                else
                    y = y - 1;
                p = p + 2 * dy - 2 * dx;
            }
            else {
                y = y;
                p = p + 2 * dy;
            }
        }
    }
    else 
    {
        if (y1 > y2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y1;
            y1 = y2;
            y2 = t;
        }
        dx = fabs(x2 - x1);
        dy = fabs(y2 - y1);
        p = 2 * dx - dy;
        x = x1;
        y = y1;
        while (y <= y2)
        {
            result.row(x)[y] = color;
            y = y + 1;
            if (p >= 0)
            {
                if (M >= 1)
                    x = x + 1;
                else
                    x = x - 1;
                p = p + 2 * dx - 2 * dy;
            }
            else
            {
                x = x;
                p = p + 2 * dx;
            }
        }
    }
    return result;
}

Image Draw::drawRectangle(Image& img, Rectangle r, unsigned int color)
{
    Image result = img;
    int x1, y1, x2, y2;
    x1 = r.get_ul().get_x();
    x2 = r.get_dr().get_x();
    y1 = r.get_ul().get_y();
    y2 = r.get_dr().get_x();
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++)
            result.row(i)[j] = color;
    }
    return result;
}

Image Draw::drawRectangle(Image& img, Point ul, Point dr, unsigned int color)
{
    Image result = img;
    int x1, y1, x2, y2;
    x1 = ul.get_x();
    x2 = dr.get_x();
    y1 = ul.get_y();
    y2 = dr.get_x();
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++)
            result.row(i)[j] = color;
    }
    return result;
    return Image();
}
