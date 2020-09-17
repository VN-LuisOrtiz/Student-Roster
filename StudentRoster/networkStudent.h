#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include <string>

class NetworkStudent : public Student { //Network Student class that inherits from Student Class.
public:
	Student::Student;
	Degree getDegreeProgram();
	void print();
private:
	Degree degree = NETWORKING;
};




#endif // !NETWORKSTUDENT_H
