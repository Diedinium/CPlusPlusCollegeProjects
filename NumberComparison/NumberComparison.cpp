// NumberComparison.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

int main()
{
	std::exception_ptr p;
	int iNumber1 = 0;
	int iNumber2 = 0;
	int iNumber3 = 0;

	std::cout << "Please enter number 1 : ";
	std::cin >> iNumber1;

	std::cout << "Please enter number 2 : ";
	std::cin >> iNumber2;

	std::cout << "Please enter number 3 : ";
	std::cin >> iNumber3;

	try {
		if ((iNumber1 == iNumber2) || (iNumber2 == iNumber3) || (iNumber1 == iNumber3)) {
			throw std::logic_error("Two numbers with the same value were entered.");
		}
		else {
			if ((iNumber1 > iNumber2) && (iNumber1 > iNumber3)) {
				printf("%d is the biggest number", iNumber1);
			}
			else if (iNumber2 > iNumber3) {
				printf("%d is the biggest number", iNumber2);
			}
			else {
				printf("%d is the biggest number", iNumber3);
			}
		}
	}
	catch (const std::exception& e) {
		p = std::current_exception();
		std::cout << "Error : " << e.what() << "\n";
	}
}

