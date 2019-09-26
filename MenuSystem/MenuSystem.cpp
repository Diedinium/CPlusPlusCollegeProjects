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

std::string sUsername = "JakeHall";
std::string sPassword = "password";
std::string sUsernameInput;
std::string sPasswordInput;

int iMenuChoiceInput;
int iFirstChoiceInput;
int iSecondChoiceInput;
int iAttempts;

int* pMenuChoiceInput = NULL;
int* pFirstChoiceInput = NULL;
int* pSecondChoiceInput = NULL;
int* pAttempts;

std::string* pUsername = NULL;
std::string* pPassword = NULL;
std::string* pUsernameInput = NULL;
std::string* pPasswordInput = NULL;


int main()
{
	pMenuChoiceInput = &iMenuChoiceInput;
	pFirstChoiceInput = &iFirstChoiceInput;
	pSecondChoiceInput = &iSecondChoiceInput;
	pAttempts = &iAttempts;

	pUsername = &sUsername;
	pPassword = &sPassword;
	pUsernameInput = &sUsernameInput;
	pPasswordInput = &sPasswordInput;

	MenuOpenPage();

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
	std::cout << "|     Option 4 - Exit console                                    |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Please specify your choice : ";

	while (!(std::cin >> *pMenuChoiceInput)) {
		MenuOpenPageError();
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	try {
		if (*pMenuChoiceInput == 1) {
			MenuOption1();
		}
		else if (*pMenuChoiceInput == 2) {
			MenuOption2();
		}
		else if (*pMenuChoiceInput == 3) {
			MenuOption3();
		}
		else if (*pMenuChoiceInput == 4) {
			system("exit");
		}
		else {
			throw std::logic_error("ERROR: A valid option was not input.");
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
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
	std::cout << "|     Option 4 - Exit console                                    |\n";
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

	while (!(std::cin >> *pFirstChoiceInput)) {
		MenuOption1Error();
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	while (!(*pFirstChoiceInput == 1)) {
		std::cout << "Please try again : ";
		std::cin >> *pFirstChoiceInput;
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	std::cout << "You chose the correct answer\n";
	system("pause");
	MenuOpenPage();
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
	std::cout << "|                         Welcome to Option 2                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|                     to the smallest number                     |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - 25                                              |\n";
	std::cout << "|     Option 2 - 102                                             |\n";
	std::cout << "|     Option 3 - 15                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "Please specify your choice : ";

	while (!(std::cin >> *pSecondChoiceInput)) {
		MenuOption2Error();
		std::cout << "ERROR: A number must be entered : ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	while (!(*pSecondChoiceInput == 3)) {
		std::cout << "Please try again : ";
		std::cin >> *pSecondChoiceInput;
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	std::cout << "You chose the correct answer\n";
	system("pause");
	MenuOpenPage();
	
}

void MenuOption2Error() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|                         Welcome to Option 2                    |\n";
	std::cout << "|             Please enter the number that corresponds           |\n";
	std::cout << "|                     to the smallest number                     |\n";
	std::cout << "|                                                                |\n";
	std::cout << "|     Option 1 - 25                                               |\n";
	std::cout << "|     Option 2 - 102                                             |\n";
	std::cout << "|     Option 3 - 15                                              |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";
}

void MenuOption3() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|                         Welcome to Option 3                    |\n";
	std::cout << "|             Please provide your username and password          |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";

	if (*pAttempts < 3) {
		std::cout << "Username : ";
		std::cin >> *pUsernameInput;

		std::cout << "Password : ";
		std::cin >> *pPasswordInput;
		if ((*pUsernameInput == *pUsername) && (*pPasswordInput == *pPassword)) {
			std::cout << "Your username and password are correct. You are now logged in.\n";
			system("pause");
			MenuOpenPage();
		}
		else {
			std::cout << "Either your username or password don't match.\n";
			++*pAttempts;
			system("pause");
			MenuOpenPage();
		}
	}
	else {
		std::cout << "The maximum number of attempts has been exceeded. Please try again later.\n";
		system("pause");
		MenuOpenPage();
	}
	
		
}

void MenuOption3Error() {
	system("CLS");
	std::cout << "+----------------------------------------------------------------+\n";
	std::cout << "|                         Welcome to Option 3                    |\n";
	std::cout << "|             Please provide your username and password          |\n";
	std::cout << "|                                                                |\n";
	std::cout << "+----------------------------------------------------------------+\n";


}

// Functions end
