/*------------------------------------utility.h
Purpose: provides general utility functions, headers, and generic using declarations.

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
#include<vector>
#include<windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::setw;
using std::to_string;
using std::string;
using std::left;

void pause();
bool printFile(string);
string fileToString(ifstream&);

#endif