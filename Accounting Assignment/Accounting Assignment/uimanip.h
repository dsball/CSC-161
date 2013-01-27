/*------------------------------------class.h
Purpose: provides functions

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
none

--- Functions ---
Name                            Return    Description; Parameter description
--------------------------------------------------------------------------------------------
pause()                         void      replace system("PAUSE") with non-system function call
    no params

printFile(string)               void      opens a file and prints it with fileToString()
    string: relative path of file being printed

fileToString(ifstream &inFile)  void      stores an ifstream in a string and returns it
    ifstream&: ifstream to be read
*/

#ifndef _UIMANIP_INTERFACE_
#define _UIMANIP_INTERFACE_

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void pause();
void printFile(string);
string fileToString(ifstream&);

#endif