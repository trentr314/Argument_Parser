/*
* Filename       tclapHeader.h
* Date           2020-2-13
* Author         Trent Rogers
* Email          trentr314@gmail.com
*
* Description
*   This C++ header file includes the necessary #includes and the prototypes for
*   the functions main and tclapFileIO.  It is included in the files tclapInput.cc
*	and tclapFileIO.cc
*/



#include <tclap/CmdLine.h>

#include <string>

#include <map>

#include <fstream>

#include <iostream>

using namespace std;

int main (int argc, char *argv[]);

void tclapFileIO(map<int,string> optionMap);
