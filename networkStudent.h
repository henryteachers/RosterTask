#pragma once
#include "student.h"

class NetworkStudent : public Student {

public: //public functions

	//constructor
	NetworkStudent(string myStudentID, string myFirstName, string myLastName,
		string myEmailAddress, int myAge, int myDays1, int myDays2, int myDays3, Degree degree);

	//print function
	void Print();

	//getdegree function
	Degree GetDegreeProgram();

private:
	Degree degree;
};