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