#include "securityStudent.h"

SecurityStudent::SecurityStudent(string myStudentID, string myFirstName, string myLastName,
	string myEmailAddress, int myAge, int myDays1, int myDays2, int myDays3, Degree myDegree)
	: Student(myStudentID, myFirstName, myLastName,
		myEmailAddress, myAge, myDays1, myDays2, myDays3) {
	degree = myDegree;
}

void SecurityStudent::Print() {
	cout << "ID: " << GetStudentID() << "\t";
	cout << "First: " << GetFirstName() << "\t";
	cout << "Last: " << GetLastName() << "\t";
	cout << "Email: " << GetEmailAddress() << "\t";
	cout << "Age: " << GetAge() << " \t";
	cout << "Days to Complete Courses: ";
	int* temp = GetDaysToCompleteCourses();
	for (int i = 0; i < 3; ++i)
		cout << temp[i] << " ";
	cout << "\tDegree: " << "SECURITY" << endl;
	return;
}

Degree SecurityStudent::GetDegreeProgram() {
	return SECURITY;
}