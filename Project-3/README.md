In particular, your project should consist of three C files countCharacter.c, caseConversion.c, mainProject.c and two header files countCharacter.h and caseConversion.h. And make a Makefile that compiles them into an executable called project3. The caseConversion.c has two functions: toUppercas(): which converts into upper case, and toLowercase(): which converts into lower case. The mainProject.c implements all header files and C files.
 
This executable project3 takes the following optional command line options:
1.    -h: This should output a help message indicating what types of inputs it expects and what it does. Your program should terminate after receiving a -h.
2.    -f inputFilename: When given -f followed by a string, your program should take the input filename as input.
3.    -c char: Specifies a different character to look for in the target file. By default, this is the character 'c'.
4.    -o outputFilename: When given -o followed by a string, your program should take the output filename as input. If the file already exists, you must append your output at the end of the file.
5.    -u: convert all lowercase characters into uppercase characters.
6.    -l: convert all uppercase characters into lowercase characters.

Your program can be run in this way:
./project3 -h
./project3 -f inputfile -o outputfile 
./project3 -f inputfile -c b  -u -o outputfile
./project3 -f inputfile -c H  -l -o outputfile
./project3 -c A -u < inputfile > outputfile
./project3 < inputfile > outputfile