#!/bin/bash

# Filename       test.sh
# Date           2022-09-16
# Author         Trent Rogers
# Email          trentr314@gmail.com
#
# Description
# 	This shell script runs the Argument_Parser program with various arguments to demonstrate its function.
#	Some of the arguments are invalid in order to demonstrate error behavior.  The script regularly echoes
#	a brief description what is happening so that the tests can be understood relatively well simply by
#	watching the terminal.



echo -e "[- Concatenating the contents of myInputText.txt: -]"
cat myInputText.txt

echo -e "\n\n[- Running Argument_Parser with -u flag and input filename myInputText.txt -]"
./Argument_Parser -u myInputText.txt
echo -e "[- Concatenating the contents of output.txt: -]"
cat output.txt

echo -e "\n[- Running Argument_Parser with -l flag and input filename myInputText.txt -]"
./Argument_Parser -l myInputText.txt
echo -e "[- Concatenating the contents of output.txt: -]"
cat output.txt

echo -e "\n[- Running Argument_Parser with no input filename -]"
./Argument_Parser 

echo -e "\n[- Running Argument_Parser with both -l and -u flags and input filename myInputText.txt -]"
./Argument_Parser -l -u myInputText.txt
