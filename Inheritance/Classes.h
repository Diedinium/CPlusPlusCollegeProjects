#pragma once

#include <string>
#include <iostream>

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

#endif // CUSTOMCLASSES_H
