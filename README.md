# File IO and Argument Parsing with TCLAP
This project uses a third-party library, TCLAP (Templatized C++ Command Line Parser), to process arguments given to the C++ program.  The program simply uppercases or lowercases the contents of an input file, according to the arguments given, and writes the result to an output file.

If you would like to run the program in your browser, visit [this Repl]()!! (please be patient as it takes a minute to run).

If you would like to better understand the TCLAP library, you can view the documentation at http://tclap.sourceforge.net

# Getting started
If you would like to run the program on your own machine, you must have g++ installed first.  If you do not have g++:

- If you are on Mac, install Xcode to get g++.

- If you are on Linux, enter 
```bash
sudo apt install g++
```
in the terminal.

- If you are on Windows, you can install the same way as Linux with the Windows Subsystem for Linux (WSL).  Simply open PowerShell as administrator and enter
```bash
$ wsl --install
```
This installs Ubuntu by default and takes quite a while.  Then from the Ubuntu terminal, you can use
```bash
$ sudo apt install g++
```

You can then navigate to the directory where you would like to download the program and enter
```bash
$ git clone https://github.com/trentr314/Argument_Parser.git
```

# Requirements
The include folder that I have on this GitHub, adjacent to the other files, is all that is needed to work with TCLAP.  Everything else should be fine with a g++ installation.

If you would like to install TCLAP for yourself, you can use bash command
```bash
$ wget http://sourceforge.net/projects/tclap/files/tclap-1.2.1.tar.gz
```
and then
```bash
tar zxfv tclap-1.2.1.tar.gz
```
and you will have the same include folder as I have on this GitHub, along with the rest of a complete TCLAP installation.

# Usage
You can run my shell scripts to compile, test and clean up the program.  I recommend running
```bash
$ ./compile.sh
```
to compile the program and create an executable Argument_Parser.  This shell script simply has a few g++ commands to build the program.  If you run
```bash
$ ./test.sh
```
then the program will be run several times with different arguments to demonstrate behavior.  The last time the program is run in the shell script it is given invalid arguments to test error behavior, which gives a little documentation of the usage.  A quick summary: 

./Argument_Parser runs the executable.  Following this command, it has an optional output filename using -o as the first flag, then -l or -u for lowercase or uppercase (or nothing to leave case unaffected), and lastly a required input filename which is always the last argument.  The contents of the input file are uppercased or lowercased or neither depending on your selection, and the result is sent to the output file, which is named output.txt if you do not specify another filename.

Running
```bash
$ ./clean.sh
```
will bring the directory back to the state it was in before you compiled the program, without object files or executables or (default) output files.  From here you can of course compile it again and run it however you like.

# Contact
Trent Rogers

Email: trentr314@gmail.com
