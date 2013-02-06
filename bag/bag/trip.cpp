#include "trip.h"

Trip::Trip()
{
	
}

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

	cout<<"\n\tLast name:";

	while(!(cin>>tempClient.lastName))
	{
		cout<<"That isn't a valid name.";
		cin.clear();
		cin.sync();
	}

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

void Trip::remClient()
{
	cout<<"\n\n\t\tEnter the client number you wish to remove: ";
	cin>>deleteMe;
	clientBag.deleteItem(deleteMe-1);
}

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

void Trip::countClients() const
{
	cout<<"\n\n\t\tThere are "<<clientBag.getCount()<<" clients scheduled for the trip.";
	Sleep(1000);
}

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
