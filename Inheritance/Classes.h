#pragma once

#include <string>
#include <iostream>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class User {
protected:
	std::string _UserName;
	std::string _FirstName;
	std::string _LastName;
	std::string _Password;
public:
	User();
	User(std::string firstname, std::string lastname, std::string password);
	std::string GetUserName() { return _UserName; }
};

class Admin : public User {
public:
	bool ChangePassword(User* userToChange, std::string oldPassword, std::string newPassword);
};

#endif // CUSTOMCLASSES_H
