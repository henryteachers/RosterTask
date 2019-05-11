#pragma once
#include "student.h"

class SoftwareStudent : public Student {

public: //public functions

	//constructor
	SoftwareStudent(string myStudentID, string myFirstName, string myLastName,
		string myEmailAddress, int myAge, int myDays1, int myDays2, int myDays3, Degree myDegree);

	//print function
	void Print();

	//getdegree function
	Degree GetDegreeProgram();

private:
	Degree degree;
};
