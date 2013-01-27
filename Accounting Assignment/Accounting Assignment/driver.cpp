/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1
Build a class which will store 20 floating point numbers and return max,min, sum, and average of the numbers.
Build a driver program which will load a file and allow the user to display the calculation results provided by the statistics class.
*/


#include "menu.h"
#include "statistics.h"
#include "uimanip.h"
#include <Windows.h>

int main()
{
	Menu statMenu("Select an Option");
	Stats currentStats;
	int myChoice=0;
	bool error;

	printFile("about.txt");
	pause();
	statMenu.addItem("Print Array");
	statMenu.addItem("Array Sum");
	statMenu.addItem("Array Average");
	statMenu.addItem("Array Max");
	statMenu.addItem("Array Min");
	statMenu.addItem("Quit");

	
	if(!currentStats.fill())
	{
		system("CLS");
		cout<<"ERROR: There has been an error reading the input file.\n";
		cout<<"Please verify the input file is properly\nformatted and that there are no more than 20 entries and try again.";
		pause();
	}
	else
	{
		while(myChoice != 6) 
		{
			myChoice = statMenu.getChoice();
			system("CLS");
			switch(myChoice)
			{
			case 1:
				cout<<"\n\n\t"<<"Printing array...\n";
				currentStats.print();
				break;
			case 2:
				cout<<"\n\n\tSum is: "<<currentStats.sum();
				break;
			case 3:
				cout<<"\n\n\tAverage is: "<<currentStats.average();
				break;
			case 4:
				cout<<"\n\n\tMax value is: "<<currentStats.bigNum();
				break;
			case 5:
				cout<<"\n\n\tMin value is: "<<currentStats.smallNum();
				break;
			case 6:
				printFile("goodbye.txt");
				break;
			default:
				cout<<"ERROR: INVALID MENU CHOICE.";
				break;
			}
			cout<<"\n\t";
			pause();
		}
	}
	return 0;
}

