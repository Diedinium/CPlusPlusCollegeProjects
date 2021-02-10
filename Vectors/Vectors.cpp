// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class User {
    std::string _name;
    int _age;
public:
    User() { _name = ""; _age = 0; }
    User(std::string strName, int iAge);
    std::string GetName() { return _name; }
    void SetName(std::string strName) { _name = strName; }
    int GetAge() { return _age; }
    void SetAge(int iAge) { _age = iAge; }
};

void OutputUsers(std::vector<User>* ptrVecUsers);
void OutputUsersIterate(std::vector<User>* ptrVecUsers);

int main()
{
    std::vector<User> vecUsers;
    vecUsers.push_back(User("Jake Hall", 21));
    vecUsers.push_back(User("Test1", 15));
    vecUsers.push_back(User("Test2", 52));
    vecUsers.push_back(User("Test3", 23));
    vecUsers.push_back(User("Test3", 82));

    OutputUsers(&vecUsers);
    OutputUsersIterate(&vecUsers);
}

void OutputUsers(std::vector<User>* ptrVecUsers) {
    for (User user : *ptrVecUsers) {
        std::cout << "\n" << user.GetName() << " is " << user.GetAge() << " years old.";
    }
}

void OutputUsersIterate(std::vector<User>* ptrVecUsers) {
    std::cout << "\n";
    for (size_t i = 0; i < ptrVecUsers->size(); i++)
    {
        std::cout << "\nUser " << i << " named " << ptrVecUsers->at(i).GetName() << " is " << ptrVecUsers->at(i).GetAge() << " years old.";
    }
}

User::User(std::string strName, int iAge) {
    _name = strName;
    _age = iAge;
}
