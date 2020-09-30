#pragma once

#include <string>
#include <iostream>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class User {
private:
	std::string _sName;
public:
	void SetName(std::string name);
	std::string GetName();
	void ChangeName();
};

#endif // CUSTOMCLASSES_H
