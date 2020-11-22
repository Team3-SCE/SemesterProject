/* Assignment: 2 Author: Team3 */

#ifndef MENU_H // if not define
#define MENU_H

#include "Agent.h" // Agent header
#include <iostream>

//class menu
class menu
{
	void signIn(); // sign in page
	void signUp(); // sign up options
	void printMenu(); // print nemu of sign in\out
	bool strongPassword(string); // check if the password is strong
public:
	menu(); //ctor
};

#endif

