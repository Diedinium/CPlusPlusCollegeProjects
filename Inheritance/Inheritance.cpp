#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "Classes.h"

void Menu(std::vector<User>* vecUsers, std::vector<Admin>* vecAdmins);

int main()
{
    std::vector<User> vecUsers;
    std::vector<Admin> vecAdmins;

    User objUser = User("Jake", "Hall", "crappyPassword");
    std::cout << "User Created: " + objUser.GetUserName() << std::endl;

    Admin objAdmin = Admin("Admin", "McAdmin", "crappyPassword");
    std::cout << "Admin Created: " + objAdmin.GetUserName() << std::endl;

    std::cout << "Attempting to change password for " + objUser.GetUserName() << std::endl;
    bool passwordChangeSuccesfull = objAdmin.ChangePassword(&objUser, "crappyPassword", "updatedPassword");

    std::string passwordMessage = passwordChangeSuccesfull ? "True" : "False";

    std::cout << "Password changed? " + passwordMessage << std::endl;

    std::cout << "Attempting to change firstName for " + objUser.GetUserName() << std::endl;
    objAdmin.SetFirstName(&objUser, "Rachel");
    std::cout << "New username : " + objUser.GetUserName() << std::endl;

    vecUsers.push_back(objUser);
    vecAdmins.push_back(objAdmin);

    Menu(&vecUsers, &vecAdmins);
}

void Menu(std::vector<User>* vecUsers, std::vector<Admin>* vecAdmins) {
    bool isLoggedIn = false;

    do {
        int logInChoice;
        std::string userName;
        std::string password;
        std::cout << "Enter 1 to login as admin, 2 to login as user: ";
        std::cin >> logInChoice;

        if (logInChoice < 1 || logInChoice > 2) {
            
        }
        else {
            std::cout << "Please enter your username:";
            std::getline(std::cin, userName);

            std::cout << "Please enter your password:";
            std::getline(std::cin, password);

            switch (logInChoice)
            {
            case 1:
                for (size_t i = 0; i < vecUsers->size(); i++)
                {
                    if (userName == vecUsers->at(i).GetUserName() && password == vecUsers->at(i).GetPassword()) {

                    }
                }
                break;
            case 2:
                break;
            default:
                break;
            }
        }
    } while (!isLoggedIn)
    
}
