// include Virtual Studio Header
#include "stdafx.h"
// include the dll
#include "StudentDll.h"
//include io stream for the output
#include <iostream>

//use namespace std so we can use the standard operations
using namespace std;

// beggining of main method
int main()
{
	//creation of object Student_Class being assigned to pointer "me"
	Student::Student_Class* me = new Student::Student_Class();

	// outputs all the variables stored in me
	cout << "Hello! I'm " << me->getFirstName() << " " << me->getLastName() << " and my id is "
		<< me->getStudentID() << endl;

	// changes all the variables' values
	me->setFirstName("notHenique"); me->setLastName("notDonati"); me->setStudentID("notMyID");

	// outputs all the new valued variables stored in me
	cout << "But now I'm " << me->getFirstName() << " " << me->getLastName() << " and my id is "
		<< me->getStudentID() << endl;

	// deletes the object me just created above
	delete me;

	// ends the main function by returning 0
	return 0;
}