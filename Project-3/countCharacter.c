#include <stdio.h>
#include <stdlib.h>
#include "countCharacter.h"

int findCharacter(char* file, const char* letter)
{
        int count = 0;
        int ch;
        FILE* f;

        f = fopen(file, "r");

        if (f == NULL)
        {
                printf("Cannot create file\n");
                return EXIT_FAILURE;
        }

        while((ch = getc(f)) != EOF)
        {
                if (ch == *letter)
                {
                        count = count+1;
                }
        }
        fclose(f);
        printf("Number of %c's found: %d\n", *letter, count);

        return 0;
}