#include "Family.h"

Family::Family() {
	_sFamilyName = "";
}

Family::Family(std::string family_name) {
	_sFamilyName = family_name;
}

void Family::add_user(User user_to_add) {
	_vec_users.push_back(user_to_add);
}