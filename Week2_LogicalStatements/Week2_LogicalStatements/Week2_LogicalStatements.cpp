// Week2_LogicalStatements.cpp : Logical statements.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>


int main()
{
	// Variable declaration
	std::string sAge = "";
	double dAge = 0;
	std::string sFirstName = "";
	std::string sLastName = "";

	// Collecting values from user
	std::cout << "Please enter your age : ";
	getline(std::cin, sAge);

	std::cout << "Please enter your First Name : ";
	getline(std::cin, sFirstName);

	std::cout << "Please enter your Last Name : ";
	getline(std::cin, sLastName);

	// Chagning input into double
	dAge = std::stod(sAge);

	// Output.
	std::cout << "Hello " << sFirstName << " " << sLastName << ", You are " << dAge << " years old.\n";

	// Logical check
	if (dAge < 5) {
		printf("At %.0f years old, you are not old enough for school.\n", dAge);
	}
	else if ((dAge >= 5) && (dAge <= 16)){
		printf("At %.0f years old, you are probably in primary or secondary school.\n", dAge);
	}
	else if ((dAge >= 17) && (dAge <= 18)) {
		printf("At %.0f years old, you are probably in college.\n", dAge);
	}
	else if ((dAge > 18) && (dAge <= 65)) {
		printf("At %.0f years old, you are either done with education or in University.\n", dAge);
	}
	else if (dAge == 67) {
		printf("At %.0f years old, Congratuations on hitting the retirement age.\n", dAge);
	}
	else {
		printf("At %.0f years old, No criteria specified for this age.\n", dAge);
	}
	
	_getch();

	return 0;
}
