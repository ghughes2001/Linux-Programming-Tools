#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 859047

void help()
{
        printf("This program takes in a series of positive numbers\n");
        printf("and fulfills tasks based on whether it is in the child and parent process\n");
}

int main(int argc, char** argv)
{
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
        int shmid = shmget(SHMKEY, 2 * sizeof(int), 0777 | IPC_CREAT);

        if (shmid == -1)
        {
                perror("Error in shmget\n");
                exit(1);
        }
        int* a = (int*) (shmat(shmid, 0, 0));

        *a = -200;
        *(a + 1) = -200;

        int status;
        pid_t childPid = fork();
        wait(&status);

        if (childPid < 0)
        {
                printf("Fork failed!!!\n");
                exit(0);
        }
        else if (childPid == 0)
        {
 	    size = argc - 1;
           int* arr = NULL;
                int i;

                arr = (int*) malloc(sizeof(int) * size);
                if (arr == NULL)
                {
                        printf("Failed in allocating memory!!\n");
                        exit(0);
                }
                for (i = 0; i < size; i++)
                {
                        arr[i] = atoi(argv[i + 1]);
                }
                int x;
                int pair = 0;

                for (i = 0; i < size; i++)
                {
                        for (x = 0; x < size; x++)
                        {
                                if (arr[i] + arr[x] == 19)
                                {
                                        pair = pair + 1;
                                        int memory = shmget(SHMKEY, 2 * sizeof(int), 0777);
                                        int* m1 = (int*) (shmat(shmid, 0, 0));

                                        if (pair == 1)
                                        {
                                                if ((*m1 != -200) && (*(m1 + 1) != -200))
                                                {
                                                        printf("Error sharing memory!!!\n");
                                                        exit(1);
                                                }
                                                *m1 = arr[i];
                                                *(m1 + 1) = arr[x];
                                                shmdt(m1);
                                                exit(0);
                                        }
                                }
                        }
                }
                if (pair == 0)
                {
                        int pMemory = shmget(SHMKEY, 2 * sizeof(int), 0777);
                        int* p1 = (int*) (shmat(shmid, 0, 0));

                        *p1 = -1;
                        *(p1 + 1) = -1;
                        shmdt(p1);
                        exit(0);
                }
        }
        if (WIFEXITED(status))
        {
                int par = shmget(SHMKEY, 2 * sizeof(int), 0777);
                int* par1 = (int*) (shmat(shmid, 0, 0));

                if ((*par1 == -200) && (*(par1 + 1) == -200))
                {
                        printf("Child did not do anything!!!\n");
                }
                if ((*par1 == -1) && (*(par1 + 1) == -1))
                {
                        printf("No pair was found!!!\n");
                }
                if ((*par1 != -1) && (*(par1 + 1) != -1) && (*par1 != -200) && (*(par1 + 1) != -200))
                {
                        printf("Pair found by child: %d %d\n", *par1, *(par1 + 1));
                }
                shmdt(par1);
        }
        return 0;
}
