// StudentDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "stdafx.h"
#include "StudentDll.h"
#include<string>

using namespace std;

namespace Student{

			Student_Class::Student_Class(){
				setFirstName((string)"Henrique");
				setLastName((string)"Donati");
				setStudentID((string)"55555555");
			}
			Student_Class::~Student_Class() {}

			void Student_Class::setFirstName(string firstNameM) {
				this->firstName = firstNameM;
			}
			string Student_Class::getFirstName() {
				return this->firstName;
			}

			void Student_Class::setLastName(string lastNameM)
			{
				this->lastName = lastNameM;
			}
			string Student_Class::getLastName() {
				return this->lastName;
			}

			void Student_Class::setStudentID(string StudentIDM) {
				this->studentID = StudentIDM;
			}
			string Student_Class::getStudentID() {
				return this->studentID;
			}
}