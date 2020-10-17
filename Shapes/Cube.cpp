#include "Shapes.h"

Cube::Cube(double size) {
	_dHeight = size;
	_dWidth = size;
	_dVolume = (_dHeight * _dWidth) * size;
}