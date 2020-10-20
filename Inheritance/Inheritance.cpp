#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Classes.h"
#include <iomanip>

void Menu(LoginManager* loginManager, ProductManager* productManager);
void Login(LoginManager* loginManager, ProductManager* productManager, bool isAdmin);
void AdminMenu(LoginManager* loginManager, ProductManager* productManager);
void UserMenu(LoginManager* loginManager, ProductManager* productManager, User* loggedInUser);
void Pause();

void ChangeUserPassword(LoginManager* loginManager);
void ChangeUserFirstName(LoginManager* loginManagern);
void ChangeUserLastName(LoginManager* loginManager);
void ListProducts(ProductManager* productManager);
void AddProduct(ProductManager* productManager);
void DeleteProduct(ProductManager* productManager);

void ChangePassword(LoginManager* loginManager, User* loggedInUser);
void BuyProduct(ProductManager* productManager);
void Basket(ProductManager* productManager);

int main()
{
	LoginManager loginManager;
	ProductManager productManager;

	loginManager.AddUser(User("Jake", "Hall", "password"));
	loginManager.AddUser(User("Tobi", "Hall", "crappyPassword1"));
	loginManager.AddUser(User("Isaac", "Hall", "crappyPassword2"));
	loginManager.AddUser(User("Luke", "Hall", "crappyPassword3"));

	loginManager.AddAdmin(Admin("Admin", "McAdmin", "password"));

	productManager.AddProduct(Product("Monitor", 50.50, 5.65));
	productManager.AddProduct(Product("Computer", 802, 25.25));
	productManager.AddProduct(Product("Mouse", 15.3, 1.28));
	productManager.AddProduct(Product("Keyboard", 25.56, 2.55));

	Menu(&loginManager, &productManager);
}

void Menu(LoginManager* loginManager, ProductManager* productManager) {
	bool isExiting = false;

	do {
		int logInChoice;
		std::string userName;
		std::string password;

		system("cls");
		std::cout << "Options:\n";
		std::cout << "1 - Login as User\n";
		std::cout << "2 - Login as Admin\n";
		std::cout << "9 - Exit\n";
		std::cout << "Options: ";
		std::cin >> logInChoice;

		switch (logInChoice) {
		case 1:
			Login(loginManager, productManager, false);
			break;
		case 2:
			Login(loginManager, productManager, true);
			break;
		case 9:
			isExiting = true;
			std::cout << "Exiting...\n";
			break;
		default:
			std::cout << logInChoice << " is not a valid choice.\n";
			break;
		}
	} while (!isExiting);
}

void Login(LoginManager* loginManager, ProductManager* productManager, bool isAdmin) {
	std::string strUserName, strPassword;
	bool isValidLogin = false;

	system("cls");
	std::cin.ignore();

	std::cout << "Please enter your username: ";
	std::getline(std::cin, strUserName);

	std::cout << "Please enter your password: ";
	std::getline(std::cin, strPassword);

	if (isAdmin) {
		isValidLogin = loginManager->CheckAdminLogin(strUserName, strPassword);
	}
	else {
		isValidLogin = loginManager->CheckUserLogin(strUserName, strPassword);
	}

	if (isValidLogin && isAdmin) {
		try {
			AdminMenu(loginManager, productManager);
		}
		catch (std::exception& ex) {
			std::cout << "Error: " << ex.what() << "\n";
			Pause();
		}
	}
	else if (isValidLogin && !isAdmin) {
		User* objUser = loginManager->GetUser(strUserName);
		UserMenu(loginManager, productManager, objUser);
	}
	else {
		std::cout << "Username or password was incorrect.\n";
		Pause();
	}
}

void AdminMenu(LoginManager* loginManager, ProductManager* productManager) {
	bool isExiting = false;
	int iAdminChoice;

	do {
		system("cls");
		std::cout << "Admin options: \n";
		std::cout << "1 - Change user password\n";
		std::cout << "2 - Change user first name\n";
		std::cout << "3 - Change user last name\n";
		std::cout << "4 - List products\n";
		std::cout << "5 - Add product\n";
		std::cout << "6 - Delete product\n";
		std::cout << "9 - Logout\n";
		std::cout << "Choice : ";
		std::cin >> iAdminChoice;

		switch (iAdminChoice)
		{
		case 1:
			ChangeUserPassword(loginManager);
			break;
		case 2:
			ChangeUserFirstName(loginManager);
			break;
		case 3:
			ChangeUserLastName(loginManager);
			break;
		case 4:
			ListProducts(productManager);
			break;
		case 5:
			AddProduct(productManager);
			break;
		case 6:
			DeleteProduct(productManager);
			break;
		case 9:
			isExiting = true;
			break;
		default:
			break;
		}
	} while (!isExiting);
}

