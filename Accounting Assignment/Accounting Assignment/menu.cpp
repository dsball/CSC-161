#include "menu.h"

Menu::Menu()
{
	title = "Menu";
	maxEntries = 8;
	numEntries = 0;
	choice = 0;
	for(int i = 0; i<maxEntries;i++)
	{
		menuEntries[i] = " ";
	}
}

Menu::Menu(string a)
{
	title = a;
	maxEntries = 8;
	numEntries = 0;
	choice = 0;
	for(int i = 0; i<maxEntries;i++)
	{
		menuEntries[i] = " ";
	}
}

void Menu::addItem(string item)
{
	if(numEntries>=maxEntries)
	{
		cout<<endl<<"Error: array full./nIncrease array limit.";
		cin.clear();
		cin.sync();
		cout<<"press a key to continue";
		cin.get();
	}
	else
	{
		menuEntries[numEntries] = item;
		numEntries++;
	}
	return;
}

int Menu::getChoice()
{
	system("CLS");
	cout<< "\t"<<title<<endl;
	for(int i = 0; i<numEntries;i++)
	{
		cout<<i+1<<": "<<menuEntries[i]<<endl;
	}
	while(true)
	{
		cout<<"Please enter your choice: ";
		cin.clear();
		cin.sync();
		cin>>choice;
		if(cin.fail() || (choice<=0 || choice>6) )
		{
			cout<<"Invalid choice. ";
			continue;
		}
		break;
	}
	return choice;
}