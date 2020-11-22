/* Assignment: 2 Author: Team3 */

#define SP "team3" //secret password for create agent
#define _CRT_SECURE_NO_WARNINGS // for strcopy
#include "Agent.h" // MatchmakingAgency header
#include "menu.h" // menu header
#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;

// ctor
menu::menu() {
	printMenu(); // call print menu
}

// function to print menu options
void menu::printMenu() {
	int choice; // keep the choice of user
	do {
		cout << "Please choose one of the following options:" << endl <<
			"1.sing - in" << endl <<
			"2.sing - up " << endl <<
			"3.Quit the program" << endl;
		cin >> choice;
		switch (choice) // options for users
		{
		case 1:
			signIn(); // sign in page 
			break;
		case 2:
			signUp(); //  sign up page
			break;
		case 3:
			cout << "see you!!"; // exit
			break;
		default:
			cout << "bad input"; // the option is not include
			break;
		}
	} while (choice != 3); // until the user choice exit
}

void menu::signIn() {
	string user, password;
	cout << "Enter user name" << endl;
	cin >> user;
	cout << "Enter password" << endl;
	cin >> password;
	//check in file

}

void menu::signUp() {
	int choose; // keep the choose of the customer
	bool check; // keep the return value from check password
	do {
		cout << "enter 1-customer, 2-agent" << endl;
		cin >> choose;
		if (choose == 1) {
			// create customer
		}
		else if (choose == 2) {
			string password;
			string userName;
			cout << "Enter secret password for create agent" << endl;
			cin >> password;
			if (password == SP) {
				cout << "Enter user name" << endl;
				cin >> userName;
				do { // do while the password is strong
					cout << "Enter strong password {rules: include lower and upper case letters, number and at least 8 letters}" << endl;
					cin >> password;
					check = strongPassword(password);
				} while (check != true);
			}
			Agent ag = Agent(password, userName);
			// write to file
			ofstream outFile;
			outFile.open("agent.dat", ios::in | ios::app);
			outFile.write(reinterpret_cast<char*> (&ag), sizeof(Agent));
			outFile.close();
		}
	} while (choose != 1 && choose != 2);
}

// function for aprove strong password
bool menu::strongPassword(string pass)
{
	bool upper = false;
	bool lower = false;
	bool number = false;
	if (pass.length() >= 8)
		for (int i = 0; i < pass.length() ; i++)
			if (pass[i] <= 'Z' && pass[i] >= 'A') // check if there is minimum one upper letter 
				upper = true;
			else if (pass[i] <= 'z' && pass[i] >= 'a') // check if there is minimum one lower letter 
				lower = true;
			else if (pass[i] <= '0' && pass[i] >= '9') //check if there is minimum one digit
				number = true;
	return upper && lower && number;
}



