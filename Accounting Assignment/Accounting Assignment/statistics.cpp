#include "statistics.h"

//default class constructor
Stats::Stats()
{
	numEntries = 0;
	maxEntries = 20;
}

//populates an array of doubles from whitespace dilineated file
//returns false if there was an error in data validation
bool Stats::fill()
{
	double temp;
	bool more = true;

	statFile.open("lab1Numbers.txt");
	if(statFile.fail())
	{
		return false;
	}
	for(int i = 0; i<maxEntries; i++)
	{
		if(statFile >> temp)
		{
			stats[i] = temp;
			numEntries++;
		}
		else if(statFile.eof())
		{
			;
		}
		else
		{
			return false;
		}
	}

	statFile>>temp;
	if(!statFile.eof())
	{
		return false;
	}
	statFile.close();
	return true;
}

//prints values from an array
void Stats::print()
{
	cout<<endl;
	for(int i = 0; i<numEntries ; i++)
	{
		cout<<std::setw(10)<<stats[i];
		if((i+1)%4 == 0)
		{
			cout<<endl;
		}
	}
}

//calculates and returns the smallest value in the array
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

//calculates and returns the largest value in the array
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

//calculates and returns the sum of values in the array
double Stats::sum()
{
	double sum = 0;
	for(int i = 0; i<numEntries ; i++)
	{

		sum += stats[i];
	}
	return sum;
}

//calculates and returns the average of values in the array
double Stats::average()
{
	return Stats::sum()/(numEntries);
}

