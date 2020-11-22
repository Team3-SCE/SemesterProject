/* Assignment: 3 Author: Hadar Amsalem,
ID: 316129212  */

#ifndef VIPCLIENT_H // if not define
#define VIPCLIENT_H
#include <iostream>
#include <cstring>
#include "String.h" // string header
#include "Client.h" // client header

using namespace std;

// class VIPclient
class VIPClient:public Client {

private:
	int numOfMimHobbys; // keep 

public:
	VIPClient(const String &name, const String &id, gender gen, int age, char **hobbys, int numOfHobbys,int numOfMinHobbys);// ctor
	virtual bool operator==(const Client& c)const; // operator ==
	VIPClient& operator=(const VIPClient& c); // operator =
	VIPClient(const VIPClient& c); //cctor
	virtual void printClient()const; // print client
	~VIPClient() {}; //dtor
};

#endif
