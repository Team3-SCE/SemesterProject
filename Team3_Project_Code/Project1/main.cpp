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
#include <windows.h>//for time delay
#include <time.h>//for date checks

using namespace std;

//master user
#define ADMIN_USER "admin"
#define ADMIN_PASS "0000"

// define gender
enum  gender { F, M };

enum  login_type { admin_login, agent_login, customer_login, no_login };//to define log in user

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

//sign in/up + menu
bool Sign_Menu();
login_type Sign_In(User*);
void Sign_Up();
//searching for new package include ordering
void Vacation_Search(User active_user);
//check if the password is strong enough for the system
bool Strong_Password(string);
//insert use to the txt file
void Write_User_To_File(User);
//check if the user already exist
bool Existing_User(string);
//check if the password is valid
bool User_Correcr_Pass(string, string, User*);
//check if passport is valid
bool Passport_Check(string);
//check which type of user has logged in
login_type Check_User_type(string);
//Users Menus
int Admin_Menu(User active_user);
int Agent_Menu_For_Admin(User active_user);
int Agent_Menu(User active_user);
int Customer_Menu(User active_user);
void PrintDeleteUsersMassages();
//Prints a specific greeting for each user(depends of the time of day)
void Print_Active_User_Message(User);
//Prints all of the users(used only by the admin)
void PrintUsersToAdmin();
//Change a costumer user into an agent user (used by the admin)
void Add_Agent();
//Menu to add or delete packages (used by the agent)
void Add_Or_Delete_Packages();
//Prints all of the existing packages(for the agent)
void print_packages();
//Gets a new package details from the agent and adds it to the packages_DB
void Add_Packages();
//Removes a package from the packages_DB
void Delete_Packages();
//Check if this serial number is not used by other package in the packages_DB
bool Is_Serial_Num_Avilable(string number);
//Send a message to an agent
void Add_Message(User active_user);
//Clears the buffer (used once inorder to deal with a problamatic string input)
void clearbuffer();
//Opens the main menu and use switch cases to navigate between all of the screens
void Main_Menu();
//Prints all of the orders by all users , used by agent
void Print_Orders_Agent();      
//Confirm the as an agent 
void Orders_Confirmation();
//Prints all of the relevant friendlist contact info
bool Print_Friendlist(string serialNum, string user);
//void Print_Friendlist(string serialNum);
//Adds contact info to friendlist_DB
void Add_To_Friendlist(User use, string serialNum);
//Take paying info and making an order(Updates ordders_DB)
void Make_An_Order(User active_user, string serial_number, int passenger);
//Checks if its a real countrys name
bool Check_County(string country);
//Print all of the paying costumers and their orders
void Print_Lead_List();
//Prints all of the costumers orders
void Print_Orders_Customer(User active_user);
//Print a package by serial number
void Print_By_Serial(string serial_num);
//check if the customer has ordered - use for lead list
bool Check_If_Ordered(string user_name);
//after ordering changing the amount of available spots in the package
void Decrease_Vacant_Spot(string serialNum, int passenger);
void Increase_To_Vacant_Spot(string serialNum ,int passangers);
//checks if the dates are valid
void Seperate(int* newyear, int* newmonth, int* newday, string date_string);//gives the dates as int values for Date_Check func
bool Date_Check(string date);
bool Date_Is_Inbetween(string datemin, string date, string datemax);//checks if the dates are between each other
bool Date_Check2(string date);
//delete an order for a costumer
void Delete_Order_Customer(User active_user, int choice);


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
	while (Sign_Menu()) { system("CLS"); } //Opening sign in menu until it returns false (clears screan in between)
	return 1;
}

