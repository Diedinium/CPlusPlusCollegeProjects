// FileHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>

struct User
{
	int iID;
	std::string sName = "";
	int iAge;
	double dSalary;
};

int main()
{
	/*std::string strName;

	std::cout << "Enter your name :";
	std::cin >> strName;

	std::ofstream File("new.txt");

	File << "Hello " << strName << "\n";
	File << "Lets do some maths\n";
	File << "What's 10 + 9?\n";
	File << "21?\n";

	File.close();

	std::cout << "\n\n";

	std::ifstream File2("new.txt");*/
	std::string sLine = "";
	/*while (getline(File2, sLine)) 
	{
		std::cout << sLine << "\n";
	}

	File2.close();*/

	std::vector<User> UserList;
	std::vector<User> ImportedUser;
	std::vector<std::string> vSplit;
	sLine = "";
	std::string sResult = "";

	User user1{ 1, "Jake", 20, 26262.42 };
	User user2{ 2, "Tobi", 17, 6262 };
	User user3{ 3, "Luke", 45, 626272 };

	UserList.push_back(user1);
	UserList.push_back(user2);
	UserList.push_back(user3);

	std::ofstream File3("users.txt");

	for (size_t i = 0; i < UserList.size(); i++)
	{
		File3 << UserList.at(i).iID << "," << UserList.at(i).sName << "," << UserList.at(i).iAge << "," << UserList.at(i).dSalary << "\n";
	}

	File3.close();

	std::ifstream File4("users.txt");
	while (getline(File4, sLine))
	{
		std::cout << sLine << "\n";
	}

	while (getline(File4, sLine)) {
		std::stringstream ssSplit(sLine);
		ImportedUser.push_back(User());

		vSplit.clear();
		
		while (getline(ssSplit, sResult, ',')) {
			vSplit.push_back(sResult);
		}

		ImportedUser.back().iID = std::stoi(vSplit.at(0));
		ImportedUser.back().sName = vSplit.at(1);
		ImportedUser.back().iAge = std::stoi(vSplit.at(2));
		ImportedUser.back().dSalary = std::stod(vSplit.at(3));
	}

	File4.close();

	for (size_t i = 0; i < ImportedUser.size(); i++)
	{
		std::cout << "User Details : " << ImportedUser[i].iID << " " << ImportedUser[i].sName << " " << ImportedUser[i].iAge << " " << ImportedUser[i].dSalary << "\n";
	}

	_getch();
}

