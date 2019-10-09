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
	int iFailedAttempts = 0;
	bool bIsLoggedIn = false;

	std::string sUsername = "Jake";
	std::string sPassword = "password";
	std::string sUsernameInput;
	std::string sPasswordInput;
	

	do {
		system("cls");
		std::cout << "1: Login\n";
		std::cout << "2: Exit\n";

		std::cout << "Please make a selection: ";
		while (!(std::cin >> iChoice)) {
			std::cout << "ERROR: A number must be entered : ";
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}
		

		switch (iChoice)
		{
		case 1:
		{
			system("cls");
			std::cout << "Welcome to the login screen\n";

			do {
				std::cout << "Username : ";
				std::cin >> sUsernameInput;

				std::cout << "Password : ";
				std::cin >> sPasswordInput;

				if (iFailedAttempts < 2) {
					if ((sUsername == sUsernameInput) && (sPassword == sPasswordInput)) {
						system("cls");
						bIsLoggedIn = true;
						std::cout << "You are now logged in.\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						iFailedAttempts++;
						std::cout << "Username or password incorrect.\n";
					}
				}
				else {
					std::cout << "Max logon attempts exceeded.\n";
					system("pause");
					break;
				}

			} while (!(sUsername == sUsernameInput) || !(sPassword == sPasswordInput));


			break;
		}
		case 2: 
		{
			std::cout << "Exiting...\n";
			break;
		}
		default:
		{
			std::cout << iChoice << " is not recognised input, please try again.\n";
			system("pause");
			break;
		}
		}
	} while (iChoice != 2 && !bIsLoggedIn);

	if (bIsLoggedIn) {
		std::cout << "You have logged in succesfully.\n";
	}
	else {
		std::cout << "You did not login\n";
	}

	return 0;

	
}

