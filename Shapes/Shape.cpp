#include "Shapes.h"

Shape::Shape() {
	_dWidth = 0;
	_dHeight = 0;
}

Shape::Shape(double height, double width) {
	_dHeight = height;
	_dWidth = width;
}