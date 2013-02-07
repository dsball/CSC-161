#include "trip.h"


//default constructor
Trip::Trip()
{
	
}

//prompts user for client information, validates data and enters into the Array. 
//Also truncates names longer than 12 characters.
void Trip::addClient()
{
	string tempInt;
	string tempString;

	cout<<"\n\tFirst name:";
	while(!(cin>>tempClient.firstName))
	{
		cout<<"That isn't a valid name.";
		cin.clear();
		cin.sync();
	}
	if(tempClient.firstName.length() > 12)
		tempClient.firstName.erase(12,string::npos);

	cout<<"\n\tLast name:";
	while(!(cin>>tempClient.lastName))
	{
		cout<<"That isn't a valid name.";
		cin.clear();
		cin.sync();
	}
	if(tempClient.lastName.length() > 12)
		tempClient.lastName.erase(12,string::npos);

	cout<<"\n\tAge:";
	while(true)
	{
		if(!(cin>>tempClient.age))
		{
			cin.clear();
			cin.sync();
			cout<<"Invalid age, try again: ";
			continue;
		}
		if(tempClient.age <0 || tempClient.age >120)
		{
			cin.clear();
			cin.sync();
			cout<<"Invalid age, try again: ";
			continue;
		}
		break;
	}

	cout<<"\n\t10 digit phone, no special characters: ";
	while(true)
	{
		if(!(cin>>tempInt))
		{
			cout<<"That's not a valid phone number!";
			continue;
		}

		tempString = tempInt;
		if(tempString.length() != 10)
		{
			cout<<"Invalid format or length, try again: ";
			continue;
		}
		tempString.insert(0,"(");
		tempString.insert(4,") ");
		tempString.insert(9,"-");
		tempClient.phone = tempString;
		break;
	}

	cout<<"\n\tExperience (0 - none, 1 - intermediate, 2 - expert):";
	cin>>tempClient.experience;

	while(tempClient.experience <0 || tempClient.experience >2)
	{
		cout<<"Invalid experience level, must be 0/1/2.";
		cout<<"Try again: ";
		cin>>tempClient.experience;
	}

	clientBag.addItem(tempClient);
}

//removes a client from the array
void Trip::remClient()
{
	cout<<"\n\n\t\tEnter the client number you wish to remove: ";
	cin>>deleteMe;
	if(!(clientBag.deleteItem(deleteMe-1)))
	{
		cout<<"Delete failed! Did you enter a valid number?";
	}
	else
	{
		cout<<"Delete Successful";
	}
}


//cancels the trip by setting clients to zero
void Trip::cancelTrip()
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

//gets number of clients on the trip and prints it to screen
void Trip::countClients() const
{
	cout<<"\nThere are "<<clientBag.getCount()<<" clients scheduled for the trip.";
	pause();
}

//lists the clients and their information
void Trip::listClients()
{
	clientList = clientBag.toVector();
	clientBagSize = clientList.size();
	system("CLS");
	cout<<"\n\t\t\tClient list \n\n";
	cout<<left<<setw(15)<<"Last Name"<<setw(15)<<"First Name"<<setw(6)<<"Age"<<setw(17)<<"Phone"<<"Experience\n";
	cout<<"-----------------------------------------------------------------\n";
	for(int i=0; i<clientBagSize; i++)
	{
		cout<<left<<setw(15)<<clientList[i].lastName<<setw(15)<<clientList[i].firstName<<setw(6)<<clientList[i].age<<setw(17)<<clientList[i].phone<<setw(3);
		switch(clientList[i].experience)
		{
			case 0:
				cout<<left<<"Beginner\n";
				break;
			case 1:
				cout<<left<<"intermediate\n";
				break;
			case 2:
				cout<<left<<"Expert\n";
				break;
		}
	}
	cout<<"\n";
	pause();
}
