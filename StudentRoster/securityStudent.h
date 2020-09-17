#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student { //Security Student class that inherits from Student Class.
public:
	Student::Student;
	Degree getDegreeProgram();
	void print();
private:
	Degree degree = SECURITY;
};




#endif // !SECURITYSTUDENT_H
