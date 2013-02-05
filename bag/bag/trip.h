#include "utility.h"
#include "bag.h"

struct client
{
	string firstName;
	string lastName;
	int age;
	int phone;
	int experience;
};

class Trip
{
private:
	Bag<client> clientBag;
	vector<client> clientList;
	int clientBagSize;

	int deleteMe;
	int index;
	int findInt;
	string findString;
public:
	Trip();
	bool addClient();
	bool remClient();
	bool cancelTrip();
	int countClients();
	void listClients();
};