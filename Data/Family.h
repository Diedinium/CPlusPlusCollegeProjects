#pragma once
#include "Common.h"
#include "User.h"

class Family
{
	std::string _sFamilyName;
	std::vector<User> _vec_users;
public:
	Family();
	Family(std::string);
	void set_family_name(std::string sFamilyName) { _sFamilyName = sFamilyName; }
	std::string get_family_name() { return _sFamilyName; }
	std::vector<User>& get_users() { return _vec_users; }
	void add_user(User);
};

