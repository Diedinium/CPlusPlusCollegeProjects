#pragma once

#include <string>
#include <iostream>

class User {
private:
	std::string _sName;
public:
	void SetName(std::string name);
	std::string GetName();
	void ChangeName();
};
