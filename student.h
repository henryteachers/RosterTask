#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {

	public: //public functions

		//constructor
		Student(string myStudentID, string myFirstName, string myLastName,
			string myEmailAddress, int myAge, int myDays1,
			int myDays2, int myDays3);

		//destructor
		~Student();
			
		//accessor functions
		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int GetAge() const;
		int* GetDaysToCompleteCourses() const;

		//mutator functions
		void SetStudentID(string myStudentID);
		void SetFirstName(string myFirstName);
		void SetLastName(string myLastName);
		void SetEmailAddress(string myEmailAddress);
		void SetAge(int myAge);
		void SetDaysToCompleteCourses(int myDays[3]);

		//print function
		virtual void Print();

		//getdegree function
		virtual Degree GetDegreeProgram();
		
	private: //private data members
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysToCompleteCourses[3];
		int* daysToComplete;
};