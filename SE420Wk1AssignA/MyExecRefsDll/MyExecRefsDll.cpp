// MyExecRefsDll.cpp
/*
	This file contains tests for all the functions of the dll declared in the other project in this solution.
Each test case calls a different function of the dll and at runtime the request goes in this order: MyExecRefsDll.cpp > MathFuncsDll.h >
MathFuncsDll.cpp and return in same order foolowing FILO (first in, last out).
*/

//io stream is so I can use cout
#include <iostream>

// including the dll
#include "MathFuncsDll.h"

//standard namespace so we can use cout without std::
using namespace std;

//beggining of main statement
int main()
{
	// creation of variables to use the test cases bellow it
	double a = 7.4;
	int b = 99;
	// testing the add function
	cout << "a + b = " <<
		MathFuncs::MyMathFuncs::Add(a, b) << endl;
	// testing the subtract function
	cout << "a - b = " <<
		MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
	// testing the multiply function
	cout << "a * b = " <<
		MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
	// testing the divide function
	cout << "a / b = " <<
		MathFuncs::MyMathFuncs::Divide(a, b) << endl;
	// test division by zero
	try
	{
		//divison by zero
		cout << "a / 0 = " <<
			MathFuncs::MyMathFuncs::Divide(a, 0) << endl;
	}
	catch (const invalid_argument &e)
	{
		//should say the exception is divison by zero
		cout << "Caught exception: " << e.what() << endl;
	}
	// end of main statement requires a int
	return 0;
}