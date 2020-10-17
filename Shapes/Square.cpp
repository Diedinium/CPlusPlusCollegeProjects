#include "Shapes.h"

Square::Square(double height, double width) {
	if (height != width) {
		throw std::exception("Error: Could not create square; Height and width must match to create a square");
	}

	_dHeight = height;
	_dWidth = width;
	_dArea = width * height;
}