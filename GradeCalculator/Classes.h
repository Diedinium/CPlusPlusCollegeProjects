#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

class Student {
protected:
	std::string _Name;
	int _Grade = 0;
	bool _Passed = false;
public:
	Student() {}
	Student(std::string name, int grade);
	std::string GetName() { return _Name; }
	void SetName(std::string name) { _Name = name; }

	int GetGrade() { return _Grade; }
	void SetGrade(int grade) { _Grade = grade; }

	std::string DidStudentPass();
};


class StudentManager {
protected:
	std::vector<Student> _vecStudents;
public:
	void AddStudent(Student student);
	std::vector<Student>* GetStudents();
	int GetAverageGrade();
	Student* GetStudentWithHighestGrade();
};
#endif // CUSTOMCLASSES_H
