// team 3

#include <iostream>
#include <fstream> // files
#include <cstring> // string
#include <string>

using namespace std;

#define ADMIN_USER "admin"
#define ADMIN_PASS "0000"

// define gender
enum  gender { F, M };

enum  login_type { admin_login , agent_login, customer_login, no_login};

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
login_type sign_in();
void sign_up();
bool strongPassword(string);
void writeUserToFile(User);
bool ExistingUser(string);
bool userCorrecrPass(string, string);
bool passportCheck(string);
login_type check_usertype(string);
int Admin_Menu();
int Agent_Menu();
int Customer_Menu();
void PrintUsersMassages();
void ContactWithAgent(User);

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
	printf("\t\t\t\t\t3-   Exit\n\n\t\t\t");
	// start system
	int choose;
	User active_user;
	cin>>choose;
	switch (choose)
	{
	case 1://Sign in
		
		system("CLS");

		switch (sign_in()) //Opening the Sign_in menu and gives what kind of user is being used. 
		{
		case admin_login:
			Admin_Menu();
			system("pause");
			break;
		case agent_login:
			switch (Agent_Menu())
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				PrintUsersMassages();
				system("pause");
				break;
			case 4:
				break;
			}
			system("pause");
			break;
		case customer_login:
			Customer_Menu();
			system("pause");
			break;
		case no_login:
			system("pause");
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
		printf("\n\n\n\n\n\n\t\t\t\tGoodbye!! hope to see you soon:)\n");
		return false;
		break;
	default:
		printf("bad input\n");
		break;
	}
}

// sign-in function
login_type sign_in() 
{
	string user, password;
	cout << "\n\n\n\t\t\t\t\tEnter user name\n\n\t\t\t\t\t" ;
	cin >> user;
	cout << "\n\n\t\t\t\t\tEnter password\n\n\t\t\t\t\t" ;
	cin >> password;
	cout << "\n\n\t\t\t\t\t";
	if (user == ADMIN_USER && password == ADMIN_PASS)
		return admin_login;
	if (!userCorrecrPass(user, password))
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
				return (is_agent=="Customer:"?customer_login:agent_login);
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

int Admin_Menu()
{
	int choice;
	system("CLS");
	printf("\n\n\n\t\t\t\t\tHello Admin\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Lead list.\n\n");
	printf("\t\t\t\t\t2-   Add/delete packages from the database.\n\n");
	printf("\t\t\t\t\t3-   Respond to customer messages.\n\n");
	printf("\t\t\t\t\t4-   Confirmation of customers orders.\n\n");
	printf("\t\t\t\t\t5-   Show User DB.\n\n");
	printf("\t\t\t\t\t6-   Make a user an agent.\n\n");
	printf("\t\t\t\t\t7-   Exit\n\n\t\t\t");
	cin >> choice;
	return choice;
}

int Agent_Menu()
{
	int choice;
	system("CLS");
	printf("\n\n\n\t\t\t\t\tHello Agent\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Lead list.\n\n");
	printf("\t\t\t\t\t2-   Add/delete packages from the database.\n\n");
	printf("\t\t\t\t\t3-   Respond to customer messages.\n\n");
	printf("\t\t\t\t\t4-   Confirmation of customers orders.\n\n");
	printf("\t\t\t\t\t5-   Exit\n\n\t\t\t");
	cin >> choice;
	return choice;
}


int Customer_Menu()
{
	int choice;
	system("CLS");
	printf("\n\n\n\t\t\t\t\tHello Customer\n\n\n\t\t\t");
	printf("\t\t What would you like to do?\n\n");
	printf("\t\t\t\t\t1-   Search for a vication package.\n\n");
	printf("\t\t\t\t\t2-   Show status of package orders.\n\n");
	printf("\t\t\t\t\t3-   Get in contact with an agent.\n\n");
	printf("\t\t\t\t\t4-   Exit\n\n\t\t\t");
	cin >> choice;
	return choice;
}


void PrintUsersMassages() {
	ifstream DB_massages;
	DB_massages.open("DB_massages.txt");

	int i = 0;
	string word;
	DB_massages >> word;
	if (!DB_massages.eof()) {
		while (!DB_massages.eof()) {
			cout << "massage number #" << i + 1 << ":" << endl;
			while (word != "//end_of_message")
			{
				cout <<word<<" ";
				DB_massages >> word;
			}
			cout << "\n~~==============================================================================~~\n";
			++i;
		}
	}
	else
		cout << "no massage" << endl;
}

void ContactWithAgent(User use) {
	string mass;
	fstream DB_massages;
	DB_massages.open("DB_massages.txt", ios::app);
	if (DB_massages.fail())
	{
		cerr << "\n\n\n\t\t\tERROR: The file couldn't be opened.\a\n\n\t\t\t";
	}
	cout << "write your massage to agent\n";
	cin >> mass; // check
	DB_massages <<"not_taken_care_of"<< use.email << " " << use.phoneNumber << " " << mass << endl;
	DB_massages << "~~==============================================================================~~" << endl;
	DB_massages.close();
}