void ChangeUserPassword(LoginManager* loginManager) {
	system("cls");
	bool boolIsExiting = false;

	do {
		std::string strUserName;
		std::string strUserPassword;

		std::cout << "Enter user name for the user you would like to update. Type 'exit' to cancel.\n";
		std::cout << "Username : ";
		std::cin >> strUserName;

		std::string lowerStrUserName = strUserName;

		std::transform(lowerStrUserName.begin(), lowerStrUserName.end(), lowerStrUserName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (lowerStrUserName == "exit") {
			boolIsExiting = true;
		}
		else {
			std::cout << "New password : ";
			std::cin >> strUserPassword;

			try
			{
				loginManager->UpdateUserPassword(strUserName, strUserPassword);
				std::cout << "User password updated\n";
				Pause();
				boolIsExiting = true;
			}
			catch (const std::exception& ex)
			{
				std::cout << "Error : " << ex.what() << "\n";
			}
		}
	} while (!boolIsExiting);
}

void ChangeUserFirstName(LoginManager* loginManager) {
	system("cls");
	bool boolIsExiting = false;

	do {
		std::string strUserName;
		std::string strFirstName;

		std::cout << "Enter user name for the user you would like to update. Type 'exit' to cancel.\n";
		std::cout << "Username : ";
		std::cin >> strUserName;

		std::string lowerStrUserName = strUserName;

		std::transform(lowerStrUserName.begin(), lowerStrUserName.end(), lowerStrUserName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (lowerStrUserName == "exit") {
			boolIsExiting = true;
		}
		else {
			std::cout << "New first name : ";
			std::cin >> strFirstName;

			try
			{
				loginManager->UpdateUserFirstName(strUserName, strFirstName);
				std::cout << "User first name updated\n";
				Pause();
				boolIsExiting = true;
			}
			catch (const std::exception& ex)
			{
				std::cout << "Error : " << ex.what() << "\n";
			}
		}
	} while (!boolIsExiting);
}

void ChangeUserLastName(LoginManager* loginManager) {
	system("cls");
	bool boolIsExiting = false;

	do {
		std::string strUserName;
		std::string strLastName;

		std::cout << "Enter user name for the user you would like to update. Type 'exit' to cancel.\n";
		std::cout << "Username : ";
		std::cin >> strUserName;

		std::string lowerStrUserName = strUserName;

		std::transform(lowerStrUserName.begin(), lowerStrUserName.end(), lowerStrUserName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (lowerStrUserName == "exit") {
			boolIsExiting = true;
		}
		else {
			std::cout << "New last name : ";
			std::cin >> strLastName;

			try
			{
				loginManager->UpdateUserLastName(strUserName, strLastName);
				std::cout << "User last name updated\n";
				Pause();
				boolIsExiting = true;
			}
			catch (const std::exception& ex)
			{
				std::cout << "Error : " << ex.what() << "\n";
			}
		}
	} while (!boolIsExiting);
}

void ListProducts(ProductManager* productManager) {
	system("cls");
	std::vector<Product> vecProductList = productManager->GetAllProducts();

	std::cout << "---------------------------------------------------------------------\n";
	std::cout << std::setw(40) << std::left << "Product name" << std::setw(20) << std::left << "Product total" << std::setw(20) << std::left << "Tax" << "\n";
	std::cout << "---------------------------------------------------------------------\n";

	for (auto& product : vecProductList)
	{
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(40) << std::left << product.GetProductName()
			<< std::fixed << std::setw(20) << std::left << product.GetProductTotal()
			<< std::fixed << std::setw(20) << std::left << product.GetProductTax()
			<< "\n";
	}

	std::cout << "\n";
	Pause();
}

void AddProduct(ProductManager* productManager) {
	system("cls");

	std::string strProductName;
	double dPriceBeforeTax;
	double dTax;

	std::cin.ignore();
	std::cout << "Enter details for the product you would like to add.\n";
	std::cout << "New product name : ";
	std::getline(std::cin, strProductName);

	std::cout << "Product price (before tax) : ";
	std::cin >> dPriceBeforeTax;

	std::cout << "Product tax : ";
	std::cin >> dTax;

	Product objProduct = Product(strProductName, dPriceBeforeTax, dTax);

	try
	{
		productManager->AddProduct(objProduct);
		std::cout << "Product added\n";
		Pause();
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error : " << ex.what() << "\n";
		Pause();
	}
}

void DeleteProduct(ProductManager* productManager) {
	system("cls");

	std::string strProductName;

	std::cin.ignore();
	std::cout << "Enter details for the product you would like to delete.\n";
	std::cout << "Product to delete : ";
	std::getline(std::cin, strProductName);

	try
	{
		productManager->DeleteProduct(strProductName);
		std::cout << "Product deleted\n";
		Pause();
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error : " << ex.what() << "\n";
		Pause();
	}
}

void UserMenu(LoginManager* loginManager, ProductManager* productManager, User* loggedInUser) {
	bool isExiting = false;
	int iUserChoice;

	do {
		system("cls");
		std::cout << "User options: \n";
		std::cout << "1 - Change password\n";
		std::cout << "2 - Buy Product\n";
		std::cout << "3 - Basket\n";
		std::cout << "9 - Logout\n";
		std::cout << "Choice : ";
		std::cin >> iUserChoice;

		std::cout << "\n";

		switch (iUserChoice)
		{
		case 1:
			ChangePassword(loginManager, loggedInUser);
			break;
		case 2:
			BuyProduct(productManager);
			break;
		case 3:
			Basket(productManager);
			break;
		case 9:
			isExiting = true;
			break;
		default:
			break;
		}
	} while (!isExiting);
}

void ChangePassword(LoginManager* loginManager, User* loggedInUser) {
	system("cls");
	std::string strUserPasswordOld, strUserPasswordNew;
	
	std::cin.ignore();
	std::cout << "Old password : ";
	std::getline(std::cin, strUserPasswordOld);

	std::cout << "New password : ";
	std::getline(std::cin, strUserPasswordNew);

	try
	{
		if (strUserPasswordOld == loggedInUser->GetPassword()) {
			loggedInUser->SetPassword(strUserPasswordNew);
			std::cout << "User password updated\n";
			Pause();
		}
		else {
			std::cout << "Error : You did not provide your current valid password." << "\n";
			Pause();
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error : " << ex.what() << "\n";
		Pause();
	}

}

void BuyProduct(ProductManager* productManager) {
	system("cls");
	std::vector<Product> vecProductList = productManager->GetAllProducts();
	size_t choice;

	std::cout << "Buy a product\n";
	std::cout << "---------------------------------------------------------------------\n";
	std::cout << std::setw(4) << std::left << "#" << std::setw(40) << std::left << "Product name" << std::setw(20) << std::left << "Product total" << std::setw(20) << std::left << "Tax" << "\n";
	std::cout << "---------------------------------------------------------------------\n";

	for (size_t i = 0; i < vecProductList.size(); i++)
	{
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(4) << std::left << i
			<< std::fixed << std::setw(40) << std::left << vecProductList[i].GetProductName()
			<< std::fixed << std::setw(20) << std::left << vecProductList[i].GetProductTotal()
			<< std::fixed << std::setw(20) << std::left << vecProductList[i].GetProductTax()
			<< "\n";
	}

	std::cout << "Choice : ";
	std::cin >> choice;

	try
	{
		productManager->BuyProduct(vecProductList[choice]);
		std::cout << "Added " << vecProductList[choice].GetProductName() << " to basket\n";
		Pause();
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error : The number you specified is not a valid choice!\n";
		Pause();
	}
}

void Basket(ProductManager* productManager) {
	system("cls");
	std::vector<Product> vecBasket = productManager->GetBasketItems();

	if (vecBasket.size() < 1) {
		std::cout << "You have not yet added any items to your basket, to see totals, go and buy some items!\n";
		Pause();
	}
	else {
		std::cout << "Your items\n";
		std::cout << "---------------------------------------------------------------------\n";
		std::cout << std::setw(4) << std::left << "#" << std::setw(40) << std::left << "Product name" << std::setw(20) << std::left << "Product total" << std::setw(20) << std::left << "Tax" << "\n";
		std::cout << "---------------------------------------------------------------------\n";

		for (size_t i = 0; i < vecBasket.size(); i++)
		{
			std::cout.precision(2);
			std::cout
				<< std::fixed << std::setw(4) << std::left << i
				<< std::fixed << std::setw(40) << std::left << vecBasket[i].GetProductName()
				<< std::fixed << std::setw(20) << std::left << vecBasket[i].GetProductTotal()
				<< std::fixed << std::setw(20) << std::left << vecBasket[i].GetProductTax()
				<< "\n";
		}

		std::cout << "\n";
		std::cout << "Total (with tax): " << productManager->GetBasketTotal() << "\n";
		std::cout << "Total tax: " << productManager->GetBasketTax() << "\n";
		Pause();
	}
}

void Pause() {
	std::cout << "Press any key to continue...\n";
	_getch();
}
