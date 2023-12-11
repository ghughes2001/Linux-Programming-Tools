GCC = gcc
CFLAGS = -g -Wall -Wshadow

project3: countCharacter.o caseConversion.o mainProject.o
        $(GCC) $(CFLAGS) countCharacter.o caseConversion.o mainProject.o -o project3

mainProject.o: mainProject.c
        $(GCC) $(CFLAGS) -c mainProject.c

caseConversion.o: caseConversion.c caseConversion.h
        $(GCC) $(CFLAGS) -c caseConversion.c caseConversion.h

countCharacter.o: countCharacter.c countCharacter.h
        $(GCC) $(CFLAGS) -c countCharacter.c countCharacter.h
