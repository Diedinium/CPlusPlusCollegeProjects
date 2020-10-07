#pragma once

#include <string>
#include <iostream>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class User {
private:
	std::string _sName;
	int _iAge;
public:
	void SetName(std::string sName) { _sName = sName; };
	std::string GetName() { return _sName; };

	void SetNum(int iNumber) { _iAge = iNumber; };
	int GetNum() { return _iAge; };

	void ChangeName();
	void ChangeName(std::string sName);
};

#endif // CUSTOMCLASSES_H
