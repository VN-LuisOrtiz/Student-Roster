#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include "degree.h"


class Student { //This class represents a Student
public:
	Student(); //Empty Constructor
	Student(std::string studentId, std::string studentFirstName, std::string studentLastName, std::string studentEmail, int studentAge, int daysToComplete[3], Degree studentDegree);
	~Student();
	void	SetId(std::string studentId);							//Mutator
	void	SetFirstName(std::string studentFirstName);				//Mutator
	void	SetLastName(std::string studentLastName);				//Mutator
	void	SetEmail(std::string studentEmail);						//Mutator
	void	SetAge(int studentAge);									//Mutator
	void	SetDays(int daysToComplete[]);							//Mutator
	void	SetDegreeType(Degree studentDegree);					//Mutator

	std::string	GetId()				const;							//Accessor
	std::string GetFirstName()		const;							//Accessor
	std::string GetLastName()		const;							//Accessor
	std::string GetEmail()			const;							//Accessor
	int			GetAge()			const;							//Accessor
	int*		GetDays();											//Accessor

	virtual void print() =0;
	virtual Degree getDegreeProgram() = 0;


private:
	std::string id;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysToCompleteCourse[3];
	Degree degreeType;
};


#endif // !STUDENT_H




