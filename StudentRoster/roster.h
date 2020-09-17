#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>

class Roster {
public:
	~Roster();
	void add(std::string id, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
	void remove(std::string id);
	void printAll();
	void printDaysInCourse(std::string id);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeType);
	Student* classRosterArray[5] = {NULL, NULL, NULL, NULL, NULL};

};

#endif // !ROSTER_H
