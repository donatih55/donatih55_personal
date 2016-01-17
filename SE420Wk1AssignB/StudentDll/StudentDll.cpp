// StudentDll.cpp : Defines the exported functions for the DLL application.
//
// import of necessary header for visual studio
#include "stdafx.h"
// including of header this file is implementing
#include "StudentDll.h"
// include string so we can deal with them through the program
#include<string>

//using this namespace so we dont have to std:: every string
using namespace std;

//namespace student where the class is defined
namespace Student {
	// contructor implementation, it sets up the default values
	Student_Class::Student_Class() {
		// sets up default firstname to my name
		setFirstName((string)"Henrique");
		// sets up default last name to my last name
		setLastName((string)"Donati");
		// sets up default ID for a ID
		setStudentID((string)"55555555");
	}
	// class destructor
	Student_Class::~Student_Class() {}
	// setter for first name
	void Student_Class::setFirstName(string firstNameM) {
		// turns the objects' fistname into the name passed by the setter
		this->firstName = firstNameM;
	}

	// getter for firstName
	string Student_Class::getFirstName() {
		// returns the class firstName variable
		return this->firstName;
	}
	// setter for lastName variable
	void Student_Class::setLastName(string lastNameM)
	{
		// turns the object's variable firstname into the one passed by the method
		this->lastName = lastNameM;
	}
	//getter fpor the variable lastName
	string Student_Class::getLastName() {
		// return's object's lastName variable
		return this->lastName;
	}
	//setter for student ID variable
	void Student_Class::setStudentID(string StudentIDM) {
		// sets the object's studentID variable into the one passed by the method
		this->studentID = StudentIDM;
	}
	//getter for studentID variable
	string Student_Class::getStudentID() {
		// returns studentID variable from object
		return this->studentID;
	}
}