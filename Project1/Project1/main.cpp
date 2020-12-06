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
	string passport; // keep passport number of customer
	string email; // keep email address
	string phoneNumber; // keep phone number 
	gender gen; // keep the gender of customer
	int age; // keep the age of customer
	bool agent ;
}User;

bool sign_menu();
void sign_in();
void sign_up();
bool strongPassword(string);
void writeUserToFile(User);
bool ExistingUser(string);
bool userCorrecrPass(string, string);
bool passportCheck(string);

int main() {
	while (sign_menu()) { system("CLS"); } //Opening sign in menu until it returns false (clears screan in between)
	return 1;
}

// login function
bool sign_menu() {
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
		system("CLS");
		sign_in();
		return true;
		break;
	case 2:
		system("CLS");
		sign_up();
		return true;
		break;
	case 3:
		system("CLS");
		printf("\n\n\n\n\n\n\t\t\t\t\goodbye!! hope to see you soon:)\n");
		return false;
		break;
	default:
		printf("bad input\n");
		break;
	}
}

// sign-in function
void sign_in() {
	string user, password;
	do {
		cout << "\n\n\n\t\t\tEnter user name\n" << endl;
		cin >> user;
		cout << "\n\n\t\t\tEnter password\n" << endl;
		cin >> password;
	} while (!userCorrecrPass(user, password));
	// cheak info
}

//// old sign-up function
//void sign_up() {
//	bool check; // keep the return value from check password
//	User use;
//	do {
//		cout << "\n\n\n\t\t\tEnter user name\n\t\t\t    ";
//		cin >>use.userName;
//		if (ExistingUser(use.userName))
//			cout << "\n\n\n\tThis user already exist.\a";
//	} while (ExistingUser(use.userName));
//	do {
//		cout << "\n\n\t\t\tEnter password\n\t\t\t    ";
//		cin >> use.password;
//		if (!strongPassword(use.password))
//			cout << "\n\n\nThis password is not strong enough (Need to include an upper,lower and numiric character and 8 or more charecters).\a\n";
//	} while (!strongPassword(use.password));
//	cout << "\n\n\t\tEnter your first name\n\t\t\t    ";
//	cin >> use.firstName;
//	cout << "\n\n\t\t\tEnter your last name\n\t\t\t    ";
//	cin >> use.lastName;
//	cout << "\n\n\t\t\tEnter your passport\n\t\t\t    ";
//	cin >> use.passport;
//	cout << "\n\n\t\t\tEnter your age\n\t\t\t    ";
//	cin >> use.age;
//	int g;
//	do {
//		cout << "\n\n\t\t\tEnter gender: 1-male, 2-female\n\t\t\t    ";
//		cin >> g;
//		if (g == 1)
//			use.gen = M;
//		else if (g == 2)
//			use.gen = F;
//		else
//			cout << "\n\n\t\t\tbad input\t\t\t";
//	} while (g!=1 && g!=2);
//	cout << "\n\n\t\t\tEnter your email\n\t\t\t    ";
//	cin >> use.email;
//	cout << "\n\n\t\t\tEnter your phone number\n\t\t\t    ";
//	cin >> use.phoneNumber;
//	use.agent = false;
//	writeUserToFile(use);
//
//}


bool ExistingUser(string username)
{
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt");

	if (DB_accounts.fail())
	{
		cerr << "\n\n\n \t\t\tERROR: The file couldn't be opened.\a" << endl;
	}

	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber,seperator;

	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber>> seperator;
	while (!DB_accounts.eof())
	while (!DB_accounts.eof())
	{
		if (UserName == username)
			return true;
		DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
	}
	DB_accounts.close();
	return false;
}

//void writeUserToFile(User use) old
//{
//	fstream DB_accounts;
//	DB_accounts.open("DB_accounts.txt", ios::app);
//	if (use.agent)
//	{
//		DB_accounts << use.userName << " " << use.password << " " << "Agent" << endl;
//	}
//	else
//		DB_accounts << use.userName << " " << use.password << " " << "Customer" << endl;
//	DB_accounts.close();
//}

void writeUserToFile(User use)//entering data from struct to txt file
{

	fstream DB_accounts;
	DB_accounts.open("DB_accounts.txt", ios::app);

	DB_accounts << (use.agent ? "Agent: ":"Customer: ") << use.firstName << " " << use.lastName << " " << use.userName << " " << use.password << " " << use.passport << " " << (use.gen ? "M" : "F") << " " << use.age << " " << use.email << " " << use.phoneNumber << endl;
	DB_accounts << "~~==============================================================================~~" << endl;

	DB_accounts.close();
}

bool userCorrecrPass(string username, string password)
{
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt");

	if (DB_accounts.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber,seperator;

	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber>> seperator;
	while (!DB_accounts.eof())
	{
		if (UserName == username)
			if (PW == password)
				return true;
			else
			{
				cerr << "\n\n\n\t\t\tThis password is incorrect.\a\n\n\t\t\t";
				return false;
			}
		
		DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber>> seperator;
	}
	cerr << "\n\n\n \t\t\tThis account dosen't exist.\a\n\n\t\t\t";
	DB_accounts.close();
	return false;
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
			else if (pass[i] <= '9' && pass[i] >= '0') //check if there is minimum one digit
				number = true;
	return upper && lower && number;
}

void sign_up() {//new sign up
	bool check; // keep the return value from check password
	User use;
	do {
		//must enter a new username to continue
		cout << "\n\n\n\t\t\tEnter user name\n\t\t\t    ";
		cin >> use.userName;
		if (ExistingUser(use.userName))
			cout << "\n\n\n\tThis user already exist.\a";
	} while (ExistingUser(use.userName));
	do {
		//must enter a valid password
		cout << "\n\n\t\t\tEnter password\n\t\t\t    ";
		cin >> use.password;
		if (!strongPassword(use.password))
			cout << "\n\n\nThis password is not strong enough (Need to include an upper,lower and numiric character and 8 or more charecters).\a\n";
	} while (!strongPassword(use.password));
	cout << "\n\n\t\tEnter your first name\n\t\t\t    ";
	cin >> use.firstName;
	cout << "\n\n\t\t\tEnter your last name\n\t\t\t    ";
	cin >> use.lastName;
	do {
		//must enter 9 characters for valid passport
		cout << "\n\n\t\t\tEnter your passport\n\t\t\t    ";
		cin >> use.passport;
		if (passportCheck(use.passport))
			cout << "\n\n\n\tThis passport in not valid, Please enter passport with minimum 9 charecters.\a";
	} while (passportCheck(use.passport));//passport check
	cout << "\n\n\t\t\tEnter your age\n\t\t\t    ";
	cin >> use.age;
	int g;
	do {
		cout << "\n\n\t\t\tEnter gender: 1-male, 2-female\n\t\t\t    ";
		cin >> g;
		if (g == 1)
			use.gen = M;
		else if (g == 2)
			use.gen = F;
		else
			cout << "\n\n\t\t\tbad input\t\t\t";
	} while (g != 1 && g != 2);
	cout << "\n\n\t\t\tEnter your email\n\t\t\t    ";
	cin >> use.email;
	cout << "\n\n\t\t\tEnter your phone number\n\t\t\t    ";
	cin >> use.phoneNumber;
	use.agent = false;
	writeUserToFile(use);

}

bool passportCheck(string passport) {
	if (passport.length() >= 8)
	{
		return true;
	}
	return false;
}