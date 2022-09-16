/*
* Filename       tclapInput.cc
* Date           2022-09-16
* Author         Trent Rogers
* Email          trentr314@gmail.com
*
* Description
*   This C++ program parses command line arguments using TCLAP and sends a map containing
*	relevant arguments to a function called tclapFileIO.cc to be processed.
*   If you would like to look at the TCLAP documentation to better understand it, you can go to http://tclap.sourceforge.net
*/

// contains all the necessary includes, including the prototype for the tclapFileIO function
#include "tclapHeader.h"

int main(int argc, char *argv[]){

	// a C++ map to contain pairs of integers (later to be indexed with an enum) and command line argument values
	map<int, string> optionMap;


	// creates a TCLAP CmdLine object for the program
	TCLAP::CmdLine cmd("Argument_Parser", ' ', "1.0");

    // creates a -l lower SwitchArg for the CmdLine object cmd
    TCLAP::SwitchArg lowerSwitch("l", "lower", "Convert all text to lowercase.", cmd, false);

	// creates a -u upper SwitchArg for the cmd CmdLine object cmd
	TCLAP::SwitchArg upperSwitch("u", "upper", "Convert all text to uppercase.", cmd, false);

	// creates a -o ValueArg (which is optional) for output filename
	// after the CmdLine object is parsed, outfileArg will contain either the specified filename or the default "output.txt" if none is specified
	TCLAP::ValueArg<std::string> outfileArg ("o", "outfile", "The name of the output file.", false, "output.txt", "output filename");
	// adds the argument outfileArg to the CmdLine object
	cmd.add(outfileArg);

	// creates an UnlabeledValueArg (which is required and is not associated with a flag) for the input file
	TCLAP::UnlabeledValueArg<std::string> infileArg("infile", "The input file name.", true, "infile.txt", "input filename", false);
	// adds the argument infileArg to the CmdLine object
	cmd.add(infileArg);



	// parse the arguments passed in using the TCLAP CmdLine object
	cmd.parse(argc, argv);


	// if the SwitchArg for lowercase is present, this will be true
	bool lowerBool = lowerSwitch.getValue();
	// adds values to the map for use by the tclapFileIO function (which will use an enum to index them)
	if(lowerBool){
		optionMap.insert(pair<int,string> (0, "-l"));
	}else{
		optionMap.insert(pair<int,string> (0, " "));
	}
	// if the SwitchArg for uppercase is present, this will be true
	bool upperBool = upperSwitch.getValue();
	// adds values to the map for use by the tclapFileIO function (which will use an enum to index them)
	if(upperBool){
		optionMap.insert(pair<int,string> (1, "-u"));
	}else{
		optionMap.insert(pair<int,string> (1, " "));
	}
	// if both the uppercase and lowercase switches are set, we will print the usage and exit
	if(lowerBool && upperBool){
		cmd.getOutput()->usage(cmd);
		exit(1);
	}

	// takes the argument for the output file and inserts it into our map
	string outfile = outfileArg.getValue();
	optionMap.insert(pair<int,string> (2, outfile));

	// takes the argument for the input file and inserts it into our map
    string infile = infileArg.getValue();
	optionMap.insert(pair<int,string> (3, infile));

	// call the tclapFileIO function to do the necessary conversions and file I/O, passing it our map
	tclapFileIO(optionMap);


	return 0;
}
