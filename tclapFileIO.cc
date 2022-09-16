/*
* Filename       tclapFileIO.cc
* Date           2022-09-16
* Author         Trent Rogers
* Email          trentr314@gmail.com
*
* Description
*   This C++ program takes a map containing parsed command line arguments and uses it to determine
*	which text file to open and read, whether to change the contents to lowercase or uppercase or
*	neither, and which text file to write to.
*/

#include "tclapHeader.h"

void tclapFileIO(map<int,string> optionMap){

	// allows values in the option map to be accessed by name (their integer keys are already known)
	enum optionNames {lower, upper, output, input};
        // lower = 0
        // upper = 1
        // output = 2
        // input = 3


	// creates a file object for reading
	fstream fileOpen;
	// takes a string containing the input filename argument from the entered map
	string inputFileName = optionMap[input].c_str();
	// opens the input file specified for reading
	fileOpen.open(inputFileName, ios::in);

	// creates a file object for writing
	fstream fileOut;
	// takes a string containing the output filename argument from the entered map
	string outputFileName = optionMap[output].c_str();
	// opens the output file for writing
	fileOut.open(outputFileName, ios::out);

	// a string variable to be used when reading/writing
	string line;

	// if the -l flag is set, we will change the text to lowercase before writing to the output file
	if(optionMap[lower] == "-l"){
		// while there is still another line to read, put the line in the variable "line"
		while(getline(fileOpen, line)){
			// iterate through every character in the string
			for(int i=0; i<line.size(); i++){
				// turn every character in the string to lowercase
				line[i] = tolower(line[i]);
			}
			// send the lowercased line to the output file
			fileOut << line << endl;
		}
	// if the -u flag is set, we will change the text to uppercase before writing to the output file
	}else if(optionMap[upper] == "-u"){
		// while there is still another line to read, put the line in the variable "line"
		while(getline(fileOpen, line)){
			// iterate through every character in the string
            for(int i=0; i<line.size(); i++){
				// turn every character in the string to uppercase
                line[i] = toupper(line[i]);
            }
			// send to uppercased line to the output file
            fileOut << line << endl;
        }
	// if neither the -l or the -u flag is set, just write the contents of the input file to the output file as-is
	}else{
		while(getline(fileOpen, line)){
        	fileOut << line << endl;
		}
	}

}