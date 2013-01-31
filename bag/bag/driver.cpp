#include "menu.h"
#include "utility.h"
#include "bag.h"

int main()
{
	Menu menuA;
	Menu menuB;
	int choice;



	Bag <int> IntBag;
	Bag <double> DoubleBag;
	Bag <string> StringBag;

	pause();
	menuA.addItem("Add integer to bag");
	menuA.addItem("Add double to bag");
	menuA.addItem("Add string to bag");
	menuA.addItem("exit");

	menuB.addItem("Add item to Bag");
	menuB.addItem("Remove item from bag");
	menuB.addItem("Empty the bag");
	menuB.addItem("Number of items in bag");
	menuB.addItem("Find an item in the bag");
	menuB.addItem("List items in the bag");
	menuB.addItem("Exit");


	choice = menuA.getChoice();

	pause();
	
	return 0;
}