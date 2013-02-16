/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1
Build a template Bag array class which will store 15 items of the same data type. The user will be able to add, remove, empty,
check item count, find an item, and list bag contents.

The driver will consist of a menu and submenus which allow the user to perform bag functions on an integer bag and a string bag.




*/

#include "menu.h"
#include "utility.h"
#include "bag.h"
#include "trip.h"

int main()
{
	Menu menuA;
	Menu menuB;
	Menu menuC;
	int choice = 0;
	int intToAdd;
	string stringToAdd;

	Trip trip;

	Bag<int> IntBag;
	vector<int> intBagList;
	int intBagSize;

	Bag<string> StringBag;
	vector<string> stringBagList;
	int stringBagSize;

	int deleteMe;
	int index = 0;
	int findInt;
	string findString;
	
	if(!printFile("about.txt"))
	{
		cout<<"ERROR READING WELCOME FILE\n";
	}
	pause();


	menuA.addItem("Test integer Array");
	menuA.addItem("Test string Array");
	menuA.addItem("Test trip array");
	menuA.addItem("exit");

	menuB.addItem("Add item to the bag");
	menuB.addItem("Remove item from the bag");
	menuB.addItem("Empty the bag");
	menuB.addItem("Number of items in bag");
	menuB.addItem("Find an item in the bag");
	menuB.addItem("List items in the bag");
	menuB.addItem("Exit");

	menuC.addItem("Add client to trip");
	menuC.addItem("Remove client from trip");
	menuC.addItem("Cancel trip");
	menuC.addItem("Number of clients in trip");
	menuC.addItem("List clients in trip");
	menuC.addItem("Exit");

	while(choice != 4)
	{
		choice = menuA.getChoice();
		switch(choice)
		{
			case 1:
				choice = 0;
				while(choice != 7)
				{
					choice = menuB.getChoice();
					switch(choice)
					{
						case 1:
							cout<<"\n\tEnter the number you wish to add: ";
							while(!(cin>>intToAdd))
							{
								cout<<"Invalid entry, try again: ";
								cin.clear();
								cin.sync();
							}
							if(IntBag.addItem(intToAdd))
							{
								cout<<"\t\tSuccessfully added.";
								Sleep(500);
							}
							else
							{
								cout<<"Add failed.";
								pause();
							}
							break;

						case 2:
							cout<<"\n\n\t\tEnter the item number you wish to remove: ";
							cin>>deleteMe;
							if(!(IntBag.deleteItem(deleteMe-1)))
							{
								cout<<"Delete failed! Did you enter a valid number?\n";
							}
							else
							{
								cout<<"Delete Successful";
							}
							pause();
							break;

						case 3:
							cout<<"\n\t\tDumping bag contents...";
							if(IntBag.empty())
							{
								cout<<"\n\t\tBag emptied!\n";
							}
							else
							{
								cout<<"\n\t\tFailed to empty bag.\n";
							}
							pause();
							break;

						case 4:
							cout<<"\n\n\t\tThere are "<<IntBag.getCount()<<" items in the bag.\n";
							pause();
							break;

						case 5:
							cout<<"\t\tEnter the number you wish to find:";
							cin>>findInt;
							index = IntBag.findItem(findInt, 0);
							if(index != -1)
							{
								cout<<findInt<<" is item number: "<<index+1<<endl;
							}
							else
							{
								cout<<"\n\t\tThat number isn't in the list!\n";
							}
							pause();
							break;
						case 6:
							intBagList = IntBag.toVector();
							intBagSize = intBagList.size();
							system("CLS");
							cout<<"\n\t\t\tDisplaying Bag Contents: \n\n";
							for(int i=0; i<intBagSize; i++)
							{
								if(i%2 == 0)
								{
									cout<<"\t\titem "<<i+1<<": "<<setw(10)<<intBagList[i];
								}
								else
								{
									cout<<"  |  item "<<i+1<<": "<<setw(10)<<intBagList[i]<<endl;
								}
							
							}
							cout<<"\n\n";
							pause();
							break;
						
						case 7:
							cout<<"\n\t\tReturning to main menu.\n";
							break;
						default:
							cout<<"ERROR: undefined entry.";
							break;
					}
				}
				break;
			case 2:
				while(choice != 7)
				{
					choice = menuB.getChoice();
					switch(choice)
					{
						case 1:
							cout<<"\n\tEnter the item you wish to add: ";
							while(!(cin>>stringToAdd))
							{
								cout<<"Invalid entry, try again: ";
								cin.clear();
								cin.sync();
							}
							if(StringBag.addItem(stringToAdd))
							{
								cout<<"\t\tSuccessfully added.";
								Sleep(500);
							}
							else
							{
								cout<<"Add failed.";
								Sleep(1000);
							}
							break;

						case 2:
							cout<<"\n\n\t\tEnter the item number you wish to remove: ";
							cin>>deleteMe;
							if(!(StringBag.deleteItem(deleteMe-1)))
							{
								cout<<"Delete failed! Did you enter a valid number?\n";
							}
							else
							{
								cout<<"Delete Successful";
							}
							break;

						case 3:
							cout<<"\n\t\tDumping bag contents...";
							if(StringBag.empty())
							{
								cout<<"\n\t\tBag emptied!\n";
							}
							else
							{
								cout<<"\n\t\tFailed to empty bag.\n";
							}
							pause();
							break;

						case 4:
							cout<<"\n\n\t\tThere are "<<StringBag.getCount()<<" items in the bag.\n";
							pause();
							break;

						case 5:
							cout<<"\t\tEnter the item you wish to find:";
							cin>>findString;
							index = StringBag.findItem(findString, 0);
							if(index != -1)
							{
								cout<<findString<<" is item number: "<<index+1<<endl;
							}
							else
							{
								cout<<"\n\t\tThat item isn't in the list!\n";
							}
							pause();
							break;
						case 6:
							stringBagList = StringBag.toVector();
							stringBagSize = stringBagList.size();
							system("CLS");
							cout<<"\n\t\t\tDisplaying Bag Contents: \n\n";
							for(int i=0; i<stringBagSize; i++)
							{
								if(i%2 == 0)
								{
									cout<<"\t\titem "<<i+1<<": "<<setw(10)<<stringBagList[i];
								}
								else
								{
									cout<<"  |  item "<<i+1<<": "<<setw(10)<<stringBagList[i]<<endl;
								}
							
							}
							cout<<"\n\n";
							pause();
							break;
						
						case 7:
							cout<<"\n\t\tReturning to main menu.\n";
							break;
						default:
							cout<<"ERROR: undefined entry.";
							Sleep(1000);
							break;
					}
				}
				break;
			case 3:
				while(choice != 6)
				{
					choice = menuC.getChoice();
					switch(choice)
					{
						case 1:
							trip.addClient();
							break;
						case 2:
							trip.remClient();
							break;
						case 3:
							trip.cancelTrip();
							break;
						case 4:
							trip.countClients();
							break;
						case 5:
							trip.listClients();
							break;
						case 6:
							cout<<"\n\t\tReturning to main menu.\n";
							break;
						default:
							cout<<"ERROR: undefined entry.";
							Sleep(1000);
							break;
					}
				}
				break;
			case 4:
				if(!printFile("goodbye.txt"))
				{
					cout<<"ERROR READING EXIT FILE\n";
				}
				pause();
				break;
			default:
				cout<<"ERROR: undefined entry.";
				break;
		}
	}
	pause();
	
	return 0;
}