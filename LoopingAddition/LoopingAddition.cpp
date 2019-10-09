// LoopingAddition.cpp : Demonostration of looping addition

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

int main()
{
	// Variables 
	int iFirstNumber = 0;
	int iSecondNumber = 0;
	int iTotal = 0;
	// Variables end

	// Input 
	std::cout << "Please input first whole nubmer:";
	while (!(std::cin >> iFirstNumber)) {
		std::cout << "ERROR: A valid whole number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	std::cout << "Please input second whole nubmer:";
	while (!(std::cin >> iSecondNumber)) {
		std::cout << "ERROR: A valid whole number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}
	// Input end

	// Looping logic
	do {
		iTotal += iFirstNumber;
		std::cout << iTotal << std::endl;
		iTotal += iSecondNumber;
		std::cout << iTotal << std::endl;
	} while (iTotal < 300);
	// Looping logic end
	return 0;
}
