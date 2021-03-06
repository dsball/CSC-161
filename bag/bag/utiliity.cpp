#include "utility.h"


//replace system("PAUSE") with non-system function call
void pause()
{
	cout<<"Press Enter to continue...";
	cin.clear();
	cin.sync();
	cin.get();
}

//opens a file and prints it with fileToString()
bool printFile(string inFile)
{
	ifstream splashFile;
	system("CLS");
	splashFile.open(inFile);
	if(splashFile.fail())
	{
		return false;
	}
	cout << fileToString(splashFile);
	splashFile.close();
	return true;
}

//stores an ifstream in a string and returns it
string fileToString(ifstream &inFile)
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
	return printMe;
}