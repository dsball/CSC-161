#include "menu.h"
#include "utility.h"
#include "bag.h"

int main()
{
	Menu menuA;
	Menu menuB;
	int choice;
	int intToAdd;
	string stringToAdd;


	Bag <int> IntBag;
	vector<int> intBagList;
	int intBagSize;

	Bag <string> StringBag;
	vector<string> stringBagList;
	int stringBagSize;

	int deleteMe;

	menuA.addItem("Manage integer bag");
	menuA.addItem("Manage string bag");
	menuA.addItem("exit");

	menuB.addItem("Add item to Bag");
	menuB.addItem("Remove item from bag");
	menuB.addItem("Empty the bag");
	menuB.addItem("Number of items in bag");
	menuB.addItem("Find an item in the bag");
	menuB.addItem("List items in the bag");
	menuB.addItem("Exit");


	choice = menuA.getChoice();
	switch(choice)
	{
		case 1:
			choice = menuB.getChoice();
			while(choice != 7)
			{
				switch(choice)
				{
					case 1:
						cout<<"Enter the number you wish to add: ";
						/*while(!(cin>>intToAdd))
						{
							cout<<"Invalid entry, try again: ";
							cin.clear();
							cin.sync();
						}*/
						cin>>intToAdd;
						if(IntBag.addItem(intToAdd))
						{
							cout<<"Successfully added.";
						}
						else
						{
							cout<<"Add failed.";
						}
						break;

					case 2:
						cout<<"Enter the item number you wish to remove: ";
						cin>>deleteMe;
						IntBag.deleteItem(deleteMe);
						break;

					case 3:
						cout<<"Dumping bag contents...";
						if(StringBag.empty())
						{
							cout<<"Bag emptied!";
						}
						else
						{
							cout<<"Failed to empty bag.";
						}
						pause();
						break;

					case 4:
						cout<<"There are "<<IntBag.getCount()<<" items in the bag.";
						Sleep(1000);
						break;

					case 5:
						break;

					case 6:
						intBagList = IntBag.toVector();
						intBagSize = intBagList.size();
						system("CLS");
						cout<<"Displaying Bag Contents: \n";
						for(int i=0; i<intBagSize; i++)
						{
							if(i%2 == 0)
							{
								cout<<"item "<<i+1<<": "<<setw(10)<<intBagList[i];
							}
							else
							{
								cout<<"\t\titem "<<i+1<<": "<<setw(10)<<intBagList[i]<<endl;
							}
							
						}
						pause();
						break;
						
					case 7:
						break;
				}
				choice = menuB.getChoice();
			}
			break;
		case 2:
			choice = menuB.getChoice();
			while(choice != 7)
			{
				
			}
			break;
		case 3:
			break;
		default:
			cout<<"ERROR: undefined entry.";
			break;
	}

	pause();
	
	return 0;
}