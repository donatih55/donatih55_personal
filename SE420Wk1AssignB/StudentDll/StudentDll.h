//so it is only compiled once
#pragma once

#include<string>
#ifdef STUDENTDLL_EXPORTS
#define STUDENTDLL_API __declspec(dllexport) 
#else
#define STUDENTDLL_API __declspec(dllimport) 
#endif

namespace	Student
{

	class Student_Class
	{
	private:
		std::string firstName;
		std::string lastName;
		std::string studentID;

	public:
		STUDENTDLL_API Student_Class();
		STUDENTDLL_API ~Student_Class();
		STUDENTDLL_API void setFirstName(std::string);
		 STUDENTDLL_API std::string getFirstName();

		STUDENTDLL_API void setLastName(std::string);
		STUDENTDLL_API std::string getLastName();
		
		 STUDENTDLL_API void setStudentID(std::string);
		 STUDENTDLL_API std::string getStudentID();

		//static STUDENTDLL_API const char* getFirstName() = 0;

	};
}