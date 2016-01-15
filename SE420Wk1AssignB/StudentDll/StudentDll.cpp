// StudentDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include<string>
#include "stdafx.h"
#include "StudentDll.h"
#include <stdexcept>

using namespace std;

namespace Student{

	class  Student_ClassA : public Student_Class{

		private:
			string firstName;
			string lastName;
			string studentID;

		public:

			Student_ClassA(){
				setFirstName((string)"Henrique");
				setLastName((string)"Donati");
				setStudentID((string)"55555555");
			}
			~Student_ClassA() {}

			virtual void setFirstName(const string firstNameM) {
				firstName = firstNameM;
			}
			virtual const string getFirstName() {
				return firstName;
			}

			virtual void setLastName(const string lastNameM)
			{
				lastName = lastNameM;
			}
			virtual const string getLastName() {
				return lastName;
			}

			virtual void setStudentID(const string StudentIDM) {
				studentID = StudentIDM;
			}
			virtual const char* getStudentID() {

			}
	};
}