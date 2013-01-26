#ifndef _MENU_INTERFACE_
#define _MENU_INTERFACE_

#include<string>
#include<iostream>

using namespace std;

class Menu
{
private:
	string menuEntries[8];
	int maxEntries;
	int numEntries;
	string title;
	int choice;
public:
	Menu();
	Menu(string);
	int getChoice();
	void addItem(string);
};

#endif