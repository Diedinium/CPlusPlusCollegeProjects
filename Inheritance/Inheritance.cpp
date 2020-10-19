#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "Classes.h"

void Menu(LoginManager* loginManager);
void Login(LoginManager* loginManager, bool isAdmin);
void AdminMenu(LoginManager* loginManager);
void UserMenu(LoginManager* loginManager);
void Pause();

int main()
{
    LoginManager loginManager;

    loginManager.AddUser(User("Jake", "Hall", "crappyPassword"));
    loginManager.AddUser(User("Tobi", "Hall", "crappyPassword1"));
    loginManager.AddUser(User("Isaac", "Hall", "crappyPassword2"));
    loginManager.AddUser(User("Luke", "Hall", "crappyPassword3"));

    loginManager.AddAdmin(Admin("Admin", "McAdmin", "crappyPassword"));

    Menu(&loginManager);
}

void Menu(LoginManager* loginManager) {
    bool isExiting = false;

    do {
        int logInChoice;
        std::string userName;
        std::string password;

        system("cls");
        std::cout << "Options:\n";
        std::cout << "1 - Login as User\n";
        std::cout << "2 - Login as Admin\n";
        std::cout << "9 - Exit\n";
        std::cout << "Options: ";
        std::cin >> logInChoice;

        switch (logInChoice) {
        case 1:
            Login(loginManager, false);
            break;
        case 2:
            Login(loginManager, true);
            break;
        case 9:
            isExiting = true;
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << logInChoice << " is not a valid choice.\n";
            break;
        }
    } while (!isExiting);
}

void Login(LoginManager* loginManager, bool isAdmin) {
    std::string strUserName, strPassword;
    bool isValidLogin = false;

    system("cls");
    std::cin.ignore();

    std::cout << "Please enter your username: ";
    std::getline(std::cin, strUserName);

    std::cout << "Please enter your password: ";
    std::getline(std::cin, strPassword);

    if (isAdmin) {
        isValidLogin = loginManager->CheckAdminLogin(strUserName, strPassword);
    }
    else {
        isValidLogin = loginManager->CheckUserLogin(strUserName, strPassword);
    }

    if (isValidLogin && isAdmin) {
        AdminMenu(loginManager);
    }
    else if (isValidLogin && !isAdmin) {
        UserMenu(loginManager);
    }
    else {
        std::cout << "Username or password was incorrect.\n";
        Pause();
    }
}

void AdminMenu(LoginManager* loginManager) {
    bool isExiting = false;
    int iAdminChoice;

    do {
        system("cls");
        std::cout << "Admin options: \n";
        std::cout << "1 - Change user password\n";
        std::cout << "2 - Change user first name\n";
        std::cout << "3 - Change user last name\n";
        std::cout << "4 - Add product\n";
        std::cout << "5 - Delete product\n";
        std::cout << "9 - Logout\n";
        std::cout << "Choice : ";
        std::cin >> iAdminChoice;

        switch (iAdminChoice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 9:
            isExiting = true;
            break;
        default:
            break;
        }
    } while (!isExiting);
}

void UserMenu(LoginManager* loginManager) {
    bool isExiting = false;
    int iUserChoice;

    do {
        system("cls");
        std::cout << "User options: \n";
        std::cout << "1 - Change password\n";
        std::cout << "2 - Buy Product\n";
        std::cout << "3 - Basket\n";
        std::cout << "9 - Logout\n";
        std::cout << "Choice : ";
        std::cin >> iUserChoice;

        std::cout << "\n";

        switch (iUserChoice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 9:
            isExiting = true;
            break;
        default:
            break;
        }
    } while (!isExiting);
}

void Pause() {
    std::cout << "Press any key to continue...\n";
    _getch();
}
