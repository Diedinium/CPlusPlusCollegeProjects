#include "customClasses.h"

void User::ChangeName() {
	std::cout << "Please enter your new name : ";
	std::getline(std::cin, _sName);
}

void User::ChangeName(std::string name) {
	_sName = name;
}