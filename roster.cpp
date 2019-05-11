#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "roster.h"
#include <sstream>
using namespace std;


//constructor
Roster::Roster() {
	for (int i = 0; i < 5; ++i)
		classRosterArray[i] = nullptr;
}

Roster::~Roster() {

	for (int i = 0; i < 5; ++i)
		if (classRosterArray[i] != nullptr)
			delete classRosterArray[i];

}

void Roster::add(int i, string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, Degree degree) {	
	if (degree == SECURITY)
		classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	else if (degree == NETWORK)
		classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	else if (degree == SOFTWARE)
		classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < 5; ++i)
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->GetStudentID() == studentID)
			{
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
	if (!found)
		cout << "Student " << studentID << " not found." << endl << endl;
}

void Roster::printAll() {
	for (int i = 0; i < 5; ++i)
		if (classRosterArray[i] != nullptr)
			classRosterArray[i]->Print();
	cout << endl << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int* myPointer = nullptr;
	int average;
	for (int i = 0; i < 5; ++i)
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->GetStudentID() == studentID)
			{
				myPointer = classRosterArray[i]->GetDaysToCompleteCourses();
			}
		}
	average = (myPointer[0] + myPointer[1] + myPointer[2]) / 3;
	cout << "The average days in the course for student " << studentID << " is " << average << endl << endl;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i)
	{
		int space = -1, atSign = -1, dot = -1;
		if (classRosterArray[i] != nullptr) {
			string temp = classRosterArray[i]->GetEmailAddress();
			space = temp.find(" ");
			atSign = temp.find("@");
			dot = temp.find(".");
			if (space != -1 || atSign == -1 || dot == -1)
				cout << "Invalid Email Address: " << temp << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; ++i)
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
				classRosterArray[i]->Print();
		}
	cout << endl;
}


int main() {
	//course title, programming language, student id and name
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Progamming Language: C++" << endl;
	cout << "Student ID: 001130918" << endl;
	cout << "Student Name: Greg Henry" << endl << endl;

	//student data
	const string studentData[] =
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Greg,Henry,ghenr14@my.wgu.edu,41,35,40,45,SOFTWARE"};

	//create instance of Roster class
	Roster classRoster;

	//parse the studentData and add to classRoster
	string txt[9];
	int num[4];
	for (int i = 0; i < 5; ++i) {

		//parse the studentData
		istringstream ss(studentData[i]);
		string item;
		int j = 0;
		while (getline(ss, item, ',')) {
			txt[j] = item;
			if (j > 3 && j < 8) {
				stringstream convert(txt[j]);
				convert >> num[j - 4];
			}
			++j;
		}

		//add each student to roster
		if (txt[8] == "NETWORK")
			classRoster.add(i, txt[0], txt[1], txt[2], txt[3], num[0], num[1], num[2], num[3], NETWORK);
		else if (txt[8] == "SOFTWARE")
			classRoster.add(i, txt[0], txt[1], txt[2], txt[3], num[0], num[1], num[2], num[3], SOFTWARE);
		else if (txt[8] == "SECURITY")
			classRoster.add(i, txt[0], txt[1], txt[2], txt[3], num[0], num[1], num[2], num[3], SECURITY);
	}

	//required function calls
	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printAverageDaysInCourse("A5");
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	system("pause");
	return 0;
	classRoster.~Roster();
}
