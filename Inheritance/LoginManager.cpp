#include "Classes.h"

bool LoginManager::CheckUserLogin(std::string userName, std::string userPassword) {
	for (auto &user : _vecUsers)
	{
		if (user.GetUserName() == userName && user.GetPassword() == userPassword) {
			return true;
		}
	}

	return false;
}

bool LoginManager::CheckAdminLogin(std::string userName, std::string userPassword) {
	for (auto& admin : _vecAdmins)
	{
		if (admin.GetUserName() == userName && admin.GetPassword() == userPassword) {
			return true;
		}
	}

	return false;
}

void LoginManager::AddUser(User user) {
	_vecUsers.push_back(user);
}

void LoginManager::AddAdmin(Admin admin) {
	_vecAdmins.push_back(admin);
}

void LoginManager::UpdateUserPassword(std::string userName, std::string newUserPassword) {
	for (auto& user : _vecUsers) {
		if (user.GetUserName() == userName) {
			user.SetPassword(newUserPassword);
			return;
		}
		else {
			throw std::exception("User not found.");
		}
	}
}

void LoginManager::UpdateUserFirstName(std::string userName, std::string newFirstName) {
	for (auto& user : _vecUsers) {
		if (user.GetUserName() == userName) {
			user.SetFirstName(newFirstName);
			user.UpdateUserName();
			return;
		}
		else {
			throw std::exception("User not found.");
		}
	}
}

void LoginManager::UpdateUserLastName(std::string userName, std::string newLastName) {
	for (auto& user : _vecUsers) {
		if (user.GetUserName() == userName) {
			user.SetLastName(newLastName);
			user.UpdateUserName();
			return;
		}
		else {
			throw std::exception("User not found.");
		}
	}
}

User* LoginManager::GetUser(std::string userName) {
	auto position = std::find_if(_vecUsers.begin(), _vecUsers.end(), [&userName](User& obj) { return obj.GetUserName() == userName; });

	if (position != _vecUsers.end()) {
		return &*position;
	}
	else {
		throw std::exception("User not found.");
	}
}