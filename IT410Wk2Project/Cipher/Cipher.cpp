/*Week 2: Week 2 - Weekly Project


Deliverable

Write a program(in a programming language of your choice) to complete the tasks and submit your source file(s), along with a short description how to use the program, to the Dropbox.

Tasks

Open file plaintext_in.txt and display its content on the screen.
Ask a user to enter a number and encrypt text file plaintext_in.txt using a simple substitution cipher(shift by n).
Display the result of encryption(ciphertext) on the screen.
Save results of encryption(ciphertext) to a file ciphertext_out.txt.
Delete file plaintext_in.txt or wipe its content.
Open file ciphertext_in.txt and display its content on the screen.
Ask user to enter a number and decrypt text file ciphertext_in.txt using a simple substitution cipher(shift by n).
Display the result of decryption(plaintext) on the screen.
Save results of decryption(plaintext) to a file plaintext_out.txt.
Submit relevant source file(s) to the Dropbox.
Sample input plaintext file

Alice
Bill the Lizard
Pat
The Caterpillar
The Cheshire Cat
The Dodo
The Dormouse
The Duchess
The Duck
The Eaglet
The Gryphon
The Hatter
The King of Hearts
The Knave of Hearts
The Lory
The March Hare
The Mock Turtle
The Mouse
The Puppy
The Queen of Hearts
The White Rabbit
Sample input ciphertext file

Gurer jnf n gnoyr frg bhg haqre n gerr va sebag bs gur ubhfr, naq gur Znepu Uner naq gur Unggre jrer univat grn ng vg.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

char Shift(char c, int shift);
string Encrypt(string p, int shift);
string Decrypt(string c, int shift);
int main() {

	/*______________________________________________________
	
	Ecnryption
	
	_________________________________________________________*/
	ifstream plainText("plaintext_in.txt");
    ofstream cipherText("ciphertext_out.txt");

	int shift = 0;	
	string input;
	string output;
    getline(plainText, input);
	plainText.close();
	cipherText << output << endl;
	cipherText.close();

	ofstream plainTextC("plaintext_in.txt", ios::trunc);
	plainTextC << "No NO NO Noooo!";
	plainTextC.close();
	
	
	cout << "Your PlainText is:" << endl << input << endl;
	cout << "Please input you shift:" << endl;
	cin >> shift;
	output = Encrypt(input, shift);
	cipherText << output << endl;
	cipherText.close();
	cout << "your encrypted string is" << endl << output << endl;

	/*____________________________________________________________________________________

	Part 2 - Decryption

	____________________________________________________________________________________
	*/

	bool flag = false;
	string flagAnswer;
	ifstream cipherText2("ciphertext_in.txt");
	ofstream plainText2("plaintext_out.txt");
	getline(cipherText2, input);
	cipherText2.close();

	cout << "Your cipherText is:" << endl << input << endl;
	do {
		cout << "Please input you shift:" << endl;
		cin >> shift;
		output = Decrypt(input, shift);
		cout << "The decrypted code is:" << endl << Decrypt(input, shift) << endl;
		cout << "Is this the desired result? (y / n)" << endl;
		cin >> flagAnswer;
		flag = (flagAnswer.find('y') ? true : false);

	} while (flag);
	plainText2 << output << endl;
	plainText2.close();


	return 0;
}
string Encrypt(string p, int shift) {
	string input = p;
	for (int i = 0; i < input.size(); i++) {
		input[i] = Shift(input[i], shift);
	}
	return input;
}
string Decrypt(string c, int shift) {
	string input = c;
	for (int i = 0; i < input.size(); i++) {
		//note it is negative
		input[i] = Shift(input[i], 0 - shift);
	}
	return input;
}
char Shift(char c, int shift) {
	bool valUpChar = false;
	bool valLoChar = false;
	if (c <= 90 && c >= 65) {
		//AKA isCaps
		valUpChar = true;
		c = 65 + ((c + shift - 65) % 26);
	}
	else if (c >= 97 && c <= 122) {
		//AKA isLow
		valLoChar = true;
		c = 97 + ((c + shift - 97) % 26);
	}
	else {
		//AKA invalid Char
		c = c;
	}

	// make sure c doesnt go over char boundries like @ or ^
	if (c < 65 && valUpChar) {
		c = 91 - (65 - c);
	}
	else if (c < 97 && valLoChar) {
		c = 123 - (97 - c);
	}
	return c;
}

