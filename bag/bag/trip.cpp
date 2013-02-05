#include "trip.h"


	
	bool remClient();
	bool cancelTrip();
	int countClients();
	vector<client> listClients();

Trip::Trip()
{

}

bool Trip::addClient()
{
	cout<<"\n\tEnter the first name followed by the last name: ";
	cin>>tempClient.firstName;
	cin>>tempClient.lastName;
	cout<<"\n\tEnter Age:";
	cin>>tempClient.age;
	cout<<"\n\tEnter the phone number";
	cin>>tempClient.phone;
	cout<<"\n\tEnter experience (0 - none, 1 - intermediate, 2 - expert):";
	cin>>tempClient.experience;

	return(clientBag.addItem(tempClient));
}

bool Trip::remClient()
{
	cout<<"\n\n\t\tEnter the item number you wish to remove: ";
	cin>>deleteMe;
	clientBag.deleteItem(deleteMe-1);
	return true;
}

bool Trip::cancelTrip()
{
	cout<<"\n\t\tDumping bag contents...";
	if(clientBag.empty())
	{
		cout<<"\n\t\tBag emptied!\n";
	}
	else
	{
		cout<<"\n\t\tFailed to empty bag.\n";
	}
	pause();
}

int Trip::countClients()
{
	cout<<"\n\n\t\tThere are "<<clientBag.getCount()<<" items in the bag.";
	Sleep(1000);
}

void Trip::listClients()
{
	clientList = clientBag.toVector();
	clientBagSize = clientList.size();
	system("CLS");
	cout<<"\n\t\t\tClient list \n\n";
	cout<<setw(15)<<"firstName,"<<"LastName,";
	for(int i=0; i<clientBagSize; i++)
	{
		cout<<setw(10)<<"Last Name"<<setw(10)<<"First Name"<<setw(4)<<"Age"<<setw(15)<<"Phone"<<setw(10)<<"Experience";
		{
			cout<<"\t\t"<<setw(10)<<clientList[i].lastName<<setw(10)<<clientList[i].firstName<<setw(10)<<clientList[i].age<<setw(15)<<clientList[i].phone<<setw(3)<<clientList[i].experience;
		}							
	}
	cout<<"\n\n";
	pause();
}
