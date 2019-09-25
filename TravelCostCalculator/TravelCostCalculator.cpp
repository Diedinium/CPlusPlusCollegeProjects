// TravelCostCalculator.cpp : 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

int main()
{
	// Variable declaration.
	std::string sName;
	double dMiles;
	double dPerMile;
	double dRemainder;
	double dTotalCost;

	// Take user input
	std::cout << "What is your first name : ";
	std::cin >> sName;

	std::cout << "How many miles are you going to travel : ";
	while (!(std::cin >> dMiles)) {
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	std::cout << "How much does your company pay per mile (format 0.00) : ";
	while (!(std::cin >> dPerMile)) {
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	// Operation logic
	if (dMiles > 100) {
		dRemainder = dMiles - 100;
		dTotalCost = (100 * dPerMile) + ((dRemainder * dPerMile) / 2);
		std::cout << "Hi " << sName << ", your total travel cost is " << (char)156 << dTotalCost;
	}
	else {
		dTotalCost = (dMiles * dPerMile);
		std::cout << "Hi " << sName << ", your total travel cost is " << (char)156 << dTotalCost;
	}

	return 0;
}

