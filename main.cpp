// team 3
#define _CRT_SECURE_NO_WARNINGS

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      ///* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White 
Note: If you don't use RESET the color will remain changed until the next time you use a color code.*/

#include <iostream>
#include <fstream> // files
#include <cstring> // string
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;


#define ADMIN_USER "admin"
#define ADMIN_PASS "0000"

// define gender
enum  gender { F, M };

enum  login_type { admin_login, agent_login, customer_login, no_login };

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
	bool agent;
	bool admin;
}User;

bool sign_menu();
login_type sign_in(User*);
void sign_up();
void vacation_search();
bool strongPassword(string);
void writeUserToFile(User);
bool ExistingUser(string);
bool userCorrecrPass(string, string, User*);
bool passportCheck(string);
login_type check_usertype(string);
int Admin_Menu(User active_user);
int Agent_Menu(User active_user);
int Customer_Menu(User active_user);
void PrintDeleteUsersMassages();
void ContactWithAgent(User);
void print_active_user_message(User);
void PrintUsersToAdmin();
void Add_Agent();
void Add_Or_Delete_Packages();
void print_packages();
void Add_Packages();
void Delete_Packages();
bool Is_Serial_Num_Avilable(string number);
void Add_Message(User active_user);
void clearbuffer();
void Main_Menu();


int main() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
	for (int i = 0; i < 3; i++) {

		std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << std::flush;
		Sleep(100);
		std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
		Sleep(100);
	}
	while (sign_menu()) { system("CLS"); } //Opening sign in menu until it returns false (clears screan in between)
	return 1;
}

// login function
bool sign_menu() {

	User active_user;
	int choose;
	active_user.firstName = active_user.lastName = "";

	// welcome
	system("CLS");
	print_active_user_message(active_user);
	Main_Menu();
	// start system
	cin >> choose;
	bool flag = true;

	switch (choose)
	{
	case 1://Sign in
		flag = true;
		system("CLS");
		switch (sign_in(&active_user)) //Opening the Sign_in menu and gives what kind of user is being used. 
		{
		case admin_login:
			do
			{
				//switch case for admin with do while

				switch (Admin_Menu(active_user)) {
				case 1:
					switch (Agent_Menu(active_user))
					{
					case 1:
						//lead list- all the customers in DB 
						break;
					case 2:
						//add and delete packages from DB
						Add_Or_Delete_Packages();
						break;
					case 3:
						//reply to customers
						PrintDeleteUsersMassages();
						system("pause");
						break;
					case 4:
						//confirm orders for customers
						break;
					case 5:
						flag = false;
						break;
					default:
						cout << "invalid choice" << endl;
						break;
					}
					break;
				case 2:
					Add_Agent();
					break;
				case 3:
					flag = false;
					break;
				default:
					cout << "invalid choice" << endl;
					break;
				}

			} while (flag);
			//Here will be a switch case with the functions of the admin menu
			break;
		case agent_login:
			//swich case for agent menu with do while
			do
			{
				switch (Agent_Menu(active_user))
				{
				case 1:
					//lead list- all the customers in DB 
					break;
				case 2:
					//add and delete packages from DB
					Add_Or_Delete_Packages();
					break;
				case 3:
					//reply to customers
					PrintDeleteUsersMassages();
					system("pause");
					break;
				case 4:
					//confirm orders for customers
					break;
				case 5:
					flag = false;
					break;
				default:
					cout << "invalid choice" << endl;
					break;
				}

			} while (flag);

			break;

		case customer_login:
			//switch case for customer menu with do while
			do
			{
				switch (Customer_Menu(active_user))
				{
				case 1:
					//vacations search
					//vacation_search();
					break;
				case 2:
					//show status for packages orders
					break;
				case 3:
					//get in contact with agent
					Add_Message(active_user);
					break;
				case 4:
					//exit
					flag = false;
					break;
				default:
					cout << "invalid choice" << endl;

					break;
				}

			} while (flag);
			break;
		case no_login:
			break;
		}

		system("pause");
		return true;
		break;

	case 2://Sign up
		system("CLS");
		sign_up();
		return true;
		break;

	case 3://quit
		system("CLS");
		printf("\n\n\n\n\n\n\t\t\t  Goodbye!! we hope to see you again soon :)\n\n\n\n\n\t\t\t\t");
		system("pause");
		return false;
		break;
	default:
		printf("bad input\n");
		break;
	}
}

