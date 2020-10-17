#include "Shapes.h"

Rectangle::Rectangle(double height, double width) {
	if (height == width) {
		throw std::exception("Error: Could not create rectangle; Height and width must be different for a rectangle");
	}

	_dHeight = height;
	_dWidth = width;
	_dArea = width * height;
}