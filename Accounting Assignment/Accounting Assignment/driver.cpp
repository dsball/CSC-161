#include "menu.h"
#include "statistics.h"
#include <Windows.h>


int main()
{
	Menu statMenu;
	Stats currentStats;
	int myChoice=0;
	welcome();
	statMenu.addItem("Print Array");
	statMenu.addItem("Array Sum");
	statMenu.addItem("Array Average");
	statMenu.addItem("Array Max");
	statMenu.addItem("Array Min");
	statMenu.addItem("Quit");

	
	currentStats.fill();
	
	while(myChoice != 6) 
	{
		myChoice = statMenu.getChoice();
		system("CLS");
		switch(myChoice)
		{
		case 1:
			cout<<"Printing array...\n";
			currentStats.print();
			break;
		case 2:
			cout<<"Sum is: ";
			cout<<currentStats.sum();
			break;
		case 3:
			cout<<"Average is: ";
			cout<<currentStats.average();
			break;
		case 4:
			cout<<"Max value is: ";
			cout<<currentStats.bigNum();
			break;
		case 5:
			cout<<"Calculating array Min...";
			cout<<currentStats.smallNum();
			break;
		case 6:
			cout<<"Ending program";
			break;
		default:
			cout<<"ERROR: INVALID MENU CHOICE.";
			break;
		}
		pause();
	}
	return 0;
}

