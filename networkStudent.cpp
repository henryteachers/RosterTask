#include "networkStudent.h"

NetworkStudent::NetworkStudent(string myStudentID, string myFirstName, string myLastName,
	string myEmailAddress, int myAge, int myDays1, int myDays2, int myDays3, Degree myDegree)
	: Student(myStudentID, myFirstName, myLastName,
		myEmailAddress, myAge, myDays1, myDays2, myDays3) {
	degree = myDegree;
}

void NetworkStudent::Print() {
	cout << "ID: " << GetStudentID() << "\t";
	cout << "First: " << GetFirstName() << "\t";
	cout << "Last: " << GetLastName() << "\t";
	cout << "Email: " << GetEmailAddress() << "\t";
	cout << "Age: " << GetAge() << " \t";
	cout << "Days to Complete Courses: ";
	int* temp = GetDaysToCompleteCourses();
	for (int i = 0; i < 3; ++i)
		cout << temp[i] << " ";
	cout << "\tDegree: " << "NETWORK" << endl;
	return;
}

Degree NetworkStudent::GetDegreeProgram() {
	return NETWORK;
}