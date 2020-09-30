#include "customClasses.h"

void User::SetName(std::string name) {
	_sName = name;
}

std::string User::GetName() {
	return _sName;
}
void User::ChangeName() {
	std::cout << "Please enter your new name : ";
	std::cin >> _sName;
}