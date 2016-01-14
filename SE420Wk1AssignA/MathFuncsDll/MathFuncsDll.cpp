/* MathFuncsDll.cpp : Defines the exported functions for the DLL application. 

	It defines the function in mathfuncsDll.h and gives them an actual return value (implementation), so Add for instance would return the sum of 
both items passed. 
	All the code written bellow will only be accessed during runtime when the function is needed, so the main
function will call the desired function under MathFuncsDll.h, which will then be link to the MathFuncsDll.cpp version of it.

*/

//imports stdafx.h bacause it is needed by visual studio, mathfuncsDll.h because that is the class being 
//implemented and stdexcept for the exception thrown in division by zero
#include "stdafx.h"
#include "MathFuncsDll.h"
#include <stdexcept>

// namespace std is necessary to use simple math operations
using namespace std;

//matching namespace for the implementation of the class
namespace MathFuncs
{
	// returns the sum of the two double numbers passed
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}
	// returns the subtraction of the two double numbers passed
	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}
	// returns the multiple of the two double numbers passed
	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}
	// returns the division of the two double numbers passed
	double MyMathFuncs::Divide(double a, double b)
	{
		//if divison by zero, throw a exception
		if (b == 0)
		{
			//throws the exception
			throw invalid_argument("divison by zero!");
		}
		return a / b;
	}
}
