// ForLoopPowerOf10.cpp : Calculating to the power of 10

#include <iostream>

int main()
{
	int iNumber = 0;

	std::cout << "Please specify a number : ";
	std::cin >> iNumber;

	int iTotal = iNumber;

	for (int i = 0; i < 10; i++) {
		iTotal = iTotal * iNumber;
	}

	std::cout << iNumber << " to the power of 10 : " << iTotal << std::endl;

	return 0;
}


