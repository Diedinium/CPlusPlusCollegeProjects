#include "Classes.h"

Student::Student(std::string name, int grade) {
	if (grade < 0 || grade > 100) {
		throw std::exception("Grade must be between 0-100");
	}

	_Name = name;
	_Grade = grade;
	_Passed = grade > 50 ? true : false;
}

std::string Student::DidStudentPass() {
	return _Passed ? "Passed" : "Failed";
}