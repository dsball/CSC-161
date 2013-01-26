#ifndef _STATISTICS_INTERFACE_
#define _STATISTICS_INTERFACE_

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class Stats
{
private:
	ifstream statFile;
	int numEntries;
	int maxEntries;
	double stats[20];
public:
	Stats();
	void fill();
	void print();
	double bigNum();
	double smallNum();
	double average();
	double sum(); 
};

void welcome();
void pause();
void printFile(ifstream &inFile);

#endif