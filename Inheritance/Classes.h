#pragma once

#include <string>
#include <iostream>
#include <vector>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class User {
protected:
	bool _isAdmin = false;
	std::string _UserName;
	std::string _FirstName;
	std::string _LastName;
	std::string _Password;
public:
	User();
	User(std::string firstname, std::string lastname, std::string password);

	std::string GetUserName() { return _UserName; }
	void SetUserName(std::string userName) { _UserName = userName; }

	std::string GetFirstName() { return _FirstName; }
	void SetFirstName(std::string password) { _FirstName = password; }

	std::string GetLastName() { return _LastName; }
	void SetLastName(std::string password) { _LastName = password; }

	std::string GetPassword() { return _Password; }
	void SetPassword(std::string password) { _Password = password; }

	void UpdateUserName();

	bool IsAdmin() { return _isAdmin; }
};

class Admin : public User {
public:
	Admin(std::string firstname, std::string lastname, std::string password);
	bool ChangePassword(User* userToChange, std::string oldPassword, std::string newPassword);
	void SetFirstName(User* userToChange, std::string newFirstName);
	void SetLastName(User* userToChange, std::string newLastName);
};

class LoginManager {
private:
	std::vector<User> _vecUsers;
	std::vector<Admin> _vecAdmins;
public:
	std::vector<User> GetUsers() { return _vecUsers; };
	std::vector<Admin> GetAdmins() { return _vecAdmins; };
	bool CheckUserLogin(std::string userName, std::string userPassword);
	bool CheckAdminLogin(std::string userName, std::string userPassword);
	void AddUser(User user);
	void AddAdmin(Admin admin);
};

class Product {
protected:
	std::string _strProductName;
	double _dProductTotal;
	double _dProductTax;
public:
	Product();
	Product(std::string productName, double productTotalBeforeTax, double productTax);
	std::string GetProductName() { return _strProductName; }
	double GetProductTotal() { return _dProductTotal; }
	double GetProductTax() { return _dProductTax; }
};

class ProductManager {
private:
	std::vector<Product> _vecProducts;
public:
	void AddProduct(Product& product);
	void DeleteProduct(std::string productName);
	Product* GetProduct(std::string productName);
	std::vector<Product> GetAllProducts();
};

#endif // CUSTOMCLASSES_H
