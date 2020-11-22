/* Assignment: 3 Author: Hadar Amsalem,
ID: 316129212  */


#include <iostream>
#include <cstring>
#include "String.h" // string header
#include "Client.h" // client header
#include "VIPClient.h" // vipclient header


using namespace std;

//ctor- first criate a client after complite the exstra
VIPClient::VIPClient(const String& name, const String& id, gender gen, int age, char **hobbys, int numOfHobbys, int numOfMinHobbys):Client(name, id, gen, age, hobbys, numOfHobbys) {
	this->numOfMimHobbys = numOfMinHobbys; // set the min number of hobbys for match 
}

//operator==
bool VIPClient::operator==(const Client& c)const {
	if (c.getGen() != this->getGen()) { // if the gender is equal
		if ((c.getAge() - this->getAge()) <= 5 && ((-1)*(c.getAge() - this->getAge()) <= 5)) {
			int count = 0; // count the same hobbys
			int k; // help to loop
			int len; // keep the length of the hobby
			for (int i = 0; i < this->getNumOfHobbies(); ++i) { 
				for (int j = 0; j < c.getNumOfHobbies(); ++j) {
					if (strlen(this->getHobbies(i)) == strlen(c.getHobbies(j))) // if the length id deffrent
					{
						len = strlen(this->getHobbies(i)); 
						for (k = 0; k < len; ++k)
							if (this->getHobbies(i)[k] != c.getHobbies(j)[k])
								break; // diffrent
						if (k == len)
							count++; // count similar hobbies
					}
				}
			}
			if (count >= this->numOfMimHobbys) // cheak the number of the same hobbys
				return true; // match!!
		}
		return false;
	}
	return false;
}

// print vip client
void VIPClient::printClient()const {
	Client::printClient(); // print data client
	cout << "number Of Mim Hobbies:" << numOfMimHobbys << endl; // print the minimum num
}

//operator=
VIPClient& VIPClient::operator=(const VIPClient& c) {
	Client::operator=(c); // cheack the data of client
	this->numOfMimHobbys = c.numOfMimHobbys; // get mim number of hoobys for match
	return *this;
}

// cctor
VIPClient::VIPClient(const VIPClient& c):Client(c){
	numOfMimHobbys = c.numOfMimHobbys;
}
