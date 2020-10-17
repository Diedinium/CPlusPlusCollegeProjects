#include <iostream>
#include <string>
#include <conio.h>
#include "Shapes.h"

int main()
{
    double dHeight, dWidth, dCubeSize;

    std::cout << "Please enter a height: ";
    std::cin >> dHeight;

    std::cout << "Please enter a width: ";
    std::cin >> dWidth;

    Triangle objTriangle = Triangle(dHeight, dWidth);

    std::cout << "Please enter cube size: ";
    std::cin >> dCubeSize;

    Cube objCube = Cube(dCubeSize);
    Square objSquare;
    Rectangle objRectangle;

    try {
        objSquare = Square(dHeight, dWidth);
        std::cout << "Square area: " << objSquare.GetArea() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        objRectangle = Rectangle(dHeight, dWidth);
        std::cout << "Rectangle area: " << objRectangle.GetArea() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Triangle area: " << objTriangle.GetArea() << std::endl;
    std::cout << "Cube volume: " << objCube.GetVolume() << std::endl;
}

