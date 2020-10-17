#include "Shapes.h"

Triangle::Triangle(double height, double width) {
	_dHeight = height;
	_dWidth = width;
	_dArea = (height * width) / 2;
}