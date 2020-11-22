/* Assignment: 2 Author: Team 3 */

#define _CRT_SECURE_NO_WARNINGS // for strcopy
#include "String.h" // string header
#include <iostream>
#include <cstring>

using namespace std;

// default ctor
String::String() {
	str = NULL; // null for deafult
}

//ctor - get array of chars and set to data
String::String(const char* arr){
	str = new char[strlen(arr)+1]; // ask for place 
	if (!str) { // if its fail
		cout << "no memory" << endl;
		return;
	}
	strcpy(str, arr); // copy the string to data
}

//cctor - get string and set to data
String::String(const String& s){
	operator=(s); // call operator =
}

// operator ==
bool String::operator==(const String& s) const {
	if (strcomper(s)) // if the strings are equal
		return true;
	return false; // not equal
}

// function that return true if the strings are equal
bool String::strcomper(const String& s)const {
	if (s.str && str) {
		if (strlen(s.str) != strlen(this->str)) // if the length is diffrent return false
			return false;
		int i = 0; // help for the loop
		while (s.str[i] != '\0') // until the end
		{
			if (s.str[i] != this->str[i]) // if samething is diffrent =false
				return false;
			++i; // promotion
		}
		if (str[i] != '\0')
			return false;
		return true; // if i am here = true
	}
	else if (s.str == NULL && str == NULL)
		return true;
	return false;
}

// operator =
String& String::operator=(const String& s) {
	if (operator==(s)) { // if they are equal return this
		return *this;
	}
	delete[] str; // free this
	str = new char[strlen(s.str)+1]; // ask for place
	if (!str) { // if uts fail
		cout << "no memory" << endl;
		exit(1);
	}
	strcpy(str, s.str); // copy the string to this
	return *this;
}

// dtor
String::~String() {
	if (this->str != NULL) { // dont do nothing if it null
		delete[] this->str;
	    this->str = NULL; // defalte value
	}
}

