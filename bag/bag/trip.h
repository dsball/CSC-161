/*------------------------------------trip.h
Purpose: defines functions for manipulating contents of client bag
--- Member Data ---
Name            Type              Description
-------------------------------------------------------------------------------------------
clientBag       Bag<client>       container for trip clients
clientList      vector<client>    vector for printing clients
tempClient    	client            holds number of clients in bag
deleteMe	    int               index of client to be removed

--- Functions ---
Name                Return    Description; Parameter description
--------------------------------------------------------------------------------------------
Trip()			    none      Default constructor
	no params

addClient()         void      prompts user for client information and enters into the Array
                              truncates names longer than 12 characters.
    no params

remClient()         void      removes a client from the array
    no params

cancelTrip()        void      cancels the trip by setting clients to zero
    no params

countClients()      void      gets number of clients on the trip and prints it to screen
    no params

listClients()       void      lists the clients and their information
    no params
*/

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
public:
	Trip();
	void addClient();
	void remClient();
	void cancelTrip();
	void countClients() const;
	void listClients();
};

#endif