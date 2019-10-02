// LogicIteration.cpp : Demo of logic and iteration within C++

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

int main()
{
	int iChoice = 0;
	std::string sUsername = "Jake";
	std::string sPassword = "password";
	std::string sUsernameInput;
	std::string sPasswordInput;

	std::cout << "1: Login\n";
	std::cout << "2: Exit\n";

	std::cout << "Please make a selection: ";
	std::cin >> iChoice;

	switch (iChoice) 
	{
		case 1: 
		{
			std::cout << "Welcome to the login screen\n";

			std::cout << "Username : ";
			std::cin >> sUsernameInput;
			
			std::cout << "Password : ";
			std::cin >> sPasswordInput;

			if ((sUsername == sUsernameInput) && (sPassword == sPasswordInput)) {
				std::cout << "You are now logged in.\n";
				system("pause");
			}
			else {
				std::cout << "Username or password incorrect.\n";
			}
		}
		case 2: 
		{
			std::cout << "Logging you out and exiting...\n";
			system("Pause");
			system("exit");
		}
		default: 
		{
			std::cout << "Not recognised input, please try again.\n";
		}
	}
	
	return 0;
}

