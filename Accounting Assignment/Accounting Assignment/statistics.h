/*------------------------------------class.h
Purpose: provides client functions to generate and utilize a custom menu

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
statFile        ifstream      ifstream of input data file
numEntries      int           number of entries populated in the array
maxEntries      int           maximum size of array
stats[20]       double        array of type double, stores data read from statFile

--- Member Functions ---
Name                Return     Description; Parameter description
--------------------------------------------------------------------------------------------
Stats();         N/A        default class constructor
	no params

fill()		     bool       populates an array of doubles from whitespace dilineated file
							returns false if there was an error in data validation
	no params

print()          void       prints values from an array
	no params

bigNum()         double     calculates and returns the largest value in the array
	no params

smallNum()       double     calculates and returns the smallest value in the array
	no params

average()        double     calculates and returns the average of values in the array
	no params

sum()            double     calculates and returns the sum of values in the array
	no params

*/


#ifndef _STATISTICS_INTERFACE_
#define _STATISTICS_INTERFACE_

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

class Stats
{
private:
	ifstream statFile;
	int numEntries;
	int maxEntries;
	double stats[20];
public:
	Stats();
	bool fill();
	void print();
	double bigNum();
	double smallNum();
	double average();
	double sum(); 
};

#endif