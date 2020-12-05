// team 3

#include <iostream>
#include <fstream> // files
#include <cstring> // string
#include <string>
using namespace std;

#define ADMIN hmmsly
#define PASS 5478

// define gender
enum  gender { F, M };

//user struct
typedef struct {
	string password; // keep password
	string userName; // keep user name 
	string firstName; // keep the name of customer
	string lastName;
	long passport; // keep passport number of customer
	gender gen; // keep the gender of customer
	int age; // keep the age of customer
	string email; // keep email address
	long phoneNumber; // keep phone number 
	bool agent = false;
}User;

void sign();
void sign_in();
void sign_up();
bool strongPassword(string);
void writeUserToFile(User);

int main() {
	sign(); // login to system
	return 1;
}

// login function
void sign() {
	// welcome
	system("CLS");
	printf("\t\t88888888888                                888  .d8888b.  888 d8b          888     \n");
	printf("\t\t    888                                    888 d88P  Y88b 888 Y8P          888     \n");
	printf("\t\t    888                                    888 888    888 888              888     \n");
	printf("\t\t    888  888d888 8888b.  888  888  .d88b.  888 888        888 888  .d8888b 888  888\n");
	printf("\t\t    888  888    .d888888 Y88  88P 88888888 888 888    888 888 888 888      888888K \n");
	printf("\t\t    888  888    888  888  Y8bd8P  Y8b.     888 Y88b  d88P 888 888 Y88b.    888 \"88b\n");
	printf("\t\t    888  888    \"Y888888   Y88P    \"Y8888  888  \"Y8888P\"  888 888  \"Y8888P 888  888\n\n\n\n");
	printf("\t\t\t\t\t Hello what would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Sign In\n\n");
	printf("\t\t\t\t\t2-   Sign Up\n\n");
	printf("\t\t\t\t\t3-   Exit\n\n");
	// start system
	int choose;
	cin>>choose;
	switch (choose)
	{
	case 1:
		sign_up();
		break;
	case 2:
		sign_in();
		break;
	case 3:
		printf("goodbye!! hope to see you soon:)\n");
		return;
		break;
	default:
		printf("bad input\n");
		break;
	}
}

// sign-in function
void sign_in() {
	string user, password;
	cout << "Enter user name" << endl;
	cin >> user;
	cout << "Enter password" << endl;
	cin >> password;
	// cheak info
}

// sign-up function
void sign_up() {
	bool check; // keep the return value from check password
	User use;
	cout << "Enter user name" << endl;
	cin >> use.userName;
	cout << "Enter password" << endl;
	cin >> use.password;
	cout << "Enter your first name" << endl;
	cin >> use.firstName;
	cout << "Enter your last name" << endl;
	cin >> use.lastName;
	cout << "Enter your passport" << endl;
	cin >> use.passport;
	cout << "Enter your age" << endl;
	cin >> use.age;
	int g;
	do {
		cout << "Enter gender: 1-male, 2-female" << endl;
		cin >> g;
		if (g == 1)
			use.gen = M;
		else if (g == 2)
			use.gen = F;
		else
			cout << "bad input";
	} while (g!=1 && g!=2);
	cout << "Enter your email" << endl;
	cin >> use.email;
	cout << "Enter your phone number" << endl;
	cin >> use.phoneNumber;
	writeUserToFile(use);
}


void writeUserToFile(User use) {
	
}


// function for aprove strong password
bool strongPassword(string pass)
{
	bool upper = false;
	bool lower = false;
	bool number = false;
	if (pass.length() >= 8)
		for (int i = 0; i < pass.length(); i++)
			if (pass[i] <= 'Z' && pass[i] >= 'A') // check if there is minimum one upper letter 
				upper = true;
			else if (pass[i] <= 'z' && pass[i] >= 'a') // check if there is minimum one lower letter 
				lower = true;
			else if (pass[i] <= '0' && pass[i] >= '9') //check if there is minimum one digit
				number = true;
	return upper && lower && number;
}
