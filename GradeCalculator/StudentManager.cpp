#include "Classes.h"

void StudentManager::AddStudent(Student student) {
	auto position = std::find_if(_vecStudents.begin(), _vecStudents.end(), [&student](Student& obj) { return obj.GetName() == student.GetName(); });

	if (position == _vecStudents.end()) {
		_vecStudents.push_back(student);
	}
	else {
		throw std::exception("Cannot add student as student with this name already exists.");
	}
}

std::vector<Student>* StudentManager::GetStudents() {
	return &_vecStudents;
}

int StudentManager::GetAverageGrade() {
	auto sum = std::accumulate(_vecStudents.begin(), _vecStudents.end(), 0, [](int i, Student& obj) { return obj.GetGrade() + i; });

	return sum / _vecStudents.size();
}

Student* StudentManager::GetStudentWithHighestGrade() {
	auto it = std::max_element(_vecStudents.begin(), _vecStudents.end(), [](Student& lhs, Student& rhs) { return lhs.GetGrade() < rhs.GetGrade(); });

	if (it != _vecStudents.end()) {
		return &*it;
	}
	else {
		throw std::exception("No students to compare");
	}
}