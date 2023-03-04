#include "Console.h"
#include "../domain/ImageProcessing/ImageProcessing.h"
#include "../domain/ImageProcessing/BrightnessContrast/Brightness_Contrast.h"
#include "../domain/ImageProcessing/GammaCorrection/Gamma.h"
#include "../domain/ImageProcessing/Convolution/Convolution.h"
#include "../utils/Draw.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Console::menu()
{
	cout << "------------------------------- Main menu ------------------------------- " << endl << endl;;
	cout << "Image processing" << endl;
	cout << "   1. Adjust brightness and contrast " << endl;
	cout << "   2. Gamma correction " << endl;
	cout << "   3. Convolution - identity " << endl;
	cout << "   4. Convolution - mean blur " << endl;
	cout << "   5. Convolution - gaussian blur " << endl;
	cout << "   6. Convolution - horizontal sobel " << endl;
	cout << "   7. Convolution - vertical sobel " <<endl << endl;
	cout << "Drawing module" << endl;
	cout << "   8. Line " << endl;
	cout << "   9. Circle " << endl;
	cout << "   10. Rectangle " << endl<<endl;
	cout << "Delete changes (press 0) " << endl;
	cout << "Save changes (press -1) " << endl;
	cout << "Exit program (press -2)" << endl;
	cout << endl<<"------------------------------------------------------------------------- " << endl;
}

void Console::start()
{
	std::string path;
	int cmd = 0;
	Image temp;
	cout << "Introduce the path of the image you want to edit: " << endl;
	cin >> path;
	cout << endl;
	temp.load(path);
	Console::menu();
	cout << endl << ">> ";
	cin >> cmd;
	while (cmd != -2) {
		float gain = 1, bias = 0, gamma = 1;
		int x, y, color = 0, radius;
		switch (cmd) {
		case 1:
			cout << "(Adjust brightness and contrast)"<<endl;
			cout << "Gain(>0): ";
			cin >> gain;
			cout << "Bias: ";
			cin >> bias;
			temp = Brightness_Contrast::adjust(temp, gain, bias);
			temp.save("images/temp.pgm");
			break;
		case 2:
			cout << "(Gamma correction)" << endl;
			cout << "Gamma(>0): ";
			cin >> gamma;
			temp = Gamma::correction(temp, gamma);
			temp.save("images/temp.pgm");
			break;
		case 3:
			cout << "(Convolution - identity)" << endl;
			temp = Convolution::identity(temp);
			temp.save("images/temp.pgm");
			break;
		case 4:
			cout << "(Convolution - mean blur)" << endl;
			temp = Convolution::mean_blur(temp);
			temp.save("images/temp.pgm");
			break;
		case 5:
			cout << "(Convolution - gaussian blur)" << endl;
			temp = Convolution::gaussian_blur(temp);
			temp.save("images/temp.pgm");
			break;
		case 6: {
			cout << "(Convolution - horizontal sobel)" << endl;
			temp = Convolution::horizontal(temp);
			temp.save("images/temp.pgm");
		}
			break;
		case 7: {
			cout << "(Convolution - vertical sobel)" << endl;
			temp = Convolution::vertical(temp);
			temp.save("images/temp.pgm");
		}
			break;
		case 8:{
			cout << "(Line)" << endl;
			cout << "x1: ";
			cin >> x;
			cout << "y1: ";
			cin >> y;
			Point p1(x, y);
			cout << "x2: ";
			cin >> x;
			cout << "y3: ";
			cin >> y;
			Point p2(x, y);
			cout << "Color (int): ";
			cin >> color;
			temp = Draw::drawLine(temp, p1, p2, color);
			temp.save("images/temp.pgm");
		}
			break;
		case 9: {
			cout << "(Circle)" << endl;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			Point p(x, y);
			cout << "Radius: ";
			cin >> radius;
			cout << "Color (int): ";
			cin >> color;
			temp = Draw::drawCircle(temp, p, radius, color);
			temp.save("images/temp.pgm");
		}
			break;
		case 10: {
			cout << "(Rectangle)" << endl;
			cout << "x1: ";
			cin >> x;
			cout << "y1: ";
			cin >> y;
			Point p3(x, y);
			cout << "x2: ";
			cin >> x;
			cout << "y3: ";
			cin >> y;
			Point p4(x, y);
			cout << "Color (int): ";
			cin >> color;
			temp = Draw::drawRectangle(temp, p3, p4, color);
			temp.save("images/temp.pgm");
		}
			break;
		case 0:
			cout << "(Delete changes)" << endl;
			temp.load(path);
			temp.save("images/temp.pgm");
			break;
		case -1:
			cout << "(Save changes)"<<endl;
			temp.load("images/temp.pgm");
			temp.save(path);
			break;
		default:
			cout << "The introduced command does not exist. Try again.\nTo save the changes press 0 and to exit the program press -1. ";
		}
		cout << endl << ">> ";
		cin >> cmd;
	}
	cout <<endl<< "Program ended successfully. :)"<<endl;
}

