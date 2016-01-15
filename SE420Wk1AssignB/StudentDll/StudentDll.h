#pragma once
#include<string>
#ifdef STUDENTDLL_EXPORTS
#define STUDENTDLL_API __declspec(dllexport) 
#else
#define STUDENTDLL_API __declspec(dllimport) 
#endif

namespace	Student
{

	class Student
	{
	public:
		Student() {};
		~Student() {};
		virtual void setFirstName(const string firstName) = 0;
		virtual const string getFirstName() = 0;

		virtual void setLastName(const string lastName) = 0;
		virtual const string getLastName() = 0;

		virtual void setStudentID(const string StudentID) = 0;
		virtual const string getStudentID() = 0;

		//static STUDENTDLL_API const char* getFirstName() = 0;

	};
}