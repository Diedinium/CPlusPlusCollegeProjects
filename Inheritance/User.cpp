#include "Classes.h"

User::User() {
	_UserName = "Default";
}

User::User(std::string firstName, std::string lastName, std::string password) {
	_FirstName = firstName;
	_LastName = lastName;
	_Password = password;
	_UserName = firstName + "." + lastName;
}

void User::UpdateUserName() {
	_UserName = _FirstName + "." + _LastName;
}