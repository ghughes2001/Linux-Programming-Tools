#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "caseConversion.h"
#include "countCharacter.h"

void help()
{
        printf("The options for this program are: \n");
        printf("-f inputFileName \n");
        printf("-o outputFileName \n");
        printf("-c char to look for and count occurrence \n");
        printf("-l convert to lower case \n");
        printf("-u convert to upper case \n");
}

int main(int argc, char** argv)
{
        char* fileName = NULL;
        char* file1 = NULL;
        const char* c = NULL;
        char* file2 = NULL;
        char* outputFileName = "out.txt";
        int option;

        while ( (option = getopt(argc, argv, "hf:o:c:u:l:")) != -1) {
                switch(option) {
                        case 'h':
                                help();
                                break;
                        case 'f':
                                fileName = optarg;
                                break;
                        case 'o':
                                outputFileName = optarg;
                                break;
                        case 'c':
                                c = optarg;
                                break;
                        case 'u':
                                file1 = optarg;
                                break;
                        case 'l':
                                file2 = optarg;
                                break;
                        default:
                                printf("Forgot part of the inputs to run program\n");
                                break;
                }
        }

        if ((fileName != NULL) && (c != NULL))
        {
                findCharacter(fileName, c);
        }

        if ((fileName != NULL) && (file1 != NULL))
        {
                toUpperCase(fileName, file1);
        }
        if ((fileName != NULL) && (file2 != NULL))
        {
                toLowerCase(fileName, file2);
        }

        FILE* inputFile;
        FILE* outFile;

        inputFile = fopen(fileName, "r");
        if (inputFile == NULL)
        {
                printf("{inputFile] was not created!\n");
                return EXIT_FAILURE;
        }

        outFile = fopen(outputFileName, "a");
        char ch;

        ch = fgetc(inputFile);
        while (ch != EOF)
        {
                fputc(ch, outFile);
                ch = fgetc(inputFile);
        }
        fclose(inputFile);
        fclose(outFile);

        return 0;
}
