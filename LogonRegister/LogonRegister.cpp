// LogonRegister.cpp : A logon and register system to demonstrate knowledge

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

struct USER {
	std::string sUserName = "";
	std::string sPassWord = "";
	std::string sUserNameInput = "";
	std::string sPassWordInput = "";
};

int main()
{
	int iChoice = 0;
	int iFailedAttempts = 0;
	bool bIsRegistered = false;
	bool bIsLoggedIn = false;
	USER mainUser;

	do {
		system("cls");
		if (bIsRegistered) {
			std::cout << "1: Login\n";
		}
		else {
			std::cout << "1: Register\n";
		}
		std::cout << "2: Exit\n";

		std::cout << "Please make a selection: ";
		while (!(std::cin >> iChoice)) {
			std::cout << "ERROR: A number must be entered : ";
			std::cin.clear();
			std::cin.ignore(123, '\n');
		}

		if (bIsRegistered) {
			switch (iChoice) {
			case 1: {
				do {
					std::cout << "Username : ";
					std::cin >> mainUser.sUserNameInput;

					std::cout << "Password : ";
					std::cin >> mainUser.sPassWordInput;

					if (iFailedAttempts < 3) {
						if ((mainUser.sUserName == mainUser.sUserNameInput) && (mainUser.sPassWord == mainUser.sPassWordInput)) {
							system("cls");
							bIsLoggedIn = true;
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

				} while (!(mainUser.sUserName == mainUser.sUserNameInput) || !(mainUser.sPassWord == mainUser.sPassWordInput));
				break;
			}
			case 2: {
				std::cout << "Exiting...\n";
				break;
			}
			default:
			{
				std::cout << iChoice << " is not a valid input...\n";
				system("pause");
				break;
			}
			}
		}
		else {
			switch (iChoice) {
			case 1: {
				std::cout << "Specify Your username : ";
				std::cin >> mainUser.sUserName;

				std::cout << "Specify Your Password : ";
				std::cin >> mainUser.sPassWord;

				bIsRegistered = true;
				break;
			}
			case 2: {
				std::cout << "Exiting...\n";
				break;
			}
			default:
			{
				std::cout << iChoice << " is not a valid input...\n";
				system("pause");
				break;
			}
			}
		}

	} while (iChoice != 2 && !bIsLoggedIn);

	if (bIsLoggedIn) {
		std::cout << "You have logged in succesfully.\n";
		system("pause");
	}
	else {
		std::cout << "You did not login\n";
		system("pause");
	}

	return 0;
}


