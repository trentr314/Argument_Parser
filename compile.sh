#!/bin/bash

# Filename       compile.sh
# Date           2022-09-05
# Author         Trent Rogers
# Email          trentr314@gmail.com
#
# Description
#   This shell script compiles tclapInput.cc and tclapFileIO.cc and links their object
#	files into an executable Argument_Parser.  It then runs Argument_Parser with a
#	variety of valid and invalid arguments, regularly concatenating the contents of the
#	input and output files to the screen to demonstrate the file I/O functions.

echo -e "Compiling and linking tclapInput.cc and tclapFileIO.cc"
g++ -c -I include tclapInput.cc
g++ -c -I include tclapFileIO.cc
g++ tclapInput.o tclapFileIO.o -o Argument_Parser
echo -e "Done"
