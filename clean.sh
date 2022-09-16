#!/bin/bash

# Filename       clean.sh
# Date           2022-09-05
# Author         Trent Rogers
# Email          trentr314@gmail.edu
#
# Description
# 	This shell script cleans up executables and object and output files for the TCLAP program.

echo -e "Cleaning up"
rm Argument_Parser
rm tclapInput.o
rm tclapFileIO.o
rm output.txt
