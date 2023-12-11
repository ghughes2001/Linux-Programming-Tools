#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "caseConversion.h"

int toUpperCase(char *file, char *out)
{
        FILE* f1;
        FILE* f2;
        char ch;

        f1 = fopen(file, "r");
        if (f1 == NULL)
        {
                printf("Error opening file\n");
                return EXIT_FAILURE;
        }
        f2 = fopen(out, "w");
        if (f2 == NULL)
        {
                printf("Error in creating output file\n");
                return EXIT_FAILURE;
        }

        while ((ch = fgetc(f1)) != EOF)
        {
                if (islower(ch))
                {
                        ch = ch-32;
                }
                putc(ch, f2);
        }
        fclose(f1);
        fclose(f2);

        return 0;
}

int toLowerCase(char *file, char *out)
{
        char ch;
        FILE* f1;
        FILE* f2;

        f1 = fopen(file, "r");
        if (f1 == NULL)
        {
                printf("Error opening file\n");
                return EXIT_FAILURE;
        }
        f2 = fopen(out, "w");
        if (f2 == NULL)
        {
                printf("Error in creating output file\n");
                return EXIT_FAILURE;
        }

        while ((ch = fgetc(f1)) != EOF)
        {
                if (isupper(ch))
                {
                        ch = ch+32;
                }
                putc(ch, f2);
        }
        fclose(f1);
        fclose(f2);

        return 0;
}
