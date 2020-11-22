/* Assignment: 2 Author: Team3 */


#define _CRT_SECURE_NO_WARNINGS // for strcopy
#include <iostream>
#include <cstring>
#include <string>
#include "customer.h" // client header


using namespace std;

//ctor
customer::customer(const string &name ,const string &id , gender gen, int age) {
	this->name = name; // get the name
	
	if (age < 18) // cheak if the age up to 18
		this->age = 18;
	else
	    this->age = age;
	this->gen = gen; // get the gender

}

// operator=
customer& customer::operator=(const customer& c) {
	if (this == &c) {
		return *this;
	}
	name= c.name; // take the name
	gen=c.gen; // take the gender
	return *this;
}

//operator ==
bool customer::operator==(const customer& c)const {
	if (c.gen != gen) { // ask for deffrent gender
		if ((c.age - age) <= 5 && ((-1)*(c.age - age)) <= 5) { // ask for minimum 5 years between
			int k;
			int len;
		}
		return false;
	}
	return false;
}


//cctor
customer::customer(const customer& c) {
	*this = c;
}

