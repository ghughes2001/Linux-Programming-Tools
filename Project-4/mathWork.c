#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

void help()
{
        printf("This program takes a file\n");
        printf("Then followed by a series of numbers\n");
}

bool isPrime(int number)
{
        int i;

        for (i = 2; i < number/2; i++)
        {
                if ((number % i) == 0)
                {
                        return false;
                }
        }
        return true;
}

int main(int argc, char** argv)
{
        int status;
        pid_t childPid = fork();

        FILE* file;

        if (childPid < 0)
        {
                printf("Fork failed!\n");
                exit(0);
        }
        else if (childPid == 0)
        {
                int size = argc - 2;
                int* argArray;
                argArray = (int*) malloc(sizeof(int) * size);

                if (argArray == NULL)
                {
                        printf("argArray memory not allocated!\n");
                }

                int i;
                printf("\n");

                for (i = 0; i < size; i++)
                {
                        argArray[i] = atoi(argv[i+2]);
                        if (atoi(argv[i+2]) < 0)
                        {
                                //argArray[i] = -argArray[i];
                        }
                }
                int* primes;
                primes = (int*) malloc(sizeof(int) * size);

                if (primes == NULL)
                {
                        printf("Primes memory not allocated!\n");
                }
                int x;
                int y = 0;

                for (x = 0; x < size; x++)
                {
                        if (argArray[x] > 0)
                        {
                                if (isPrime(argArray[x]))
                                {
                                        primes[y] = argArray[x];
                                        primes[y++] = argArray[x];
                                }
                        }
                }

                file = fopen(argv[1], "w");
                if (file == NULL)
                {
                        printf("File not created\n");
                        return EXIT_FAILURE;
                }
                if (file != NULL)
                {
                        fprintf(file, "Child: %d: ", getpid());
                        for (i = 0; i < size; i++)
                        {
                                fprintf(file, "%d ", argArray[i]);
                        }
                        fprintf(file, "\n");
                        int j;
                        int foundPair = 0;

                        fprintf(file, "Child: %d: ", getpid());
                        for (x = 0; x < size; x++)
                        {
                                for (j = 0; j < size; j++)
                                {
                                        if ((primes[x] + primes[j] <= 50) && (primes[x] != 0) && (primes[j] != 0))
                                        {
                                                foundPair = foundPair + 1;
                                                fprintf(file, "%d-%d; ", primes[x], primes[j]);
                                        }
                                }
                        }
                        fprintf(file, "\n");

                        if (foundPair >= 1)
                        {
                                return EXIT_SUCCESS;
                        }
                        else
                        {
                                return EXIT_FAILURE;
                        }
                }
                fclose(file);
                free(primes);
                free(argArray);
        }
        wait(&status);

        if ( WIFEXITED(status) )
        {
                file = fopen(argv[1], "a");
                if (file == NULL)
                {
                        printf("File not opened\n");
                }
                if (file != NULL)
                {
                        int exitStatus = WEXITSTATUS(status);
                        fprintf(file, "Parent: %d: %d\n", childPid, exitStatus);
                }
                fclose(file);
        }
        int option;

        while ((option = getopt(argc, argv, ":h")) != -1)
        {
                switch(option)
                {
                        case 'h':
                                help();
                                exit(0);
                        default:
                                break;
                }
        }

        return 0;
}