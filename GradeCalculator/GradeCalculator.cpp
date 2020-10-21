#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Classes.h"
#include <iomanip>

void Menu(StudentManager* studentManager);
void ListStudents(StudentManager* studentManager);
void AddStudent(StudentManager* studentManager);
int ValidateIntInput();
void Pause();

int main()
{
    StudentManager studentManager;

    studentManager.AddStudent(Student("Jake Hall", 65));
    studentManager.AddStudent(Student("Tobi Hall", 52));
    studentManager.AddStudent(Student("Isaac Hall", 42));
    studentManager.AddStudent(Student("Luke Hall", 99));

    Menu(&studentManager);
}

void Menu(StudentManager* studentManager) {
    bool boolIsExiting = false;

    do {
        system("cls");
        int choice;

        std::cout << "Welcome to the Grades calculator, please enter your choice: \n";
        std::cout << "1 - Add new student\n";
        std::cout << "2 - List students\n";
        std::cout << "9 - Exit\n";
        std::cout << "Choice : ";
        choice = ValidateIntInput();

        switch (choice)
        {
        case 1:
            AddStudent(studentManager);
            break;
        case 2:
            ListStudents(studentManager);
            break;
        case 9:
            boolIsExiting = true;
            break;
        default:
            std::cout << choice << " is not a valid option\n";
            Pause();
            break;
        }
    } while (!boolIsExiting);
}

void ListStudents(StudentManager* studentManager) {
    system("cls");
    std::vector<Student>* vecStudents = studentManager->GetStudents();

    std::cout << "Current students: \n";

    std::cout << "---------------------------------------------------------------------\n";
    std::cout << std::setw(30) << std::left << "Student name" << std::setw(20) << std::left << "Grade percentage" << std::setw(20) << std::left << "Passed?" << "\n";
    std::cout << "---------------------------------------------------------------------\n";

    for (auto& student : *vecStudents)
    {
        std::cout.precision(2);
        std::cout
            << std::fixed << std::setw(30) << std::left << student.GetName()
            << std::fixed << std::setw(20) << std::left << student.GetGrade()
            << std::fixed << std::setw(20) << std::left << student.DidStudentPass()
            << "\n";
    }

    std::cout << "\n";

    std::cout << "Average: " << studentManager->GetAverageGrade() << "\n";

    Student* highestGrade = studentManager->GetStudentWithHighestGrade();

    std::cout << "Student with highest grade : " << highestGrade->GetName() << "\n";

    Pause();
}

void AddStudent(StudentManager* studentManager) {
    system("cls");

    std::string strStudentName;
    int iGrade;

    std::cout << "Enter student name : ";
    std::getline(std::cin, strStudentName);

    std::cout << "Enter student grade : ";
    iGrade = ValidateIntInput();

    try
    {
        studentManager->AddStudent(Student(strStudentName, iGrade));
        std::cout << "Student added\n";
        Pause();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error : " << ex.what() << "\n";
        Pause();
    }
}

int ValidateIntInput() {
    std::string input;
    std::getline(std::cin, input);

    while (std::cin.fail() || std::cin.eof() || input.find_first_not_of("0123456789") != std::string::npos) {

        std::cout << "Error : Input must be whole number: ";

        if (input.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, input);
    }

    return std::stoi(input);
}

void Pause() {
    std::cout << "\n";
    std::cout << "Press any key to continue...";
    _getch();
}


