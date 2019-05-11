#pragma once
using namespace std;

class Roster {

	public: //public functions

		//constructor
		Roster();
		~Roster();

		//functions
		void add(int i, string studentID, string firstName, string lastName,
			string emailAddress, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, Degree degree);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(int degreeProgram);

	private: //private data members
		Student* classRosterArray[5];
};