/* Assignment: 2 Author: Team3 */

#ifndef CLIENT_H // if not define
#define CLIENT_H
#include <iostream>
#include <cstring>

using namespace std;

// define gender
enum  gender { F, M };

// class client
class customer {

private:
	string password; 
	string userName;
	string name; // keep the name of client
	long passport; // keep the ID of client
	gender gen; // keep the gender of client
	int age; // keep the age of client
	string email; // array that keep the hobbys of client
	long phoneNumber; // keep the number of the client's hobbys

public:
	customer(const string &name,const string &id, gender gen, int age); //ctor
	virtual bool operator==(const customer& c)const; // operator ==
	customer& operator=(const customer& c); // operator =
	string getName()const { return name; }; // inline function to get the name
	gender getGen()const { return gen; }; // inline function to get the gender
	int getAge()const { return age; }; // inline function to get the age
	customer(const customer& c); //cctor
};

#endif
