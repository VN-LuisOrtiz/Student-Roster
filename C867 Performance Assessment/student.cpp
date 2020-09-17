#include <iostream>
#include <string>
#include "student.h"

//CONSTRUCTORS
Student::Student() {
	SetId("0");
	SetFirstName("0");
	SetLastName("0");
	SetEmail("0");
	SetAge(0);
	SetDays(0);
	SetDegreeType(SOFTWARE);
}


Student::Student(std::string studentId, std::string studentFirstName, std::string studentLastName, std::string studentEmail, int studentAge, int daysToComplete[3], Degree studentDegree) {
	SetId(studentId);
	SetFirstName(studentFirstName);
	SetLastName(studentLastName);
	SetEmail(studentEmail);
	SetAge(studentAge);
	SetDays(daysToComplete);
	SetDegreeType(studentDegree);
}

//DESTRUCTOR
Student::~Student() { //No resources where requested dynamically, hence why the destructor is empty

}

//MUTATORS
void Student::SetId(std::string studentId) {
	id = studentId;
}

void Student::SetFirstName(std::string studentFirstName) {
	firstName = studentFirstName;
}

void Student::SetLastName(std::string studentLastName) {
	lastName = studentLastName;
}

void Student::SetEmail(std::string studentEmail) {
	email = studentEmail;
}

void Student::SetAge(int studentAge) {
	age = studentAge;
}

void Student::SetDays(int daysToComplete[]) {
	for (int i = 0; i < 3; i++)
		daysToCompleteCourse[i] = daysToComplete[i];
}

void Student::SetDegreeType(Degree studentDegree) {
	degreeType = studentDegree;
}

//ACCESSORS
std::string Student::GetId() const {
	return id;
}

std::string Student::GetFirstName() const {
	return firstName;
}

std::string Student::GetLastName() const {
	return lastName;
}

std::string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDays() {
	return daysToCompleteCourse;			
}

//PRINT
void Student::print() {
	std::string type;
	if (degreeType == 0) {
		type = "SECURITY";
		std::cout << id << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << "  \tdaysInCourse: {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1]
		<< ", " << daysToCompleteCourse[2] << "} Degree Program: " << type << std::endl;
	}
	else if (degreeType == 1) {
		type = "NETWORK";
		std::cout << id << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << " \tdaysInCourse: {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1]
		<< ", " << daysToCompleteCourse[2] << "} Degree Program: " << type << std::endl;
	}
	else {
		type = "SOFTWARE";
		std::cout << id << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age << " \tdaysInCourse: {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1]
		<< ", " << daysToCompleteCourse[2] << "} Degree Program: " << type << std::endl;
	}

}



