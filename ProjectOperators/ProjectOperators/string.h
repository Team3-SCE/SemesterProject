/* Assignment: 3 Author: Hadar Amsalem,
ID: 316129212  */

#define _CRT_SECURE_NO_WARNINGS // for strcopy
#ifndef STRING_H // if not define
#define STRING_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
// class string

class String {

private:
	char *str; // keep the string

public:
	String();//defult ctor
	String(const char * arr); //ctor
	String(const String& s); //cctor
	bool operator==(const String& s)const; // operator ==
	String& operator=(const String& s); //operator=
	void printStr()const { cout << str<<endl; }; //print string
	bool strcomper(const String& s)const; //comper between strings
	~String(); //dtor
};


#endif
