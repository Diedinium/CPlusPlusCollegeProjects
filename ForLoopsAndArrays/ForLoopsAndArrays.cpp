// ForLoopsAndArrays.cpp : Demo of for loops and arrays.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

int main()
{
	// int iNumbers = { values here } is how you declare values.
	int iNumbers[5];
	int totalNumber = 0;

	// To get size of array in C++ we need to get the size of the array in bytes, divided by the size of the array pointer.
	for (int i = 0; i < (sizeof(iNumbers) / sizeof(*iNumbers)); i++) {
		std::cout << "Type in number " << i + 1 << " : ";
		std::cin >> iNumbers[i];
		totalNumber += iNumbers[i];
	}

	std::cout << "Total value : " << totalNumber << std::endl;

	std::cout << "\n";

	for (auto y : iNumbers) std::cout << "Value : " << y << "\n";
	
	return 0;
}


