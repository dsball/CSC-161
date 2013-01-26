#include "statistics.h"

ifstream  welcomeFile;

Stats::Stats()
{
	numEntries = 0;
	maxEntries = 20;
}

void Stats::fill()
{
	string temp;

	statFile.open("lab1Numbers.txt");
	for(int i = 0; i<maxEntries && statFile >> stats[i]; i++)
	{
		numEntries++;
	}
	statFile.close();
}

void Stats::print()
{
	cout<<endl;
	for(int i = 0; i<numEntries ; i++)
	{
		cout<<stats[i]<<endl;
	}
}


double Stats::smallNum()
{
	int smallest = 0;
	for(int i = 0; i<numEntries ; i++)
	{
		if(stats[i]<stats[smallest])
		{
			smallest = i;
		}
	}
	return stats[smallest];
	return 0;
}


double Stats::bigNum()
{
	int largest = 0;
	for(int i = 0; i<numEntries ; i++)
	{
		if(stats[i]>stats[largest])
		{
			largest = i;
		}
	}
	return stats[largest];
	return 0;
}


double Stats::sum()
{
	double sum = 0;
	for(int i = 0; i<numEntries ; i++)
	{

		sum += stats[i];
	}
	return sum;
}

double Stats::average()
{
	return Stats::sum()/(numEntries);
}

void pause()
{
	cout<<"\n\nPress Enter to continue...";
	cin.clear();
	cin.sync();
	cin.get();
}

void welcome()
{
	system("CLS");
	welcomeFile.open("about.txt");
	printFile(welcomeFile);
	welcomeFile.close();
	pause();
}

void printFile(ifstream &inFile)
{
	string printMe = "";
	string temp;

	if(inFile)
	{
		while(inFile.good())
		{
			getline(inFile, temp);
			temp += "\n";
			printMe += temp;
		}
	}
	else
	{
		cout<<"No input detected!";
	}

	system("CLS");
	cout<<printMe;
}

