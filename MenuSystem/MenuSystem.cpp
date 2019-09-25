// MenuSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <conio.h>

void MenuOpenPage();
void MenuOption1();
void MenuOption2();
void MenuOption3();
void MenuOpenPageError();
void MenuOption1Error();
void MenuOption2Error();
void MenuOption3Error();

int main()
{
	std::string sUsername = "JakeHall";
	std::string sPassword = "password";
	std::string sUsernameInput;
	std::string sPasswordInput;
	int iMenuChoiceInput;
	int iFirstChoiceInput;
	int iSecondChoiceInput;

	MenuOpenPage();

	while (!(std::cin >> iMenuChoiceInput)) {
		MenuOpenPageError();
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	try {
		if (iMenuChoiceInput == 1) {
			MenuOption1();
			while (!(std::cin >> iFirstChoiceInput)) {
				MenuOption1Error();
				std::cout << "ERROR: A number must be entered : ";
				std::cin.clear();
				std::cin.ignore(123, '\n');
			}
		}
		else if (iMenuChoiceInput == 2) {
			MenuOption2();
			while (!(std::cin >> iSecondChoiceInput)) {
				MenuOption2Error();
				std::cout << "ERROR: A number must be entered : ";
				std::cin.clear();
				std::cin.ignore(123, '\n');
			}
		}
		else if (iMenuChoiceInput == 3) {
			MenuOption3();
		}
		else {
			throw std::logic_error("ERROR: A valid option was not input.");
		}
	}
	catch (const std::exception& e){
		std::cout << e.what() << "\n";
	}

	return 0;
}

// Functions

void MenuOpenPage() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|               Welcome to the Menu System                       |\n";
	std::cout << "|         Please select one of the following options by          |\n";
	std::cout << "|       typing the corresponding option number into the          |\n";
	std::cout << "|               console and pressing Enter                       |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - Select the largest number                       |\n";
	std::cout << "|     Option 2 - Select the lowest number                        |\n";
	std::cout << "|     Option 3 - Log in                                          |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Please specify your choice : ";
}

void MenuOpenPageError() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|               Welcome to the Menu System                       |\n";
	std::cout << "|         Please select one of the following options by          |\n";
	std::cout << "|       typing the corresponding option number into the          |\n";
	std::cout << "|               console and pressing Enter                       |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - Select the largest number                       |\n";
	std::cout << "|     Option 2 - Select the lowest number                        |\n";
	std::cout << "|     Option 3 - Log in                                          |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
}

void MenuOption1() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|                         Welcome to Option 1                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|                     to the largest number                      |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - 57                                              |\n";
	std::cout << "|     Option 2 - 12                                              |\n";
	std::cout << "|     Option 3 - 37                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Please specify your choice : ";
}

void MenuOption1Error() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|                         Welcome to Option 1                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|                     to the largest number                      |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - 57                                              |\n";
	std::cout << "|     Option 2 - 12                                              |\n";
	std::cout << "|     Option 3 - 37                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
}

void MenuOption2() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|							Welcome to Option 2                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|						to the smallest number                     |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|		Option 1 - 8                                               |\n";
	std::cout << "|     Option 2 - 102											   |\n";
	std::cout << "|     Option 3 - 15                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Please specify your choice : ";
}

void MenuOption2Error() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|							Welcome to Option 2                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|						to the smallest number                     |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|		Option 1 - 8                                               |\n";
	std::cout << "|     Option 2 - 102											   |\n";
	std::cout << "|     Option 3 - 15                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
}

void MenuOption3() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|							Welcome to Option 3                    |\n";
	std::cout << "|             Please provide your username and password          |\n";
	std::cout << "|																   |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Username : ";
}

void MenuOption3Error() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|							Welcome to Option 3                    |\n";
	std::cout << "|             Please provide your username and password          |\n";
	std::cout << "|																   |\n";
	std::cout << "+----------------------------------------------------------------+\n";
}

// Functions end
