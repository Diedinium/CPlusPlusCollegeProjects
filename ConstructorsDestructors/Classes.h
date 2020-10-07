#pragma once

#include <string>
#include <iostream>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class Rectangle {
private:
	int _iWidth;
	int _iHeight;
public:
	Rectangle();
	Rectangle(int iHeight, int iWidth);

	int GetHeight() { return _iHeight; };
};

#endif // CUSTOMCLASSES_H
