#ifndef _TRIP_INTERFACE_
#define _TRIP_INTERFACE_

#include "utility.h"
#include "bag.h"

struct client
{
	string firstName;
	string lastName;
	int age;
	string phone;
	int experience;
};

class Trip
{
private:
	Bag<client> clientBag;
	vector<client> clientList;
	int clientBagSize;
	client tempClient;

	int deleteMe;
	int index;
	int findInt;
	string findString;
public:
	Trip();
	void addClient();
	void remClient();
	void cancelTrip();
	void countClients() const;
	void listClients();
};

#endif