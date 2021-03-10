#include "Utilities.h"

void util::initialise_family(Family& obj_family) {
	std::string str_name;

	std::cout << "Please enter family name: ";
	std::cin >> str_name;

	obj_family.set_family_name(str_name);
}