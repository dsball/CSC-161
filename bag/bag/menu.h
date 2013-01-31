/*------------------------------------class.h
Purpose: provides client functions to generate and utilize a custom menu

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
menuEntries     string array   array of menu options
maxEntries      int            number of entries possible in one menu
numEntries      int            number of menu entries used
title           string         stores menu title
choice          int            stores choice selected by user

--- Member Functions ---
Name              Return     Description; Parameter description
--------------------------------------------------------------------------------------------
Menu()            N/A        default class constructor
	no params

Menu(string)      N/A        class constructor with custom title input
	string:  menu title      

initMenu()        void       initializes non-unique portions of class
	no params

getChoice()       int        prints menu and gets menu choice from user
	no params

addItem(string)   void       adds a menu item to the menu
	string: menu item name

*/


#ifndef _MENU_INTERFACE_
#define _MENU_INTERFACE_

#include "utility.h"
#include<string>
#include<iostream>

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
	void initMenu();
	int getChoice();
	void addItem(string);
	void print();
};

#endif