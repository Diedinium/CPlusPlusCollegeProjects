// ClassesLearning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include "customClasses.h"

int main()
{
	std::string inputName;
	User objUser;

	std::cout << "Welcome to the program\n";

	std::cout << "Please enter your name: ";
	std::cin >> inputName;

	objUser.SetName(inputName);

	std::cout << "Welcome to the program " << objUser.GetName() << std::endl;

	objUser.ChangeName();

	std::cout << "Name is now : " << objUser.GetName() << std::endl;
}