// login function
bool Sign_Menu() {

	User active_user;
	int choose;
	active_user.firstName = active_user.lastName = "";

	// welcome
	system("CLS");
	Print_Active_User_Message(active_user);
	Main_Menu();
	// start system
	cin >> choose;
	bool flag = true;

	switch (choose)
	{
	case 1://Sign in
		flag = true;
		system("CLS");
		switch (Sign_In(&active_user)) //Opening the Sign_in menu and gives what kind of user is being used. 
		{
		case admin_login:
			do
			{
				//switch case for admin with do while

				switch (Admin_Menu(active_user)) {
				case 1:
					switch (Agent_Menu_For_Admin(active_user))
					{
					case 1:
						//lead list- all the customers in DB 
						Print_Lead_List();
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
						Orders_Confirmation();
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
					cout << "\n\n\n\t\t\t\tInvalid choice, Please try again\n\n\n\n\t\t\t\t" << endl;
					system("pause");
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
					Print_Lead_List();
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
					Orders_Confirmation();
					break;
				case 5:
					flag = false;
					break;
				default:
					cout << "\n\n\n\t\t\t\tInvalid choice, Please try again\n\n\n\n\t\t\t\t" << endl;
					system("pause");
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
					Vacation_Search(active_user);
					//Vacation_Search();
					break;
				case 2:
					//show status for packages orders
					Print_Orders_Customer(active_user);//BUG
					system("pause");
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
					cout << "\n\n\n\t\t\t\tInvalid choice, Please try again\n\n\n\n\t\t\t\t" << endl;
					system("pause");
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
		Sign_Up();
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
login_type Sign_In(User* active_user)
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
	if (!User_Correcr_Pass(user, password, active_user))
		return no_login;
	return Check_User_type(user);
	// cheak info
}

login_type Check_User_type(string user)
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

bool Existing_User(string username)
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

void Write_User_To_File(User use)//entering data from struct to txt file
{

	fstream DB_accounts;
	DB_accounts.open("DB_accounts.txt", ios::app);

	DB_accounts << (use.agent ? "Agent: " : "Customer: ") << use.firstName << " " << use.lastName << " " << use.userName << " " << use.password << " " << use.passport << " " << (use.gen ? "M" : "F") << " " << use.age << " " << use.email << " " << use.phoneNumber << endl;
	DB_accounts << "~~==============================================================================~~" << endl;

	DB_accounts.close();
}

bool User_Correcr_Pass(string username, string password, User* active_user)
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
bool Strong_Password(string pass)
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
/*
void Sign_Up() {//new sign up
	User use;
	string _age;
	do {
		//must enter a new username to continue
		cout << "\n\n\n\t\t\tEnter user name\n\n\t\t\t";
		cin >> use.userName;
		if (Existing_User(use.userName))
			cout << "\n\n\n\t\t     This user already exist.\a";
	} while (Existing_User(use.userName));
	do {
		//must enter a valid password
		cout << "\n\n\n\t\t\tEnter password\n\n\t\t\t";
		cin >> use.password;
		if (!Strong_Password(use.password))
			cout << "\n\n\n\t\t\tThis password is not strong enough \n    (Need to include an upper,lower and numiric character and 8 or more charecters).\a\n\t\t\t";
	} while (!Strong_Password(use.password));
	cout << "\n\n\n\t\t\tEnter your first name\n\n\t\t\t";
	cin >> use.firstName;
	cout << "\n\n\t\t\tEnter your last name\n\n\t\t\t";
	cin >> use.lastName;
	do {
		//must enter 9 characters for valid passport
		cout << "\n\n\n\t\t\tEnter your passport\n\n\t\t\t";
		cin >> use.passport;
		if (!Passport_Check(use.passport))
			cout << "\n\n\n\t   This passport in not valid, Please enter passport with maximum 8 charecters.\a";
	} while (!Passport_Check(use.passport));//passport check
	cout << "\n\n\t\t\tEnter your age\n\n\t\t\t";
	bool flag = false;
	do
	{
		flag = false;
		cin >> _age;
		for (size_t i = 0; i < _age.length(); i++)
		{
			if (_age[i] < '0' || _age[i]>'9') {

				flag = true;

			}
		}

		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);
	use.age = stoi(_age);



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
	Write_User_To_File(use);

}
*/
bool Passport_Check(string passport) {
	if (passport.length() <= 8)
	{
		return true;
	}
	return false;
}

int Admin_Menu(User active_user)
{
	int choice;
	system("CLS");
	Print_Active_User_Message(active_user);
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
int Agent_Menu_For_Admin(User active_user)
{
	int choice;
	system("CLS");
	Print_Active_User_Message(active_user);
	printf("\n\n\n\t\t\t\t\t Agent menu\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Lead list.\n\n");//done
	printf("\t\t\t\t\t2-   Add/Delete packages from the database.\n\n");//done
	printf("\t\t\t\t\t3-   Respond to customer messages.\n\n");//done
	printf("\t\t\t\t\t4-   Confirmation of customers orders.\n\n");//done
	printf("\t\t\t\t\t5-   Sign Out\n\n\t\t\t\t");
	printf("\t6 or above back to admin menu\n\n\t\t\t\t");
	do
	{
		cin >> choice;
		if (choice == 0)
			cout << "\t\t\t\t0 is not in the list please select from the list above" << endl << "\t\t\t\t";
	} while (choice == 0);
	cout << "\n\n\t\t\t\t";
	return choice;
}
int Agent_Menu(User active_user)
{
	int choice;
	system("CLS");
	Print_Active_User_Message(active_user);
	printf("\n\n\n\t\t\t\t\t Agent menu\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Lead list.\n\n");//done
	printf("\t\t\t\t\t2-   Add/Delete packages from the database.\n\n");//done
	printf("\t\t\t\t\t3-   Respond to customer messages.\n\n");//done
	printf("\t\t\t\t\t4-   Confirmation of customers orders.\n\n");//done
	printf("\t\t\t\t\t5-   Sign Out\n\n\t\t\t\t");
	cin >> choice;
	cout << "\n\n\t\t\t\t";
	return choice;
}

int Customer_Menu(User active_user)
{
	int choice;
	system("CLS");
	Print_Active_User_Message(active_user);
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

		cout << "\n\n\n\n\t\t\t\tno massage\n\n" << endl;
		return;
	}
	//need to close DB and to open it again to be abe to read the file again in order to delete a line from it 
	DB_massages.close();
	DB_massages.open("DB_massages.txt");
	DB_massages >> word;

	int choice;
	cout << "Which message you took care of? (WARNING: the number you pick will be removed from databse)\n\n\n\t\t\t\t To go back enter " << i + 1 << " or above" << endl;
	do
	{
		cin >> choice;
		if ((!(choice > 0)))
			cout << "\n\t\t\tPlease chose a valid number from the list" << endl;
	} while (!(choice > 0));
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

void Print_Active_User_Message(User active_user)
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
//
//void Add_Agent() {
//	PrintUsersToAdmin();
//	int choice, i = 0;
//	cout << "Which user do you wish to make as Agent? (0 To go back)" << endl;
//	cin >> choice;
//	if (choice == 0)
//		return;
//	choice -= 1;
//	string agent = "Agent: ";
//	string customer = "Customer: ";
//	ifstream DB_accounts;
//	ofstream temp;
//
//	string is_agent, FirstName, lastName, UserName, PW, PP, Gender, Age, Email, PhoneNumber, seperator;
//
//	DB_accounts.open("DB_accounts.txt", ios::out);
//	temp.open("temp.txt", ios::app);
//	DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
//
//	while (!DB_accounts.eof()) {
//		if (i == choice)
//		{
//			is_agent = agent;
//			temp << is_agent << FirstName << " " << lastName << " " << UserName << " " << PW << " " << PP << " " << Gender << " " << Age << " " << Email << " " << PhoneNumber << "\n" << seperator << endl;
//
//		}
//		else
//		{
//			temp << is_agent << " " << FirstName << " " << lastName << " " << UserName << " " << PW << " " << PP << " " << Gender << " " << Age << " " << Email << " " << PhoneNumber << "\n" << seperator << endl;
//
//		}
//		DB_accounts >> is_agent >> FirstName >> lastName >> UserName >> PW >> PP >> Gender >> Age >> Email >> PhoneNumber >> seperator;
//		++i;
//	}
//	temp.close();
//	DB_accounts.close();
//	cout << "Updated databse" << endl;
//	remove("DB_accounts.txt");
//	rename("temp.txt", "DB_accounts.txt");
//}

void Add_Or_Delete_Packages() {
	system("CLS");
	print_packages();
	cout << endl;

	int choice = 0;
	do
	{
		printf("\n\n\n\n\t\t\t\t\t1-   To add packages.\n\n");
		printf("\t\t\t\t\t2-   To delete packages.\n\n");
		printf("\t\t\t\t\t3-   To go back.\n\n\n\t\t\t\t");

		cin >> choice;
		if (!(choice == 2 || choice == 1 || choice == 3))
		{
			printf("\t\t\t\t\t   Invalid input, Please try again.\n\n\n\t\t\t\t");

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
//
//void Delete_Packages() {
//
//	int choice;
//	ifstream DB_packages;
//	DB_packages.open("DB_packages.txt");
//	if (DB_packages.fail())
//	{
//		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
//	}
//
//	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;
//	DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
//	if (DB_packages.eof())
//	{
//		cerr << "\n\n\t\t\t\t No packages found in database" << endl;
//		system("pause");
//		return;
//	}
//	cout << "\n\n\n\n\t\t\t\tWhich package do you wish to remove (0 To Go back)" << endl;
//	cin >> choice;
//	if (choice == 0)
//		return;
//	ofstream temp;
//	temp.open("temp.txt");
//	int i;
//	for (i = 1; (!DB_packages.eof()); i++)
//	{
//		if (i != choice)
//		{
//			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n" << seperator << endl;
//		}
//		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
//	}
//	temp.close();
//	DB_packages.close();
//	if (choice > i)
//	{
//		cout << "The chosen package is not exist" << endl;
//	}
//	else
//	{
//		cout << "Removed package!" << endl;
//	}
//	remove("DB_packages.txt");
//	rename("temp.txt", "DB_packages.txt");
//	print_packages();
//}

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
		cout << "\n\n\tVaccent spots:" << vacant_spots << "  Price (per passenger): " << price << "$\n\n";
		cout << seperator << endl << endl;
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		i++;
	} while (!DB_packages.eof());
	DB_packages.close();
	//system("pause");
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
	cout << "\n\n\n\n\t\t\t\tSent!" << endl;
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
//void Orders_Confirmation() {
//	//need to open packages DB and take serial number 
//	//need to open text file(DB) for payment and customer username
//	//print the orders
//	Print_Orders_Agent();
//	//cin->choice which one package do you wish to remove
//	int choice, i = 1;
//	cout << "Which package do you want to approved/decline? (0 to cancel)" << endl;
//	cin >> choice;
//	if (choice == 0)
//	{
//		return;
//	}
//
//	//then need to -1 from package database 
//	//then to replace from waiting to approved or decline in order DB
//	ifstream DB_orders;
//	DB_orders.open("DB_orders.txt");
//	if (DB_orders.fail())
//	{
//		cout << "ERROR: no file found\a" << endl;
//		return;
//	}
//	ofstream temp2;
//	temp2.open("temp2.txt", ios::app);
//	string status, username, serial_num, credit_num, credit_exp, cvv;
//	int is_approved;
//	DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv;
//
//	while (!DB_orders.eof()) {
//		if (status == "waiting")
//		{
//
//			if (i == choice)
//			{
//
//				cout << "1- To approve\n2- To decline\n(other number to skip)" << endl;
//				cin >> is_approved;
//				if (is_approved == 1)
//				{
//					/*status = "approved";*/
//					temp2 << "approved " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << endl;
//					//Decrease_Vacant_Spot(serial_num);
//
//				}
//				if (is_approved == 2)
//				{
//					status = "decline ";
//					temp2 << "decline" << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << endl;
//					Increase_To_Vacant_Spot(serial_num);
//				}
//			}
//			else
//			{
//				temp2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << endl;
//			}
//			++i;
//
//		}
//		else
//		{
//			temp2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << endl;
//
//		}
//		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv;
//
//	}
//
//	temp2.close();
//	DB_orders.close();
//	remove("DB_orders.txt");
//	rename("temp2.txt", "DB_orders.txt");
//
//
//}
void Print_Orders_Agent() {
	ifstream DB_orders;
	DB_orders.open("DB_orders.txt");
	if (DB_orders.fail())
	{
		cout << "ERROR: no file found\a" << endl;
		return;
	}
	int i = 1;
	string status, username, serial_num, credit_num, credit_exp, cvv, passangers;
	//DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv
	DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv>> passangers;
	while (!DB_orders.eof())
	{
		if (status == "waiting")
		{
			cout << "\n\n\n\n\t\t\t\tOrder number " << i << ":" << endl;
			cout << "\n\n\t\t\t\t" << "Status: " << status << "\n\t\t\t\t" << "Username:" << username << "\tSerial Number:" << serial_num << "\n\t\t\t\tCredit Number:\t" << credit_num << "\n\t\t\t\tCredit Experation Date: " << credit_exp << "\tCredit CVV: " << cvv << "\n\t\t\t\tNumber of passangers:" << passangers;
			cout << "\n\t\t\t~------------------------------------------------------------------------------------~" << endl;
			i++;
		}
		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv >> passangers;
	}
	DB_orders.close();

}
//from here im adding func
bool Print_Friendlist(string serialNum, string user)
{//added
	int age;
	string serialN, firstName, lastName, phoneNumber, email, gen, username, seperator;

	ifstream DB_friendList;

	DB_friendList.open("DB_friendList.txt");

	if (DB_friendList.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	DB_friendList >> serialN >> firstName >> lastName >> phoneNumber >> email >> gen >> age >> username >> seperator;

	bool flag = false;
	do {

		if (user == username && serialN == serialNum)
			flag = true;

		DB_friendList >> serialN >> firstName >> lastName >> phoneNumber >> email >> gen >> age >> username >> seperator;
	} while (!DB_friendList.eof());

	if (!flag)
		return false;

	else //add this to fix print problem 
	{
		cout << "\n\t\t\tThe friend list:\n\n";
	}

	DB_friendList.close();
	DB_friendList.open("DB_friendList.txt");

	DB_friendList >> serialN >> firstName >> lastName >> phoneNumber >> email >> gen >> age >> username >> seperator;
	do {
		if (serialN == serialNum && user != username)
			cout << "\t\t\t\t\tFirst Name: " << firstName << "\t Last Name: " << lastName << "\n\n\t\t\t\tPhone Number: " << phoneNumber << " Email: " << email << " Gender: " << gen << " Age: " << age << "\n\t\t" << seperator << endl;
		DB_friendList >> serialN >> firstName >> lastName >> phoneNumber >> email >> gen >> age >> username >> seperator;
	} while (!DB_friendList.eof());
	DB_friendList.close();
}

void Add_To_Friendlist(User use, string serialNum) {//added
	string Fname = use.firstName;
	string Lname = use.lastName;
	string phone = use.phoneNumber;
	string email = use.email;
	gender gen = use.gen;
	int age = use.age;
	string username = use.userName;

	ofstream DB_friendlist;
	DB_friendlist.open("DB_friendlist.txt", ios::app);

	if (DB_friendlist.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
		system("pause");
	}

	DB_friendlist << serialNum << " " << Fname << " " << Lname << " " << phone << " " << email << " " << (use.gen ? "M" : "F") << " " << age << " " << username << "\n";
	DB_friendlist << "------------------------------------------------------------------------------------" << endl;

	DB_friendlist.close();
}

void Make_An_Order(User active_user, string serial_number, int passenger)//added
{
	int choice;
	ofstream DB_orders;
	DB_orders.open("DB_orders.txt", ios::app);

	if (DB_orders.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
		system("pause");
	}

	string credit_num, credit_exp, cvv;
	do
	{
		cout << "\n\n\n\n\t\t\t\tEnter your credit card number:\n\n\t\t\t\t";
		cin >> credit_num;
		if (credit_num.length() != 16)
		{
			cout << "\n\n\n\n\t\t\t\tInvalid credit card number, Please enter only 16 digits for credit card\a" << endl;

		}

	} while (credit_num.length() != 16);
	cout << "\n\n\n\n\t\t\t\tEnter your credit card experation date:\n\n\t\t\t\t";
	cin >> credit_exp;//need to check date-agent will check valid credit card 
	do
	{
		cout << "\n\n\n\n\t\t\t\tEnter your credit card cvv:\n\n\t\t\t\t";
		cin >> cvv;
		if (cvv.length() != 3)
		{
			cout << "\n\n\n\n\t\t\t\tInvalid number, Please enter only 3 digits for cvv\a" << endl;
		}

	} while (cvv.length() != 3);
	Decrease_Vacant_Spot(serial_number, passenger);
	DB_orders << "waiting " << active_user.userName << " " << serial_number << " " << credit_num << " " << credit_exp << " " << cvv <<" "<< passenger << endl;
	DB_orders.close();
	cout << "\n\n\n\n\t\t\t\tDo you wish to be in friend list?\n (other people will be able to see your contact details)\n\n\t\t\t\t1- yes\t2- no:\n\n\n\n\t\t\t\t";
	do
	{
		cin >> choice;
		if (!(choice == 1 || choice == 2))
		{
			cout << "\n\n\n\n\t\t\t\tBad input, Pleae enter 1 or 2 only\n\n\n\n\t\t\t\t" << endl;
		}

	} while (!(choice == 1 || choice == 2));
	if (choice == 1)
	{
		Add_To_Friendlist(active_user, serial_number);
	}
}
//shir func
bool Check_County(string country)
{
	if (country[0] >= 'a' && country[0] <= 'z')
	{

		country[0] = country[0] - 32;
	}

	string countries[] = { "Afghanistan","Algeria","American Samoa","Andorra","Angola","Anguilla","Antarctica","Antarctica"
		,"Antigua And Barbuda"
		,"Argentina"
		,"Armenia"
		,"Aruba"
		,"Australia"
		,"Austria"
		,"Azerbaijan"
		,"Bahamas"
		,"Bahrain"
		,"Bangladesh"
		,"Barbados"
		,"Belarus"
		,"Belgium"
		,"Belize"
		,"Benin"
		,"Bermuda"
		,"Bhutan"
		,"Bolivia"
		,"Bosnia And Herzegovina"
		,"Botswana"
		,"Bouvet Island"
		,"Brazil"
		,"British Indian Ocean Territory"
		,"Brunei Darussalam"
		,"Bulgaria"
		,"Burkina Faso"
		,"Burundi"
		,"Cambodia"
		,"Cameroon"
		,"Canada"
		,"Cape Verde"
		,"Cayman Islands"
		,"Central African Republic"
		,"Chad"
		,"Chile"
		,"China"
		,"Christmas Island"
		,"Cocos(keeling) Islands"
		,"Colombia"
		,"Comoros"
		,"Congo"
		,"Congo"
		,"Cook Islands"
		,"Costa Rica"
		,"Cote D'ivoire"
		,"Croatia"
		,"Cuba"
		,"Cyprus"
		,"Czech Republic"
		,"Denmark"
		,"Djibouti"
		,"Dominica"
		,"Dominican Republic"
		,"East Timor"
		,"Ecuador"
		,"Egypt"
		,"El Salvador"
		,"Equatorial Guinea"
		,"Eritrea"
		,"Estonia"
		,"Ethiopia"
		,"Falkland Islands"
		,"Faroe Islands"
		,"Fiji"
		,"Finland"
		,"France"
		,"French Guiana"
		,"French Polynesia"
		,"French Southern Territories"
		,"Gabon"
		,"Gambia"
		,"Georgia"
		,"Germany"
		,"Ghana"
		,"Gibraltar"
		,"Greece"
		,"Greenland"
		,"Grenada"
		,"Guadeloupe"
		,"Guam"
		,"Guatemala"
		,"Guinea"
		,"Guinea - bissau"
		,"Guyana"
		,"Haiti"
		,"Heard Island And Mcdonald Islands"
		,"Holy See(vatican City State)"
		,"Honduras"
		,"Hong Kong"
		,"Hungary"
		,"Iceland"
		,"India"
		,"Indonesia"
		,"Iran"
		,"Iraq"
		,"Ireland"
		,"Israel"
		,"Italy"
		,"Jamaica"
		,"Japan"
		,"Jordan"
		,"Kazakstan"
		,"Kenya"
		,"Kiribati"
		,"Korea"
		,"Korea"
		,"Kosovo"
		,"Kuwait"
		,"Kyrgyzstan"
		,"Lao"
		,"Latvia"
		,"Lebanon"
		,"Lesotho"
		,"Liberia"
		,"Libyan Arab Jamahiriya"
		,"Liechtenstein"
		,"Lithuania"
		,"Luxembourg"
		,"Macau"
		,"Madagascar"
		,"Malawi"
		,"Malaysia"
		,"Maldives"
		,"Mali"
		,"Malta"
		,"Marshall Islands"
		,"Martinique"
		,"Mauritania","Mauritius"
	,"Mayotte"
	,"Mexico"
	,"Moldova"
	,"Monaco"
	,"Mongolia"
	,"Montserrat"
	,"Montenegro"
	,"Morocco"
	,"Mozambique"
	,"Myanmar"
	,"Namibia"
	,"Nauru"
	,"Nepal"
	,"Netherlands"
	,"Netherlands Antilles"
	,"New Caledonia"
	,"New Zealand"
	,"Nicaragua"
	,"Niger"
	,"Nigeria"
	,"Niue"
	,"Norfolk Island"
	,"Northern Mariana Islands"
	,"Norway"
	,"Oman"
	,"Pakistan"
	,"Palau"
	,"Panama"
	,"Papua New Guinea"
	,"Paraguay"
	,"Peru"
	,"Philippines"
	,"Pitcairn"
	,"Poland"
	,"Portugal"
	,"Puerto Rico"
	,"Qatar"
	,"Reunion"
	,"Romania"
	,"Russian Federation"
	,"Rwanda"
	,"Saint Helena"
	,"Saint Kitts And Nevis"
	,"Saint Lucia"
	,"Saint Pierre And Miquelon"
	,"Saint Vincent And The Grenadines"
	,"Samoa"
	,"San Marino"
	,"Sao Tome And Principe"
	,"Saudi Arabia"
	,"Senegal"
	,"Serbia"
	,"Seychelles"
	,"Sierra Leone"
	,"Singapore"
	,"Slovakia"
	,"Slovenia"
	,"Solomon Islands"
	,"Somalia"
	,"South Africa"
	,"South Georgia"
	,"Spain"
	,"Sri Lanka"
	,"Sudan"
	,"Suriname"
	,"Svalbard And Jan Mayen"
	,"Swaziland"
	,"Sweden"
	,"Switzerland"
	,"Syrian Arab Republic"
	,"Taiwan, Province Of China"
	,"Tajikistan"
	,"Tanzania"
	,"Thailand"
	,"Togo"
	,"Tokelau"
	,"Tonga"
	,"Trinidad And Tobago"
	,"Tunisia"
	,"Turkey"
	,"Turkmenistan"
	,"Turks And Caicos Islands"
	,"Tuvalu"
	,"Uganda"
	,"Ukraine"
	,"United Arab Emirates"
	,"United Kingdom"
	,"United States"
	,"Uruguay"
	,"Uzbekistan"
	,"Vanuatu"
	,"Venezuela"
	,"Viet Nam"
	,"Virgin Islands"
	,"Virgin Islands"
	,"Wallis And Futuna"
	,"Western Sahara"
	,"Yemen"
,"Zambia"
,"Zimbabwe" };




	for (int i = 0; i <= 236; i++)
	{
		if (countries[i] == country)
		{
			return true;
		}
	}
	return false;
}/*
void Add_Packages()
{
	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price;
	system("CLS");
	cout << "\n\n\n\t\t\tEnter destenation\n\n\t\t\t";
	cin >> destenation;
	if (destenation[0] >= 'a' && destenation[0] <= 'z')
	{

		destenation[0] = destenation[0] - 32;
	}
	while (!Check_County(destenation))
	{
		cout << "\n\n\n\t\t\tThe destenation is wrong.\n\t\t\tPlease try again";
		cout << "\n\n\n\t\t\tEnter destenation\n\n\t\t\t";
		cin >> destenation;
	}

	cout << "\n\n\n\t\t\tEnter origin\n\n\t\t\t";
	cin >> origin;
	if (origin[0] >= 'a' && origin[0] <= 'z')
	{

		origin[0] = origin[0] - 32;
	}
	while (!Check_County(origin))
	{
		cout << "\n\n\n\t\t\tThe origin is wrong.\n\t\t\tPlease try again";
		cout << "\n\n\n\t\t\tEnter origin\n\n\t\t\t";
		cin >> origin;
	}

	cout << "\n\n\n\t\t\tEnter departure date\n\n\t\t\t";
	cin >> departure_date;
	cout << "\n\n\n\t\t\tEnter return date\n\n\t\t\t";
	cin >> return_date;
	cout << "\n\n\n\t\t\tEnter hotel\n\n\t\t\t";
	cin >> hotel;
	cout << "\n\n\n\t\t\tEnter flight company\n\n\t\t\t";
	cin >> flight_company;
	cout << "\n\n\n\t\t\tEnter flight number\n\n\t\t\t";
	cin >> flight_number;
	cout << "\n\n\n\t\t\tEnter vacant spots\n\n\t\t\t";
	bool flag = false;
	do
	{
		flag = false;
		cin >> vacant_spots;
		for (size_t i = 0; i < vacant_spots.length(); i++)
		{
			if (vacant_spots[i] < '0' || vacant_spots[i]>'9') {

				flag = true;


			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);


	cout << "\n\n\n\t\t\tEnter price (in dollars)\n\n\t\t\t";
	do
	{
		flag = false;
		cin >> price;
		for (size_t i = 0; i < price.length(); i++)
		{
			if (price[i] < '0' || price[i]>'9') {

				flag = true;

			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);


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
	DB_packages << "~------------------------------------------------------------------------------------~" << endl;

	DB_packages.close();

}*/
//luba
void Print_Orders_Customer(User active_user) {
	system("clear");
	ifstream DB_orders;
	DB_orders.open("DB_orders.txt");
	if (DB_orders.fail())
	{
		cout << "ERROR: no file found\a" << endl;
		return;
	}
	int i = 1;
	string status, username, serial_num, credit_num, credit_exp, cvv,passangers;
	DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv>> passangers;
	while (!DB_orders.eof())
	{
		if (active_user.userName == username)
		{
			cout << "\n\n\t" << "Status: " << status << "\t\t\tPassangers: "<< passangers<< "\n\t\t\t\t";
			cout << "\n\t\t\t\tOrder number " << i << ":" << endl;
			Print_By_Serial(serial_num);
			//cout << "\n\t\t\t~------------------------------------------------------------------------------------~" << endl;
			i++;
			//cout << "\n\t\t\tThe friend list:\n\n";
			Print_Friendlist(serial_num, username);
		}
		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv>> passangers;

	}
	DB_orders.close();
	
	int choice;
	cout << "\n\n\t\tIf you wish to remove one of the orders please select the number (0 to go back):\n\t\t\t\t ";
	do
	{
		cin >> choice;
		if (choice > i || choice < 0)
		{
			cout << "\n\t\t\t\tInvalid choice, Please select from the list above\n\t\t\t\t";
		}
	} while (choice > i || choice < 0);

	if (choice == 0)
		return;
	Delete_Order_Customer(active_user, choice);
	system("pause");
	system("clear");
	cout << "\n\n\n\n\t\t\tThe database has been updated succesfully\n\n\n\n\t\t\t";


}
void Print_By_Serial(string serial_num)
{
	//system("CLS");
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
	do {
		if (serial_num == serial_number)
		{
			cout << "\tSerial Num." << serial_number << endl;
			cout << "\n\n\tDestenation: " << destenation << "  Origin: " << origin << "  Departure date: " << departure_date;
			cout << "\n\n\tReturn date: " << return_date << "  Hotel: " << hotel << "  Flight company: " << flight_company << "  Flight number: " << flight_number << endl;
			cout << "\t" << seperator << endl << endl;
		}
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	} while (!DB_packages.eof());


	DB_packages.close();
	//system("pause");
}
//hadar
void Print_Lead_List() {
	system("CLS");
	ifstream DB_accounts;
	string is_agent, FirstName, LastName, userN, passw, passp, gen, email, phone, age, seperator;
	User use;
	DB_accounts.open("DB_accounts.txt");
	if (DB_accounts.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	do {
		DB_accounts >> is_agent >> FirstName >> LastName >> userN >> passw >> passp >> gen >> age >> email >> phone >> seperator;
		if (is_agent == "Customer:" && Check_If_Ordered(userN))
		{
			cout << "\n\n\n\n\t\t\t\tFirst Name: " << FirstName << "\tLast Name: " << LastName << "\tGender: " << gen << "\n\t\t\t\tEmail: " << email << "\tPhone: " << phone << endl;
			use.userName = userN;
			Print_Orders_Customer(use);
		}


	} while (!DB_accounts.eof());
	DB_accounts.close();
	system("pause");
}

bool Check_If_Ordered(string user_name)
{
	ifstream DB_orders;
	User use;
	DB_orders.open("DB_orders.txt");
	if (DB_orders.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	string status, username, serial_num, credit_num, credit_exp, cvv, passangers;
	do
	{
		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv>> passangers;
		if (user_name == username)
		{
			DB_orders.close();
			return true;
		}

	} while (!DB_orders.eof());
	DB_orders.close();
	return false;
}
//maor
void Increase_To_Vacant_Spot(string serialNum , int passangers)
{
	fstream DB_packages;
	DB_packages.open("DB_packages.txt");

	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;

	fstream temp;
	temp.open("temp.txt", ios::app);

	do
	{
		if (serialNum == serial_number)
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << (stoi(vacant_spots) + passangers) << " " << price << "\n" << seperator << endl;
			DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		}
		else
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n" << seperator << endl;
			DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		}
	} while (!DB_packages.eof());

	temp.close();
	DB_packages.close();
	remove("DB_packages.txt");
	rename("temp.txt", "DB_packages.txt");
}

void Decrease_Vacant_Spot(string serialNum, int passenger)
{
	fstream DB_packages;
	DB_packages.open("DB_packages.txt");

	if (DB_packages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}

	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price, seperator;

	fstream temp;
	temp.open("temp.txt", ios::app);

	do
	{
		if (serialNum == serial_number)
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << (stoi(vacant_spots) - passenger) << " " << price << "\n" << seperator << endl;
			DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		}
		else
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n" << seperator << endl;
			DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
		}
	} while (!DB_packages.eof());

	temp.close();
	DB_packages.close();
	remove("DB_packages.txt");
	rename("temp.txt", "DB_packages.txt");
}
//matan & hadar
void Vacation_Search(User active_user) {
	system("CLS");
	int user_choice;
	//ofstream outfile("serials_file.txt");
	ifstream DB_packages;
	DB_packages.open("DB_packages.txt");
	system("CLS");

	string from, to, departure_date, return_date, passengers, min_price, max_price;
	cout << "\n\n\n\n\t\t\t\tDear customer please enter the vacation details.\n";
	cout << "\n\n\n\n\t\t\t\tto:\n\n\t\t\t\t";
	cin >> to;
	while (Check_County(to) == false) {
		cerr << "\n\n\n\n\t\t\t\tError,please vaild country\n\n\t\t\t\t";
		cin >> to;
	}
	if (to[0] >= 'a' && to[0] <= 'z')
	{

		to[0] = to[0] - 32;
	}
	cout << "\n\n\n\n\t\t\t\tOrigin country\n\n\t\t\t\t";
	cin >> from;
	if (from[0] >= 'a' && from[0] <= 'z')
	{

		from[0] = from[0] - 32;
	}
	while (Check_County(from) == false) {
		cerr << "error,please vaild country\n";
		cin >> from;
	}

	cout << "\n\n\n\n\t\t\t\tDeparture date (DD/MM/YYYY)";
	do
	{
		do
		{
			cout << "\n\n\n\n\t\t\t\t";

			cin >> departure_date;//need to check
		} while (!Date_Check2(departure_date));


	} while (!(Date_Check(departure_date)));


	cout << "\n\n\n\n\t\t\t\tReturn date (DD/MM/YYYY)";
	do
	{
		do
		{
			cout << "\n\n\n\n\t\t\t\t";
			cin >> return_date;//need to check

		} while (!Date_Check2(return_date));


	} while (!(Date_Check(return_date)));
	bool flag = false;

	cout << "\n\n\n\n\t\t\t\tNumber of passengers\n\n\t\t\t\t";
	do
	{
		flag = false;
		cin >> passengers;
		for (size_t i = 0; i < passengers.length(); i++)
		{
			if (passengers[i] < '0' || passengers[i]>'9') {

				flag = true;

			}
		}

		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);
	while (stoi(passengers) < 1)
	{
		cerr << "\n\n\n\n\t\t\t\terror,the number of passengers must  be above 0\n\n\n\n\t\t\t\t";
		cin >> passengers;
	}
	for (size_t i = 1; i < stoi(passengers); i++)
	{
		string FirstName, LastName, PS;
		//Passport_Check(string)
		cout << "\n\n\n\n\t\t\t\tEnter additional passenger number " << i << " first name:\n\n\n\n\t\t\t\t";
		cin >> FirstName;
		cout << "\n\n\n\n\t\t\t\tEnter additional passenger number " << i << " last name:\n\n\n\n\t\t\t\t";
		cin >> LastName;
		cout << "\n\n\n\n\t\t\t\tEnter additional passenger number " << i << " passport:\n\n\n\n\t\t\t\t";
		do
		{
			cin >> PS;
			if (!Passport_Check(PS))
			{
				cout << "\n\n\n\n\t\t\t\tInvalid passport\a" << endl;
			}

		} while (!Passport_Check(PS));


	}//getting passengers  details 
	cout << "\n\n\n\n\t\t\t\tMax price in dollars (0 for no max price)\n\n\t\t\t\t";
	flag = false;
	do
	{
		flag = false;
		cin >> max_price;
		for (size_t i = 0; i < max_price.length(); i++)
		{
			if (max_price[i] < '0' || max_price[i]>'9') {

				flag = true;

			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";
	} while (flag);
	cout << "\n\n\n\n\t\t\t\tMin price in dollars (0 for no min price)\n\n\t\t\t\t";
	do
	{
		flag = false;
		cin >> min_price;
		for (size_t i = 0; i < min_price.length(); i++)
		{
			if (min_price[i] < '0' || min_price[i]>'9') {

				flag = true;

			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t\t";

	} while (flag);
	system("CLS");
	string serial_number, destenation, origin, departure_date_temp, return_date_temp, hotel, flight_company, flight_number, vacant_spots, price, seperator;
	if (max_price[0] == '0')
		max_price = "99999999";//defualt value
	if (min_price[0] == '0')
		min_price = "1";//defualt value
	int i = 1;
	flag = false;
	DB_packages >> serial_number >> destenation >> origin >> departure_date_temp >> return_date_temp >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;

	do
	{

		if (to == destenation && origin == from)
			if (Date_Is_Inbetween(departure_date, departure_date_temp, return_date) && Date_Is_Inbetween(departure_date, return_date_temp, return_date))
				if (stoi(passengers) <= stoi(vacant_spots))
					if (stoi(min_price) <= stoi(price))
						if (stoi(max_price) >= stoi(price))
						{
							//serials_file << serial_number;
							cout << "Package number:" << i << "\tSerial Num." << serial_number << endl;
							cout << "\n\n\tDestenation: " << destenation << "  Origin: " << origin << "  Departure date: " << departure_date;
							cout << "\n\n\tReturn date: " << return_date << "  Hotel: " << hotel << "  Flight company: " << flight_company << "  Flight number: " << flight_number;
							cout << "\n\n\tVaccent spots:" << vacant_spots << "  Price (per passenger): " << price << "$" << "\n\n";
							cout << seperator << endl << endl;
							i++;
							flag = true;
						}
		DB_packages >> serial_number >> destenation >> origin >> departure_date_temp >> return_date_temp >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;

	} while (!DB_packages.eof());
	if (flag)
	{
		cout << "\t\tTerms & Conditions: You will receive appropriate advertisements related to your package\n" << endl;
		cout << "\t\t\t\tPlease pick a package?\n";
		cin >> user_choice;

		i = 1;
		DB_packages.close();
		DB_packages.open("DB_packages.txt");
		do
		{
			DB_packages >> serial_number >> destenation >> origin >> departure_date_temp >> return_date_temp >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
			if (to == destenation && origin == from)
				if (Date_Is_Inbetween(departure_date, departure_date_temp, return_date) && Date_Is_Inbetween(departure_date, return_date_temp, return_date))
					if (stoi(passengers) <= stoi(vacant_spots))
						if (stoi(min_price) <= stoi(price))
							if (stoi(max_price) >= stoi(price))
							{
								if (i == user_choice)
								{
									DB_packages.close();
									Make_An_Order(active_user, serial_number, stoi(passengers));
									break;
								}
								++i;
							}
		} while (!DB_packages.eof());
	}
	else
	{
		cout << "\n\n\n\n\t\t\t\tNo match found!" << endl;
		system("pause");
		DB_packages.close();

	}

}
void Seperate(int* newyear, int* newmonth, int* newday, string date_string)
{
	// date in mm/dd/yyyy format
	string s = date_string;

	int n = s.length();

	// declaring character array
	char* char_array = (char*)malloc(n + 1);

	// copying the contents of the
	// string to char array
	strcpy(char_array, s.c_str());



	// pointer to current split section
	char* pch;
	// info needed
	int month = -1, day = -1, year = -1;

	// split the date from beginning to the first occurrence of /
	pch = strtok(char_array, "/");
	// while we have more / chars
	while (pch != NULL)
	{
		// set the variables
		int num = atoi(pch);
		if (month == -1) month = num;
		else if (day == -1) day = num;
		else if (year == -1) year = num;

		// continue splitting the string
		pch = strtok(NULL, "/");
	}
	newyear[0] = year;
	newmonth[0] = month;
	newday[0] = day;

	// check if we got correct data
	//printf("%d %d %d", month, day, year);
}
bool Date_Is_Inbetween(string datemin, string date, string datemax)
{
	int daymin = 0, day = 0, daymax = 0, monthmin = 0, month = 0, monthmax = 0, yearmin = 0, year = 0, yearmax = 0;

	Seperate(&yearmin, &monthmin, &daymin, datemin);
	Seperate(&year, &month, &day, date);
	Seperate(&yearmax, &monthmax, &daymax, datemax);

	bool min = true, max = true;

	if (year < yearmin)
	{
		min = false;
	}
	else if (year == yearmin && month < monthmin)
	{
		min = false;
	}
	else if (year == yearmin && month == monthmin && day < daymin)
	{
		min = false;
	}

	if (yearmax < year)
	{
		max = false;
	}
	else if (yearmax == year && monthmax < month)
	{
		max = false;
	}
	else if (yearmax == year && monthmax == month && daymax < day)
	{
		max = false;
	}


	return (max && min);

}
bool Date_Check(string date)
{
	int year = 0, month = 0, day = 0;
	Seperate(&year, &day, &month, date);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	tm.tm_year;
	tm.tm_mon;
	tm.tm_mday;

	if (month > 12 || month < 1) {
		cout << "\n\n\n\n\t\t\t\tinvalid month\a" << endl;
		return false;

	}
	if (month == 2)
	{
		if (day <= 0 || day > 29) {
			cout << "\n\n\n\n\t\t\t\tinvalid day for this month\a" << endl;;
			return false;
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day <= 0 || day > 30) {

			cout << "\n\n\n\n\t\t\t\tinvalid day for this month\a" << endl;
			return false;

		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day <= 0 || day > 31) {

			cout << "\n\n\n\n\t\t\t\tinvalid day for this month\a" << endl;
			return false;
		}

	}
	if (year < 2020)
	{
		cout << "\n\n\n\n\t\t\t\tinvalid year\a" << endl;
		return false;

	}
	else if (year == 2020 && month < (tm.tm_mon + 1))
	{
		cout << "\n\n\n\n\t\t\t\tinvalid month\a" << endl;
		return false;

	}
	else if (year == 2020 && month == (tm.tm_mon + 1) && day < tm.tm_mday)
	{
		cout << "\n\n\n\n\t\t\t\tinvalid day\a" << endl;
		return false;

	}
	return true;
}
bool Date_Check2(string date) {

	for (size_t i = 0; i < date.length(); i++)
	{
		if (!((date[i] == '/') || (date[i] >= '0' && date[i] <= '9')))
		{
			cout << "\n\n\n\n\t\t\t\tPlease try with / format" << endl;
			return false;
		}
	}
	return true;
}
void Sign_Up() //***after fix
{//new sign up
	User use;
	string _age;
	do {
		//must enter a new username to continue
		cout << "\n\n\n\t\t\tEnter user name\n\n\t\t\t";
		cin >> use.userName;
		if (Existing_User(use.userName))
			cout << "\n\n\n\t\t     This user already exist.\a";
	} while (Existing_User(use.userName));
	do {
		//must enter a valid password
		cout << "\n\n\n\t\t\tEnter password\n\n\t\t\t";
		cin >> use.password;
		if (!Strong_Password(use.password))
			cout << "\n\n\n\t\t\tThis password is not strong enough \n    (Need to include an upper,lower and numiric character and 8 or more charecters).\a\n\t\t\t";
	} while (!Strong_Password(use.password));
	cout << "\n\n\n\t\t\tEnter your first name\n\n\t\t\t";
	cin >> use.firstName;
	cout << "\n\n\t\t\tEnter your last name\n\n\t\t\t";
	cin >> use.lastName;
	do {
		//must enter 9 characters for valid passport
		cout << "\n\n\n\t\t\tEnter your passport\n\n\t\t\t";
		cin >> use.passport;
		if (!Passport_Check(use.passport))
			cout << "\n\n\n\t   This passport in not valid, Please enter passport with maximum 8 charecters.\a";
	} while (!Passport_Check(use.passport));//passport check
	cout << "\n\n\t\t\tEnter your age\n\n\t\t\t";
	bool flag = false;
	do
	{
		flag = false;
		cin >> _age;
		for (size_t i = 0; i < _age.length(); i++)
		{
			if (_age[i] < '0' || _age[i]>'9') {

				flag = true;

			}
		}

		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);
	use.age = stoi(_age);



	string g;//change:int to string
	do {
		cout << "\n\n\n\t\t\tEnter gender: 1-male, 2-female\n\n\t\t\t";
		cin >> g;
		if (atoi(g.c_str()) == 1)//change g==1 to atoi(g.c_str()) == 1
			use.gen = M;
		else if (atoi(g.c_str()) == 2)//change g==1 to atoi(g.c_str()) == 1
			use.gen = F;
		else
			cout << "\n\n\n\t\t\tbad input\n\n\t\t\t";
	} while (atoi(g.c_str()) != 1 && atoi(g.c_str()) != 2);//change g to atoi(g.c_str()) 
	cout << "\n\n\n\t\t\tEnter your email\n\n\t\t\t";
	cin >> use.email;
	cout << "\n\n\n\t\t\tEnter your phone number\n\n\t\t\t";
	cin >> use.phoneNumber;
	use.agent = false;
	Write_User_To_File(use);

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
	if (choice > i - 1 || choice < 0)
	{
		cout << "You entered a number not from list, Database has not changed" << endl;

	}
	else
	{
		cout << "Updated databse" << endl;

	}
	system("pause");
	remove("DB_accounts.txt");
	rename("temp.txt", "DB_accounts.txt");
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
	for (i = 1; (!DB_packages.eof()); i++)
	{
		if (i != choice)
		{
			temp << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n" << seperator << endl;
		}
		DB_packages >> serial_number >> destenation >> origin >> departure_date >> return_date >> hotel >> flight_company >> flight_number >> vacant_spots >> price >> seperator;
	}
	temp.close();
	DB_packages.close();
	if (choice > i)
	{
		cout << "\n\n\n\t\t\t\tThe chosen package is not exist\n\n\t\t\t" << endl;
		system("pause");

	}
	else
	{
		cout << "\n\n\n\t\t\t\tRemoved package!\n\n\t\t\t" << endl;
	}
	remove("DB_packages.txt");
	rename("temp.txt", "DB_packages.txt");
	print_packages();
}
void Add_Packages()
{
	string serial_number, destenation, origin, departure_date, return_date, hotel, flight_company, flight_number, vacant_spots, price;
	system("CLS");
	cout << "\n\n\n\t\t\tEnter destenation\n\n\t\t\t";
	cin >> destenation;
	if (destenation[0] >= 'a' && destenation[0] <= 'z')
	{

		destenation[0] = destenation[0] - 32;
	}
	while (!Check_County(destenation))
	{
		cout << "\n\n\n\t\t\tThe destenation is wrong.\n\t\t\tPlease try again";
		cout << "\n\n\n\t\t\tEnter destenation\n\n\t\t\t";
		cin >> destenation;
	}

	cout << "\n\n\n\t\t\tEnter origin\n\n\t\t\t";
	cin >> origin;
	if (origin[0] >= 'a' && origin[0] <= 'z')
	{

		origin[0] = origin[0] - 32;
	}
	while (!Check_County(origin))
	{
		cout << "\n\n\n\t\t\tThe origin is wrong.\n\t\t\tPlease try again";
		cout << "\n\n\n\t\t\tEnter origin\n\n\t\t\t";
		cin >> origin;
	}

	cout << "\n\n\n\t\t\tEnter departure date\n\n\t\t\t";
	cin >> departure_date;
	cout << "\n\n\n\t\t\tEnter return date\n\n\t\t\t";
	cin >> return_date;
	cout << "\n\n\n\t\t\tEnter hotel\n\n\t\t\t";
	cin >> hotel;
	cout << "\n\n\n\t\t\tEnter flight company\n\n\t\t\t";
	cin >> flight_company;
	cout << "\n\n\n\t\t\tEnter flight number\n\n\t\t\t";
	cin >> flight_number;
	cout << "\n\n\n\t\t\tEnter vacant spots\n\n\t\t\t";
	bool flag = false;
	do
	{
		flag = false;
		cin >> vacant_spots;
		for (size_t i = 0; i < vacant_spots.length(); i++)
		{
			if (vacant_spots[i] < '0' || vacant_spots[i]>'9') {

				flag = true;


			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);


	cout << "\n\n\n\t\t\tEnter price (in dollars)\n\n\t\t\t";
	do
	{
		flag = false;
		cin >> price;
		for (size_t i = 0; i < price.length(); i++)
		{
			if (price[i] < '0' || price[i]>'9') {

				flag = true;

			}
		}
		if (flag)
			cout << "\n\n\n\t\t\t\tPlease enter only digits\n\n\n\t\t\t";

	} while (flag);


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

	//DB_packages << endl
	DB_packages << serial_number << " " << destenation << " " << origin << " " << departure_date << " " << return_date << " " << hotel << " " << flight_company << " " << flight_number << " " << vacant_spots << " " << price << "\n";
	DB_packages << "------------------------------------------------------------------------------------" << endl;

	DB_packages.close();

}
void Orders_Confirmation() {
	system("CLS");
	//need to open packages DB and take serial number 
	//need to open text file(DB) for payment and customer username
	//print the orders
	Print_Orders_Agent();
	//cin->choice which one package do you wish to remove
	int choice, i = 1;
	bool exist = false; //if the choice exist
	cout << "\n\n\n\n\t\t\t\tWhich package do you want to approved/decline? (0 to cancel)\n\n\n\n\t\t\t\t";
	cin >> choice;


	if (choice == 0)
	{
		return;
	}


	//then need to -1 from package database 
	//then to replace from waiting to approved or decline in order DB
	ifstream DB_orders;
	DB_orders.open("DB_orders.txt");
	if (DB_orders.fail())
	{
		cout << "ERROR: no file found\a" << endl;
		return;
	}

	ofstream temp2;
	temp2.open("temp2.txt", ios::app);
	string status, username, serial_num, credit_num, credit_exp, cvv, passangers;
	int is_approved;
	DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv >> passangers;

	while (!DB_orders.eof()) {
		if (status == "waiting")
		{

			if (i == choice)
			{
				exist = true;
				cout << "\n\t\t\t\t1- To approve\n\t\t\t\t2- To decline\n\t\t\t(other number to skip)" << endl;
				cin >> is_approved;
				if (is_approved == 1)
				{
					// status = "approved"; 
					temp2 << "approved " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv <<" "<< passangers<<endl;
					//Decrease_Vacant_Spot(serial_num);

				}
				if (is_approved == 2)
				{
					status = "decline ";
					temp2 << "decline" << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv <<" "<< passangers << endl;
					Increase_To_Vacant_Spot(serial_num, stoi(passangers));
				}
			}
			else
			{
				temp2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << " " << passangers << endl;
			}
			++i;

		}
		else
		{
			temp2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << " " << passangers << endl;

		}
		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv >> passangers ;

	}
	if (exist == false)
	{
		cerr << "\n\n\n\t\t\t\tERROR: This choice is invalid \n\n\n\n\t\t\t\t\a" << endl;
		system("pause");
	}

	temp2.close();
	DB_orders.close();
	remove("DB_orders.txt");
	rename("temp2.txt", "DB_orders.txt");


}

void Delete_Order_Customer(User active_user, int choice) 
{

	ifstream DB_orders;
	ofstream temp_2;
	temp_2.open("temp2.txt");
	DB_orders.open("DB_orders.txt");
	if (DB_orders.fail())
	{
		cout << "ERROR: no file found\a" << endl;
		return;
	}
	int i = 1;
	string status, username, serial_num, credit_num, credit_exp, cvv, passangers;
	DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv >> passangers;
	while (!DB_orders.eof())
	{
		if (active_user.userName == username)
		{
			if (i != choice)//copy every order except users choice
					temp_2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << " " << passangers << endl;
			else if (status != "decline")
				Increase_To_Vacant_Spot(serial_num, stoi(passangers));
			i++;
		}
		else
			temp_2 << status << " " << username << " " << serial_num << " " << credit_num << " " << credit_exp << " " << cvv << " " << passangers << endl;

		DB_orders >> status >> username >> serial_num >> credit_num >> credit_exp >> cvv >> passangers;
	}

	temp_2.close();
	DB_orders.close();

	remove("DB_orders.txt");
	rename("temp2.txt", "DB_orders.txt");

}