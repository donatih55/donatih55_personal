#pragma once
#pragma warning
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
	public:
		//Student_Class() {};
		//~Student_Class() {};
    	static STUDENTDLL_API void setFirstName(const string) {}
		static STUDENTDLL_API string getFirstName() {}

		static STUDENTDLL_API void setLastName(const string) {}
		static STUDENTDLL_API string getLastName() {}
		
		static STUDENTDLL_API void setStudentID(const string) {}
		static STUDENTDLL_API string getStudentID() {}

		//static STUDENTDLL_API const char* getFirstName() = 0;

	};
}