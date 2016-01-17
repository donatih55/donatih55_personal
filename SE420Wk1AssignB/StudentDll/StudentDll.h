//so it is only compiled once
#pragma once
//includes string so we can do some string variables and functions with it
#include<string>

//macro for dll if studentdll had been exported
#ifdef STUDENTDLL_EXPORTS
//set declspecs as dllexport
#define STUDENTDLL_API __declspec(dllexport) 
//if studentdll nad not been exported, but imported
#else
//set declspecs as dllimport
#define STUDENTDLL_API __declspec(dllimport) 
//end of macro
#endif

//declaring the namespace student
namespace	Student
{
	//declaring the Student_Class
	class Student_Class
	{

	//private variables declaration
	private:
		// this is the string for the first name
		std::string firstName;
		//this is the string for the last name
		std::string lastName;
		//this is the string for the student ID
		std::string studentID;

	//public methods declaration
	public:
		//contructor that sets default values
		STUDENTDLL_API Student_Class();
		//desctructor
		STUDENTDLL_API ~Student_Class();
		// setter for the first name variable
		STUDENTDLL_API void setFirstName(std::string);
		// getter for the first name variable
		STUDENTDLL_API std::string getFirstName();
		// setter for the last name variable
		STUDENTDLL_API void setLastName(std::string);
		// getter for the last name variable
		STUDENTDLL_API std::string getLastName();
		//setter for student ID
		STUDENTDLL_API void setStudentID(std::string);
		//getter for student ID 
		STUDENTDLL_API std::string getStudentID();
	};
}