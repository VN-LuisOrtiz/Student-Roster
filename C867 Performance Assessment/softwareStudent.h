#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student { //Software Student class that inherits from Student Class.
public:
	Student::Student;
	Degree getDegreeProgram();
	void print();
private:
	Degree degree = SOFTWARE;
};


#endif // !SOFTWARESTUDENT_H
