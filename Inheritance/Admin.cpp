#include "Classes.h";

Admin::Admin(std::string firstName, std::string lastName, std::string password) {
	_isAdmin = true;
	_FirstName = firstName;
	_LastName = lastName;
	_Password = password;
	_UserName = firstName + "." + lastName;
}

bool Admin::ChangePassword(User* userToChange, std::string oldPassword, std::string newPassword) {
	if (userToChange->GetPassword() == oldPassword) {
		userToChange->SetPassword(newPassword);
		return true;
	}
	else {
		return false;
	}
}

void Admin::SetFirstName(User* userToChange, std::string newFirstName) {
	userToChange->SetFirstName(newFirstName);
	userToChange->UpdateUserName();
}

void Admin::SetLastName(User* userToChange, std::string newLastName) {
	userToChange->SetLastName(newLastName);
	userToChange->UpdateUserName();
}