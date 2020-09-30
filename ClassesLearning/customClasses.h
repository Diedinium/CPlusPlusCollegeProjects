#pragma once

#include <string>

class User {
private:
	std::string _sName;
public:
	void SetName(std::string name) {
		_sName = name;
	}

	std::string GetName() {
		return _sName;
	}
};
