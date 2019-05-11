#pragma once
#include "student.h"

Student::Student(string myStudentID, string myFirstName, string myLastName,
	string myEmailAddress, int myAge, int myDays1,
	int myDays2, int myDays3) 
{
	studentID = myStudentID;
	firstName = myFirstName;
	lastName = myLastName;
	emailAddress = myEmailAddress;
	age = myAge;
	daysToCompleteCourses[0] = myDays1;
	daysToCompleteCourses[1] = myDays2;
	daysToCompleteCourses[2] = myDays3;
	daysToComplete = daysToCompleteCourses;
}

Student::~Student() {

}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysToCompleteCourses() const {
	return daysToComplete;
}

void Student::SetStudentID(string myStudentID) {
	studentID = myStudentID;
	return;
}

void Student::SetFirstName(string myFirstName) {
	firstName = myFirstName;
	return;
}

void Student::SetLastName(string myLastName) {
	lastName = myLastName;
	return;
}

void Student::SetEmailAddress(string myEmailAddress) {
	emailAddress = myEmailAddress;
	return;
}

void Student::SetAge(int myAge) {
	age = myAge;
	return;
}

void Student::SetDaysToCompleteCourses(int myDays[3]) {
	for (int i = 0; i < 3; ++i)
		daysToCompleteCourses[i] = myDays[i];
}

void Student::Print() {
	
}

Degree Student::GetDegreeProgram() {
	return NETWORK;
}