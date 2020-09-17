#include "roster.h"
#include <iostream>
#include <string>
#include <vector>

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL)
			classRosterArray[i]->print();
	}
}

void Roster::add(std::string id, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program) {
	int daysCombined[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == NULL) {
			if (program == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(id, firstName, lastName, email, age, daysCombined, program);
			}
			else if (program == SECURITY) {
				classRosterArray[i] = new SecurityStudent(id, firstName, lastName, email, age, daysCombined, program);
			}
			else {
				classRosterArray[i] = new NetworkStudent(id, firstName, lastName, email, age, daysCombined, program);
			}
			break;
		}
	}
}
void Roster::remove(std::string id) {
	bool removed=false; //holds true if the requested id has been removed already, false if hasn't yet
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL && classRosterArray[i]->GetId() == id) {
			classRosterArray[i] = NULL;
			removed = true;
			std::cout << id << " has been removed." << std::endl;
		}
	}
	if (removed == true)
		std::cout << "Student not found!" << std::endl;

}

void Roster::printInvalidEmails() {
	bool error;
	for (int i = 0; i < 5; i++) {
		error = false;
		Student* student = classRosterArray[i];
		std::string email = student->GetEmail();
		if (email.find("@") == std::string::npos) {
			error = true;
		}
		if (email.find(".") == std::string::npos) {
			error = true;
		}
		if (email.find(" ") != std::string::npos) {
			error = true;
		}
		if (error == true) {
			std::cout << "This is an invalid email: " << email << std::endl;
		}
	}


}

void Roster::printDaysInCourse(std::string id) {
	int i = 0;
	int total = 0; //The total results of the days in 3 courses
	double avg = 0.0;

	while (i < 5) {
		if ((classRosterArray[i] != NULL) && (id == classRosterArray[i]->GetId())) {
			int* daysToAvg = classRosterArray[i]->GetDays();
			
			for (int i = 0; i < 3; i++) {
				total = total + daysToAvg[i];
			}
			avg = static_cast<double>(total) / 3.0;
			std::cout << "The average of number of days in 3 courses for the student on row#" << i+1 << " is: " << avg << std::endl;
		}
		i++;
	}

}

void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; i++) {
		Student* student = classRosterArray[i];
		if (student->getDegreeProgram() == degreeProgram)
			student->print();
	}
}

Roster::~Roster(){ //No resources where requested dynamically, hence why the destructor is empty

}


int main() {
	std::cout << "Scripting and Programming - Applications C867, C++,  ID:000855626, Luis Ortiz" << std::endl;

	Roster* classRoster = new Roster();

	const std::string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Luis,Ortiz,lorti21@wgu.edu,22,60,50,50,SOFTWARE" 
	};

	for (int i = 0; i < 5; i++) {
		std::string temp;
		std::vector <std::string> data(9);
		temp = studentData[i];


		int j = 0;
		while (j < 9)
		{
			if (temp.find(',') > 0) {
				data.at(j) = temp.substr(0, temp.find(','));

			}
			if (temp.find(',') == std::string::npos) {
				data.at(j) = temp;
				//cout<<"ONLY ONCE"<<endl;
			}
			temp.replace(0, temp.find(',') + 1, "");
			j++;
			//cout << line << " SIZE:  " << line.size() << endl;
			//cout<<data[j]<<endl;
		}


		if (temp[temp.size() - 1] == 'E') { //Software
			(*classRoster).add(data.at(0), data.at(1), data.at(2), data.at(3), stoi(data.at(4)), stoi(data.at(5)), stoi(data.at(6)), stoi(data.at(7)), SOFTWARE);
		}
		else if (temp[temp.size() - 1] == 'Y') { //Security
			classRoster->add(data.at(0), data.at(1), data.at(2), data.at(3), stoi(data.at(4)), stoi(data.at(5)), stoi(data.at(6)), stoi(data.at(7)), SECURITY);
		}
		else { //Network
			classRoster->add(data.at(0), data.at(1), data.at(2), data.at(3), stoi(data.at(4)), stoi(data.at(5)), stoi(data.at(6)), stoi(data.at(7)), NETWORKING);
		}
	}
	
	classRoster->printAll();
	std::cout << std::endl;
	classRoster->printInvalidEmails();
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		classRoster->printDaysInCourse(classRoster->classRosterArray[i]->GetId());
	}
	std::cout << std::endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	std::cout << std::endl;
	classRoster->remove("A3");
	classRoster->remove("A3");
	delete classRoster; //deletes the dynamically allocated "classRoster"
	std::cout << std::endl << "Press \"Enter\" to exit. Thank you!" << std::endl; 
	std::cin.get(); 
}








