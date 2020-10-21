#pragma once

#include <string>
#include <iostream>
#include <vector>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class Student {
protected:
	std::string _Name;
	int _Grade
public:
	std::string GetName() { return _Name; }
	void SetName(std::string name) { _Name = name; }
};

#endif // CUSTOMCLASSES_H