// sign-in function
login_type sign_in(User* active_user)
{
	string user, password;
	cout << "\n\n\n\t\t\t\t\tEnter user name\n\n\t\t\t\t\t";
	cin >> user;
	cout << "\n\n\t\t\t\t\tEnter password\n\n\t\t\t\t\t";
	cin >> password;
	cout << "\n\n\t\t\t\t\t";
	if (user == ADMIN_USER && password == ADMIN_PASS)
	{
		active_user->admin = true;
		active_user->firstName = "Admin";
		active_user->lastName = "";
		return admin_login;
	}
	if (!userCorrecrPass(user, password, active_user))
		return no_login;
	return check_usertype(user);
	// cheak info
}

login_type check_usertype(string user)
{
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt");

	if (DB_accounts.fail())
	{
		cerr << "\n\n\n \t\t\tERROR: The file couldn't be opened.\a" << endl;
	}

	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;

	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
	while (!DB_accounts.eof())
		while (!DB_accounts.eof())
		{
			if (UserName == user)
				return (is_agent == "Customer:" ? customer_login : agent_login);
			DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
		}
	DB_accounts.close();
}

bool ExistingUser(string username)
{
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt");

	if (DB_accounts.fail())
	{
		cerr << "\n\n\n \t\t\tERROR: The file couldn't be opened.\a" << endl;
	}

	if (username == ADMIN_USER)
	{
		return true;
	}

	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;

	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
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

void writeUserToFile(User use)//entering data from struct to txt file
{

	fstream DB_accounts;
	DB_accounts.open("DB_accounts.txt", ios::app);

	DB_accounts << (use.agent ? "Agent: " : "Customer: ") << use.firstName << " " << use.lastName << " " << use.userName << " " << use.password << " " << use.passport << " " << (use.gen ? "M" : "F") << " " << use.age << " " << use.email << " " << use.phoneNumber << endl;
	DB_accounts << "~~==============================================================================~~" << endl;

	DB_accounts.close();
}

bool userCorrecrPass(string username, string password, User* active_user)
{
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt");

	if (DB_accounts.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	string is_agent, FirstName, LastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;

	DB_accounts >> is_agent >> FirstName >> LastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
	while (!DB_accounts.eof())
	{
		if (UserName == username)
			if (PW == password)
			{
				//if the user password is correct change it to be the active user

				active_user->agent = (is_agent == "Customer:" ? false : true);
				active_user->firstName = FirstName;
				active_user->lastName = LastName;
				active_user->userName = UserName;
				active_user->password = PW;
				active_user->passport = PP;
				active_user->gen = (Gender == "M" ? M : F);
				active_user->age = stoi(Age);
				active_user->email = Email;
				active_user->phoneNumber = PhoneNumber;

				return true;
			}
			else
			{
				cerr << "\n\n\n\n\t\t\t\tThis password is incorrect.\a\n\n\t\t\t";
				return false;
			}

		DB_accounts >> is_agent >> FirstName >> LastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
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
	if (pass.length() > 8)
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
	User use;
	do {
		//must enter a new username to continue
		cout << "\n\n\n\t\t\tEnter user name\n\n\t\t\t";
		cin >> use.userName;
		if (ExistingUser(use.userName))
			cout << "\n\n\n\t\t     This user already exist.\a";
	} while (ExistingUser(use.userName));
	do {
		//must enter a valid password
		cout << "\n\n\n\t\t\tEnter password\n\n\t\t\t";
		cin >> use.password;
		if (!strongPassword(use.password))
			cout << "\n\n\n\t\t\tThis password is not strong enough \n    (Need to include an upper,lower and numiric character and 8 or more charecters).\a\n\t\t\t";
	} while (!strongPassword(use.password));
	cout << "\n\n\n\t\t\tEnter your first name\n\n\t\t\t";
	cin >> use.firstName;
	cout << "\n\n\t\t\tEnter your last name\n\n\t\t\t";
	cin >> use.lastName;
	do {
		//must enter 9 characters for valid passport
		cout << "\n\n\n\t\t\tEnter your passport\n\n\t\t\t";
		cin >> use.passport;
		if (passportCheck(use.passport))
			cout << "\n\n\n\t   This passport in not valid, Please enter passport with maximum 8 charecters.\a";
	} while (passportCheck(use.passport));//passport check
	cout << "\n\n\t\t\tEnter your age\n\n\t\t\t";
	cin >> use.age;
	int g;
	do {
		cout << "\n\n\n\t\t\tEnter gender: 1-male, 2-female\n\n\t\t\t";
		cin >> g;
		if (g == 1)
			use.gen = M;
		else if (g == 2)
			use.gen = F;
		else
			cout << "\n\n\n\t\t\tbad input\n\n\t\t\t";
	} while (g != 1 && g != 2);
	cout << "\n\n\n\t\t\tEnter your email\n\n\t\t\t";
	cin >> use.email;
	cout << "\n\n\n\t\t\tEnter your phone number\n\n\t\t\t";
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

int Admin_Menu(User active_user)
{
	int choice;
	system("CLS");
	print_active_user_message(active_user);
	printf("\n\n\n\t\t\t\t\t Admin menu\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   For agent menu.\n\n");
	//Agent_Menu(active_user); if choice is 1
	printf("\t\t\t\t\t2-   Make a user an agent.\n\n");
	printf("\t\t\t\t\t3-   Sign Out\n\n\t\t\t\t");
	cin >> choice;
	cout << "\n\n\t\t\t\t";
	return choice;
}

int Agent_Menu(User active_user)
{
	int choice;
	system("CLS");
	print_active_user_message(active_user);
	printf("\n\n\n\t\t\t\t\t Agent menu\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Lead list.\n\n");
	printf("\t\t\t\t\t2-   Add/Delete packages from the database.\n\n");
	printf("\t\t\t\t\t3-   Respond to customer messages.\n\n");
	printf("\t\t\t\t\t4-   Confirmation of customers orders.\n\n");
	printf("\t\t\t\t\t5-   Sign Out\n\n\t\t\t\t");
	cin >> choice;
	cout << "\n\n\t\t\t\t";
	return choice;
}

int Customer_Menu(User active_user)
{
	int choice;
	system("CLS");
	print_active_user_message(active_user);
	printf("\n\n\n\t\t\t\t\tCustomer\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Search for a vacations package.\n\n");
	printf("\t\t\t\t\t2-   Show status of package orders.\n\n");
	printf("\t\t\t\t\t3-   Get in contact with an agent.\n\n");
	printf("\t\t\t\t\t4-   Sign Out\n\n\t\t\t\t");
	cin >> choice;
	cout << "\n\n\t\t\t\t";
	return choice;
}

void PrintDeleteUsersMassages() {
	ifstream DB_massages;
	DB_massages.open("DB_massages.txt");
	int i = 0;
	string word;
	system("CLS");
	DB_massages >> word;
	if (!DB_massages.eof()) {
		while (!DB_massages.eof()) {
			cout << "massage number #" << i + 1 << ":" << endl;
			while (word != "//end_of_message")
			{
				if (word == "Message:")
					cout << endl;
				cout << word << " ";
				DB_massages >> word;
			}
			cout << "\n~~==============================================================================~~\n";
			++i;
			DB_massages >> word;

		}
	}
	else {

		cout << "no massage" << endl;
		system("pause");
		return;
	}
	//need to close DB and to open it again to be abe to read the file again in order to delete a line from it 
	DB_massages.close();
	DB_massages.open("DB_massages.txt");
	DB_massages >> word;

	int choice;
	cout << "Which message you took care of? (WARNING: the number you pick will be removed from databse)\n\n\n\t\t\t\t To go back enter " << i + 1 << " or above" << endl;
	cin >> choice;
	i = 1;
	ofstream temp;
	temp.open("temp.txt", ios::app);
	while (!DB_massages.eof()) {
		while (word != "//end_of_message")
		{
			if (i != choice)
			{
				temp << word << " ";

			}
			//cout << word << " ";
			DB_massages >> word;
		}
		if (word == "//end_of_message" && i != choice)
		{
			temp << "//end_of_message\n";
		}
		++i;
		DB_massages >> word;
		if (DB_massages.eof())
		{
			break;
		}
	}
	temp.close();
	DB_massages.close();
	remove("DB_massages.txt");
	rename("temp.txt", "DB_massages.txt");

}

void ContactWithAgent(User use) {
	string mass;
	fstream DB_massages;
	DB_massages.open("DB_massages.txt", ios::app);
	if (DB_massages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	cout << "\n\n\n\t\t\tLeave a massage for a travel agent:\n\n\n\t\t\t";
	cin >> mass; // check
	DB_massages << "not_taken_care_of" << use.email << " " << use.phoneNumber << " " << mass << endl;
	DB_massages << "~~==============================================================================~~" << endl;
	DB_massages.close();
}

void print_active_user_message(User active_user)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//cout << "its " << tm.tm_hour << " aclock"<<" ";
	string day_greeting;
	if (tm.tm_hour >= 0 && tm.tm_hour < 12)
	{
		day_greeting = "Good Morning";
	}
	else if (tm.tm_hour >= 12 && tm.tm_hour < 16)
	{
		day_greeting = "Good Afternoon";
	}
	else if (tm.tm_hour >= 16 && tm.tm_hour < 21)
	{
		day_greeting = "Good Evening";
	}
	else if (tm.tm_hour >= 21 && tm.tm_hour < 24)
	{
		day_greeting = "Good Night";
	}

	cout << "\n\t" << day_greeting << " " << active_user.firstName << " " << active_user.lastName << endl << endl;
}

void PrintUsersToAdmin() {
	system("CLS");
	/* ifstream file("DB_accounts.txt");
		cout << file.rdbuf();; print all the DB the way it is*/
	ifstream DB_accounts;
	DB_accounts.open("DB_accounts.txt", ios::out);//open the file for output
	if (DB_accounts.fail())
	{
		cout << "ERROR: no file found\a" << endl;
		return;
	}
	int i = 0;
	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;
	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;

	while (!DB_accounts.eof()) {
		cout << "User number #" << i + 1 << ":" << endl;
		//printing values from DB_accounts
		cout << "account type:" << (is_agent == "Agent:" ? "Agent" : "Customer") << "\n\tFirst Name: " << FirstName << "\tLast Name:" << lastName << "\tUserName:" << UserName << "\n\tPassword:" << PW << "\tPastport:" << PP << "\tGender:" << Gender << "\n\tAge:" << Age << "\tEmail:" << Email << "\tPhone number:" << PhoneNumber << "\n" << seperator << endl;
		//getting data for cout
		++i;
		DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
	}
	DB_accounts.close();

}

void Add_Agent() {
	PrintUsersToAdmin();
	int choice, i = 0;
	cout << "Which user do you wish to make as Agent? (0 To go back)" << endl;
	cin >> choice;
	if (choice == 0)
		return;
	choice -= 1;
	string agent = "Agent: ";
	string customer = "Customer: ";
	ifstream DB_accounts;
	ofstream temp;

	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;

	DB_accounts.open("DB_accounts.txt", ios::out);
	temp.open("temp.txt", ios::app);
	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;

	while (!DB_accounts.eof()) {
		if (i == choice)
		{
			is_agent = agent;
			temp << is_agent << FirstName << " " << lastName << " " << UserName << " " << PW << " " << PP << " " << Gender << " " << Age << " " << Email << " " << PhoneNumber << "\n" << seperator << endl;

		}
		else
		{
			temp << is_agent << " " << FirstName << " " << lastName << " " << UserName << " " << PW << " " << PP << " " << Gender << " " << Age << " " << Email << " " << PhoneNumber << "\n" << seperator << endl;

		}
		DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
		++i;
	}
	temp.close();
	DB_accounts.close();
	cout << "Updated databse" << endl;
	remove("DB_accounts.txt");
	rename("temp.txt", "DB_accounts.txt");
}

void Add_Or_Delete_Packages() {
	system("CLS");
	print_packages();
	cout << endl;

	int choice = 0;
	do
	{
		printf("\n\n\n\n\t\t\t\t\t1-   To add packages.\n\n");
		printf("\t\t\t\t\t2-   To delete packages.\n\n");
		printf("\t\t\t\t\t3-   To go back.\n\n");

		cin >> choice;
		if (!(choice == 2 || choice == 1 || choice == 3))
		{
			printf("\t\t\t\t\t   Invalid input, Please try again.\n\n");

		}
	} while (!(choice == 2 || choice == 1 || choice == 3));
	if (choice == 1)
	{
		Add_Packages();
	}
	if (choice == 2)
	{
		Delete_Packages();
	}
	if (choice == 3)
	{
		return;
	}
}

void Delete_Packages() {
	
	int choice;
	ifstream DB_packages;
	DB_packages.open("DB_packages.txt");
	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;
	DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	if (DB_packages.eof())
	{
		cerr << "\n\n\t\t\t\t No packages found in database" << endl;
		system("pause");
		return;
	}
	cout << "\n\n\n\n\t\t\t\tWhich package do you wish to remove (0 To Go back)" << endl;
	cin >> choice;
	if (choice == 0)
		return;
	ofstream temp;
	temp.open("temp.txt");
	int i;
	for ( i = 1; (!DB_packages.eof()); i++)
	{
		if (i != choice)
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n" << seperator << endl;
		}
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	}
	temp.close();
	DB_packages.close();
	if (choice>i)
	{
		cout << "The chosen package is not exist" << endl;
	}
	else
	{
		cout << "Removed package!" << endl;
	}
	remove("DB_packages.txt");
	rename("temp.txt", "DB_packages.txt");
	print_packages();
}

void print_packages()
{
	system("CLS");
	ifstream DB_packages;
	DB_packages.open("DB_packages.txt");

	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;

	DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	if (DB_packages.eof())
	{
		return;
	}
	int i = 1;
	do
	{
		cout << "Package number:" << i << "\tSerial Num." << serial_number << endl;
		cout << "\n\n\tDestenation: " << destenation << "  Origin: " << origin << "  Departure date: " << departure_date;
		cout << "\n\n\tReturn date: " << return_date << "  Hotel: " << hotel << "  Flight company: " << flight_company << "  Flight number: " << flight_number;
		cout << "\n\n\tVaccent spots:" << vacant_spots << "  Price (per passenger): " << price << "\n\n";
		cout << seperator << endl << endl;
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		i++;
	} while (!DB_packages.eof());
	DB_packages.close();
	//system("pause");
}

void Add_Packages()
{
	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price;
	system("CLS");
	cout << "\n\n\n\t\t\tEnter destenation\n\n\t\t\t";
	cin >> destenation;
	cout << "\n\n\n\t\t\tEnter origin\n\n\t\t\t";
	cin >> origin;
	cout << "\n\n\n\t\t\tEnter departure_date\n\n\t\t\t";
	cin >> departure_date;
	cout << "\n\n\n\t\t\tEnter return_date\n\n\t\t\t";
	cin >> return_date;
	cout << "\n\n\n\t\t\tEnter hotel\n\n\t\t\t";
	cin >> hotel;
	cout << "\n\n\n\t\t\tEnter flight_company\n\n\t\t\t";
	cin >> flight_company;
	cout << "\n\n\n\t\t\tEnter flight_number\n\n\t\t\t";
	cin >> flight_number;
	cout << "\n\n\n\t\t\tEnter vacant_spots\n\n\t\t\t";
	cin >> vacant_spots;
	cout << "\n\n\n\t\t\tEnter price\n\n\t\t\t";
	cin >> price;

	do
	{
		cout << "\n\n\n\t\t\tEnter serial number\n\n\t\t\t";
		cin >> serial_number;
		if (!Is_Serial_Num_Avilable(serial_number))
		{
			cerr << "\n\n\n\t\t\t This serial number is not avilable.\n\n\a";
		}
	} while (!Is_Serial_Num_Avilable(serial_number));


	fstream DB_packages;
	DB_packages.open("DB_packages.txt", ios::app);

	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	DB_packages << endl << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n";
	DB_packages << "~~------------------------------------------------------------------------------------~~" << endl;

	DB_packages.close();

}

bool Is_Serial_Num_Avilable(string number)
{
	ifstream DB_packages;
	DB_packages.open("DB_packages.txt");

	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;

	DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	if (DB_packages.eof())
	{
		return true;
	}

	do
	{
		if (serial_number == number)
			return  false;
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	} while (!DB_packages.eof());

	DB_packages.close();
	return true;
}

void Add_Message(User active_user) {
	string message;
	ofstream DB_messages;
	DB_messages.open("DB_massages.txt", ios::app);
	if (DB_messages.fail())
	{
		cout << "ERROR: cannot open file" << endl;
		return;
	}
	system("CLS");
	cout << "\n\n\n\n\t\t\t\tPlease enter your massage:\n\n\n\t\t\t";

	clearbuffer();//need to clear buffer before reading string type from user
	getline(cin, message);

	DB_messages << "Name: " << active_user.firstName << " " << active_user.lastName << " Phone number: " << active_user.phoneNumber << " Email:" << active_user.email << "\nMessage: " << message << " " << "//end_of_message\n";
	cout << "Sent!" << endl;
	system("pause");

	DB_messages.close();
}
void clearbuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}
void Main_Menu() {
	cout << RED;
	printf("\t\t88888888888                                888  .d8888b.  888 d8b          888     \n");
	cout << YELLOW;
	printf("\t\t    888                                    888 d88P  Y88b 888 Y8P          888     \n");
	cout << MAGENTA;
	printf("\t\t    888                                    888 888    888 888              888     \n");
	cout << BLUE;
	printf("\t\t    888  888d888 8888b.  888  888  .d88b.  888 888        888 888  .d8888b 888  888\n");
	cout << CYAN;
	printf("\t\t    888  888    .d888888 Y88  88P 88888888 888 888    888 888 888 888      888888K \n");
	cout << YELLOW;
	printf("\t\t    888  888    888  888  Y8bd8P  Y8b.     888 Y88b  d88P 888 888 Y88b.    888 \"88b\n");
	cout << RED;
	printf("\t\t    888  888    \"Y888888   Y88P    \"Y8888  888  \"Y8888P\"  888 888  \"Y8888P 888  888\n\n\n\n");
	cout << RESET;

	printf("\t\t\t\t\t Hello what would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Sign In\n\n");
	printf("\t\t\t\t\t2-   Sign Up\n\n");
	printf("\t\t\t\t\t3-   Exit\n\n\t\t\t");
}