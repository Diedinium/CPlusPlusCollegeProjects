#include <iostream>
#include <string>
#include <conio.h>
#include "customClasses.h"

int main()
{
	std::string inputName;
	std::string inputNum;
	User objUser;

	std::cout << "Welcome to the program\n";

	std::cout << "Please enter your name: ";
	std::getline(std::cin, inputName);

	objUser.SetName(inputName);

	std::cout << "Welcome to the program " << objUser.GetName() << std::endl;

	std::cout << "Please enter your age: ";
	std::getline(std::cin, inputNum);

	objUser.SetNum(std::stoi(inputNum));

	std::cout << "Age is " << objUser.GetNum() << std::endl;

	objUser.ChangeName();
	//objUser.ChangeName(inputName);

	std::cout << "Name is now : " << objUser.GetName() << std::endl;
}




