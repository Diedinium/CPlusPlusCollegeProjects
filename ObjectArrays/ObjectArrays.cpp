#include <iostream>
#include <string>

class clsUser {
    std::string _strName;
    int _iAge;
public:
    clsUser();
    void SetName(std::string strName) { _strName = strName; }
    std::string GetName() { return _strName; }
    void SetAge(int iAge) { _iAge = iAge; }
    int GetAge() { return _iAge; }
};

class clsMember : public clsUser {
    int _iScore;
public:
    void SetScore(int iScore) { _iScore = iScore; }
    int GetScore() { return _iScore; }
};

void GetAllUserDetails(clsMember objMembers[], const int iSize) {
    std::string sName = "";
    int iAge = 0;
    int iScore = 0;

    for (size_t i = 0; i < iSize; i++)
    {
        std::cout << "Please enter member " << i + 1 << "'s name: ";
        std::cin >> sName;
        objMembers[i].SetName(sName);

        std::cout << "Please enter member " << i + 1 << "'s age: ";
        std::cin >> iAge;
        objMembers[i].SetAge(iAge);

        std::cout << "Please enter member " << i + 1 << "'s score: ";
        std::cin >> iScore;
        std::cout << "\n";
        objMembers[i].SetScore(iScore);
    }
}

void OutputUserDetails(clsMember objMembers[], const int iSize) {
    for (size_t i = 0; i < iSize; i++)
    {
        std::cout << "Member " << i + 1 << "'s name: " << objMembers[i].GetName() << "\n";
        std::cout << "Member " << i + 1 << "'s age: " << objMembers[i].GetAge() << "\n";
        std::cout << "Member " << i + 1 << "'s score: " << objMembers[i].GetScore() << "\n\n";
    }
}

int main()
{
    const int iSize = 3;
    clsMember objMembers[iSize];
   
    GetAllUserDetails(objMembers, iSize);

    OutputUserDetails(objMembers, iSize);
}

clsUser::clsUser() {
    _strName = ""; 
    _iAge = 0;
}
