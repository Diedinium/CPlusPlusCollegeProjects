#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

#ifndef SHAPES_H
#define SHAPES_H

class Shape {
protected:
	double _dHeight;
	double _dWidth;
public:
	Shape();
	Shape(double height, double width);
};

class Triangle : public Shape {
private:
	double _dArea;
public:
	Triangle(double height, double width);
	double GetArea() { return _dArea; }
};

class Cube : public Shape {
private:
	double _dVolume;
public:
	Cube(double size);
	double GetVolume() { return _dVolume; }
};

class Square : public Shape {
protected:
	double _dArea;
public:
	Square() : Shape() {}
	Square(double height, double width);
	double GetArea() { return _dArea; }
};

class Rectangle : public Square {
public:
	Rectangle() : Square() {}
	Rectangle(double height, double width);
};

#endif // SHAPES_H